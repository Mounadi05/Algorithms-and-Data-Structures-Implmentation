#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
template <typename T>
class stack
{
    private : 
        class Node 
        {
            public :
                T data;
                Node *next;
                Node(const T & data):data(data),next(nullptr){}
                Node(const T & data, Node *next):data(data),next(next){}
        };
        Node * _tail;
        Node * _S;
        size_t _size;  
    public :
        stack():_tail(nullptr),_S(nullptr),_size(0){}
        stack(const stack & s)
        {
            this->_size = s._size;
            Node *tmp = s._S;
            while(tmp)
            {
                _S = new Node(tmp->data);
                Node *cur = _S;
                tmp = tmp->next;
                while(tmp)
                {
                    cur->next = new Node(tmp->data);
                    cur =  cur->next;
                    if (tmp->next == nullptr)
                        this->_tail = cur;
                    tmp = tmp->next;
                }
            }
        }
        ~stack()
        {
            Node *del;
            while(_size)
            {
                del = _S->next;
                delete _S;
                _S = nullptr;
                _S = del;
                _size--;
            }
          
        }
        const stack & operator=(const stack & s)
        {
            Node *del;
            while(_S)
            {
                del = _S->next;
                delete _S;
                _S = del;
            }
           this->_size = s._size;
            Node *tmp = s._S;
            while(tmp)
            {
                _S = new Node(tmp->data);
                Node *cur = _S;
                tmp = tmp->next;
                while(tmp)
                {
                    cur->next = new Node(tmp->data);
                    cur =  cur->next;
                    if (tmp->next == nullptr)
                        this->_tail = cur;
                    tmp = tmp->next;
                }
            }
            return *this;
        }
        bool empty()
        {
            return  (_size == 0);
        }
        void push(const T & data)
        {
            if (empty())
            {
                _S = new Node(data);
                _tail = _S;
            }
            else
            {
                _tail->next = new Node(data);
                _tail = _tail->next;
            }
            _size++;
        }
        T & top()
        {
            if (empty()) throw std::runtime_error("stack is empty");
            return _tail->data;
        }
        void pop()
        {
            if (empty()) throw std::runtime_error("stack is empty");
            Node *tmp = _S;
            Node *cur;
            while(tmp->next)
            {
                cur = tmp;
                tmp = tmp->next;
            }
            _tail = cur;
            cur->next = nullptr;
            delete tmp;
            tmp = nullptr;
            _size--;
        }
        size_t size()
        {
            return _size;
        }
        void swap(stack &s)
        {
            size_t size_tmp = s._size;
            s._size = this->_size;
            this->_size = size_tmp;
            Node *tmp = s._S;
            s._S = this->_S;
            this->_S = tmp;
        }
        friend bool operator==(const stack<T> &lhs, const stack<T> &rhs)
        {
            if(lhs.size() != rhs.size()) return false;
            Node *left = lhs._S;
            Node *right = rhs._S;
            while(left != nullptr) 
            {
                if(left->data != right->data) return false;
                left = left->next;
                right = right->next;
            }
            return true;   
        }
         friend bool operator<(const stack<T> &lhs, const stack<T> &rhs) {
            if (lhs.size() < rhs.size()) return true;
            Node *left = lhs._S;
            Node *right = rhs._S;
            while (left != nullptr && right != nullptr) 
            {
                if (left->data < right->data) return true;
                if (right->data < left->data) return false;
                left = left->next;
                right = right->next;
            }
            return false;
        }
        friend bool operator!=(const stack<T> &lhs, const stack<T> &rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator>(const stack<T> &lhs, const stack<T> &rhs)
        {
            return !(lhs < rhs);
        }
        friend bool operator>=(const stack<T> &lhs, const stack<T> &rhs)
        {
            return ((lhs > rhs) ||(lhs == rhs));
        }
        friend bool operator<=(const stack<T> &lhs, const stack<T> &rhs)
        {
            return ((lhs < rhs) ||(lhs == rhs));
        }
};

#endif