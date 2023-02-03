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
void  postorderIterative2(TreeNode* root)
{
    std::stack<TreeNode*> tree;
    TreeNode *prev = nullptr;
    while(root || !tree.empty())
    {
        while(root)
        {                
            tree.push(root);
            root = root->left;
        }
        root = tree.top();
        if (!root->right || root->right == prev)
        {
            std::cout << " " << root->val;
            tree.pop();
            prev = root;
            root = nullptr;
        }
        else
            root = root->right;
    }

}

 //  Recursive 
void postorderRecursive(TreeNode* root) 
{
    if (root == nullptr)
        return ;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    std::cout << " " << root->val;

}
