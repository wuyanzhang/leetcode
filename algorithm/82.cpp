#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* CreateList(int n)
{
    ListNode *p,*s;
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next == NULL;
    p = head;
    for(int i = 0; i < n; i++)
    {
        s = (ListNode*)malloc(sizeof(ListNode));
        cin >> s->val;
        s->next = NULL;
        p->next = s;
        p = p->next;
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head)
{
    if(head->next == NULL)
        return NULL;
    ListNode *p = head;
    ListNode *left,*right;
    while(p->next)
    {
        left = p->next;
        right = left;
        while(right->next && right->next->val == left->val)
            right = right->next;
        if(left == right)
            p = p->next;
        else
            p->next = right->next;
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = deleteDuplicates(CreateList(n));
    while(head->next != NULL)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    return 0;
}
