#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return;
    bool colZero = false,rowZero = false;
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++)
    {
        if(matrix[i][0] == 0)
            colZero = true;
    }
    for(int j = 0; j < n; j++)
    {
        if(matrix[0][j] == 0)
            rowZero = true;
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if(colZero)
    {
        for(int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    if(rowZero)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
}

int main()
{
    vector<vector<int> > matrix = {
        {1,1,2,1},
        {3,4,0,2},
        {1,0,1,5}
    };
    setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
