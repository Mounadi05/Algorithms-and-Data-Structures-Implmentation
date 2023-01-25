#ifndef CONST_QUEUE_HPP
#define CONST_QUEUE_HPP
#include <iostream>

template <typename T>
class queue{

    private:
        class node
        {
            public :
                const T &data;
                node *next;
                node(const T &data):data(data),next(nullptr){}
        };
        node * _q;
        unsigned int _size;
    public :
        queue():_q(nullptr),_size(0){}
        queue(const queue &q)
        {
            _size = q._size;
            node *tmp = q._q;
            if(tmp != nullptr)
            {
                _q = new node(tmp->data);
                tmp = tmp->next;
                node *cmp = _q;
                while(tmp != nullptr)
                {
                    cmp->next = new node(tmp->data);
                    cmp = cmp->next;
                    tmp = tmp->next; 
                }
            }  
        }
        ~queue()
        {
            node *del;
            while(_q != nullptr)
            {
                del = _q->next;
                delete _q;
                _q = del;
            }
        }
        const queue & operator=(const queue &q)
        { 
            node *del;
            while(_q != nullptr)
            {
                del = _q->next;
                delete _q;
                _q = del;
            }
            this->_size = q._size;
            node *tmp = q._q;
            if(tmp != nullptr)
            {
                _q = new node(tmp->data);
                tmp = tmp->next;
                node *cmp = _q;
                while(tmp != nullptr)
                {
                    cmp->next = new node(tmp->data);
                    cmp = cmp->next;
                    tmp = tmp->next; 
                }
            } 
            return *this;
        }
        void push(const T &data)
        {
            node *node_add = new node(data);
            node *tmp =  _q;
            if (tmp == nullptr)
                _q = node_add;
            else
            {
                while(tmp->next != nullptr)
                    tmp =  tmp->next;
                tmp->next = node_add;
            }
            _size++;
        }
        void pop()
        {
            if (_q != nullptr)
            {
                node *tmp = _q;
                _q = _q->next;
                delete tmp;
                 _size--;
            }
           
        }
        const T & front()
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            return  _q->data;
        }
        unsigned int size() const
        {
            return _size;
        }
        bool empty()
        {
            return _size == 0;
        }
        const T & back()
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            node *tmp = _q;
            while(tmp != nullptr && tmp->next != nullptr)
                tmp = tmp->next;
            return  tmp->data;
        }
        friend bool operator<(const queue<T> &lhs, const queue<T> &rhs)
        {
            if (lhs.size() < rhs.size()) return true;
            node *r = rhs._q;
            node *l = lhs._q;
            while(r != nullptr && l != nullptr)
            {
                if (l->data < r->data) return true;
                if (r->data < l->data) return false;
                l = l->next;
                r = r->next;
            }
            return false;
        }
        friend bool operator==(const queue<T> &lhs, const queue<T> &rhs)
        {
            if (lhs.size() != rhs.size()) return false;
            node *r = rhs._q;
            node *l = lhs._q;
            while(r != nullptr && l != nullptr)
            {
                if (l->data != r->data) return false;
                l = l->next;
                r = r->next;
            }
            return true;
        }
        friend bool operator>(const queue<T> &lhs , const queue<T> &rhs)
        {
            return !(lhs < rhs);      
        }
        friend bool operator<=(const queue<T> &lhs, const queue<T> &rhs)
        {
            return ((lhs < rhs) || (lhs == rhs));
        }
        friend bool operator!=(const queue<T> &lhs, const queue<T> &rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator>=(const queue<T> &lhs, const queue<T> &rhs)
        {
            return ((lhs > rhs) || (lhs == rhs));
        }
};
#endif