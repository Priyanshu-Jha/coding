#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
// T = O(N) s = O(n)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        TreeNode *temp = root->left;
        while (temp->right != NULL)
            temp = temp->right;
        root->val = temp->val;
        root->left = deleteNode(root->left, root->val);
    }
    return root;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}