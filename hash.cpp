// Реализация хеш-таблицы в C++

#include <iostream>
#include <list>
using namespace std;

class HashTable { // Реализована через массив списков. 
                  // Размер таблицы определяется ближайшим простым числом 
                    // от минимально требуемого размера для получения равномерного распределения.
                  // Сама таблица при этом не хранит в себе ключи.
                  // Ключи нужны только чтобы добавить/удалить элемент.
    int capacity;
    list<int> *table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key, int value);

    int checkPrime(int n) {
        int i;
        if (n == 1 || n == 0) {
            return 0;
        }
        for (i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key) {
        return (key % capacity);
    }
    void displayHash();
};

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity]; // статический массив размером capacity из списков
}
void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push_back(data); // Добаление элемента через адресную арифметику по номеру списка
}

void HashTable::deleteItem(int key, int value) {
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == value) break;
    }

    if (i != table[index].end()) {
        table[index].erase(i);
    }
        
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; i++) {
        cout << "list[" << i << "]";
        for (auto x : table[i]) {
          cout << " --> " << x;
        }
        cout << endl;
    }
}

int main() {

    int data[] = {23, -63, 80, 37, 94, 23, -41, -45, 24, 94, 81, -27, 14, -2, 12, 75, -96, 41, -25, 
                51, -75, 24, -61, 98, -31, -18, 95, -93, -87, -46, -87, 36, -9, 94, -27, -16, 16, 33, 
                39, -60, 26, 20, 13, -60, -82, -75, -86, -78, 66, -10, 73, 92, -86, -88, 89, -16, -6,
                83, -9, 7, -64, 5, -57, 27, -1, 16, -89, -85, -52, 51, -45, 75, -30, 69, -85, -12, 94,
                -70, 10, 60, 20, -17, 51, 34, -5, 39, -83, 90, 21, 9, -4, 58, -87, 39, -15, 12, -45, -4, 27, 4};
    int size = 100;

    HashTable h(size);

    for (int i = 0; i < size; i++) {
        h.insertItem(i, data[i]);
    }

    h.insertItem(95, 23432);
    h.insertItem(97, 1001);
    h.deleteItem(95 + h.getPrime(size), 23432);

    h.displayHash();
}