#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    if(nums.size() == 1 || nums.size() == 0)
        return;
    int i = nums.size()-2;
    while(i >= 0 && nums[i]>=nums[i+1])
        i--;
    if(i < 0)
    {
        sort(nums.begin(),nums.end());
    }
    else
    {
        for(int j = nums.size()-1; j > i; j--)
        {
            if(nums[j]>nums[i])
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        sort(nums.begin()+i+1,nums.end());
    }
}

int main()
{
    int a[] = {1,5,1};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
