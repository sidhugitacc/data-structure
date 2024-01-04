#include <stdio.h>
#include <stdlib.h>

struct Bus {
    int bus_id;
    float departure_time;
    float fare;
};

int mergeSortComparisons = 0;
int mergeSortDataTransfers = 0;
int quickSortComparisons = 0;
int quickSortDataTransfers = 0;

void merge(struct Bus arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Bus L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        mergeSortDataTransfers++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        mergeSortDataTransfers++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        mergeSortComparisons++;
        if (L[i].departure_time <= R[j].departure_time) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        mergeSortDataTransfers++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        mergeSortDataTransfers++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        mergeSortDataTransfers++;
    }
}

void mergeSort(struct Bus arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void swap(struct Bus *a, struct Bus *b) {
    struct Bus temp = *a;
    *a = *b;
    *b = temp;
    quickSortDataTransfers += 3;  
}

int partition(struct Bus arr[], int low, int high) {
    float pivot = arr[high].fare;//pivot element is taken as the last element
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) {
        quickSortComparisons++;
        if (arr[j].fare < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Bus arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void readFromFile(struct Bus arr[], int n, const char *filename) {
    int i;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        fscanf(file, "%d %f %f", &arr[i].bus_id, &arr[i].departure_time, &arr[i].fare);
    }

    fclose(file);
}

void writeToFile(struct Bus arr[], int n, const char *filename) {
    int i;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        fprintf(file, "%d %.2f %.2f\n", arr[i].bus_id, arr[i].departure_time, arr[i].fare);
    }

    fclose(file);
}

int main() {
    int n, i;
    printf("Enter the number of buses: ");
    scanf("%d", &n);

    struct Bus buses[n];

    for (i = 0; i < n; i++) {
        buses[i].bus_id = i + 1;
        buses[i].departure_time = (float)rand() / RAND_MAX * 24;  
        buses[i].fare = (float)rand() / RAND_MAX * 1000;          
    }

    writeToFile(buses, n, "unsorted_buses.txt");

    readFromFile(buses, n, "unsorted_buses.txt");

    mergeSort(buses, 0, n - 1);

    printf("Merge Sort Comparisons: %d\n", mergeSortComparisons);
    printf("Merge Sort Data Transfers: %d\n", mergeSortDataTransfers);
    mergeSortComparisons = 0;
    mergeSortDataTransfers = 0;

    writeToFile(buses, n, "merge_sorted_buses.txt");

    readFromFile(buses, n, "unsorted_buses.txt");

    quickSort(buses, 0, n - 1);

    printf("Quick Sort Comparisons: %d\n", quickSortComparisons);
    printf("Quick Sort Data Transfers: %d\n", quickSortDataTransfers);
    quickSortComparisons = 0;
    quickSortDataTransfers = 0;

    writeToFile(buses, n, "quick_sorted_buses.txt");

    return 0;
}
