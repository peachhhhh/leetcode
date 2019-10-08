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

//双指针，快慢指针
bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    ListNode *l1, *l2;
    l1 = head;
    l2 = head;
    do
    {
        if (l2->next == NULL || l2->next->next == NULL)
        {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next->next;
    } while (l1 != l2);
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