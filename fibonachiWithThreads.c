#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int fibonachi(int n) {
    if (n <= 0) { return 0; }
    if (n == 1) { return 1; }

    return fibonachi(n - 1) + fibonachi(n - 2);
}

void *threadFibonachi(void *n) {
    int *indexVal = (int*)malloc(sizeof(int));
    indexVal = (int*)n;

    *indexVal = fibonachi(*indexVal);

    return (void*)indexVal;
}

int main() {
    pthread_t thread;
    void *ret;
    int n = 0;

    puts("Input n-th fibonachi index");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        int index = i;
        pthread_create(&thread, NULL, threadFibonachi, (void*)&index);
        pthread_join(thread, (void*)&ret);
        printf("%d ", *(int*)ret);

        if (i == n) { putchar(10); }
    }
    
    return 0;
}