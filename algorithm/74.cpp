#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int m = matrix.size()-1;
    int n = matrix[0].size()-1;
    if(target < matrix[0][0] || target > matrix[m][n])
        return false;
    int left = 0,right = m;
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(target == matrix[mid][0])
            return true;
        else if(target > matrix[mid][0])
            left = mid+1;
        else
            right = mid-1;
    }
    int tmp = right;
    left = 0;
    right = matrix[tmp].size() - 1;
    while (left <= right)
    {
        int mid = (left+right) / 2;
        if (matrix[tmp][mid] == target) return true;
        else if (matrix[tmp][mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool searchMatrix1(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int m = matrix.size()-1;
    int n = matrix[0].size()-1;
    if(target < matrix[0][0] || target > matrix[m][n])
        return false;
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (matrix[mid / n][mid % n] == target) return true;
        else if (matrix[mid / n][mid % n] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int> > matrix = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };
    bool result = searchMatrix1(matrix,11);
    cout << result << endl;
    return 0;
}
