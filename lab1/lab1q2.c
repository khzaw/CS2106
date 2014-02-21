// Name : Kaung Htet
// Matric No : A0105860L
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    int call;
    char cwd[999];
    syscall(SYS_getcwd, cwd, 999);

    call = syscall(SYS_getpid);
    printf("Process's ID:%d\n", call);

    call = syscall(SYS_getppid);
    printf("Parent's process ID:%d\n", call);

    printf("Current working directory:\t%s\n", cwd);
    return 0;
}
