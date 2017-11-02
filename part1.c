#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *PhilosopherThread(void *threadid);
void creatPhilosopher(int nthreads);



int main(int argc, char *argv[])
{
   int nthreads = atoi(argv[1]);
   char *name = "Mohammad Nadim";
   printf ("You are %s and you created %d threads.\n" ,name,nthreads);
   creatPhilosopher(nthreads);
   
}

void *PhilosopherThread(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("This is philosopher %ld.\n", tid+1);
   pthread_exit(NULL);
}

void creatPhilosopher(int nthreads){
   pthread_t threads[nthreads];
   int rc;
   long t;
   for(t=0;t<nthreads;t++){
     rc = pthread_create(&threads[t], NULL, PhilosopherThread, (void *)t);
     }
   //pthread_exit(NULL);
   int rcc;
   long tt;
   for(tt=0;tt<nthreads;tt++){
     rcc = pthread_join(threads[tt], NULL);
     }

   printf("%ld threads have been joined successfully now.\n", tt);
}
