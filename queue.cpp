#include <cassert>

class CQueue {
public:
    explicit CQueue (int size) :
        buffersize ( size ),
        head ( 0 ),
        tail ( 0 ) 
    {
        buffer = new int[buffersize];
    }
    ~CQueue() { delete [] buffer; };

    // Добавление
    void Enqueue (int a) {
        assert ((tail + 1) % buffersize != head );
        buffer[tail] = a;
        tail = ( tail + 1) % buffersize;
    }
    // Извлечение
    int Dequeue() {
        assert( head != tail ); // Проверка что очередь не пуста
        int result = buffer[head];
        head = (head + 1) % buffersize;
        return result;
    }

    bool IsEmpty() const { return head == tail; };
private:
    int *buffer;
    int buffersize;
    int head;
    int tail;
};