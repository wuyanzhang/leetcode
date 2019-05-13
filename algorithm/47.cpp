#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > ans;

void Find(vector<int> nums,int left,int right)
{
    if(left == right)
    {
        ans.push_back(nums);
    }
    for(int i = left; i <= right; i++)
    {
        if(i != left && nums[i] == nums[left])
            continue;
        swap(nums[left],nums[i]);
        Find(nums,left+1,right);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    Find(nums,0,nums.size()-1);
    return ans;
}

int main()
{
    int a[] = {1,1,2};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<vector<int> > result;
    result = permuteUnique(nums);
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
