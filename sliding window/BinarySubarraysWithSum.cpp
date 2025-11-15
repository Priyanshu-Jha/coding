#include <bits/stdc++.h>
using namespace std;
// .. T = O(N) s = O(1)
int solve(vector<int> &arr, int n)
{
    if (n < 0)
        return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < arr.size())
    {
        sum += arr[r];

        while (sum > n)
        {
            sum -= arr[l];
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return abs(solve(nums, goal) - solve(nums, goal - 1));
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}