#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : nums)
    {
        pq.push(it);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

// t(n) = O(nlogk) S(n) = O(k)

// Optimize  Hoare's Selection Algorithm