#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* printMessage(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    // Messages to be printed by each thread
    char message1[50] = "Thread 1: Hello!";
    char message2[50] = "Thread 2: How are you?";
    char message3[50] = "Thread 3: Goodbye!";

    // Creating three threads
    pthread_create(&thread1, NULL, printMessage, message1);
    pthread_create(&thread2, NULL, printMessage, message2);
    pthread_create(&thread3, NULL, printMessage, message3);

    // Waiting for all three threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have completed.\n");
    return 0;
}
