#include <stdio.h>
#include <pthread.h>

void *printHello(void *arg) {
    printf("Hello ");
    pthread_exit(NULL);
}

void *printWorld(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create thread for printing "Hello"
    if (pthread_create(&thread1, NULL, printHello, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for thread1 to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    // Create thread for printing "World"
    if (pthread_create(&thread2, NULL, printWorld, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for thread2 to finish
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    return 0;
}
