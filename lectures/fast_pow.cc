#include <stdio.h>

int pow(int x, int n) {
    if (n == 0) return int(1);
    if (n % 2 != 0) return pow(x, n-1) * x;
    int y = pow(x, n/2);
    return y*y;
}

int main() {
    int a = pow (2,3);
    printf("%d\n", a);
    return 0;
}
