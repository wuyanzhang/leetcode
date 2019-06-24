#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<TreeNode*> divide(int start,int end)
{
    vector<TreeNode*> result;
    if(start > end)
    {
        result.push_back(NULL);
    }
    for(int i = start; i <= end; i++)
    {
        auto left = divide(start,i-1);
        auto right = divide(i+1,end);
        for(auto a : left)
        {
            for(auto b : right)
            {
                TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
                node->val = i;
                node->left = a;
                node->right = b;
                result.push_back(node);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n)
{
    if(n == 0)
        return {};
    vector<TreeNode*> res = divide(1,n);
    return res;
}

void Inorder(TreeNode *root,vector<int> &result)
{
    if(!root)
        return;
    result.push_back(root->val);
    if(root->left)
        Inorder(root->left,result);
    if(root->right)
        Inorder(root->right,result);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    Inorder(root,result);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<TreeNode*> res = generateTrees(n);
    for(int i = 0; i < res.size(); i++)
    {
        vector<int> result = inorderTraversal(res[i]);
        for(int j = 0; j < result.size(); j++)
        {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}