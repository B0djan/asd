#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template<typename T>
void bubble_sort(vector<T> &a); // +

template<typename T>
void shell_sort(vector<T> &a); // +

template<typename T>
void insert_sort(vector<T> &a); // +

template<typename T>
void selection_sort(vector<T> &a); // +

template<typename T>
void merge_sort(vector<T> &a, size_t start, size_t end); // +

template<typename T>
void quick_sort(vector<T> &a, int first, int last); // +

template<typename T>
void count_sort(vector<T> &a, T min, T max); // +

template<typename T>
void radix_sort(vector<T> &a); // +

template<typename T>
void pyramidal_sort(vector<T> &a); // +

template<typename T>
void make_heap(vector<T> &a, int first, int last);

template<typename T>
void make_true_heap(vector<T> &a, int first, int last);

template<typename T>
void sort_node_tree(vector<T> &a, int parent, int last);

template<typename T>
void print(vector<T> a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> arr = {1, 5, 6, 3, 4, 9, 11, 4, 5, 16, 0, 611, -2, 25243, -543, 4, 0 , 23 , 22, 124 , -4333, 3, -8, -3533, 7, -10};
    //{301, -4645, -5495, 9632, 4330, 45 ,1035, 2367, -864, 0, 35, -1991, -978, 8859, -8549, 1, -17, 9149, 3405, -285, 2081, 3497, 9798, 8047, 7909, 7078, 616, 3806, 617, 7958, -8275, 949, 5186, 2096, 3288, 3651, 340, 8347, 4553, 9220, 3806, 583, 164, 1798, 8632, 9511, 9460, 4575, 7800, 8929};
    pyramidal_sort(arr);
    // radix_sort(arr);
    // quick_sort(arr, 0, arr.size() - 1);
    // merge_sort(arr,0, arr.size());
    print(arr);
    return 0;
}


template<typename T>
void bubble_sort(vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        for (size_t j = 0; j < a.size() - i - 1; ++j) {
            if (a[j+1] < a[j])
                swap(a[j+1], a[j]);
        }
    }
}

template<typename T>
void shell_sort(vector<T> &a) {

    for (int step = a.size() / 2; step > 0; step /= 2)
        for (int i = step; i < a.size(); i++) {
            int tmp = a[i];
            int j;
            for (j = i; j >= step; j -= step) {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }

}

template<typename T>
void insert_sort(vector<T> &a) {
    for (size_t i = 1; i < a.size(); ++i) {
        for (size_t j = i; j > 0; --j) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
            }
        }
    }
}

