#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
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

ListNode* rotateRight(ListNode* head, int k)
{
    if (!head) return NULL;
    int len = 0;
    ListNode* p = head;
    while(p->next != NULL)
    {
        len++;
        p = p->next;
    }
    if(k > len)
        k %= len;
    ListNode *front_ = head->next;
    ListNode *last = head->next;
    while(k-1 > 0)
    {
        last = last->next;
        k--;
    }
    while(last->next != NULL)
    {
        front_ = front_->next;
        last = last->next;
    }
    last->next = head->next;
    head->next = front_;
    return head;
}

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    ListNode* head = CreateList(n);
    head = rotateRight(head,k);
    for(int i = 0; i < n; i++)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    return 0;
}


