#include<iostream>
#include<vector>
#include<string>
using namespace std;

int factorial(int n)
{
    int res = 1;
    while(n > 0)
    {
        res *= n;
        n--;
    }
    return res;
}

string getPermutation(int n, int k)
{
    k -= 1;
    int index;
    int count = 0;
    string result = "";
    string origin;
    for(int i = 0; i < n; i++)
    {
        origin.push_back('1' + i);
    }
    int i = 1;
    while(count < n)
    {
        index = k / factorial(n-i);
        k = k - index * factorial(n-i);
        result += origin[index];
        origin.erase(origin.begin()+index);
        count++;
        i++;
    }
    return result;
}

int main()
{
    int n,k;
    cin >> n >> k;
    string result = getPermutation(n,k);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}
