#include <iostream>
#include <algorithm>

#define SIZE 20

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Print(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

void bublesort(int a[], int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size-1; i++) {
            if (a[i] > a[i+1]) {
                std::swap(a[i], a[i+1]);
                sorted = false;
            }
        }
    }
}

void insertion(int a[], int size) {
    for (int i = size - 1; i > 0; i--) {
        if (a[i-1] > a[i]) {
            std::swap(a[i-1], a[i]);
        }
    }

    for (int i = 2; i < size; i++) {
        int j = i;
        int tmp = a[i];
        while (tmp < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}

int binarySearch (int val, int a[], int size) {
    int l = 0;
    int r = size;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= val) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return a[l] == val ? l : -1;
}

int main() {

    int array[SIZE];

    for (int i = 0; i < SIZE; i ++) {
        array[i] = getRandomNumber(-100, 100);
    }

    Print(array, SIZE);

    //bublesort(array, SIZE);



    Print(array, SIZE);

    int answer = binarySearch(68, array, SIZE);
    std::cout << answer << std::endl;

    return 0;
}