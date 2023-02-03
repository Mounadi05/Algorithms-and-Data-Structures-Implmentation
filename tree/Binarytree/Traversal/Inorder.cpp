#include <iostream>
#include <stack>
#include <vector>

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
void   inorderIterative(TreeNode* root)
{
    std::stack<TreeNode*> tree;
    while(root || !tree.empty())
    {
        while(root)
        {
            tree.push(root);
            root = root->left;
        }
        root = tree.top();
        tree.pop();
        std::cout << " " << root->val;
        root = root->right;
    }
}

//  Recursive 
void    inorderRecursive(TreeNode* root) 
{
    if (!root) return ;
    inorderRecursive(root->left);
    std::cout << " " << root->val;
    inorderRecursive(root->right);
}
