#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Find(vector<int> candidates,int target,vector<vector<int> > &res,vector<int> &temp,int start)
{
    if(target == 0)
    {
        res.push_back(temp);
        return;
    }
    if(target < 0)
        return;
    for(int i = start; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        Find(candidates,target - candidates[i],res,temp,i);
        temp.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int> candidates, int target)
{
    vector<vector<int> > res;
    vector<int> temp;
    Find(candidates,target,res,temp,0);
    return res;
}

int main()
{
    int a[] = {2,3,6,8};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<vector<int> > result;
    result = combinationSum(nums,8);
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
