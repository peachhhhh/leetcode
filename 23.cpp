#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//优先队列priority_queue
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if(lists.empty()){
        return NULL;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    vector<ListNode *>::iterator it = lists.begin();
    while (it != lists.end())
    {
        while ((*it) != NULL)
        {
            q.push((*it)->val);
            (*it) = (*it)->next;
        }
        it++;
    }
    if(q.empty()){
        return NULL;
    }
    ListNode *l, *head = new ListNode(q.top());
    q.pop();
    l = head;
    while (!q.empty())
    {
        ListNode *buff = new ListNode(1);
        buff->val = q.top();
        q.pop();
        l->next = buff;
        l = l->next;
    }
    return head;
}

int main()
{
    return 0;
}