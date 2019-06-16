#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

ListNode* CreateList(int n)
{
    ListNode *p,*s;
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
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

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(head == NULL || head->next == NULL)
        return NULL;
    ListNode *pre = head;
    for(int i = 0; i < m-1; i++)
    {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    for(int i = m; i < n; i++)
    {
        ListNode *t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
    }
    return head;
}

int main()
{
    int len,m,n;
    cin >> len >> m >> n;
    ListNode *head = reverseBetween(CreateList(len),m,n);
    while(head->next)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    return 0;
}