#include <iostream>
  
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
    // iterative
TreeNode* searchBST(TreeNode* root, int val) 
{
    while(root)
    {
        if (root->val == val)
            return root;
        {
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
    }
    return nullptr;
}

    //  Recursive 
TreeNode* searchBST(TreeNode* root, int val) 
{
    if (!root || root->val == val)
        return root;
    if (val < root->val)
        root =  searchBST(root->left,val);
    else
        root = searchBST(root->right,val);
    return root;
}