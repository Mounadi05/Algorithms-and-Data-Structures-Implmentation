#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory>

template <typename T, typename Alloc = std::allocator<T> >
class stack 
{
    private:
        T* _array;
        size_t _top;
        size_t _capacity;
        Alloc alloc;
    public:
        stack(): _top(-1), _capacity(10), _array(nullptr) {
            _array = alloc.allocate(_capacity);
        }
        stack(const stack & S)
        {
            _top = S._top;
            _capacity = S._capacity;
            _array = alloc.allocate(_capacity);
            for(int i = 0; i <= _top ; i++)
                _array[i] = S._array[i];
        }
        const stack &operator=(const stack & S)
        {
            if (this->_capacity > 0)
                alloc.deallocate(_array,_capacity);
            _top = S._top;
            _capacity = S._capacity;
            _array = alloc.allocate(_capacity);
            for(int i = 0; i <= _top ; i++)
                _array[i] = S._array[i];
            return *this;
        }
        ~stack()
        {
            alloc.deallocate(&_array[0],_capacity);
        }
        int size() const
        {
             return _top + 1;
        }
        bool empty()
        {
            return (_top == -1);
        }
        void push(const T &data)
        {
            if (_top + 1 == _capacity)
            {
                T * newarray = alloc.allocate(_capacity * 2);
                for(int i = 0; i <= _top ; i++)
                    alloc.construct(&newarray[i],_array[i]);
                alloc.construct(&newarray[++_top],data);
                alloc.deallocate(_array,_capacity);
                _capacity *= 2;
                _array = newarray;
            }
            else
                alloc.construct(&_array[++_top],data);
        }
        T & top()
        {
             return _array[_top];
        }
        const T & top() const
        {
             return _array[_top];
        }
        void pop()
        {
            alloc.destroy(&_array[_top--]);
        }
        void swap(stack & S)
        {
            int tmp = this->_top;
            this->_top = S._top;
            S._top = tmp;
            tmp = this->_capacity;
            this->_capacity = S._capacity;
            S._capacity= tmp;
            T * _tmp = this->_array;
            this->_array= S._array;
            S._array = _tmp;
        }
        friend bool operator==(const stack<T> &lhs, const stack<T> &rhs)
        {
            if (lhs.size() != rhs.size()) return false;
            for(int i = 0; i < lhs._top ; i++)
                if (rhs._array[i] != lhs._array[i]) return false;
            return true;
        }
        friend bool operator<(const stack<T> &lhs, const stack<T> &rhs)
        {
            if(lhs.size() >= rhs.size()) return false;
            for(int i = 0; i < lhs.size() ; i++)
            {
                if(lhs._array[i] < rhs._array[i]) return true;
                if(lhs._array[i] > rhs._array[i]) return false;
            }
            return false;
        }
        friend bool operator>(const stack<T> &lhs , const stack <T> &rhs)
        {
            return !(lhs < rhs);
        }
        friend bool operator!=(const stack<T> &lhs , const stack <T> &rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator>=(const stack<T> &lhs , const stack <T> &rhs)
        {
            return ((lhs > rhs) || lhs == rhs);
        }
        friend bool operator<=(const stack<T> &lhs , const stack <T> &rhs)
        {
            return ((lhs < rhs) || lhs == rhs);
        }
};
 
#endif