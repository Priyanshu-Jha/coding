#include <bits/stdc++.h>
using namespace std;
// t  = O(n+m) s = O(1)
string minWindow(string s, string t)
{
    int l = 0, r = 0, ans = 1e9, n = s.size(), m = t.size(), cnt = 0, sindex = -1;
    unordered_map<char, int> mp;

    for (auto it : t)
        mp[it]++;

    while (r < n)
    {
        if (mp[s[r]] > 0)
            cnt++;
        mp[s[r]]--;

        while (cnt == m)
        {
            if (r - l + 1 < ans)
            {
                ans = r - l + 1;
                sindex = l;
            }
            mp[s[l]]++;
            if (mp[s[l]] > 0)
                cnt--;
            l++;
        }
        r++;
    }
    return sindex == -1 ? "" : s.substr(sindex, ans);
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}