#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    unordered_map<char, int> mp;
    for (auto it : tasks)
        mp[it]++;

    for (auto it : mp)
    {
        pq.push(it.second);
        cout << it.second << " ";
    }
    int time = 0;
    while (!pq.empty() or !q.empty())
    {
        if (!pq.empty())
        {
            int it = pq.top();
            pq.pop();
            if (it - 1 > 0)
                q.push({it - 1, time + n});
        }

        if (q.size() > 0 and q.front().second == time)
        {
            pq.push(q.front().first);
            q.pop();
        }
        time++;
    }
    return time;
}

// T = O(nlog26) s= (N)