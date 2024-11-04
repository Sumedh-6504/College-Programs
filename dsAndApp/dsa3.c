#include <stdio.h>
#include <stdlib.h>

void push(int item);
int pop();
void palindrom();
void display();

int main()
{
    int n, i;

    printf("Enter the number of stack elements: ");
    scanf("%d", &n);

    while (1)
    {
        printf("1. Push an item");
        printf("2. Pop an item");
        printf("3. check Palindrome");
        printf("4. Display Stack elements");
        printf("5. Exit");
        printf("Enter your choice: ");
        scanf("%d", &n);
        printf("\n");
    }
}