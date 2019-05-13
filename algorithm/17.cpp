#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> table = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void DFS(vector<string> &res,string digits,int cur_num,string cur_s)
{
    if(cur_num == digits.size())
    {
        res.push_back(cur_s);
    }
    else
    {
        int num = digits[cur_num] - '0';
        for(int i = 0; i < table[num].size(); i++)
        {
            cur_s.push_back(table[num][i]);
            cur_num++;
            DFS(res,digits,cur_num,cur_s);
            cur_num--;
            cur_s.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if(digits.size() == 0)
        return {};
    DFS(res,digits,0,"");
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result;
    int i;
    result = letterCombinations(s);
    for(i = 0; i < result.size()-1; i++)
    {
        cout << result[i] << " ";
    }
    cout << result[i] << endl;
    return 0;
}
