# Binary Search Tree (BST) Implementation
This is an implementation of a binary search tree (BST) in C++. A BST is a type of tree data structure that is used to store and organize data in a way that allows for efficient searching, insertion, and deletion.

## Usage

### The bst class provides several methods for traversing the tree and manipulating its contents:

* inorder(): performs an inorder traversal of the tree, printing the key-value pairs of each node in sorted order
* postorder(): performs a postorder traversal of the tree, printing the key-value pairs of each node
* preorder(): performs a preorder traversal of the tree, printing the key-value pairs of each node
* insert(key, value): inserts a new node with the given key-value pair into the tree
* remove(key): removes the node with the given key from the tree
* replace(key, value): replaces the value of the node with the given key with a new value
* empty(): returns true if the tree is empty, false otherwise
* size(): returns the number of nodes in the tree
* clear() :  This function calls 'deleteTree', which is used to recursively deallocate all nodes.

## Implementation Details

The bst class is implemented using a private Node struct to represent each node in the tree. Each Node contains pointers to its left and right child nodes, as well as the key-value pair for that node.

Insertion, deletion, and search operations are implemented using standard BST algorithms. In particular, insertion and deletion are implemented iteratively using a while loop, while search is implemented using a recursive function.

The bst class is also designed to be memory-safe. Memory for each node is dynamically allocated using new and deallocated using delete when nodes are removed from the tree. The deleteTree function is used to recursively deallocate all nodes in the tree when the bst object is destroyed.

