#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    // code here
    nth_element(begin(arr), begin(arr) + k - 1, end(arr));
    return arr[k - 1];
}
// nth_element()       Finds k-th smallest element    O(n) avg  faster then priority_queue