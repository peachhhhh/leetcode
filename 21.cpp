#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    while (l1 && l2)
    {
        if (l1->val >= l2->val)
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        else
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
    }
    if (l1)
    {
        temp->next = l1;
    }
    else if (l2)
    {
        temp->next = l2;
    }
    return head->next;
}


int main()
{
    ListNode *a = new ListNode(1), *tempa;
    ListNode *b = new ListNode(1), *tempb;
    int al, bl;
    cout << "alength:" << endl;
    cin >> al;
    cout << "blength:" << endl;
    cin >> bl;
    cout << "a:" << endl;
    cin >> a->val;
    tempa = a;

    for (int i = 1; i < al; i++)
    {
        ListNode *buff = new ListNode(1);
        cout << "a:" << endl;
        cin >> buff->val;
        tempa->next = buff;
        tempa = buff;
    }
    cout << "b:" << endl;
    cin >> b->val;
    tempb = b;
    for (int i = 1; i < bl; i++)
    {
        ListNode *buff = new ListNode(1);
        cout << "b:" << endl;
        cin >> buff->val;
        tempb->next = buff;
        tempb = buff;
    }
    cout << "------" << endl;
    ListNode *s = mergeTwoLists(a, b);
    while (s != NULL)
    {
        cout << s->val << " ";
        s = s->next;
    }
    cout << "------" << endl;
    return 0;
}