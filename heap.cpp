#include <iostream>
#include <algorithm>

class Heap {
    static const int max_size = 100;
    int *data;
    int HeapSize;
public:
    Heap() : HeapSize ( 0 ) {
        data = new int[max_size];
    }

    void add(int n) {
        int i, parent;
        i = HeapSize;
        data[i] = n;
        parent = (i - 1) / 2;
        while (parent >= 0 && i > 0) {
            if (data[i] > data[parent]) {
                std::swap(data[i], data[parent]);
            }
            i = parent;
            parent = (i - 1) / 2;
        }
        HeapSize++;
    }

    void outHeap() {
        int i = 0;
        int k = 1;
        while (i < HeapSize) {
            while ((i < k) && (i < HeapSize)) {
                std::cout << data[i] << ' ';
                i++;
            }
            std::cout << std::endl;
            k = k * 2 + 1;
        }
    }

    void out() {
        for (int i = 0; i < HeapSize; i++) {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }

    void heapify(int i) {
        int left, right;
        int tmp;
        left = i * 2 + 1;
        right = i * 2 + 2;
        if (left < HeapSize) {
            if (data[i] < data[left]) {
                std::swap(data[i], data[left]);
                heapify(left);
            }
        }
        if (right < HeapSize) {
            if (data[i] < data[right]) {
                std::swap(data[i], data[right]);
                heapify(right);
            }
        }
    }
};


int main() {

    Heap heap;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        heap.add(elem);
    }

    return 0;
}