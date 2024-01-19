#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bus {
    char busNumber[10];
    int totalSeats;
    int availableSeats;
    struct Bus* left;
    struct Bus* right;
} Bus;

Bus* createBus(char busNumber[], int totalSeats) {
    Bus* newBus = (Bus*)malloc(sizeof(Bus));
    strcpy(newBus->busNumber, busNumber);
    newBus->totalSeats = totalSeats;
    newBus->availableSeats = totalSeats;
    newBus->left = NULL;
    newBus->right = NULL;
    return newBus;
}

void breadthFirstTraversal(Bus* root) {
    if (root == NULL)
        return;

    Bus* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        Bus* currentBus = queue[++front];
        printf("Bus Number: %s, Available Seats: %d/%d\n", currentBus->busNumber, currentBus->availableSeats, currentBus->totalSeats);

        if (currentBus->left != NULL)
            queue[++rear] = currentBus->left;
        if (currentBus->right != NULL)
            queue[++rear] = currentBus->right;
    }
}

void depthFirstTraversal(Bus* root) {
    if (root == NULL)
        return;

    depthFirstTraversal(root->left);
    printf("Bus Number: %s, Available Seats: %d/%d\n", root->busNumber, root->availableSeats, root->totalSeats);
    depthFirstTraversal(root->right);
}

int main() {
    Bus* root = createBus("BusA", 50);
    root->left = createBus("BusB", 40);
    root->right = createBus("BusC", 30);
    root->left->left = createBus("BusD", 20);
    root->left->right = createBus("BusE", 15);
    root->right->left = createBus("BusF", 25);
    root->right->right = createBus("BusG", 35);

    int choice;

    do {
        printf("\nBus Reservation System Menu\n");
        printf("1. Breadth-First Traversal\n");
        printf("2. Depth-First Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Breadth-First Traversal:\n");
                breadthFirstTraversal(root);
                break;
            case 2:
                printf("Depth-First Traversal:\n");
                depthFirstTraversal(root);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

