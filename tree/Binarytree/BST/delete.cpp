struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * FindMin(TreeNode *node)
{
    TreeNode *root = node;
    while(root->left)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(!root) return root;
    else if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else
    {
        // case : no child
        if (!root->right && !root->left)
        {
            delete root;
            root = nullptr;
            return root;
        }
        // case : one child in left 
        else if (!root->right)
        {
            TreeNode *tmp = root;
            root = tmp->left;
            delete tmp;
            return root;
        }
         // case : one child in right
        else if (!root->left)
        {
            TreeNode *tmp = root;
            root = tmp->right;
            delete tmp;
            return root;
        }
        // case : two child
        else
        {
            TreeNode *tmp = FindMin(root->right);
            root->val = tmp->val;
            root->right =  deleteNode(root->right, tmp->val);
        }
    }
    return root;
}