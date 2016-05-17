#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread()
{
	printf("Hello, world!\n");
}

int main(int argc, char* argv[])
{
  int i;
  int n;
  n = atoi(argv[1]); 
  pthread_t tid[n];
  for(i = 0; i < n; i = i + 1)
  {
    pthread_create(&tid[i], NULL, thread, NULL);
    pthread_join(tid[i], NULL);
  }
  exit(0);
}
