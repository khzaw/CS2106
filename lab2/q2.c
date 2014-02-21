#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void create_child(int lvl) {
  pid_t child1, child2;
  int status1, status2;
  
  if(lvl == 0) {
    return;
  } else {
    lvl = lvl-1;
    if((child1 = fork()) == 0) {
      printf("Child: %d, Parent: %d\n", getpid(), getppid());
      create_child(lvl);
    } else if(child1 > 0) {
      if((child2 = fork()) == 0) {
        printf("Child: %d, Parent: %d\n", getpid(), getppid());
        create_child(lvl);
      } else if(child2 > 0) {
        waitpid(child2, &status2, 0);
      } else perror(strerror(errno));
    } else perror(strerror(errno));
    waitpid(child1, &status2, 0);
    // uncomment next line to view the pstree e.g., pstree -p `superdaddy's pid`
    // sleep(30);
  }
}

int main(int argc, char ** argv) {
  int n = atoi(argv[1]);
  printf("Superdaddy: %d\n", getpid());
  create_child(n);
}

