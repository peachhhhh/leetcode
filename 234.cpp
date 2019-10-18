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

//快慢双指针 慢指针移动的同时 反转前半部分链表  最后比较原链表后半部分和反转的链表
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
    {
        return true;
    }
    ListNode *fast = head, *slow = head, *newlisthead = nullptr, *tmp;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        tmp = slow->next;
        slow->next = newlisthead;
        newlisthead = slow;
        slow = tmp;
    }
    if (fast)
    {
        slow = slow->next;
    }
    while (slow)
    {
        if (slow->val != newlisthead->val)
        {
            return false;
        }
        newlisthead = newlisthead->next;
        slow = slow->next;
    }
    return true;
}

void test()
{
}

int main()
{
    test();
    return 0;
}