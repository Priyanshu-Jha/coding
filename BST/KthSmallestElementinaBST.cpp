#include <bits/stdc++.h>
using namespace std;

// T = O(N) S  = O(N)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int ans = -1, cnt = 0;
    void solve(TreeNode *root, int key)
    {
        if (!root)
            return;
        solve(root->left, key);
        cnt++;
        if (key == cnt)
        {
            ans = root->val;
            return;
        }
        solve(root->right, key);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        solve(root, k);
        return ans;
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
