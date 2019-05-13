#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

vector<ListNode*>& Createlist(int n)
{
    int len;
    vector<ListNode*> lists;
    for(int i = 0; i < n; i++)
    {
        cout << "Please enter the length:";
        cin >> len;
        ListNode cur_list[len];
        for(int j = 0; j < len;j++)
        {
            cin >> cur_list[j].val;
            if(j+1 < len)
                cur_list[j].next = &cur_list[j+1];
            else
                cur_list[j].next = NULL;
        }
        lists.push_back(cur_list);
        memset(cur_list,0,len*sizeof(ListNode));
    }
    return lists;
}

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
    ListNode* root = new ListNode;
    ListNode* p = root;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1)
        p->next = l1;
    if(l2)
        p->next = l2;
    return root->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if(lists.size() == 0)
        return NULL;
    if(lists.size() == 1)
        return lists[0];
    if(lists.size() == 2)
        return mergeTwoLists(lists[0],lists[1]);
    vector<ListNode*> sub_list1;
    vector<ListNode*> sub_list2;
    int mid = lists.size()/2;
    for(int i = 0; i < mid; i++)
    {
        sub_list1.push_back(lists[i]);
    }
    for(int j = mid; j < lists.size(); j++)
    {
        sub_list2.push_back(lists[j]);
    }
    ListNode* l1 = mergeKLists(sub_list1);
    ListNode* l2 = mergeKLists(sub_list2);
    ListNode* result = mergeTwoLists(l1,l2);
    return result;
}

int main()
{
    int n;
    ListNode* head = new ListNode;
    cout << "Please enter the length of vector:";
    cin >> n;
    head = mergeKLists(Createlist(n));
    /*
    ListNode list1[2];
    list1[0].val = -1;
    list1[0].next = &list1[1];
    list1[1].val = 1;
    list1[1].next = NULL;

    ListNode list2[3];
    list2[0].val = -3;
    list2[0].next = &list2[1];
    list2[1].val = 1;
    list2[1].next = &list2[2];
    list2[2].val = 4;
    list2[2].next = NULL;

    ListNode list3[4];
    list3[0].val = -2;
    list3[0].next = &list3[1];
    list3[1].val = -1;
    list3[1].next = &list3[2];
    list3[2].val = 0;
    list3[2].next = &list3[3];
    list3[3].val = 2;
    list3[3].next = NULL;

    vector<ListNode *> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    head = mergeKLists(lists);
    */
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
