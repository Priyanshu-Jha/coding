#include <bits/stdc++.h>
using namespace std;

// T = O(N) s = O(K)
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, n = s.size();
    int ans = 0;
    while (j < n)
    {
        if (mp[s[j]] >= 1)
        {
            while (mp[s[j]] >= 1)
            {
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
        }
        else
            mp[s[j]]++;
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}