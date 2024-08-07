#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>  // Add this line for link and unlink

struct stat buf;

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("COMMAND USAGE\n");
        return -1;
    }

    stat(argv[1], &buf);
    printf("NO. of Links (before link()): %lu\n", buf.st_nlink);
    
    int x = link(argv[1], argv[2]);
    if (x == 0) {
        printf("Link is successful\n");
        stat(argv[1], &buf);
        printf("NO. of Links (after link()): %lu\n", buf.st_nlink);
        
        printf("Now let's unlink %s:\n", argv[2]);
        int y = unlink(argv[2]);
        if (y == 0) {
            printf("Unlink of %s from %s is successful\n", argv[2], argv[1]);
            stat(argv[1], &buf);
            printf("NO. of Links (after unlink()): %lu\n", buf.st_nlink);
            return 0;
        } else {
            printf("Unlink is unsuccessful\n");
            return 3;
        }
    } else {
        printf("Link is unsuccessful\n");
        return 2;
    }
}
