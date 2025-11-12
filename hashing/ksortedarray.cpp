#include <bits/stdc++.h>
using namespace std;
// first solution T = O(Nlogn), S = O(N)
string isKSortedArray(int arr[], int n, int k)
{
    // code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
        pq.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (abs(mp[pq.top()] - i) > k)
            return "No";
        pq.pop();
    }
    return "Yes";
}