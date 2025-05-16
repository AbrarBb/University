#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct thread_data {
    int id;
    char message[50];
};

void* printMessage(void* arg) {
    struct thread_data* data = (struct thread_data*)arg;
    printf("Thread says: %s | ID: %03d\n", data->message, data->id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    // Last 3 digits of ID
    int id_suffix = 43;

    // Data to pass to each thread
    struct thread_data data1 = {id_suffix, "Thread 1: Hello!"};
    struct thread_data data2 = {id_suffix, "Thread 2: How are you?"};
    struct thread_data data3 = {id_suffix, "Thread 3: Goodbye!"};

    // Create threads
    pthread_create(&thread1, NULL, printMessage, &data1);
    pthread_create(&thread2, NULL, printMessage, &data2);
    pthread_create(&thread3, NULL, printMessage, &data3);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have completed.\n");
    return 0;
}
