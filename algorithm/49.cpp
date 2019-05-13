#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string,vector<string>> result;
    vector<vector<string> > res;
    for(int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(),s.end());
        result[s].push_back(strs[i]);
    }
    for(auto iter = result.begin(); iter != result.end(); iter++)
    {
        res.push_back(iter->second);
    }
    return res;
}

int main()
{
    string str[]={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strArray(str,str+6);
    vector<vector<string> > output;
    output = groupAnagrams(strArray);
    for(int i = 0; i < output.size(); i++)
    {
        for(int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
