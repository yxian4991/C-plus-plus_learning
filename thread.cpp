/*
 * Written in 2019-01-17
 * copy a project from runoob.com
 * aim to learn thread.h & thread::join & thread::detach
 */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
struct thread_data{
   int  thread_id;
   char *message;
};
 
void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;
 
   my_data = (struct thread_data *) threadarg;
 
   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;
 
   pthread_exit(NULL);
}
 
int main ()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   pthread_attr_t attr;
   void *status;
   int rc;
   int i;
   //make attribution of created threads joinable
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
   for( i=0; i < NUM_THREADS; i++ ){
      cout <<"main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      td[i].message = (char*)"This is message";
      rc = pthread_create(&threads[i], NULL,
                          PrintHello, (void *)&td[i]);
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

   //exit thread using thread::join or thread::detach safely
   pthread_attr_destroy(&attr);
   for( i=0; i < NUM_THREADS; i++ ){
      rc = pthread_join(threads[i], &status);
      if (rc){
         cout << "Error:unable to join," << rc << endl;
         exit(-1);
      }
      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
   }
 
   cout << "Main: program exiting." << endl;

   pthread_exit(NULL);


}

