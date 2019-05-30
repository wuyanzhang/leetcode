#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;
    int pre = 0,cur = 1,count = 1;
    while(cur < nums.size())
    {
        if(nums[pre] == nums[cur] && count == 0)
            cur++;
        else
        {
            if(nums[pre] == nums[cur])
                count--;
            else
                count = 1;
            nums[++pre] = nums[cur++];
        }
    }
    return pre+1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int len = removeDuplicates(nums);
    for(int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << len << endl;
    return 0;
}
