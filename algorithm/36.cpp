#include<iostream>
#include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char> >& board)
{
    vector<vector<bool> > row(board.size(),vector<bool>(board[0].size(),false));
    vector<vector<bool> > col(board.size(),vector<bool>(board[0].size(),false));
    vector<vector<bool> > block(board.size(),vector<bool>(board[0].size(),false));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '1';
                if(row[i][num] || col[num][j] || block[(i/3)*3 + j/3][num])
                {
                    return false;
                }
                else
                {
                    row[i][num] = true;
                    col[num][j] = true;
                    block[(i/3)*3 + j/3][num] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
	vector<vector<char> > A = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };
    if(isValidSudoku(A))
        cout << "true";
    else
        cout << "false";
    return 0;
}
