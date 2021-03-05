#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void *task_body_time(void* pv)
{
    int i=0;
    time_t t;
    struct tm* current_time;
    /* Get current time in seconds */
    t = time(NULL);
    /* Change the format to hh : mm : ss*/
    current_time = localtime(&t);
    printf("%02d : %02d : %02d \n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

}

void getTime()
{
    int i, k=10;
    pthread_t ptrarray[k];

    for(i=0; i<k; ++i)
    {
        /* Create a thread to get current time */
        pthread_create(&ptrarray[i], NULL, task_body_time, (void *)(__intptr_t)i);
        /* Sleep for 3 seconds */
        sleep(3);
    }
    
    for(i=0; i<k; i++)
    {
        pthread_join(ptrarray[i], NULL);
    }
}

int main()
{
  /* Get the current time*/
  getTime();
}
