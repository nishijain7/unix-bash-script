#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>  // For link and unlink
#include <setjmp.h>

static jmp_buf envBuf;

int main(int argc, char **argv) {
    struct stat buf;
    int x = setjmp(envBuf);

    // First part: File linking and unlinking
    if (x == 0) {
        printf("x=%d, thus setjmp is called first time\n", x);

        if (argc != 3) {
            printf("COMMAND USAGE\n");
            exit(0);
        }

        if (stat(argv[1], &buf) != 0) {
            exit(0);
        }
        printf("NO. of Links (before link()): %lu\n", buf.st_nlink);

        if (link(argv[1], argv[2]) == 0) {
            printf("Link is successful\n");
            if (stat(argv[1], &buf) != 0) {
                exit(0);
            }
            printf("NO. of Links (after link()): %lu\n", buf.st_nlink);

            printf("Now let's unlink %s:\n", argv[2]);
            if (unlink(argv[2]) == 0) {
                printf("Unlink of %s from %s is successful\n", argv[2], argv[1]);
                if (stat(argv[1], &buf) != 0) {
                    exit(0);
                }
                printf("NO. of Links (after unlink()): %lu\n", buf.st_nlink);
            } else {
                exit(0);
            }
        } else {
            exit(0);
        }

        // Trigger the second part
        longjmp(envBuf, 1);
    }

    // Second part: setjmp/longjmp output
    else if (x == 1) {
        printf("Second\n");
        longjmp(envBuf, 2);
    } else if (x == 2) {
        printf("x=%d, setjmp is not called first time, thus returns the value specified in the longjmp\n", x);
        printf("main\n");
    }

    return 0;
}
