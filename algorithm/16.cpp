#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int min = abs(nums[0]+nums[1]+nums[2]-target);
    int sum;
    int sum2 = 0;
    for(int i = 0; i < nums.size()-2; i++)
    {
        int j = i + 1;
        int k = nums.size()-1;
        while(j < k)
        {
            sum = nums[i]+nums[j]+nums[k];
            cout << i << " " << j << " " << k << " ";
            cout << target << " " ;
            if(abs(nums[i]+nums[j]+nums[k]-target) <= min)
            {
                min = abs(nums[i]+nums[j]+nums[k]-target);
                sum2 = nums[i]+nums[j]+nums[k];
            }
            if(sum > target)
                k--;
            else if(sum < target)
            {
                j++;
            }
            else
                return target;
        }
        cout << "hah" << endl;
    }
    return sum2;
}

int main()
{
    int a[] = {1,1,1,0};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    int result = threeSumClosest(nums,-100);
    cout << result << endl;
    return 0;
}
