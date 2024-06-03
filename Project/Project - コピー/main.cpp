#include <stdio.h>

int main() {
    int x = 6;
    int y = 12;
    int temp;

    temp = x;
    x = y;
    y = temp;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}


