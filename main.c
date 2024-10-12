#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to solve the Josephus problem using a circular linked list
int josephus(int n, int m) {
    // Create a circular linked list of size n
    struct Node *head = createNode(1);
    struct Node *prev = head;

    for (int i = 2; i <= n; i++) {
        struct Node* newNode = createNode(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head;  // Make the list circular

    // Iterate and eliminate nodes
    struct Node *ptr = head;
    struct Node *temp;

    while (ptr->next != ptr) {  // Continue until only one node remains
        // Skip m-1 nodes
        for (int i = 1; i < m; i++) {
            prev = ptr;
            ptr = ptr->next;
        }

        // Eliminate the m-th node
        printf("Person %d is eliminated.\n", ptr->data);
        prev->next = ptr->next;  // Remove the node
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    int survivor = ptr->data;  // Last person remaining
    free(ptr);  // Free the last node
    return survivor;
}

int main() {
    int n, m;

    // Separate inputs for number of people and elimination count
    printf("Enter the number of people (n): ");
    scanf("%d", &n);

    printf("Enter the elimination count (m): ");
    scanf("%d", &m);

    // Output: position of the last person
    int survivor = josephus(n, m);
    printf("The person who survives is at position: %d\n", survivor);

    return 0;
}
