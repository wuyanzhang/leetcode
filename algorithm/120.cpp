#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
    int m = triangle.size();
    vector<vector<int>> res(m+1, vector<int>(m+1, 0));
    for(int i = m-1; i >= 0; --i)
        for(int j = 0; j < triangle[i].size(); ++j)
            res[i][j] = min(res[i+1][j],res[i+1][j+1]) + triangle[i][j];
    return res[0][0];
}

int main()
{
    vector<vector<int> > triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };
    int result = minimumTotal(triangle);
    cout << result << endl;
    return 0;
}