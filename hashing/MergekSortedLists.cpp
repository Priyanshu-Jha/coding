#include <bits/stdc++.h>
using namespace std;

// t = O(Nlogk) s = O(K)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
    int k = lists.size();
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != NULL)
        {
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        temp->next = it.second;
        temp = temp->next;
        if (it.second->next != NULL)
        {
            pq.push({it.second->next->val, it.second->next});
        }
    }
    return ans->next;
}