#include<iostream>
#include<vector>
using namespace std;

//µİ¹é
bool canJump(vector<int>& nums,int index)
{
    if((index+nums[index]) == nums.size()-1)
        return true;
    else if((index+nums[index]) < nums.size()-1 && nums[index] != 0)
    {
        canJump(nums,index+nums[index]);
    }
    else
    {
        return false;
    }
}

//Ì°ĞÄ
bool canJump1(vector<int>& nums)
{
    int n = nums.size();
    if(n == 0)
        return true;
    int res = nums[0];
    int i = 0;
    while(i < n-1 && res > 0){
        i++;
        res--;
        res = max(res, nums[i]);
    }
    return i==n-1?true:false;
}

int main()
{
    vector<int> nums = {3,0,1,1,4};
    bool result = canJump1(nums);
    if(result)
        cout << "Ture";
    else
        cout << "False";
    return 0;
}


















