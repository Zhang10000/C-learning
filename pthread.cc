#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *thread1( void *arg )
{
    printf("thread 1 returning ... \n");
    int *p = (int*)malloc(sizeof(int));
    *p = 1;
    return (void*)p;
}
void *thread2( void *arg )
{
    printf("thread 2 exiting ...\n");
    int *p = (int*)malloc(sizeof(int));
    *p = 2;
    pthread_exit((void*)p);
}
void *thread3( void *arg )
{
    while ( 1 ){ //
        printf("thread 3 is running ...\n");
        sleep(1);
   }
    return NULL;
}
int main( void )
{
    pthread_t tid;
    void *ret;
    // thread 1 return
    pthread_create(&tid, NULL, thread1, NULL);
    pthread_join(tid, &ret);
    printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret);
    free(ret);
    // thread 2 exit
    pthread_create(&tid, NULL, thread2, NULL);
    pthread_join(tid, &ret);
    printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret);
    free(ret);
    
    // thread 3 cancel by other
    pthread_create(&tid, NULL, thread3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &ret);
    if ( ret ==  PTHREAD_CANCELED )
        printf("thread return, thread id %X, return code:PTHREAD_CANCELED\n", tid);
    else
        printf("thread return, thread id %X, return code:NULL\n", tid);
}


------------------------------------------------------------------------------------
    
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *thread_run( void * arg )
{
   pthread_detach(pthread_self());
   printf("%s\n", (char*)arg);
   return NULL;
}
int main( void )
{
   pthread_t tid;
   if ( pthread_create(&tid, NULL, thread_run, "thread1 run...") != 0 ) {
       printf("create thread error\n");
       return 1;
   }
   int ret = 0;
   sleep(1);//很重要，要让线程先分离，再等待
   if ( pthread_join(tid, NULL ) == 0 ) {
       printf("pthread wait success\n");
       ret = 0;
   } else {
       printf("pthread wait failed\n");
       ret = 1;
   }
   return ret;
}
