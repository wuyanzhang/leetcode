#include<iostream>
#include<vector>
using namespace std;

int cur = 1;
void resolve(vector<vector<int> > &matrix,int row11,int rownn,int col11,int colnn,int n)
{
    int l = col11;
    int r = row11;
    if(col11 == colnn && row11 == rownn)
    {
        matrix[r][l] = cur;
    }
    while(l < colnn)
    {
        if(cur == n+1)
            break;
        matrix[r][l] = cur;
        cur++;
        l++;
    }
    while(r < rownn)
    {
        if(cur == n+1)
            break;
        matrix[r][l] = cur;
        cur++;
        r++;
    }
    while(l > col11)
    {
        if(cur == n+1)
            break;
        matrix[r][l] = cur;
        cur++;
        l--;
    }
    while(r > row11)
    {
        if(cur == n+1)
            break;
        matrix[r][l] = cur;
        cur++;
        r--;
    }

}

vector<vector<int>> generateMatrix(int n)
{
    if(n == 0)
        return {};
    int row11 = 0;
    int col11 = 0;
    int rownn = n-1;
    int colnn = n-1;
    vector<vector<int> > matrix(n,vector<int>(n));
    while(row11 <= rownn && col11 <= colnn)
    {
        resolve(matrix,row11++,rownn--,col11++,colnn--,n*n);
    }
    return matrix;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > result = generateMatrix(n);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
