# Stack Data Structure 

The stack class is a templated class that implements a basic stack data structure in C++ using a singly linked list. The stack is a last-in, first-out (LIFO) data structure, where elements are inserted and removed from the same end.

## Usage
### Instantiating a stack
To create a new stack, simply declare an instance of the class, like so:`stack<int> myStack;`

This creates a new stack object called myStack that can store integers.

### Pushing elements onto the stack
To add an element to the top of the stack, call the push() function and pass in the element you want to add as an argument: `myStack.push(42);`
This adds the integer 42 to the top of the stack.

### Popping elements off the stack
To remove the top element from the stack, call the pop() function: `myStack.pop();`

This removes the top element from the stack.

### Swapping stacks
You can swap the contents of two stacks by calling the swap() function:

## Implementation Details
The stack class is implemented using a singly-linked list. Each node in the linked list contains a data member that stores the value of the element, and a next pointer that points to the next node in the list.

The stack class has a Node inner class that represents the nodes in the linked list. The stack class also has a _S member that points to the first node in the list (the "head" of the list), a _tail member that points to the last node in the list (the "tail" of the list), and a _size member that stores the number of elements currently on the stack.

## Methodes

* push: adds an element to the top of the stack.
* pop: removes the top element from the stack.
* top: returns a reference to the top element of the stack.
* empty: returns true if the stack is empty, false otherwise.
* size: returns the number of elements in the stack.
* swap: swaps the contents of two stacks.

## Operator Overloading
The stack class overloads several operators to allow for comparison between stack objects. These operators include:

* `== `(equal to)

* `!= `(not equal to)

* `<` (less than)

* `>` (greater than)

* `<=` (less than or equal to)

* `>=` (greater than or equal to)

These operators allow you to compare stack objects based on their contents.

## Memory Management
The stack class manages memory by allocating new nodes on the heap for each element added to the stack, and deallocating them when elements are removed. The class uses a destructor to deallocate all nodes when the stack object is destroyed. The class also has a copy constructor and copy assignment operator to allow for deep copying of stack objects.
