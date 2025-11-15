#include <bits/stdc++.h>
using namespace std;
// T = O(N) s = O(1)
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        while (r < n)
        {
            if (nums[r] == 0)
            {
                k--;
                while (k < 0)
                {
                    if (nums[l] == 0)
                        k++;
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}