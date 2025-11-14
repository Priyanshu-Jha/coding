#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N)
{
    vector<int> ans(N);
    unordered_map<int, int> mp, prev;
    for (int i = N - 1; i >= 0; i--)
    {
        mp[arr[i]] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int rank = 0;
    for (auto it : arr)
        pq.push({it, rank++});
    rank = 1;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (prev[it.first] != 0)
            ans[it.second] = prev[it.first];
        else
        {
            prev[it.first] = rank;
            ans[mp[it.first]] = rank++;
        }
    }
    return ans;
}

// T = O(Nlogn)  s = O(N)