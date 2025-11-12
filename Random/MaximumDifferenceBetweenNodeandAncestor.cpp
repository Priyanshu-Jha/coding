#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void solve(TreeNode *root, int low, int high, int &ans)
{
    if (root == NULL)
        return;

    ans = max({ans, abs(root->val - low), abs(root->val - high)});
    low = min(low, root->val);
    high = max(high, root->val);
    solve(root->left, low, high, ans);
    solve(root->right, low, high, ans);
}
int maxAncestorDiff(TreeNode *root)
{
    int ans = 0;
    solve(root, root->val, root->val, ans);
    return ans;
}
