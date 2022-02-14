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


void sort_insertion(int* a, int size) {
    for (int i = size - 1; i > 0; i--) {
        if (a[i-1] > a[i]) {
            int tmp = a[i-1]; a[i-1] = a[i]; a[i] = tmp;
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

//  1 8 7 4 2
//  1 8 7 4 4
//  1 8 7 7 4
//  1 8 8 7 4
//  1 2 8 7 4

int binarySearch(int val, int a[], int size) {
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



void merge(int *a, int low, int mid, int high, int *aux) {
    int i, j;
    for (i = mid+1; i > low; i--) aux[i-1] = a[i-1];
    for (j = mid; j < high; j++) aux[high+mid-j] = a[j+1];
    for (int k = low; k <= high; k++) {
        if (aux[j] < aux[i])
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
    }
}

void mergeSort(int a[], int low, int high, int *aux) {
    if (high - low <= 1) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(a, low, mid, aux);
    mergeSort(a, mid+1, high, aux);
    merge(a, low, mid, high, aux);
}

void sort_merge(int *a, int n) {
    int *aux = new int[n];
    mergeSort(a, 0, n-1, aux);
    delete [] aux;
}

int Partition(int *a, int n) {
    if (n <= 1) {
        return 0;
    }
    const int &pivot = a[n-1];
    int i = 0, j = n - 2;
    while (i <= j) {
        for (; a[i] < pivot; ++i) {}
        for (; j>= 0 && !(a[j] < pivot); --j) {}
        if (i < j) {
            std::swap(a[i++], a[j--]);
        }
    }
    std::swap (a[i], a[n-1]);
    return i;
}

void quickSort (int *a, int n) {
    int part = Partition(a, n);
    if (part > 0) quickSort(a, part);
    if (part + 1 < n) quickSort(a + part + 1, n - (part + 1));
}

static void heapify(int *a, int i, int n)
{
    int curr = a[i];
    int index = i;
    for (;;) {
        int left = index + index + 1;
        int right = left + 1;
        if ( left < n && a[left] > curr)
            index = left;
        if ( right < n && a[right] > a[index])
            index = right;
        if (index == i ) break;
        a[i] = a[index];
        a[index] = curr;
        i = index;
    }
}

void sort_heap(int *a, int n) {
    for(int i = n/2-1; i >= 0; i--) {
        heapify(a, i, n);
    }
    while( n > 1 ) {
        n--;
        int tmp = a[0];
        a[0] = a[n];
        a[n] = tmp;
        heapify(a, 0, n);
    }
}

int main() {

    int array[SIZE];

    for (int i = 0; i < SIZE; i ++) {
        array[i] = getRandomNumber(-100, 100);
    }

    Print(array, SIZE);

    //sort_insertion(array, SIZE);

    sort_heap(array, SIZE);

    Print(array, SIZE);

    return 0;
}