#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
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

void inorder(TreeNode *root,vector<TreeNode*> &list,vector<int> &vals)
{
    if(!root)
        return;
    inorder(root->left,list,vals);
    list.push_back(root);
    vals.push_back(root->val);
    inorder(root->right,list,vals);
}

void BFS(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if(cur->left != NULL)
            q.push(cur->left);
        if(cur->right != NULL)
            q.push(cur->right);
    }
}

void recoverTree(TreeNode* &root)
{
    vector<TreeNode*> list;
    vector<int> vals;
    inorder(root,list,vals);
    sort(vals.begin(),vals.end());
    for(int i = 0; i < list.size(); i++)
    {
        list[i]->val = vals[i];
    }
}

int main()
{
    TreeNode *root = CreateTree();
    recoverTree(root);
    BFS(root);
    return 0;
}