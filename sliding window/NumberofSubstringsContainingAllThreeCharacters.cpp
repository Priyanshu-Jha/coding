#include <bits/stdc++.h>
using namespace std;
// T = O(n) s = O(1)
int numberOfSubstrings(string s)
{
    int l = 0, r = 0, n = s.size(), ans = 0;
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[s[r] - 'a']++;
        while (mp[0] > 0 and mp[1] > 0 and mp[2] > 0)
        {
            ans += n - r;
            mp[s[l] - 'a']--;
            l++;
        }
        r++;
    }
    return ans;
}
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}