#include <bits/stdc++.h>
using namespace std;

// T = O(n), s = O(1)
int totalFruit(vector<int> &fruits)
{
    int ans = 0;
    int l = 0, r = 0, first = -1, second = -1, firstfeq = 0, secondfeq = 0;
    int n = fruits.size();
    while (r < n)
    {
        if (first == -1)
        {
            first = fruits[r];
            firstfeq++;
        }
        else if (fruits[r] == first)
        {
            firstfeq++;
        }
        else if (second == -1)
        {
            second = fruits[r];
            secondfeq++;
        }
        else if (second == fruits[r])
            secondfeq++;
        else
        {
            if (fruits[r - 1] == first)
            {
                swap(second, first);
                swap(secondfeq, firstfeq);
            }
            while (firstfeq != 0)
            {
                if (fruits[l] == first)
                    firstfeq--;
                else
                    secondfeq--;
                l++;
            }
            first = second;
            firstfeq = secondfeq;
            second = fruits[r];
            secondfeq = 1;
        }
        // cout << first << " " << firstfeq << " " << second << " "
        //      << secondfeq << endl;
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