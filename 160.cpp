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

//双指针，提示：两个链表总长度固定，当一个指针移动到尾部，则跳转到另一个链表的头
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != p2)
    {
        p1 == nullptr ? p1 = headB : p1 = p1->next;
        p2 == nullptr ? p2 = headA : p2 = p2->next;
    }
    return p1;
}

void test()
{
}

int main()
{
    test();
    return 0;
}