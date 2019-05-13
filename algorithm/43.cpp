#include<iostream>
#include<string>
#include<vector>
using namespace std;

string multiply_(string num1, string num2)
{
    string result_ = "";
    string result = "";
    int num_1 = 0;
    int num_2 = 0;
    int index = 1;
    for(int i = num1.size()-1; i >= 0; i--)
    {
        num_1 += (num1[i]-'0')*index;
        index *= 10;
    }
    index = 1;
    for(int i = num2.size()-1; i >= 0; i--)
    {
        num_2 += (num2[i]-'0')*index;
        index *= 10;
    }
    int ans = num_1*num_2;
    while(ans > 0)
    {
        result_ += ans%10 + '0';
        ans /= 10;
    }
    for(int i = result_.size()-1; i >= 0; i--)
    {
        result += result_[i];
    }
    return result;
}

string multiply(string num1, string num2)
{
    int n = num1.size()+num2.size();
    int value[n] = {0};
    string result = "";
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            value[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
        }
    }
    int carry = 0;
    for(int i = n-1; i >= 0; i--)
    {
        value[i] += carry;
        carry = value[i]/10;
        value[i] %= 10;
    }
    int beginIndex = 0;
    while (beginIndex < n && value[beginIndex] == 0)
    {
        beginIndex++;
    }
    for(int i = beginIndex; i < n; i++)
    {
        result += value[i]+'0';
    }
    return result;
}


int main()
{
    string num1 = "123";
    string num2 = "456";
    cout << multiply_(num1,num2) << endl;
    cout << multiply(num1,num2) << endl;
    return 0;
}




















