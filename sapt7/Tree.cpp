#include "Tree.h"

template<typename T>
typename Tree<T>::Node* Tree<T>::add_node(Node* parent, const T& value) {
    Node* newNode = new Node(value);
    newNode->parent = parent;
    if (parent == nullptr) {
        if (root != nullptr) {
            newNode->first_child = root;
            root->parent = newNode;
            root = newNode;
        } else {
            root = newNode;
        }
    } else {
        if (parent->first_child == nullptr)
            parent->first_child = newNode;
        else {
            Node* temp = parent->first_child;
            while (temp->next_sibling != nullptr)
                temp = temp->next_sibling;
            temp->next_sibling = newNode;
        }
    }
    return newNode;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::get_node(Node* node) {
    if (node == nullptr)
        return root;
    return node;
}

template<typename T>
bool Tree<T>::remove_child(Node* parent, Node* child) {
    if (!parent || !child) return false;
    if (parent->first_child == child) {
        parent->first_child = child->next_sibling;
        return true;
    } else {
        Node* current = parent->first_child;
        while (current && current->next_sibling != child)
            current = current->next_sibling;
        if (current) {
            current->next_sibling = child->next_sibling;
            return true;
        }
    }
    return false;
}

template<typename T>
void Tree<T>::delete_node(Node* node) {
    if (node == nullptr) return;
    if (node->parent != nullptr)
        remove_child(node->parent, node);
    else
        root = nullptr;
    Node* child = node->first_child;
    while (child) {
        Node* next = child->next_sibling;
        delete_node(child);
        child = next;
    }
    delete node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::find(Node* start, bool (*cmp)(const T&, const void*), const void* param) {
    if (start == nullptr)
        start = root;
    if (start == nullptr)
        return nullptr;
    if (cmp(start->data, param))
        return start;
    Node* child = start->first_child;
    while (child != nullptr) {
        Node* result = find(child, cmp, param);
        if (result != nullptr)
            return result;
        child = child->next_sibling;
    }
    return nullptr;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::insert(Node* parent, int index, const T& value) {
    Node* newNode = new Node(value);
    newNode->parent = parent;
    if (parent == nullptr) {
        if (root != nullptr) {
            newNode->first_child = root;
            root->parent = newNode;
            root = newNode;
        } else {
            root = newNode;
        }
        return newNode;
    }
    if (index <= 0 || parent->first_child == nullptr) {
        newNode->next_sibling = parent->first_child;
        parent->first_child = newNode;
        return newNode;
    }
    Node* current = parent->first_child;
    int i = 0;
    while (current->next_sibling != nullptr && i < index - 1) {
        current = current->next_sibling;
        i++;
    }
    newNode->next_sibling = current->next_sibling;
    current->next_sibling = newNode;
    return newNode;
}

template<typename T>
void Tree<T>::sort(Node* parent, bool (*cmp)(const T&, const T&)) {
    if (parent == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        typename Tree<T>::Node** curr = &(parent->first_child);
        while (*curr && (*curr)->next_sibling) {
            Node* first = *curr;
            Node* second = first->next_sibling;
            bool condition = false;
            if (cmp)
                condition = cmp(second->data, first->data);
            else
                condition = (second->data < first->data);
            if (condition) {
                first->next_sibling = second->next_sibling;
                second->next_sibling = first;
                *curr = second;
                swapped = true;
            }
            curr = &((*curr)->next_sibling);
        }
    } while (swapped);
}

template<typename T>
int Tree<T>::count(Node* node) {
    if (node == nullptr)
        node = root;
    if (node == nullptr)
        return 0;
    int total = 0;
    Node* child = node->first_child;
    while (child) {
        total++;
        total += count(child);
        child = child->next_sibling;
    }
    return total;
}

template<typename T>
void Tree<T>::clear() {
    if (root)
        delete_node(root);
    root = nullptr;
}

