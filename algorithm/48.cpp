#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0)
        return;
    int col = matrix[0].size()-1;
    int row = matrix.size()-1;
    int Col = matrix[0].size()-1;
    int Row = matrix.size()-1;
    for(int i = 0; i < row; i++)
    {
        for(int j = i; j < col; j++)
        {
            swap(matrix[i][j],matrix[j][Col-i]);
            swap(matrix[i][j],matrix[Row-i][Col-j]);
            swap(matrix[i][j],matrix[Row-j][i]);
        }
        row--;
        col--;
    }
}

int main()
{
    vector<vector<int> > matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    rotate(matrix);
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
