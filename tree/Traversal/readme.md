# Tree Traversal

This function includes iterative and recursive implementations of the three types of tree traversal: inorder, postorder, and preorder. It takes a binary tree node as input and outputs the values of the nodes in the specified orde

## Iterative Implementations

### Inorder
The iterative implementation of inorder traversal uses a stack to keep track of the nodes. It pushes the left child of each node onto the stack until it reaches a leaf node. It then pops the top node from the stack, prints its value, and sets the root to its right child. This process continues until the stack is empty.

### Postorder
The iterative implementation of postorder traversal uses a stack and a pointer to the previously visited node. It pushes the left child of each node onto the stack until it reaches a leaf node. It then pops the top node from the stack and checks if it has a right child or if its right child has been visited. If not, it pushes the right child onto the stack and repeats the process for the right child. If yes, it prints the value of the node and sets the previously visited node to the current node. This process continues until the stack is empty.

### Preorder
The iterative implementation of preorder traversal uses a stack and a vector to keep track of the right child nodes. It prints the value of each node, pushes its right child onto the vector if it exists, and sets the root to its left child. If there are nodes in the vector, it sets the root to the last node in the vector and removes it from the vector. This process continues until the root is null and the vector is empty.

### Level Order
This implementation demonstrates a breadth-first traversal of a binary tree, also known as a level order traversal. It systematically traverses the tree level by level using a queue to keep track of nodes.
 
## Recursive Implementations

### Inorder
The recursive implementation of inorder traversal first checks if the current node is null. If not, it recursively calls itself on the left child, prints the value of the current node, and recursively calls itself on the right child.

### Postorder
The recursive implementation of postorder traversal first checks if the current node is null. If not, it recursively calls itself on the left child, recursively calls itself on the right child, and prints the value of the current node.

### Preorder
The recursive implementation of preorder traversal first checks if the current node is null. If not, it prints the value of the current node, recursively calls itself on the left child, and recursively calls itself on the right child.
