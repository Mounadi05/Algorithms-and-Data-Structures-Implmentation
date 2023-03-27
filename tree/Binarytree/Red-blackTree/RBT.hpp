#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
template <class k, class v>
class rbt {

    private :
       struct Node
       {
            Node *parent, *left, *right;
            bool isBlack;
            bool isLeftChild;
            k _key;
            v _value;
            Node(k key, v value):parent(NULL),left(NULL),right(NULL),
            isBlack(false),isLeftChild(false),_key(key),_value(value){}
       };
        Node *_root;
        size_t _size;
    public :
        explicit rbt():_root(NULL),_size(0){}
        void insert(k key,v value)
        {
            if (_root == NULL) {
                _root = new Node(key,value);
                _root->isBlack = true;
                _size++;
            }
        }
        k key(){return _root->_key;}
        v value(){return _root->_value;}
        size_t size() {return _size;}
};

#endif