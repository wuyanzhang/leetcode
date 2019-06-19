#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string s)
{
    if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
        return false;
    int res = atoi(s.c_str());
    return (res >= 0 && res <= 255);
}

void restore(string s,int k,string out,vector<string> &res)
{
    if(k == 0)
    {
        if(s.empty())
            res.push_back(out);
    }
    else
    {
        for(int i = 1; i <= 3; i++)
        {
            if(s.size() >= i && isValid(s.substr(0,i)))
            {
                if(k == 1)
                    restore(s.substr(i),k-1,out+s.substr(0,i),res);
                else
                    restore(s.substr(i),k-1,out+s.substr(0,i)+".",res);
            }
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    restore(s,4,"",res);
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result = restoreIpAddresses(s);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        if(i < result.size()-1)
            cout << ", ";
    }
    return 0;
}