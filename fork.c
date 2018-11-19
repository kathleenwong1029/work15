#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void child(){
  srand(time(NULL));
  printf("Forking off ... \n");
  printf("Child PID: %d\n", getpid());
  int sleep_t = (rand() % 16 ) + 5;
  sleep(sleep_t);
  printf("Child sleeping...\n");
  printf("Child process finished\n");
  exit(sleep_t);
}

int main(){
  printf("Pre-fork message ... \n");
  int c = fork();
  int p,status,c1;
  if(!c){
    child();
  }
  else{
  c1 = fork();
  if(!c1){
    child();
  }
  p = wait(&status);
    printf("Completed child PID:%d\n",p);
    printf("Complted child slept for %d seconds\n", WEXITSTATUS(status));
    printf("Parent process is done \n");
  }

  return 0;
}
