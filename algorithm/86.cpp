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


ListNode* partition(ListNode* head, int x)
{
    ListNode *p = head->next;
    ListNode *head_low = new ListNode();
    ListNode *p1 = head_low;
    ListNode *head_high = new ListNode();
    ListNode *p2 = head_high;
    while(p != NULL)
    {
        if(p->val < x)
        {
            p1->next = p;
            p1 = p1->next;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p1->next = head_high->next;
    p2->next = NULL;
    return head_low;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = partition(CreateList(n),3);
    while(head->next != NULL)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    return 0;
}