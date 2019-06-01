#include <iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target)
{
    if(nums.size() == 0)
        return false;
    int low = 0;
    int high = nums.size()-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] == target)
            return true;
        else if(nums[low] < nums[mid])
        {
            if(nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else if(nums[mid] < nums[high])
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if(nums[mid] == nums[low] && nums[high] == nums[mid])
        {
            for(auto& e : nums)
                if(e == target) return true;
            return false;
        }
        else
            high = mid;
    }
    return false;
}

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target;
    cin >> target;
    bool result = search(nums,target);
    cout << result << endl;
    return 0;
}
