#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createLinkedList() {
    int n, data;
    struct Node* newNode;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displayLinkedList() {
    struct Node* current = head;
    
    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void insertInMiddle(int data, int position) {
    if (position < 1) {
        printf("Invalid position for insertion.\n");
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    struct Node* current = head;
    int count = 1;
    
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    
    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        return;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirstNode() {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteLastNode() {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    
    if (head->data == data) {
        deleteFirstNode();
        return;
    }
    
    struct Node* current = head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Element not found in the linked list.\n");
        return;
    }
    
    prev->next = current->next;
    free(current);
}

int search(int data) {
    struct Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1; 
}

int main() {
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a Single Linked List\n");
        printf("2. Display the Linked List\n");
        printf("3. Insert a New Node at the Beginning\n");
        printf("4. Insert a New Node at the End\n");
        printf("5. Insert a Node in the Middle\n");
        printf("6. Delete the First Node\n");
        printf("7. Delete a Node from the Middle\n");
        printf("8. Delete the Last Node\n");
        printf("9. Search for an Existing Element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createLinkedList();
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position for insertion: ");
                scanf("%d", &position);
                insertInMiddle(data, position);
                break;
            case 6:
                deleteFirstNode();
                break;
            case 7:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 8:
                deleteLastNode();
                break;
            case 9:
                printf("Enter data to search: ");
                scanf("%d", &data);
                position = search(data);
                if (position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found in the linked list.\n");
                }
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}