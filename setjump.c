#include <stdio.h>
#include <setjmp.h>

static jmp_buf envBuf;

void second() {
    printf("Second\n");
    longjmp(envBuf, 2);
}

void first() {
    second();
    printf("First\n");
}

int main(int argc, char** argv) {
    int x = setjmp(envBuf);
    if (x == 0) {
        printf("x=%d, thus setjmp is called first time\n", x);
        first();
    } else {
        printf("x=%d, setjmp is not called first time, thus returns the value specified in the longjmp \n", x);
        printf("main\n");
    }
    return 0;
}
