#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > a;
    vector<int> array1;
    if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
        return a;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size()-2; i++)
    {
        int j = i+1;
        int k = nums.size()-1;
        while(j < k)
        {
            if(nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else if(nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else
            {
                array1.push_back(nums[i]);
                array1.push_back(nums[j]);
                array1.push_back(nums[k]);
                a.push_back(array1);
                array1.clear();
                while(nums[j+1] == nums[j] && j < nums.size()-2)
                    j++;
                j++;
                while(nums[k] == nums[k-1] && k > 2)
                    k--;
                k--;
            }
            while(nums[i+1] == nums[i])
            {
                i++;
                if(i > nums.size()-2)
                    break;
            }
            //cout << i << " " << j << " " << k << " " << endl;
        }
    }
    return a;
}
int main()
{
    int a[] = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<vector<int> > vec;
    vec = threeSum(nums);
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[0].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}
