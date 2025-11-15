#include <bits/stdc++.h>
using namespace std;

// T = O(n) s = O(k)
int solve(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, ans = 0, n = nums.size();
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            mp[nums[l]]--;

            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }

        ans += (r - l + 1);
        cout << ans << " ";
        r++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int ans = solve(nums, k) - solve(nums, k - 1);

    return ans;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}