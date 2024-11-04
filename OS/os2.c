// Program - 3: Simulate producer-consumer problem using semaphores

// NOTE - 1
/*
Semaphore - In computer science, a semaphore is a variable or abstract data type that controls access to a shared resource by multiple threads. Semaphores are used to avoid critical section problems in concurrent systems, such as multitasking operating systems.
*/

// NOTE - 2
/*
When x = 0, the first item will be stored at index 0 of the buffer array. This is because x % BUFFER_SIZE will be 0 when x is 0, regardless of the value of BUFFER_SIZE.

So, the first item will go to buffer[0], the second to buffer[1], and so on. Once x reaches BUFFER_SIZE, the next item will go back to buffer[0], and the process continues in a circular manner.
*/

// College Code

#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;
int wait(int s)
{
    return (--s);
}

void producer()
{

    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf(" \n Producer produced the item : %d ", x);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumed the item : %d", x);
    x--;

    mutex = signal(mutex);
}

int main()
{

    int n;
    void producer();
    void consumer();
    printf(" \n 1.Producer \n 2.Consumer \n 3. Exit \n");

    while (1)
    {
        printf(" \n Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:

            if (mutex == 1 && empty != 0)

                producer();

            else

                printf("Buffer is Full!");

            break;
        case 2:

            if (mutex == 1 && full != 0)

                consumer();

            else

                printf("Buffer is Empty!");

            break;

        case 3:

            exit(0);

            break;
        }
    }

    return 0;
}

// Code for deep-understanding for what is happening in the college code!

/*
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int x = 0;
int mutex = 1, full = 0, empty = BUFFER_SIZE;

int wait(int s)
{
    return --s;
}

int signal(int s)
{
    return ++s;
}

void producer()
{
    int item;

    mutex = wait(mutex);
    while (full == BUFFER_SIZE)
    {
        printf("Buffer is full. Producer waiting...\n");
        // You can add a delay here to avoid busy waiting
    }
    item = rand() % 100; // Generate a random item
    buffer[x % BUFFER_SIZE] = item;
    x++;
    full = signal(full);
    empty = wait(empty);
    mutex = signal(mutex);

    printf("Producer produced item %d\n", item);
}

void consumer()
{
    int item;

    mutex = wait(mutex);
    while (empty == BUFFER_SIZE)
    {
        printf("Buffer is empty. Consumer waiting...\n");
        // You can add a delay here to avoid busy waiting
    }
    x--; // decrementation before accessing because when we try to access then the index
    item = buffer[x % BUFFER_SIZE];
    full = wait(full);
    empty = signal(empty);
    mutex = signal(mutex);

    printf("Consumer consumed item %d", item);
}

int main()
{
    int n;

    while (1)
    {
        printf("\n1. Producer\n2. Consumer\n3. Exit\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
*/