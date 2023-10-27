#include <stdio.h>

#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 10

void readNames(char names[MAX_NAMES][MAX_NAME_LENGTH], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        // Remove the newline character if it is present
        size_t len = strlen(names[i]);
        if (names[i][len - 1] == '\n') {
            names[i][len - 1] = '\0';
        }
    }
}

void displayNames(char names[MAX_NAMES][MAX_NAME_LENGTH], int n) {
    printf("Names are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

void bubbleSort(char names[MAX_NAMES][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of names (max %d): ", MAX_NAMES);
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input
    
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    readNames(names, n);
    printf("\nBefore Sorting:\n");
    displayNames(names, n);

    bubbleSort(names, n);
    printf("\nAfter Sorting:\n");
    displayNames(names, n);

    return 0;
}