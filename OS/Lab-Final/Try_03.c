#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* printMessage(void* arg) {
    int num = *((int*)arg);
    printf("Thread received number: %d\n", num);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int args[3] = {123, 456, 789}; // Example arguments: last 3 digits of IDs

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printMessage, &args[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
