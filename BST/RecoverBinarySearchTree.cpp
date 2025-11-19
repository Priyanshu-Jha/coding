#include <bits/stdc++.h>
using namespace std;
// t = O(N) s  =O(N)
class Solution
{
public:
    TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);
    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        traversal(root->left);
        if (prev->val > root->val)
        {
            if (first == NULL)
            {
                first = prev;
                second = root;
            }
            else
            {
                second = root;
            }
        }
        prev = root;
        traversal(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        traversal(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
// t = O(NlogN) s = O(N)
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
    vector<int> inorder;
    int cnt = 0;
    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
    void convert(TreeNode *root)
    {
        if (root == NULL)
            return;
        convert(root->left);
        if (root->val != inorder[cnt])
            root->val = inorder[cnt];
        cnt++;
        convert(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        traversal(root);
        sort(begin(inorder), end(inorder));
        convert(root);
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}