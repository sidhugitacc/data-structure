#include <stdio.h>
int i;

void read(int *array, int n) {
    printf("enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n) {
    printf("numbers are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void oddplay(int *array, int n) {
    printf("numbers are: ");
    for(i = 0; i < n; i+2) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void displayEvenNumbers(int *array, int n) {
    printf("Even numbers are: ");
    for(i = 0; i < n; i++) {
        if(array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int maxnum (int *array, int n) {
    int temp = array[0];
    for(i = 1; i < n; i++) {
        if(array[i] > temp) {
            temp = array[i];
        }
    }
    return temp;
}
void calculateSumAndAverage(int *array, int n, int *sum, float *average) {
    *sum = 0;
    for(i = 0; i < n; i++) {
        *sum += array[i];
    }
    *average = (float)*sum / n;
}


int main()
{
	    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

  
    int array[n];
    read(array, n);
    display(array, n);
    oddplay(array, n);
    displayEvenNumbers(array, n);

    int max = maxnum(array, n);
    printf("Maximum number is: %d\n", max);

    int sum;
    float average;
    calculateSumAndAverage(array, n, &sum, &average);
    printf("Sum is: %d\n", sum);
    printf("Average is: %.2f\n", average);

    return 0;
}
