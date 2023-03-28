#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#include <exception>

template <class k, class v>
class rbt
{
    private:
        struct Node
        {
            Node *parent, *left, *right;
            bool isBlack;
            bool isLeftChild;
            k _key;
            v _value;
            Node(k key, v value) : parent(NULL), left(NULL), right(NULL),
            isBlack(false), isLeftChild(false), _key(key), _value(value) {}
        };
        Node *_root;
        size_t _size;
        Node * findMin(Node *root)
        {
            while(root && root->left)
                root = root->left;
            return root;
        }
        Node * deleteNode(Node *root, const k &key)
        {
            if(root == NULL) return root;
            else if (root->_key > key) root->left = deleteNode(root->left,key);
            else if (root->_key < key) root->right=  deleteNode(root->right,key);            
            else
            {
                // One child
                if (!root->right && !root->left)
                {    
                    delete root;
                    root = NULL;
                    return root;
                }
                else if(!root->left) // One child in right
                {
                    Node *tmp = root;
                    root = root->right;
                    delete tmp;
                    return root;
                }
                else if (!root->right) // One child in left
                {
                    Node *tmp = root;
                    root = root->left;
                    delete tmp;
                    return root;
                }
                else
                {
                    Node *tmp = findMin(root->right);
                    root->_value = tmp->_value;
                    root->_key = tmp->_key;
                    deleteNode(root->right,tmp->_key);
                }
            }
            return root;
        }
        void copyNode(Node *root) 
        {
            if (root == NULL)
                return ;
            copyNode(root->left);
            insert(root->_key,root->_value);
            copyNode(root->right);
        }
    public:
        rbt() : _root(NULL), _size(0) {}
        explicit rbt(const rbt & other):_root(NULL),_size(0)
        {
            this->_size = other._size;
            if (other._root != NULL) copyNode(other._root);
        }
        rbt & operator=(const rbt & other)
        {
            this->~rbt();
            new(this)rbt(other);
            return *this;
        }
        ~rbt()
        {
            if (_root != NULL) {
                deleteTree(_root);
                _root = NULL;
            }
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
        void insert(k key, v value)
        {
            Node *newNode = new Node(key, value);
            newNode->isBlack = false; // New node is always colored red

            Node *parent = NULL;
            Node *current = _root;
            while (current != nullptr)
            {
                parent = current;
                if (key < current->_key)
                {
                    current = current->left;
                    newNode->isLeftChild = true;
                }
                else
                {
                    current = current->right;
                    newNode->isLeftChild = false;
                }
            }
            newNode->parent = parent;
            if (parent == NULL) // Tree was empty, new node becomes root
            {
                _root = newNode;       
                _root->isBlack = true; // Root node must be colored black
            }
            else if (key < parent->_key) 
                parent->left = newNode;
            else 
                parent->right = newNode;
            _size++;
        }
        void erase(const k& key){_root = deleteNode(_root,key);}
        v & operator[] (const k& key)
        {
            Node *root = _root; 
            while(root)
            {
                if (root->_key== key)
                    return root->_value ;              
                {
                    if (key < root->_key)
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            throw std::runtime_error("error : not found");
            return root->_value;
        }
        void traversal(){traversal(_root);}
        void traversal(Node *root) 
        {
            if (root == NULL)
                return ;
            traversal(root->left);
            std::cout << " " << root->_value << std::endl;;
            traversal(root->right);
        }
        k &key() { return _root->_key; }
        v &value() { return _root->_value; }
        size_t size() { return _size; }
        bool empty(){ return _root == NULL; }
};
#endif
