#include <bits/stdc++.h>
using namespace std;
// t = O(logn) s = O(1)
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
    // TreeNode* result = NULL;
    // int val = INT_MAX;

    // void inorder(TreeNode* root,int key){
    //     if(root == NULL)
    //         return;
    //     inorder(root->left,key);
    //     if(root->val>key and root->val<val){
    //         result = root;
    //         val = root->val;
    //     }
    //     inorder(root->right,key);
    // }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        // inorder(root,p->val);
        // return result;
        TreeNode *ans = NULL, *temp = root;
        while (temp != NULL)
        {
            if (temp->val == p->val)
            {
                temp = temp->right;
            }
            else if (temp->val > p->val)
            {
                ans = temp;
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return ans;
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}