#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool> > row(9,vector<bool>(9,false));
vector<vector<bool> > col(9,vector<bool>(9,false));
vector<vector<bool> > block(9,vector<bool>(9,false));

bool DFS(vector<vector<char> >& board)
{
    int rows = -1,cols = -1;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
            {
                rows = i;
                cols = j;
            }
        }
    }
    if(rows < 0)
    {
        return true;
    }
    else
    {
        for(int i = 0; i < 9; i++)
        {
            if(row[rows][i] || col[i][cols] || block[(rows/3)*3 + cols/3][i])
                continue;
            else
            {
                board[rows][cols] = i+'1';
                row[rows][i] = true;
                col[i][cols] = true;
                block[(rows/3)*3 + cols/3][i] = true;
                if(DFS(board))
                    return true;
                board[rows][cols] = '.';
                row[rows][i] = false;
                col[i][cols] = false;
                block[(rows/3)*3 + cols/3][i] = false;
            }
        }
        return false;
    }
}

bool solveSudoku(vector<vector<char> >& board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '1';
                row[i][num] = true;
                col[num][j] = true;
                block[(i/3)*3 + j/3][num] = true;

            }
        }
    }
    bool res = DFS(board);
    return res;
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
    if(solveSudoku(A))
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution!" << endl;
    }
    return 0;
}
