#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generate_string(vector<string> &res,string s,int count1,int count2,int n)
{
    if(count1 > n || count2 > n)
        return;
    if(count1 == n && count2 == n)
    {
        res.push_back(s);
        return;
    }
    if(count1 >= count2)
    {
       string ss = s;
       generate_string(res,s+'(',count1+1,count2,n);
       generate_string(res,ss+')',count1,count2+1,n);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    generate_string(res,"",0,0,n);
    return res;
}

int main()
{
    int n;
    vector<string> result;
    cout << "Please enter the value of n:";
    cin >> n;
    result = generateParenthesis(n);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
