#include <stdio.h>

class myset {
public:
    myset(size_t size) {}
    ~myset() {}
    void insert(size_t elem) {}
    void erase(size_t elem) {}
    bool in(size_t elem) {
        return false;
    }
};

int main() {
    myset s(1000);
    for (size_t i = 0; i < 10; i++) {
        s.insert(i);
    }
    for (size_t i = 0; i < 20; i ++) {
        if (s.in(i)) {
            printf("%zu found\n", i);
        }
    }
    s.erase(5);
    if (s.in(5)) {
        printf("OOPS: %zu must not be in set\n", (size_t)5);
    }
    return 0;
}
