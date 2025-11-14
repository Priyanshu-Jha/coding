#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : arr)
        pq.push(it);

    int ans = 0;
    if (arr.size() == 1)
        return 0;
    int val1, val2;
    while (pq.size() > 1)
    {

        val1 = pq.top();
        pq.pop();
        val2 = pq.top();
        pq.pop();
        ans += val1 + val2;
        pq.push(val1 + val2);
    }
    return ans;
}

// t = O(nlogn) s = O(n)