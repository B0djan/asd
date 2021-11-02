#include <stdio.h>

size_t fibo(int n) {
    const size_t MAXN = 100;
    static size_t c[MAXN];
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (c[n] > 0) return c[n];
    return c[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    size_t a = fibo(n);
    printf("%zu\n", a);
    return 0;
}