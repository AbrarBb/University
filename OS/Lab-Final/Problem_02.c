#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* printMessage(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t threads[3];
    char* messages[3] = {
        "Message from thread 1",
        "Message from thread 2",
        "Message from thread 3"
    };

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printMessage, messages[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
