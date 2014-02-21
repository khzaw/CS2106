// Name : Kaung Htet
// Matric No : A0105860L
#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[256];
    printf("PID:%d\n", getpid());
    printf("Parent's ID:%d\n", getppid());
    printf("Current working directory:%s\n", getcwd(cwd, sizeof(cwd)));
}
