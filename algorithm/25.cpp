#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* CreateList(int n)
{
    if(n == 0)
        return NULL;
    ListNode* head = new ListNode;
    cin >> head->val;
    ListNode* pre = head;
    for(int i = 0; i < n-1; i++)
    {
        ListNode* p = new ListNode;
        cin >> p->val;
        pre->next = p;
        pre = pre->next;
    }
    pre->next = NULL;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* pre = head;
    ListNode* p = head;
    ListNode* q = head;
    if(head == NULL || k == 1)
        return head;
    for(int i = 0; i < k-1; i++)
    {
        if(q->next == NULL)
            return head;
        q = q->next;
    }
    head = q;
    while(p->next != head)
    {
        q = p->next;
        p->next = q->next;
        q->next = pre;
        pre = q;
    }
    p->next = reverseKGroup(head->next,k);
    head->next = pre;
    return head;
}

int main()
{
    int n,k;
    ListNode* head = new ListNode;
    cout << "Please enter the length of the list,the number of the reverse:";
    cin >> n >> k;
    head = reverseKGroup(CreateList(n),k);
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}




