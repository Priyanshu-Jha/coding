#include <bits/stdc++.h>
using namespace std;
// T = O(K)  s = (1)
int maxScore(vector<int> &cardPoints, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += cardPoints[i];
    int ans = sum;
    int x = k - 1;
    for (int i = cardPoints.size() - 1; i >= cardPoints.size() - k && x >= 0; i--)
    {
        sum += cardPoints[i] - cardPoints[x--];
        ans = max(ans, sum);
    }
    return ans;
}
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}