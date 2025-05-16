#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* helloThread(void* arg) {
    printf("Hello, World!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, helloThread, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
