#include<iostream>
#include<vector>
using namespace std;

void DFS(int n,int k,int level,vector<int> &cur,vector<vector<int> > &res)
{
    if(cur.size() == k)
    {
        res.push_back(cur);
        return;
    }
    for(int i = level; i <= n; i++)
    {
        cur.push_back(i);
        DFS(n,k,i+1,cur,res);
        cur.pop_back();
    }
}

vector<vector<int>> combine(int n,int k)
{
    vector<vector<int> > res;
    vector<int> cur;
    DFS(n,k,1,cur,res);
    return res;
}

vector<vector<int>> combine1(int n, int k)
{
    if (k > n || k < 0) return {};
    if (k == 0) return {{}};
    vector<vector<int>> res = combine(n - 1, k - 1);
    for (auto &a : res) a.push_back(n);
    for (auto &a : combine(n - 1, k)) res.push_back(a);
    return res;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int> > result;
    result = combine(n,k);
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
