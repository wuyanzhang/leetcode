#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int> > cur;
    vector<vector<int> > result = {{}};
    for(int i = 0; i < nums.size(); i++)
    {
        cur = result;
        int size = result.size();
        for(int j = 0; j < size; j++)
        {
            cur[j].push_back(nums[i]);
            int count = 0;
            for(int k = 0; k < size; k++)
            {
                if(cur[j] == result[k])
                    break;
                count++;
            }
            if(count == size)
                result.push_back(cur[j]);
        }
        cur.clear();
    }
    return result;
}

int main()
{
    vector<int> nums = {1,2,2};
    vector<vector<int> > result = subsetsWithDup(nums);
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