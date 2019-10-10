#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//合并两个有序链表，来自21题
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

//裁剪链表，返回第二段链表的头指针
ListNode *cut(ListNode *head, int step)
{
    ListNode *temp = head;
    while (step > 1 && temp)
    {
        temp = temp->next;
        step--;
    }
    if (!temp)
    {
        return nullptr;
    }
    ListNode *secondlist = temp->next;
    temp->next = nullptr;
    return secondlist;
}

//归并排序，自底向上，非递归
ListNode *sortList(ListNode *head)
{
    ListNode *temp = head;
    int size = 0;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    ListNode *dummyhead = new ListNode(0); //虚拟头结点，用于连接头结点head
    dummyhead->next = head;
    for (int i = 1; i <= size; i = i * 2)
    {
        ListNode *record = dummyhead; //每一次新的步长的归并的开始
        ListNode *curhead = dummyhead->next;
        while (curhead) //当前头指针用于标记将要进行下一次归并的头指针的位置
        {
            ListNode *first = curhead;
            ListNode *second = cut(first, i);
            curhead = cut(second, i);
            record->next = mergeTwoLists(first, second); //在一次归并中，裁剪前两个步长为i的有序链表，归并在记录点后
            while (record->next)
            {
                record = record->next; //将记录点移动到已归并好的链表的尾部
            }
        }
    }
    return dummyhead->next;
}

void test()
{
}

int main()
{
    test();
    return 0;
}