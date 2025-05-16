#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold person data
struct a 
{
    char name[50];
    int b; // age
};

// Thread function
void* printPerson(void* arg) 
{
    struct a* person = (struct a*)arg; // Cast to struct pointer
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->b);
    return NULL;
}

int main() 
{
    pthread_t thread;

    // Create and fill a struct
    struct a person = {"Lajim", 23};

    // Create a thread and pass the struct
    pthread_create(&thread, NULL, printPerson, &person);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}
