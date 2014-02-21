#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) {
  int n = atoi(argv[1]);
  int childpid = 0;

  char *execargv[] = {
    "-e",
    "bash",
    NULL,
    NULL
  };
  char *execenviron[] = {NULL};

  for(int i = 1; i <= n; i++) {
    childpid = fork();

    if(childpid == 0) {
      // in the child process
      printf("xterm from child process %d\n", i);
      // execv("/opt/X11/bin/xterm", execargv);
      execv("/usr/bin/xterm", execargv);
    } else if(childpid > 0) {
      // in the parent process, return value is the PID of the newly created // child process
      int status;
      waitpid(childpid, &status, 0);
      if(status == 0) {
        printf("Child process terminated normally\n");
      }
      if(status == 1) {
        printf("Child process terminated with an error!\n");
      }
    } else {
      printf("fork failed!\n");
      exit(1);
    }
  }
  exit(0);
}
