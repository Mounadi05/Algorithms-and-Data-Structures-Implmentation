
# Stack Implementation
This repository contains two implementations of a stack data structure, one using an array and the other using a linked list.

## [Stack using Array](https://github.com/Mounadi05/Algorithms-and-Data-Structures-Implmentation/blob/master/stack/stack_array/stack.hpp)
The stack class defined in stack_array.hpp uses an array to implement the stack data structure. The stack's capacity is initialized to 10 by default, and can be resized as the number of elements increases. The class is defined as follows:

`template <typename T, typename Alloc = std::allocator<T> >`

### The stack class has the following public methods:

* push(const T& data): inserts an element into the stack.
* pop(): removes and returns the top element from the stack.
* top(): returns the top element in the stack without removing it.
* empty(): returns true if the stack is empty, false otherwise.
* size(): returns the number of elements in the stack.
* overloaded comparison operators (==, !=, <, >, <=, >=) and a swap method.

## [Stack using Linked List](https://github.com/Mounadi05/Algorithms-and-Data-Structures-Implmentation/blob/master/stack/stack_LinkedList/stack.hpp)

The stack class defined in stack_linked_list.hpp uses a linked list to implement the stack data structure. The class is defined as follows:


### The stack class has the following public methods:

* push(const T& data): inserts an element into the stack.
* pop(): removes and returns the top element from the stack.
* top(): returns the top element in the stack without removing it.
* empty(): returns true if the stack is empty, false otherwise.
* size(): returns the number of elements in the stack.
* overloaded comparison operators (==, !=, <, >, <=, >=) and a swap method.
