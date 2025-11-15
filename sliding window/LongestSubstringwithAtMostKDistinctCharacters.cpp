#include <bits/stdc++.h>
using namespace std;

// T = (n) S = O(k)
int lengthOfLongestSubstringKDistinct(string s, int k)
{
    int l = 0, r = 0, ans = 0, n = s.size();
    unordered_map<char, int> mp;
    while (r < n)
    {
        mp[s[r]]++;
        while (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}