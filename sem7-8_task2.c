#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
int cnt = 0;

void *mythread(void *dummy)
{
    pthread_t mythid;
    mythid = pthread_self();
    cnt = cnt + 1;

    printf("Thread %d, calculation result = %d\n", mythid, cnt);

    return NULL;
}


int main()
{
    pthread_t thid, thid2, mythid;
    int res;

    res = pthread_create( &thid, (pthread_attr_t *)NULL, mythread, NULL);

    if (res != 0) {
        printf ("error");
        exit(-1);
    }

    printf("Second thread created, thid = %d\n", thid);

    res = pthread_create( &thid2, (pthread_attr_t *)NULL, mythread, NULL);

    if (res != 0) {
        printf ("error");
        exit(-1);
    }

    printf("Third thread created, thid = %d\n", thid2);

    mythid = pthread_self();
    cnt = cnt + 1;

    printf ("error");
    pthread_join(thid, (void **)NULL);
    pthread_join(thid2, (void **)NULL);

    return 0;
}
