#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bus {
    int id;
    char route[100];
    int available_seats;

};

int linear_search(struct Bus arr[], int n, int target, int *comparisons) {
	int i;
    for (i = 0; i < n; ++i) {
        (*comparisons)++;
        if (arr[i].id == target) {
            return i;
        }
    }
    return -1;
}

int sentinel_search(struct Bus arr[], int n, int target, int *comparisons) {
    int last_id = arr[n - 1].id;
    arr[n - 1].id = target;

    int i = 0;
    while (arr[i].id != target) {
        (*comparisons)++;
        i++;
    }

    arr[n - 1].id = last_id;

    if (i < n - 1 || arr[n - 1].id == target) {
        return i;
    } else {
        return -1;
    }
}

int binary_search(struct Bus arr[], int n, int target, int *comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        (*comparisons)++;
        int mid = (low + high) / 2;

        if (arr[mid].id == target) {
            return mid;
        } else if (arr[mid].id < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void bubble_sort(struct Bus arr[], int n, int *element_comparisons, int *data_transfers) {
	int i,j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            (*element_comparisons)++;
            if (arr[j].id > arr[j + 1].id) {
            
                struct Bus temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                (*data_transfers)++;
            }
        }
    }
}

void insertion_sort(struct Bus arr[], int n, int *element_comparisons, int *data_transfers) {
	int i;
    for (i = 1; i < n; ++i) {
        struct Bus key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].id > key.id) {
            (*element_comparisons)++;
            
            arr[j + 1] = arr[j];

            (*data_transfers)++;
            j--;
        }

        arr[j + 1] = key;
        (*data_transfers)++;
    }
}
#define n 5
void main() {
//    const int n = 5; 

    struct Bus buses[n] = {
        {501, "Route A", 50},
        {503, "Route B", 30},
        {502, "Route C", 40},
        {505, "Route D", 60},
        {504, "Route E", 45}
    };

    int target_id = 503;

    
    int linear_index, linear_comparisons = 0;
    linear_index = linear_search(buses, n, target_id, &linear_comparisons);
    printf("Linear Search: Bus found at index %d with %d element comparisons\n", linear_index, linear_comparisons);

    
    int bubble_element_comparisons = 0, bubble_data_transfers = 0;
    bubble_sort(buses, n, &bubble_element_comparisons, &bubble_data_transfers);
    printf("Bubble Sort: %d element comparisons, %d data transfers\n", bubble_element_comparisons, bubble_data_transfers);

    
    int binary_index, binary_comparisons = 0;
    binary_index = binary_search(buses, n, target_id, &binary_comparisons);
    printf("Binary Search: Bus found at index %d with %d element comparisons\n", binary_index, binary_comparisons);

    
    int sentinel_index, sentinel_comparisons = 0;
    sentinel_index = sentinel_search(buses, n, target_id, &sentinel_comparisons);
    printf("Sentinel Search: Bus found at index %d with %d element comparisons\n", sentinel_index, sentinel_comparisons);

    
    int insertion_element_comparisons = 0, insertion_data_transfers = 0;
    insertion_sort(buses, n, &insertion_element_comparisons, &insertion_data_transfers);
    printf("Insertion Sort: %d element comparisons, %d data transfers\n",insertion_element_comparisons, insertion_data_transfers);

}
