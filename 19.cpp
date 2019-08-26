#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//双指针，间隔n，一起从左往右移动
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *head1, *head2, *temp;
    head1 = head;
    head2 = head;
    if (head->next == NULL)
    {
        return {};
    }
    for (int i = 0; i < n; i++) //先移动head2，使其与head1间隔n
    {
        head2 = head2->next;
    }
    if (head2 == NULL) //head1还未移动，head2已到末尾，直接从head的后一项return
    {
        return head->next;
    }
    while (head2->next != NULL) //head1和head2一起右移
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    head1->next = head1->next->next; //删去节点
    return head;
}

int main()
{
    // ListNode *h2;
    // ListNode *h;
    // h->next = h2;
    // removeNthFromEnd(&h2, 2);
    return 0;
}