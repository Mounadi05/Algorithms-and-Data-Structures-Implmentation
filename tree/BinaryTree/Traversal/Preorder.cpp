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
 
 
// iterative with stack
void  preorderIterative1(TreeNode* root)
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
  // iterative
void  preorderIterative2(TreeNode* root)
{
    std::vector<TreeNode*> right;
    while(root)
    {
        std::cout << " " << root->val ;
        if (root->right != nullptr)
            right.push_back(root->right);
        root = root->left;
        if (!right.empty() && !root)
        {   
            root = right.back();
            right.pop_back();
        }
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

