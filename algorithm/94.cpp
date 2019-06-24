#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* CreateTree()
{
    int ch;
    TreeNode *p;
    cin >> ch;
    if(ch == 999)
        p = NULL;
    else
    {
        p = (TreeNode*)malloc(sizeof(TreeNode));
        p->val = ch;
        p->left = CreateTree();
        p->right = CreateTree();
    }
    return p;
}

void Inorder(TreeNode *root,vector<int> &result)
{
    if(!root)
        return;
    if(root->left)
        Inorder(root->left,result);
    result.push_back(root->val);
    if(root->right)
        Inorder(root->right,result);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    Inorder(root,result);
    return result;
}

vector<int> inorderTraversal1(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode *p = root;
    while(p || !s.empty())
    {
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        result.push_back(p->val);
        p = p->right;
    }
    return result;
}

int main()
{
    TreeNode *root = CreateTree();
    vector<int> result = inorderTraversal1(root);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}