template<typename T>
void selection_sort(vector<T> &a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        for (size_t j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
}

template<typename T>
void count_sort(vector<T> &a, int min, int max) {
    vector<size_t> F(max - min + 1);
    for (int i = 0; i < a.size(); ++i) {
        F[a[i] - min]++;
    }

    int k = 0;
    for (int i = 0; i < F.size(); ++i) {
        if (F[i] == 0) continue;
        for (int j = F[i]; j > 0; --j) {
            a[k] = i + min;
            k++;
        }
    }
}

template<typename T>
void merge_sort(vector<T> &a, size_t start, size_t end) {
    if (end - start < 2) {
        return;
    }
    if (end - start == 2) {
        if (a[start] > a[start + 1]) {
            swap(a[start], a[start + 1]);
        }
        return;
    }
    merge_sort(a, start, start + (end - start) / 2);
    merge_sort(a, start + (end - start) / 2, end);

    vector<T> buff;
    size_t begin_first = start;
    size_t end_first = start + (end - start) / 2;
    size_t begin_second = end_first;
    size_t end_second = end;

    while (buff.size() < end - start) {
        if (begin_first >= end_first || (begin_second < end_second && a[begin_second] <= a[begin_first])) {
            buff.push_back(a[begin_second]);
            begin_second++;
        } else {
            buff.push_back(a[begin_first]);
            begin_first++;
        }
    }
    for (size_t i = start; i < end; ++i ) {
        a[i] = buff[i - start];
    }
    //print(a);
}

template<typename T>
void quick_sort(vector<T> &a, int first, int last) {
    if (first >= last) {
        return;
    }

    int left = first;
    int right = last;
    auto middle = a[(left + right) / 2];
    
    while (left < right) {
        while (a[left] < middle)
            left++;
        while (middle < a[right])
            right--;
        
        if (left <= right ) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }

    quick_sort(a, first, right);
    quick_sort(a, left, last);
}

template<typename T>
void radix_sort(vector<T> &a) {
    auto max = max_element(a.begin(), a.end());
    auto min = min_element(a.begin(), a.end());
    T mx = *max;
    T mn = *min;
    mx = (abs(mx) > abs(mn))? abs(mx) : abs(mn); //получение самого "длинного" числа, знак не важен

    int radix = 1;
    while (mx > 10) {
        radix++;
        mx /= 10;
    }

    vector<vector<int>> frequency(20); // для отрицательных тоже), [-9, -8, -7 .. -0, 0, 1 , 2 .. 9]

    for (int k = 0; k < radix; ++k) {
        for (int i = 0; i < 20; ++i) {
            frequency[i].clear();
        }

        for (int i = 0; i < a.size(); ++i) { // a[i]/(int)pow(10, k))%10 - получение цифры текущего разряда
            if (a[i] < 0) {
                frequency[(a[i]/(int)pow(10, k))%10 + 9].push_back(a[i]);
                continue;
            }
            frequency[(a[i]/(int)pow(10, k))%10 + 10].push_back(a[i]);
        }

        int i = 0;
        for (int j = 0; j < 20; ++j) {
            auto it = frequency[j].begin();
            while (it != frequency[j].end()) {
                a[i] = *it;
                it++;
                i++;
            }
        }
    }
}
template<typename T>
void sort_node_tree(vector<T> &a, int parent, int last) { // рекурсивно обходит всех детей
    if (2*parent + 1 > last) return;

    if (a[2*parent + 1] > a[parent]) {
        swap(a[parent], a[2*parent + 1]);
        sort_node_tree(a, 2*parent + 1, last);
    }

    if (2*parent + 2 > last) return;
    if (a[2*parent + 2] > a[parent]) {
        swap(a[parent], a[2*parent + 2]);
        sort_node_tree(a, 2*parent + 2, last);
    }
}

template<typename T>
void make_true_heap(vector<T> &a, int first, int last) { // Принцип возрастающей кучи: Каждый родитель больше свох детей
    int order_heap = 0;
    int n = last + 1;
    while (n > 1) {
        n /= 2;
        order_heap++;
    }

    for (int level = order_heap; level > 0; --level) {
        for (int i = 0; i < 1<<(level - 1); ++i) { 
            int index = (1<<(level - 1)) - 1 + i;
            int left_child = 2*index + 1;
            int right_child = 2*index + 2;

            if (left_child > last) break;
            if (a[left_child] > a[index]) {
                swap(a[index], a[left_child]);
                sort_node_tree(a, left_child, last);
            }

            if (right_child > last) break;
            if (a[right_child] > a[index]) {
                swap(a[index], a[right_child]);
                sort_node_tree(a, right_child, last);
            }
        }
    }
}

template<typename T>
void make_heap(vector<T> &a, int first, int last) { // По факту делает не тру кучу, а просто вытягивает максимальных элемент наверх
    int order_heap = 0;
    int n = last + 1;
    while (n > 1) {
        n /= 2;
        order_heap++;
    }
    for (int level = order_heap; level > 0; --level) {
        for (int i = 0; i < 1<<(level - 1); ++i) { 
            int index = (1<<(level - 1)) - 1 + i;
            int left_child = 2*index + 1;
            int right_child = 2*index + 2;

            if (left_child > last) break;
            if (a[left_child] > a[index]) {
                swap(a[index], a[left_child]);
            }

            if (right_child > last) break;
            if (a[right_child] > a[index]) {
                swap(a[index], a[right_child]);
            }
        }
    }
}

template<typename T>
void pyramidal_sort(vector<T> &a) {
    for (int i = a.size() - 1; i > 0; --i) {
        make_true_heap(a, 0, i); // но можно и просто make_heap(a, 0, i); - выполняется быстрее, но не канон 
        //print(a);
        swap(a[0], a[i]);
    }
}