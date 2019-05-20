#include<iostream>
#include<vector>
using namespace std;

void sortColors1(vector<int>& nums)
{
    int count_1 = 0,count_2 = 0,count_3 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
            count_1++;
        else if(nums[i] == 1)
            count_2++;
        else if(nums[i] == 2)
            count_3++;
    }
    int i = 0;
    while(count_1 > 0)
    {
        nums[i++] = 0;
        count_1--;
    }
    while(count_2 > 0)
    {
        nums[i++] = 1;
        count_2--;
    }
    while(count_3 > 0)
    {
        nums[i++] = 2;
        count_3--;
    }
}

void sortColors(vector<int>& nums)
{
    int red = 0;
    int blue = nums.size()-1;
    for(int i = 0; i <= blue; i++)
    {
        if(nums[i] == 0)
        {
            swap(nums[red],nums[i]);
            red++;
        }
        else if(nums[i] == 2)
        {
            swap(nums[i--],nums[blue]);
            blue--;
        }
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0,1};
    sortColors(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
