#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

template <typename T>
class queue{

    private:
        class node
        {
            public :
             T data;
             node *next;
             node(T &data):data(data),next(nullptr){}
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
        void push(T data)
        {
            node *node_add = new node(data);
            node *tmp = _q;
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
        T & front()
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            return _q->data;
        }
        T & front() const
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            return _q->data;
        }
        unsigned int size()
        {
            return _size;
        }
        bool empty()
        {
            return _size == 0;
        }
        T & back()
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            node *tmp = _q;
            while(tmp != nullptr && tmp->next != nullptr)
                tmp = tmp->next;
            return  tmp->data;
        }
        T & back() const
        {
            if(empty()) throw std::runtime_error("Error: Queue is empty");
            node *tmp = _q;
            while(tmp != nullptr && tmp->next != nullptr)
                tmp = tmp->next;
            return  tmp->data;
        }
};
#endif