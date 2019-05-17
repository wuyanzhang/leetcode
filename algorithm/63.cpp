#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int> > dp(m,vector<int>(n,0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if(i == 0 && j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = dp[i][j-1];
            else if(j == 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (long long)dp[i-1][j] + (long long)dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int> > input = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    int result = uniquePathsWithObstacles(input);
    cout << result << endl;
    return 0;
}
