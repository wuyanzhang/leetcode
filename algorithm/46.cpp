#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > res;
vector<int> temp;
void Find(vector<int>& nums,vector<int> &label)
{
    if(temp.size() == nums.size())
    {
        res.push_back(temp);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(label[i] == 0)
        {
            label[i] = 1;
            temp.push_back(nums[i]);
            Find(nums,label);
            temp.pop_back();
            label[i] = 0;
        }
    }
}


vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> label(nums.size(),0);
    Find(nums,label);
    return res;
}


int main()
{
    int a[] = {1,2,3};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    vector<vector<int> > result;
    result = permute(nums);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
