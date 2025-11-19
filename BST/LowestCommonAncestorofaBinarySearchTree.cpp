#include <bits/stdc++.h>
using namespace std;

// T = O(N), s = O(N)
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
    void solve(TreeNode *root, TreeNode *p, vector<TreeNode *> &arr)
    {
        if (root == NULL)
            return;
        arr.push_back(root);
        if (root == p)
            return;
        if (root->val > p->val)
            solve(root->left, p, arr);
        else
            solve(root->right, p, arr);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // vector<TreeNode*> arr1, arr2;

        // solve(root, p, arr1);
        // solve(root, q, arr2);
        // int i = 0, j = 0;
        // while (i < arr1.size() and j < arr2.size()) {
        //     if (arr1[i] != arr2[j])
        //         break;
        //     i++;
        //     j++;
        // }
        // // cout << arr1[i - 1]->val;
        // return arr1[i - 1];
        if (root == NULL)
            return NULL;
        if (root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}