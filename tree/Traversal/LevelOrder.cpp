#include <iostream>
#include <queue>
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
void levelOrder(TreeNode* root) 
{
    std::queue<TreeNode*> tree;
    if(root) tree.push(root);
    int levels = 0;
    while(!tree.empty())
    {
        levels = tree.size();
        for(int i = 0; i < levels;i++)
        {
            TreeNode* current = tree.front();
            tree.pop();
            std::cout << current->val << " ";
            if(current->left) tree.push(current->left);
            if(current->right) tree.push(current->right);
        }
        std::cout << std::endl;      
    }
}