#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

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

ListNode* swapPairs(ListNode* head)
{
    ListNode* prev = head;
    ListNode* p;
    ListNode* q;
    while(prev->next && prev->next->next)
    {
        p = prev -> next;
        q = prev -> next -> next;
        p -> next = q -> next;
        q -> next = p;
        prev -> next = q;
        prev = prev -> next -> next;
    }
    return head;
}

int main()
{
    int n;
    ListNode* head = NULL;
    head = new ListNode;
    cout << "Please enter the length of the list:";
    cin >> n;
    head = swapPairs(CreateList(head,n));
    while(head -> next)
    {
        cout << head -> next -> val << " ";
        head = head -> next;
    }
    return 0;
}
