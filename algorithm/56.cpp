#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool lessmark(vector<int> &a,vector<int> &b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(),intervals.end(),lessmark);
    for(int i = 0; i < intervals.size(); i++)
    {
        while(i+1 < intervals.size() && intervals[i][1] >= intervals[i+1][0])
        {
            if(intervals[i][0] < intervals[i+1][0] && intervals[i][1] > intervals[i+1][1])
                intervals.erase(intervals.begin()+i+1);
            else
            {
                intervals[i][1] = intervals[i+1][1];
                intervals.erase(intervals.begin()+i+1);
            }
        }

    }
    return intervals;
}


int main()
{
    vector<vector<int> > intervals = {
        {1,4},{2,3}
    };
    vector<vector<int> > result = merge(intervals);
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


