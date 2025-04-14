#ifndef TREE_H
#define TREE_H

template<typename T>
class Tree {
public:
    struct Node {
        T data;
        Node* parent;
        Node* first_child;
        Node* next_sibling;
        Node(const T& value) : data(value), parent(nullptr), first_child(nullptr), next_sibling(nullptr) {}
    };

    Tree() : root(nullptr) {}
    ~Tree() { clear(); }

    Node* add_node(Node* parent, const T& value);
    Node* get_node(Node* node);
    void delete_node(Node* node);
    Node* find(Node* start, bool (*cmp)(const T&, const void*), const void* param);
    Node* insert(Node* parent, int index, const T& value);
    void sort(Node* parent, bool (*cmp)(const T&, const T&));
    int count(Node* node);
    void clear();
    Node* get_root() const { return root; }

private:
    Node* root;
    bool remove_child(Node* parent, Node* child);
};


#endif // TREE_H

