#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

struct Reservation {
    int reservationID;
    char passengerName[50];
    int seatNumber;
    struct Reservation* next;
    struct Reservation* prev; 
};

struct Reservation* createReservation(int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = (struct Reservation*)malloc(sizeof(struct Reservation));
    if (newReservation != NULL) {
        newReservation->reservationID = reservationID;
        strncpy(newReservation->passengerName, passengerName, sizeof(newReservation->passengerName) - 1);
        newReservation->seatNumber = seatNumber;
        newReservation->next = NULL;
        newReservation->prev = NULL;
    }
    return newReservation;
}

struct Reservation* insertSingle(struct Reservation* head, int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = createReservation(reservationID, passengerName, seatNumber);
    if (newReservation != NULL) {
        newReservation->next = head;
        head = newReservation;
    }
    return head;
}
struct Reservation* insertEndSingle(struct Reservation* head, int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = createReservation(reservationID, passengerName, seatNumber);
    if (newReservation != NULL) {
        if (head == NULL) {
            head = newReservation;
        } else {
            struct Reservation* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newReservation;
        }
    }
    return head;
}
struct Reservation* insertDouble(struct Reservation* head, int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = createReservation(reservationID, passengerName, seatNumber);
    if (newReservation != NULL) {
        newReservation->next = head;
        if (head != NULL) {
            head->prev = newReservation;
        }
        head = newReservation;
    }
    return head;
}
struct Reservation* insertEndDouble(struct Reservation* head, int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = createReservation(reservationID, passengerName, seatNumber);
    if (newReservation != NULL) {
        if (head == NULL) {
            head = newReservation;
        } else {
            struct Reservation* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newReservation;
            newReservation->prev = current;
        }
    }
    return head;
}

struct Reservation* insertCircular(struct Reservation* head, int reservationID, const char* passengerName, int seatNumber) {
    struct Reservation* newReservation = createReservation(reservationID, passengerName, seatNumber);
    if (newReservation != NULL) {
        if (head == NULL) {
            head = newReservation;
            head->next = head;
        } else {
            struct Reservation* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newReservation;
            newReservation->next = head; 
        }
    }
    return head;
}

struct Reservation* deleteSingle(struct Reservation* head, int reservationID) {
    struct Reservation* current = head;
    struct Reservation* prev = NULL;

    while (current != NULL && current->reservationID != reservationID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Reservation with ID %d not found in Single Linked List.\n", reservationID);
        return head;
    }
	if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Reservation with ID %d deleted from Single Linked List.\n", reservationID);
    return head;
}
struct Reservation* deleteDouble(struct Reservation* head, int reservationID) {
    struct Reservation* current = head;

    while (current != NULL && current->reservationID != reservationID) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Reservation with ID %d not found in Double Linked List.\n", reservationID);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Reservation with ID %d deleted from Double Linked List.\n", reservationID);
    return head;
}
struct Reservation* deleteCircular(struct Reservation* head, int reservationID) {
    struct Reservation* current = head;
    struct Reservation* prev = NULL;

    while (current != NULL && current->reservationID != reservationID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Reservation with ID %d not found in Circular Linked List.\n", reservationID);
        return head;
    }

    if (current->next == current) {
        free(current);
        head = NULL;
    } else {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            head = current->next;
            while (prev->next != current) {
                prev = prev->next;
            }
            prev->next = head;
        }

        free(current);
    }

    printf("Reservation with ID %d deleted from Circular Linked List.\n", reservationID);
    return head;
}
void displayList(struct Reservation* head) {
    struct Reservation* current = head;
    printf("Reservation List:\n");
    while (current != NULL) {
        printf("ID: %d, Passenger Name: %s, Seat Number: %d\n", current->reservationID, current->passengerName, current->seatNumber);
        current = current->next;
    }
    printf("\n");
}
void displayCircularList(struct Reservation* head) {
    if (head == NULL) {
        printf("Circular List is empty.\n");
        return;
    }

    struct Reservation* current = head;
    printf("Reservation Circular List:\n");
    do {
        printf("ID: %d, Passenger Name: %s, Seat Number: %d\n", current->reservationID, current->passengerName, current->seatNumber);
        current = current->next;
    } while (current != head);
    printf("\n");
}
void freeList(struct Reservation* head) {
    struct Reservation* current = head;
    while (current != NULL) {
        struct Reservation* temp = current;
        current = current->next;
        free(temp);
    }
}

void main() {
    struct Reservation* singleList = NULL;
    struct Reservation* doubleList = NULL;
    struct Reservation* circularList = NULL;
    int choice;
    int reservationID;
    char passengerName[50];
    int seatNumber;

    do {
        printf("\nBus Reservation Menu:\n");
        printf("1. Insert into Single Linked List\n");
        printf("2. Insert into Double Linked List\n");
        printf("3. Insert into Circular Linked List\n");
        printf("4. Delete from Single Linked List\n");
        printf("5. Delete from Double Linked List\n");
        printf("6. Delete from Circular Linked List\n");
        printf("7. Display Single Linked List\n");
        printf("8. Display Double Linked List\n");
        printf("9. Display Circular Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Reservation ID: ");
                scanf("%d", &reservationID);
                printf("Passenger Name: ");
                scanf("%s", passengerName);
                printf("Seat Number: ");
                scanf("%d", &seatNumber);
                singleList = insertSingle(singleList, reservationID, passengerName, seatNumber);
                break;
            case 2:
                printf("Reservation ID: ");
                scanf("%d", &reservationID);
                printf("Passenger Name: ");
                scanf("%s", passengerName);
                printf("Seat Number: ");
                scanf("%d", &seatNumber);
                doubleList = insertDouble(doubleList, reservationID, passengerName, seatNumber);
                break;
            case 3:
                printf("Reservation ID: ");
                scanf("%d", &reservationID);
                printf("Passenger Name: ");
                scanf("%s", passengerName);
                printf("Seat Number: ");
                scanf("%d", &seatNumber);
                circularList = insertCircular(circularList, reservationID, passengerName, seatNumber);
                break;
            case 4:
                printf("Enter Reservation ID to delete from Single Linked List: ");
                scanf("%d", &reservationID);
                singleList = deleteSingle(singleList, reservationID);
                break;
            case 5:
                printf("Enter Reservation ID to delete from Double Linked List: ");
                scanf("%d", &reservationID);
                doubleList = deleteDouble(doubleList, reservationID);
                break;
            case 6:
                printf("Enter Reservation ID to delete from Circular Linked List: ");
                scanf("%d", &reservationID);
                circularList = deleteCircular(circularList, reservationID);
                break;
            case 7:
                displayList(singleList);
                break;
            case 8:
                displayList(doubleList);
                break;
            case 9:
                displayCircularList(circularList);
                break;
            case 0:
                freeList(singleList);
                freeList(doubleList);
                freeList(circularList);
                printf("Exiting Bus Reservation System.\n");
                break;
            default:
                printf("Enter a valid option.\n");
        }
    } while(choice != 0);

}
