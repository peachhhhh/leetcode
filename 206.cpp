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

//三指针
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *f = head, *s = head->next, *tmp = head;
    f->next = nullptr;
    while (tmp)
    {
        tmp = s->next;
        s->next = f;
        f = s;
        s = tmp;
    }
    return f;
}

void test()
{
}

int main()
{
    test();
    return 0;
}