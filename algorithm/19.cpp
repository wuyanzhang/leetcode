#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* prev = head;
    ListNode* p = head;
    ListNode* q = head;
    bool start = false;
    for(int i = 0; i < n; i++)
    {
        q = q -> next;
    }
    while(q)
    {
        if(start)
            prev = prev -> next;
        p = p -> next;
        start = true;
        q = q -> next;
    }
    if(p == head)
        head = head -> next;
    prev -> next = p -> next;
    //cout << p -> val;
    return head;
}

ListNode* CreateList(ListNode* head,int n)
{
    ListNode* p = head;
    for(int i = 0; i < n; i++)
    {
        ListNode* node = new ListNode;
        cin >> node -> val;
        p -> next = node;
        p = node;
    }
    return head;
}

int main()
{
    int n,m;
    ListNode* head = NULL;
    head = new ListNode;
    cout << "Please enter the length of the list:";
    cin >> n;
    cout << "Please enter the number of m:";
    cin >> m;
    removeNthFromEnd(CreateList(head,n),m);
    while(head -> next)
    {
        cout << head -> next -> val;
        head = head -> next;
    }
    return 0;
}


