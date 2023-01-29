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
void  preorderIterative(TreeNode* root)
{
    std::stack<TreeNode*> tmp;
    if (!root) return ;
    tmp.push(root);
     while(!tmp.empty())
    {
        root = tmp.top();
        tmp.pop();
        std::cout << " " << root->val ;
        if(root->right) tmp.push(root->right);
        if(root->left) tmp.push(root->left);
    }
 }

//  Recursive 
void preorderRecursive(TreeNode* root) 
{
    if (root == nullptr)
        return ;
    std::cout << " " << root->val;
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

