#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BST.hpp"

using namespace std;

int main() {
    bst<int, int> tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(2, 20);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);
    tree.insert(11, 110);
    tree.insert(9, 90);
    tree.insert(88, 880);
    tree.insert(13, 130);
    tree.insert(99, 990);

    cout << "In-order traversal: "<< std::endl;
    tree.inorder();
    cout << endl;

    cout << "Pre-order traversal: "<< std::endl;
    tree.preorder();
    cout << endl;

    cout << "Post-order traversal: "<< std::endl;
    tree.postorder();
    cout << endl;

    cout << "Search for key=7: " << tree.search(7) << endl;
    cout << "Search for key=99: " << tree.search(99) << endl;

    tree.remove(7);
    tree.remove(2);
    tree.remove(9);
    cout << "remove keys : 7, 2, 9" << endl;
    cout << endl;
    cout << "In-order traversal after removing some nodes: " << std::endl;
    tree.inorder();
    cout << endl;


    cout << "replace key : 88  with value : 8888 ? " << 
    (tree.replace(88, 8888) ? "yes" : "no") << endl;

    cout << "replace key : 6  with value : 6666 ? " << 
    (tree.replace(6, 6666) ? "yes" : "no") << endl;

    cout << "After replace:" << endl;
    tree.inorder();
    cout << "Is the tree empty? " << (tree.empty() ? "yes" : "no") << endl;

     tree.clear();

    cout << "Is the tree empty after clear()? " << (tree.empty() ? "yes" : "no") << endl;

    const int SIZE = 50;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int key = rand() % SIZE;
        int val = rand() % SIZE;
        tree.insert(key, val);
    }
    for (int i = 0; i < SIZE; i++) {
        int key = rand() % SIZE;
        try{
            int value =  tree.search(key);
          // std::cout << "key : " << key << " value : " << value << std::endl;
        }
        catch(...)
        {
            //std::cout << "key : " << key << " value : not found"  << std::endl;
            continue;
        }
    }

    return 0;
}