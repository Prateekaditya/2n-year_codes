#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

typedef struct queue
{
    node *head;
} queue;

void enqueue(queue *q, int data, int priority)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (q->head == NULL || q->head->priority < priority)
    {
        new_node->next = q->head;
        q->head = new_node;
    }
    else
    {
        node *temp = q->head;
        while (temp->next != NULL && temp->next->priority > priority)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int dequeue(queue *q)
{
    if (q->head == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->head->data;
    node *temp = q->head->next;
    free(q->head);
    q->head = temp;

    return data;
}

void delete(queue *q, int data)
{
    if (q->head == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    if (q->head->data == data)
    {
        node *temp = q->head->next;
        free(q->head);
        q->head = temp;
    }
    else
    {
        node *prev = q->head;
        node *cur = q->head->next;
        while (cur != NULL && cur->data != data)
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur != NULL)
        {
            prev->next = cur->next;
            free(cur);
        }
        else
        {
            printf("Element not found in queue!\n");
        }
    }
}

void traverse(queue *q)
{
    if (q->head == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    node *temp = q->head;
    while (temp != NULL)
    {
        printf("%d (%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    queue q;
    q.head = NULL;

    int choice;

    printf("Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Delete\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data, priority;
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(&q, data, priority);
            break;
        case 2:
            int dequeued_data = dequeue(&q);
            if (dequeued_data != -1)
            {
                printf("Dequeued data: %d\n", dequeued_data);
            }
            break;
        case 3:
            int data_to_delete;
            printf("Enter data to delete: ");
            scanf("%d", &data_to_delete);
            delete (&q, data_to_delete);
            break;
        case 4:
            traverse(&q);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}