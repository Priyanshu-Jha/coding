#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        priority_queue<pair<int, pair<int, int>>> pq;

        sort(begin(a), end(a), [](int x, int y)
             { return x > y; });
        sort(begin(b), end(b), [](int x, int y)
             { return x > y; });
        int n = a.size();
        vector<int> ans;

        set<pair<int, int>> st;
        pq.push({a[0] + b[0], {0, 0}});
        st.insert({0, 0});
        while (k != 0 and !pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int i = it.second.first, j = it.second.second;
            // cout<<i<<" "<<j<<endl;
            ans.push_back(it.first);
            if (i + 1 < n and st.find({i + 1, j}) == st.end())
            {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            if (j + 1 < n and st.find({i, j + 1}) == st.end())
            {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
            k--;
        }
        return ans;
    }
};

// T = O(nlogn) S = O(n)