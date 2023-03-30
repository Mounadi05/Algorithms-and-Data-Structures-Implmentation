# Queue Implementation in C++
This is a templated implementation of a Queue data structure, implemented using a singly-linked list. It supports the standard queue operations such as push, pop, front, back, size, and empty. It also provides comparison operators for comparison with other queues.
The queue class is a template class, which means it can hold any data type.

## Getting Started

* To use this queue implementation, simply include the queue.hpp header file in your code: `#include "queue.hpp"`
* Then, you can create a queue of any type by specifying its template parameter, for example: `queue<int> my_queue;`

## Operators

The class has the following overloaded operators:

* Assignment operator operator=
* Comparison operators ==, !=, <, >, <=, >=

## Methods

The class has the following methods:

* push(T data) - adds a new element to the back of the queue.
* pop() - removes the first element from the queue.
* front() - returns a reference to the first element in the queue.
* back() - returns a reference to the last element in the queue.
* size() - returns the number of elements in the queue.
* empty() - returns true if the queue is empty.

## Implementation Details
The Queue class is implemented using a singly linked list of nodes, where each node contains the data element and a pointer to the next node in the list. The Queue class also keeps track of the current size of the Queue, and provides methods to add and remove elements from the Queue, as well as to access the front and back elements of the Queue.

The Queue class supports copy construction and assignment, as well as the standard comparison operators. The comparison operators are implemented using the size and ordering of the elements in the Queue. The == operator compares the size and values of the elements in the Queue, while the other operators compare the size and ordering of the elements.
