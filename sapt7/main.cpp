#include <iostream>
#include "Tree.h"

bool compareInt(const int &nodeValue, const void* param) {
    int compVal = *static_cast<const int*>(param);
    return nodeValue == compVal;
}

bool compareSortInt(const int &a, const int &b) {
    return a < b;
}

int main() {
    Tree<int> tree;
    Tree<int>::Node* root = tree.add_node(nullptr, 10);
    Tree<int>::Node* child1 = tree.add_node(root, 5);
    Tree<int>::Node* child2 = tree.add_node(root, 15);
    Tree<int>::Node* child3 = tree.insert(root, 1, 7);
    std::cout << "Numarul total de descendent ai radacinii: " << tree.count(nullptr) << std::endl;
    int searchVal = 7;
    Tree<int>::Node* found = tree.find(nullptr, compareInt, &searchVal);
    if(found)
        std::cout << "Nod gasit cu valoarea: " << found->data << std::endl;
    else
        std::cout << "Nodul nu a fost gasit" << std::endl;
    tree.sort(root, compareSortInt);
    std::cout << "Copiii radacinii dupa sortare: ";
    Tree<int>::Node* child = root->first_child;
    while (child) {
        std::cout << child->data << " ";
        child = child->next_sibling;
    }
    std::cout << std::endl;
    tree.delete_node(child1);
    std::cout << "Numarul total dupa stergere: " << tree.count(nullptr) << std::endl;
    tree.clear();
    return 0;
}

