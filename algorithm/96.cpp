#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int result = numTrees(n);
    cout << result;
    return 0;
}