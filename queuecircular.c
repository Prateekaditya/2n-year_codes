#include <stdio.h>
#include<string.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void push()
{
    int element;
    printf("Enter the element to push: ");
    scanf("%d", &element);

    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = element;
}

void pop()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
        return;
    }

    int element = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    printf("The popped element is %d\n", element);
}

void delete()
{
    int element;
    printf("Enter the element to delete: ");
    scanf("%d", &element);

    int index = -1;
    for (int i = front; i <= rear; i++)
    {
        if (queue[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Element not found\n");
        return;
    }

    if (index == front)
    {
        pop();
    }
    else if (index == rear)
    {
        rear--;
    }
    else
    {
        for (int i = index; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }

    printf("The element has been deleted\n");
}

void traverse()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("The elements of the queue are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. inqueue\n");
        printf("2. dequeue\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            delete ();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}