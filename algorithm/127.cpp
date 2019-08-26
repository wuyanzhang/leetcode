#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    set<string> wordSet(wordList.begin(), wordList.end());
    if(!wordSet.count(endWord))
        return 0;
    queue<string> q;
    q.push(beginWord);
    int res = 0;
    while(!q.empty())
    {
        for(int k = q.size(); k > 0; k--)
        {
            string word = q.front();
            q.pop();
            if(word == endWord)
                return res+1;
            for(int i = 0; i < word.size(); i++)
            {
                string newWord = word;
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[i] = ch;
                    if(wordSet.count(newWord) && newWord != word)
                    {
                        q.push(newWord);
                        wordSet.erase(newWord);
                    }
                }
            }

        }
        res++;
    }
    return 0;
}


int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {
            "hot",
            "dot",
            "dog",
            "lot",
            "log",
            "cog"
    };
    int result = ladderLength(beginWord,endWord,wordList);
    cout << result << endl;
    return 0;
}