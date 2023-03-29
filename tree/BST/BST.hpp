#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <exception>

template <class k, class v>
class bst
{
    private:
        struct Node
        {
            Node *left, *right;
            k _key;
            v _val;
            Node(){}
            Node(k key, v val) : _key(key),_val(val), left(NULL), right(NULL) {}
        };
    Node *_root;
    size_t _size;
    void insertIntoBST(k key, v val) 
    {
        Node *tmp = _root;
        if (tmp == NULL)
        {
            _root = new Node(key,val);
            _size++;
        }   
        else
        {
            while(tmp)
            {
                if (tmp->_val > val)
                {    
                    if (tmp->left != NULL)
                        tmp = tmp->left;
                    else
                    {
                        tmp->left = new Node(key,val);
                        _size++;
                        break ;
                    }
                        
                }
                else
                {                    
                    if (tmp->right != NULL)
                        tmp = tmp->right;
                    else
                    {
                        tmp->right = new Node(key,val);
                        _size++;
                        break;
                    }
                }
            }
        }
    }
    Node * FindMin(Node *root)
    {
         while(root->left)
            root = root->left;
        return root;
    }
    
    Node* deleteNode(Node* root, k key) 
    {
        if(!root) return root;
        else if (key < root->_key) root->left = deleteNode(root->left, key);
        else if (key > root->_key) root->right = deleteNode(root->right, key);
        else
        {
            // case : no child
            if (!root->right && !root->left)
            {
                delete root;
                root = nullptr;
                _size--;
                return root;
            }
            // case : one child in left 
            else if (!root->right)
            {
                Node *tmp = root;
                root = tmp->left;
                delete tmp;
                _size--;
                return root;
            }
            // case : one child in right
            else if (!root->left)
            {
                Node *tmp = root;
                root = tmp->right;
                delete tmp;
                _size--;
                return root;
            }
            // case : two child
            else
            {
                Node *tmp = FindMin(root->right);
                root->_val = tmp->_val;
                root->_key = tmp->_key;
                root->right =  deleteNode(root->right, tmp->_key);
              }
        }
        return root;
    }
    void copyNode(Node *root) 
    {
            if (root == NULL)
                return ;
            copyNode(root->left);
            insert(root->_key,root->_val);
            copyNode(root->right);
    }
    void    inorder(Node* root) 
    {
        if (root == NULL) 
            return ;
        inorder(root->left);
        std::cout << " key : " << root->_key << 
        "      <<<<>>>>  val : " << root->_val << std::endl;
        inorder(root->right);
    }
    void    postorder(Node* root) 
    {
        if (root == NULL)
            return ;
        postorder(root->left);
        postorder(root->right);
        std::cout << " key : " << root->_key << 
        "      <<<<>>>>  val : " << root->_val << std::endl;
    }
    void preorder(Node * root) 
    {
        if (root == NULL)
            return ;
        std::cout << " key : " << root->_key << 
        "      <<<<>>>>  val : " << root->_val << std::endl;
        preorder(root->left);
        preorder(root->right);
    }
    void deleteTree(Node* node) 
    {
        if (node == nullptr)
            return;
        
        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
        node = NULL;
    }
    public :
        bst() : _root(NULL), _size(0) {}
        bst(const bst & other):_root(NULL),_size(0)
        {
            this->_size = other._size;
            if (other._root != NULL) copyNode(other._root);
        }
        bst & operator=(const bst & other)
        {
            this->~bst();
            new(this)bst(other);
            return *this;
        }
        ~bst()
        {
            if (_root != NULL) {
                deleteTree(_root);
            _root = NULL;
            }
        }
        void    inorder() 
        {
           inorder(_root);
        }
        void    postorder() 
        {
            postorder(_root);
        }
        void preorder() 
        {
            preorder(_root);
        }
        void insert(k key, v val)
        {
             Node *tmp = _root;
            if (tmp == NULL)
            {
                _root = new Node(key,val);
                _size++;
            }   
            else
            {
                while(tmp)
                {
                    if (tmp->_val > val)
                    {    
                        if (tmp->left != NULL)
                            tmp = tmp->left;
                        else
                        {
                            tmp->left = new Node(key,val);
                            _size++;
                            break ;
                        }
                            
                    }
                    else
                    {                    
                        if (tmp->right != NULL)
                            tmp = tmp->right;
                        else
                        {
                            tmp->right = new Node(key,val);
                            _size++;
                            break;
                        }
                    }
                }
            }

        }
        void remove(k key)
        {
            _root = deleteNode(_root, key);
        }
        bool replace(const k& key, v value)
        {
            Node *root = _root; 
            while(root)
            {
                if (root->_key== key)
                {
                    root->_val = value;
                    return true;
                }
                 {
                    if (key < root->_key)
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            return false;
        }
        bool empty()
        {
            return (_root == NULL);
        }
        v search (const k& key)
        {
            Node *root = _root; 
            while(root)
            {
                if (root->_key== key)
                    return root->_val;              
                {
                    if (key < root->_key)
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            throw std::runtime_error("error : not found");
            return root->_val;
        }
        size_t size()
        {
            return _size;
        }
        void clear()
        {
              if (_root != NULL) 
                deleteTree(_root);
            _root = NULL;
        }
};

#endif
