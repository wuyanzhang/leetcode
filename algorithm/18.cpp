#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > a;
    vector<int> array1;
    sort(nums.begin(),nums.end());
    if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2 || nums.size() ==3)
        return a;
    for(int i = 0; i < nums.size()-3; i++)
    {
        while(nums[i+1] == nums[i])
            i++;
        for(int j = i+1; j < nums.size()-2; j++)
        {
            while(nums[j+1] == nums[j])
                j++;
            for(int k = j+1; k < nums.size()-1; k++)
            {
                while(nums[k+1] == nums[k])
                    k++;
                for(int l = k+1; l < nums.size(); l++)
                {
                    while(nums[l+1] == nums[l])
                        l++;
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target)
                    {
                        array1.push_back(nums[i]);
                        array1.push_back(nums[j]);
                        array1.push_back(nums[k]);
                        array1.push_back(nums[l]);
                        a.push_back(array1);
                        array1.clear();
                    }
                    if(l == nums.size()-1)
                        break;
                }
                if(k == nums.size()-2)
                    break;
            }
            if(j == nums.size()-3)
                break;
        }
        if(i == nums.size()-4)
            break;
    }
    return a;
}

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<vector<int> > vec;
    vec = fourSum(nums,target);
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[0].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}









