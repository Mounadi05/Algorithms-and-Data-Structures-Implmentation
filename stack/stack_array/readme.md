# Stack Class
This is a C++ implementation of a stack class, which is a linear data structure that follows the Last-In-First-Out (LIFO) principle.

The stack class template takes two template parameters, T and Alloc, where T represents the type of the elements stored in the stack and Alloc represents the allocator type used for memory management.

 ## Class Members
* _array: a pointer to the underlying array of elements.
* _top: an integer that represents the index of the top element of the stack.
* _capacity: an integer that represents the current capacity of the stack.
* alloc: an allocator object used to manage the memory of the stack.
Class Methods
* stack(): default constructor that creates an empty stack with a default capacity of 10.
* stack(const stack & S): copy constructor that creates a new stack that is a copy of an existing stack S.
const stack &operator=(const stack & S): copy assignment operator that assigns an existing stack S to the current stack.
* ~stack(): destructor that deallocates the memory used by the stack.
* int size() const: returns the number of elements in the stack.
* bool empty(): returns true if the stack is empty, false otherwise.
*void push(const T &data): adds a new element to the top of the stack.
* T & top(): returns a reference to the top element of the stack.
* const T & top() const: returns a const reference to the top element of the stack.
* void pop(): removes the top element from the stack.
* void swap(stack & S): swaps the contents of the current stack with another stack S.
* friend bool operator==(const stack<T> &lhs, const stack<T> &rhs): compares two stacks for equality.
* friend bool operator<(const stack<T> &lhs, const stack<T> &rhs): compares two stacks, returns true if lhs is less than rhs.
* friend bool operator>(const stack<T> &lhs , const stack <T> &rhs): compares two stacks, returns true if lhs is greater than rhs.
* friend bool operator!=(const stack<T> &lhs , const stack <T> &rhs): compares two stacks for inequality.
* friend bool operator>=(const stack<T> &lhs , const stack <T> &rhs): compares two stacks, returns true if lhs is greater than or equal to rhs.
* friend bool operator<=(const stack<T> &lhs , const stack <T> &rhs): compares two stacks, returns true if lhs is less than or equal to rhs.

  ## Usage
To use the stack class, include the stack.hpp header file and create a new instance of the class as shown below:

```
#include "stack.hpp"
stack<int> s;
```
You can then use the class methods to add, remove, and access elements of the stack, as well as compare it with other stacks.

 ## Memory Management
The stack class uses an allocator object alloc for memory management. The default allocator is std::allocator, but you can also specify a custom allocator when creating an instance of the class. The alloc.allocate method is used to allocate memory for the stack, and the `alloc.deallocate
