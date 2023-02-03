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
TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    TreeNode *tmp = root;
    if (!root)
        return new TreeNode(val);
    else
    {
        while(tmp)
        {
            if (tmp->val > val)
            {    
                if (tmp->left)
                    tmp = tmp->left;
                else
                {
                    tmp->left = new TreeNode(val);;
                    return root;
                }
            }
            else
            {                    
                if (tmp->right)
                    tmp = tmp->right;
                else
                {
                    tmp->right = new TreeNode(val);
                    return root;
                }
            }
        }
    }
    return tmp;
}

    // Recursive
TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(!root)
        return new TreeNode(val);
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else 
        root->right = insertIntoBST(root->right, val);
    return root;
}