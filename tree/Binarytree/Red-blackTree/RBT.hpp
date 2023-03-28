#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
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
    public:
        explicit rbt() : _root(NULL), _size(0) {}
        ~rbt()
        {
            if (_root != nullptr) {
                deleteTree(_root);
                _root = nullptr;
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
            newNode->isBlack = false;

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
            if (parent == nullptr)
            {
                _root = newNode;       
                _root->isBlack = true; 
            }
            else if (key < parent->_key) 
                parent->left = newNode;
            else 
                parent->right = newNode;
            _size++;
        }
        v & operator[] (const k& key)
        {
            Node *root = _root; 
            while(root)
            {
                if (root->_key== key)
                    break;
                {
                    if (key < root->_key)
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            return root->_value;
        }
        k key() { return _root->_key; }
        v value() { return _root->_value; }
        size_t size() { return _size; }
};

#endif