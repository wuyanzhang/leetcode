#include<iostream>
#include<vector>
using namespace std;

int two_side(vector<int> nums,int low,int high,int target)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(nums[mid] == target)
        return mid;
    if(nums[mid] < nums[high])
    {
        if(nums[mid] < target && target <= nums[high])
        {
            return two_side(nums,mid+1,high,target);
        }
        else
        {
            return two_side(nums,low,mid-1,target);
        }
    }
    else
    {
        if(nums[low] <= target && target < nums[mid])
        {
            return two_side(nums,low,mid-1,target);
        }
        else
        {
            return two_side(nums,mid+1,high,target);
        }
    }
}

int search(vector<int> nums, int target)
{
    return two_side(nums,0,nums.size()-1,target);
}

int main()
{
    int a[] = {4,5,6,7,0,1,2};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    cout << search(nums,0) << endl;
    return 0;
}
