#include<iostream>
#include<vector>
using namespace std;

bool search(vector<vector<char> >& board,string word,int index,int i,int j,vector<vector<bool> >& visited)
{
    if(index == word.size())
        return true;
    int m = board.size(), n = board[0].size();
    if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index] || visited[i][j] == true)
        return false;
    visited[i][j] = true;
    bool res = search(board, word, index + 1, i - 1, j, visited)
                 || search(board, word, index + 1, i + 1, j, visited)
                 || search(board, word, index + 1, i, j - 1, visited)
                 || search(board, word, index + 1, i, j + 1, visited);
    visited[i][j] = false;
    return res;
}

bool exist(vector<vector<char>>& board, string word)
{
    if(board.size() == 0 || board[0].size() == 0)
        return false;
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > visited(m,vector<bool>(n,false));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(search(board,word,0,i,j,visited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char> > board = {
          {'A','B','C','E'},
          {'S','F','C','S'},
          {'A','D','E','E'}
    };
    string word = "SEE";
    bool result = exist(board,word);
    cout << result << endl;
    return 0;
}
