#include <bits/stdc++.h>
using namespace std;

// T = O(N) s = O(1)
int characterReplacement(string s, int k)
{
    int ans = 0;
    int l = 0, r = 0, n = s.size();
    int frq = -1, temp = 0;
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[s[r] - 'A']++;
        frq = max(frq, mp[s[r] - 'A']);

        while ((r - l + 1) - frq > k)
        {
            mp[s[l] - 'A']--;
            temp = 0;
            for (auto it : mp)
                temp = max(temp, it.second);
            frq = temp;
            l++;
        }

        ans = max(ans, r - l + 1);
        // cout<<ans<<" "<<frq<<endl;
        r++;
    }
    return ans;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}