#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#include <exception>

template <class k, class v>
class BST
{
    private:
        struct Node
        {
            Node *left, *right;
            k _key;
            v _value;
            Node() : val(0), left(nullptr), right(nullptr) {}
            Node(k key, v value) : _key(key),_value(value), left(nullptr), right(nullptr) {}
        };
    Node* insertIntoBST(Node* root, int val) 
    {
        Node *tmp = root;
        if (!root)
            return new Node(val);
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
                        tmp->left = new Node(val);;
                        return root;
                    }
                }
                else
                {                    
                    if (tmp->right)
                        tmp = tmp->right;
                    else
                    {
                        tmp->right = new Node(val);
                        return root;
                    }
                }
            }
        }
        return tmp;
    }

};
#endif
