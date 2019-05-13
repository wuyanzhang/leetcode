#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> nums,int low,int high,int target)
{
    if(high == 0)
        return 0;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(nums[mid] >= target)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

vector<int> searchRange(vector<int>& nums,int target)
{
    if(nums.size() == 0)
        return {-1,-1};
    vector<int> cur;
    int ans = search(nums,0,nums.size()-1,target);
    if(nums[ans] == target)
    {
        cur.push_back(ans);
        while(nums[ans] == target && (ans+1) < nums.size() && nums[ans+1] == target)
            ans++;
        cur.push_back(ans);
        return cur;
    }
    else
        return {-1,-1};
}

int main()
{
    int a[] = {5,6,6,7,8,8,8,10};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<int> result;
    result = searchRange(nums,8);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
