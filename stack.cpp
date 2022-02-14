#include <iostream>
#include <cassert>

// с помощью массива

class CStack {
public:
    explicit CStack(int _bufferSize) : 
        bufferSize(_bufferSize),
        top(-1) {
        buffer = new int[bufferSize];
    }
    ~CStack() {
        delete [] buffer;
    }

    void Push(int a) {
        assert(top + 1 < bufferSize);
        buffer[++top] = a;
    }
    int Pop() {
        assert(top != -1);
        return buffer[top--];
    }

    bool IsEmpty() const { return top == -1; };

private:
    int* buffer;
    int bufferSize;
    int top;
};

int main() {
    return 0;
}