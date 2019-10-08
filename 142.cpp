#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *l1, *l2;
    l1 = head;
    l2 = head;
    do
    {
        if (l2->next == NULL || l2->next->next == NULL)
        {
            return NULL;
        }
        l1 = l1->next;
        l2 = l2->next->next;
    } while (l1 != l2);
    // ----有环----
    ListNode *l3 = head;
    while (l3 != l2)
    {
        l3 = l3->next;
        l2 = l2->next;
    }
    return l2;
}

void test()
{
}

int main()
{
    test();
    return 0;
}