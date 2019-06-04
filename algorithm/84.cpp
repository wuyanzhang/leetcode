#include <iostream>
#include<vector>
#include<stack>
using namespace std;
//https://blog.csdn.net/Zolewit/article/details/88863970

int largestRectangleArea(vector<int>& heights)
{
    heights.push_back(0);
    stack<int> stk;
    int maxArea = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        while(!stk.empty() && heights[i]<heights[stk.top()])
        {
            int top= stk.top();
            stk.pop();
            maxArea = max(maxArea,heights[top]*(stk.empty()? i:(i - stk.top() -1)));
        }
        stk.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int max_area = largestRectangleArea(heights);
    cout << max_area << endl;
    return 0;
}