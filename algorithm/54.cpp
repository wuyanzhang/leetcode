#include<iostream>
#include<vector>
using namespace std;


void resolve(vector<vector<int> > matrix,vector<int> &result,int row11,int col11,int rownn,int colnn)
{
    int r = row11;
    int l = col11;
    if(row11 == rownn)
    {
        for(int i = col11; i <= colnn; i++)
        {
            result.push_back(matrix[row11][i]);
        }
    }
    else if(col11 == colnn)
    {
        for(int i = row11; i <= rownn; i++)
        {
            result.push_back(matrix[i][col11]);
        }
    }
    else
    {
        while(l < colnn)
        {
            result.push_back(matrix[r][l]);
            l++;
        }
        while(r < rownn)
        {
            result.push_back(matrix[r][l]);
            r++;
        }
        while(l > col11)
        {
            result.push_back(matrix[r][l]);
            l--;
        }
        while(r > row11){
            result.push_back(matrix[r][l]);
            r--;
        }
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0)
        return {};
    int row11 = 0;
    int col11 = 0;
    int rownn = matrix.size()-1;
    int colnn = matrix[0].size()-1;
    vector<int> result;
    while(row11 <= rownn && col11 <= colnn)
    {
        resolve(matrix,result,row11++,col11++,rownn--,colnn--);
    }
    return result;
}

int main()
{
    vector<vector<int> > matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> result = spiralOrder(matrix);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
