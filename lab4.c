#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bus reservation item
struct BusReservationItem
{
    int seatNumber; // Assume seat number is an integer for simplicity
// You can include other information about the reservation here
    struct BusReservationItem *next;
};

// Structure to represent a bus reservation queue
struct BusReservationQueue
{
    struct BusReservationItem *front;
    struct BusReservationItem *rear;
};

// Function to initialize an empty bus reservation queue
void initializeBusReservationQueue(struct BusReservationQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the bus reservation queue is empty
int isBusReservationQueueEmpty(struct BusReservationQueue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue (add) a reservation to the bus reservation queue
void enqueueBusReservation(struct BusReservationQueue *queue, int seatNumber)
{
// Create a new reservation item
    struct BusReservationItem *newItem = (struct BusReservationItem *)malloc(sizeof(struct BusReservationItem));
    if (!newItem)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newItem->seatNumber = seatNumber;
    newItem->next = NULL;

// If the bus reservation queue is empty, set both front and rear to the new item
    if (isBusReservationQueueEmpty(queue))
    {
        queue->front = newItem;
        queue->rear = newItem;
    }
    else
    {
        // Otherwise, add the new item to the rear and update the rear
        queue->rear->next = newItem;
        queue->rear = newItem;
    }
}

// Function to dequeue (remove) a reservation from the bus reservation queue
int dequeueBusReservation(struct BusReservationQueue *queue)
{
// Check if the bus reservation queue is empty
    if (isBusReservationQueueEmpty(queue))
    {
        fprintf(stderr, "Bus reservation queue is empty\n");
        exit(EXIT_FAILURE);
    }

// Get the seat number of the front reservation item
    int seatNumber = queue->front->seatNumber;

// Move front to the next item
    struct BusReservationItem *temp = queue->front;
    queue->front = queue->front->next;

// If the bus reservation queue becomes empty, update rear to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

// Free the memory of the dequeued reservation item
    free(temp);

    return seatNumber;
}

// Function to display the seat numbers of reservations in the bus reservation queue
void displayBusReservationQueue(struct BusReservationQueue *queue)
{
// Check if the bus reservation queue is empty
    if (isBusReservationQueueEmpty(queue))
    {
        printf("Bus reservation queue is empty\n");
        return;
    }

    printf("Reservations in the bus reservation queue:\n");

// Traverse the bus reservation queue and print the seat number of each reservation
    struct BusReservationItem *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->seatNumber);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    struct BusReservationQueue busReservationQueue;
    initializeBusReservationQueue(&busReservationQueue);

    int choice, seatNumber;

    while (1)
    {
        printf("\nBus Reservation Menu:\n");
        printf("1. Enqueue (Add reservation)\n");
        printf("2. Dequeue (Remove reservation)\n");
        printf("3. Display reservations in the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the seat number for the reservation: ");
            scanf("%d", &seatNumber);
            enqueueBusReservation(&busReservationQueue, seatNumber);
            printf("Reservation enqueued successfully!\n");
            break;
        case 2:
            if (!isBusReservationQueueEmpty(&busReservationQueue))
            {
                seatNumber = dequeueBusReservation(&busReservationQueue);
                printf("Dequeued reservation with seat number: %d\n", seatNumber);
            }
            else
            {
                printf("Bus reservation queue is empty. Cannot dequeue.\n");
            }
            break;
        case 3:
            displayBusReservationQueue(&busReservationQueue);
            break;
        case 4:
            printf("Exiting the Bus Reservation System.\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

