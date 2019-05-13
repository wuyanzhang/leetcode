#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    int result;
    int cur = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == cur)
        {
            cur++;
            result = cur;
        }
        else
        {
            result = cur;
        }
    }
    return result;
}

int main()
{
    int a[] = {1,0,4,6};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    cout << firstMissingPositive(nums) << endl;
    return 0;
}
