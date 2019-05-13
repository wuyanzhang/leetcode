#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int> > res;
    int cur = 0;
    while(cur < intervals.size() && intervals[cur][1] < newInterval[0])
    {
        res.push_back(intervals[cur]);
        cur++;
    }
    while(cur < intervals.size() && intervals[cur][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0],intervals[cur][0]);
        newInterval[1] = max(newInterval[1],intervals[cur][1]);
        ++cur;
    }
    res.push_back(newInterval);
    while(cur < intervals.size())
    {
        res.push_back(intervals[cur]);
        cur++;
    }
    return res;
}

int main()
{
    vector<vector<int> > intervals = {
        {1,3},{6,9}
    };
    vector<int> newInterval = {2,5};
    vector<vector<int> > result = insert(intervals,newInterval);
    for(int i = 0; i < intervals.size(); i++)
    {
        for(int j = 0; j < intervals[i].size(); j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}





