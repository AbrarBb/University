#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to be executed by the thread
void* myThreadFun(void* vargp) {
    printf("Printing from Thread\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    printf("Before Thread\n");

    // Creating a thread
    pthread_create(&thread_id, NULL, myThreadFun, NULL);

    // Waiting for the thread to complete
    pthread_join(thread_id, NULL);

    printf("After Thread\n");
    return 0;
}
