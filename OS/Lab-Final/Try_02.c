#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* squareThread(void* arg) {
    int num = *((int*)arg);
    printf("Square: %d\n", num * num);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int value = 7; // example integer to pass
    pthread_create(&thread_id, NULL, squareThread, &value);
    pthread_join(thread_id, NULL);
    return 0;
}
