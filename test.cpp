#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

void sortInsertion(int *a, int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i] < a[i-1]) {
            int tmp = a[i];
            a[i] = a[i-1];
            a[i-1] = tmp;
        }
    }
    for (int i = 2; i < n; i++) {
        int j = i;
        int tmp = a[i];
        while (tmp < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}



int main() {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2 ,1};
    sortInsertion(a, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}