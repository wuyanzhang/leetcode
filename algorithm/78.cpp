#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int> > cur;
    vector<vector<int> > res = {{}};
    for(int i = 0; i < nums.size(); i++)
    {
        cur = res;
        int size = res.size();
        for(int j = 0; j < size; j++)
        {
            cur[j].push_back(nums[i]);
            res.push_back(cur[j]);
        }
        cur.clear();
    }
    return res;
}

void DFS(vector<int>& nums,int level,vector<vector<int> >& res,vector<int>& cur)
{
    res.push_back(cur);
    for(int i = level; i < nums.size(); i++)
    {
        cur.push_back(nums[i]);
        DFS(nums,i+1,res,cur);
        cur.pop_back();
    }
}

vector<vector<int>> subsets1(vector<int>& nums)
{
    vector<vector<int> > res;
    vector<int> cur;
    DFS(nums,0,res,cur);
    return res;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<vector<int> > result;
    result = subsets1(nums);
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
