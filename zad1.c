#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THR 16

void* printHello (void* thrID)
{
  printf("Hello SCR by thread ID %ld\n", (long) thrID);
  pthread_exit(0);
}


int main()
{
  pthread_t testThread[16];

  for(long i = 0; i < NUM_THR; ++i)
    pthread_create(&testThread[i], NULL, printHello, (void*) i);  //params: ptr na watek, arg watku, fun do exec przez watek, arg przekaz tej funkcji

  pthread_exit(0);
}

