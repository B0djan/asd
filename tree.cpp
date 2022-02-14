#include <iostream>

class Tree {
    int data;
    Tree *left;
    Tree *right;
    Tree *parent;
public:
    Tree(int data) : data (data) {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Tree *searchNode(Tree *t, int key) {
        Tree *p = t;
        while (t != nullptr) {
            p = t;
            if (t->data == data) return t;
            t = key > t->data ? t->right : t->left;
        }
        return p;
    }

    Tree *minNode(Tree *t) {
        if (t == nullptr) return nullptr;
        while (t->left != nullptr) {
            t = t->left;
        }
        return t;
    }

    void insertNode (Tree *t, int data) {};
};

int main() {
    return 0;
}