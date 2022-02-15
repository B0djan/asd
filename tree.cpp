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

    Tree *searchNode(Tree *t, int data) {
        Tree *p = t;
        while (t != nullptr) {
            p = t;
            if (t->data == data) return t;
            t = data > t->data ? t->right : t->left;
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

    void insertNode (Tree *t, int data) {
        Tree *parent = t;
        while (t != NULL) {
            parent = t;
            if (t->data == data) return;
            t = data > t->data ? t->right : t->left;
        }
        Tree *node = new Tree(data);
        if (data < parent->data)
            parent->left = node;
        else
            parent->right = node;
    };
};

int main() {
    Tree *root = new Tree(10);
    return 0;
}