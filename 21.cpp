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
    ListNode *head;
    ListNode *temp;
    if (l1 == NULL && l2 == NULL) //若有空链表，直接返回答案
    {
        return NULL;
    }
    else if (l1 == NULL && l2 != NULL)
    {
        return l2;
    }
    else if (l1 != NULL && l2 == NULL)
    {
        return l1;
    }
    else //head用来记录合并后的头，temp用来移动合并链表
    {
        if (l1->val >= l2->val)
        {
            temp = l2;
            l2 = l2->next;
        }
        else
        {
            temp = l1;
            l1 = l1->next;
        }
        head = temp;
        while (l1 != NULL && l2 != NULL)
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
        while (l1 != NULL)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL)
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        return head;
    }
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