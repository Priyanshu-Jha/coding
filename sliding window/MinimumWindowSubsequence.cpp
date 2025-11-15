#include <bits/stdc++.h>
using namespace std;

// T = o(nm) S = o(1)
string minWindow(string s1, string s2)
{
    int i = 0, j = 0, k = 0;
    string ans;
    int res = 1e9;
    while (j < s1.size() and k < s2.size())
    {
        if (s1[j] == s2[k])
            k++;

        if (k == s2.size())
        {
            i = j;
            k = s2.size() - 1;
            while (i >= 0 and k >= 0)
            {
                if (s1[i] == s2[k])
                    k--;
                i--;
            }
            i++;
            if (res > j - i + 1)
            {
                res = j - i + 1;
                ans = s1.substr(i, j - i + 1);
            }
            k = 0;
            j = i + 1;
        }
        j++;
    }
    return ans;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}