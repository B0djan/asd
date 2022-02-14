#include <iostream>
#include <cassert>

struct CNode {
    int Data;
    CNode* Next;
    CNode* Prev;

    CNode () : Data( 0 ), Next( 0 ), Prev ( 0 ) {};

    CNode* Search(CNode* head, int a) {
        CNode* current = head;
        while (current != 0) {
            if (current->Data == a)
                return current;
            current = current->Next;
        }
        return 0;
    }

    // Вставака элемента "а" после текущего
    CNode* InsertAfter(CNode* node, int a) {
        assert(node != 0);
        //Создаем новый элемент.
        CNode* newNode = new CNode();
        newNode->Next = node->Next;
        newNode->Prev = node;
        // Обновлчем Prev следующего элеммента если он есть
        if (node->Next != 0) {
            node->Next->Prev = newNode;
        }
        // Обновляем Next текущего элемента
        node->Next = newNode;
        return newNode;
    }
};

int main() {
    return 0;
}