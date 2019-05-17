#include<iostream>
#include<vector>
using namespace std;

int factorial(int n)
{
    int res = 1;
    while(n > 0)
    {
        res *= n;
        n--;
    }
    return res;
}

// 组合数法
int uniquePaths_(int m, int n)
{
    int res = factorial(m+n-2) / (factorial(m-1)*factorial(n-1));
    return res;
}

// 动态规划法
int uniquePaths(int m, int n)
{
    vector<vector<int> > dp(m,vector<int>(n,0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m,n;
    cin >> m >> n;
    cout << uniquePaths(m,n);
    return 0;
}





















