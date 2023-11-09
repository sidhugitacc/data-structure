#include<stdio.h>
#include<stdlib.h>

struct busBooking
{
	int seatNumber;
    char isBooked;
    char passengerName[50];
    char departure[50];
    char destination[50];
    char departureTime[10];
    char arrivalTime[10];
    int fare;
};


int linearSearch(struct busBooking b[], int length, int key) {
	int i;
    for (i = 0; i < length; i++) {
        if (b[i].seatNumber == key) {
            return i; 
        }
    }
    return -1;
}


void insertRecord(struct busBooking b[], int length) {
    if (length >= 5) {
        printf("The array is full. Cannot insert more records.\n");
        return;
    }

    printf("Enter the details for the new record:\n");
    printf("Enter seat number: ");
    scanf("%d", &b[length].seatNumber);
    printf("Enter if seat is confirmed y-yes n-no: ");
    scanf(" %c", &b[length].isBooked);
    printf("Enter passenger name: ");
    scanf("%s", b[length].passengerName);
    printf("Enter place of departure: ");
    scanf("%s", b[length].departure);
    printf("Enter place of destination: ");
    scanf("%s", b[length].destination);
    printf("Enter departure time: ");
    scanf("%s", b[length].departureTime);
    printf("Enter arrival time: ");
    scanf("%s", b[length].arrivalTime);
    printf("Enter bus fare: ");
    scanf("%d", &b[length].fare);
}

void sortBySeatNumber(struct busBooking b[], int n) {
	int i,j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (b[j].seatNumber > b[j + 1].seatNumber) {
        struct busBooking temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
      }
    }
  }
}

void disptable(struct busBooking b[], int n)
{
	    int i;
		printf("\tSeatNumber IsBooked   PassengerName   Departure    Destination   DepartureTime   ArrivalTime    Fare");
		 for(i=0;i<n;i++)
		 {
		 	
		    printf("\n\t\t%d\t %c \t%s\t\t %s\t %s\t\t %s\t\t %s\t %d",b[i].seatNumber,b[i].isBooked,b[i].passengerName,b[i].departure,b[i].destination,b[i].departureTime,b[i].arrivalTime,b[i].fare);
		}
}
void deleteRecord(struct busBooking b[], int *length, int key) {
    int deleteIndex = linearSearch(b, *length, key);
    int i;

    if (deleteIndex != -1) {
        for ( i = deleteIndex; i < *length - 1; i++) {
            b[i] = b[i + 1];
        }
        (*length)--;
        printf("Record with seat number %d deleted successfully.\n", key);
    } else {
        printf("Seat number %d not found. Deletion failed.\n", key);
    }
}

void main()
{
	struct busBooking b[5];
	int i,j,ch,ch1,c,c1;
	int extractedIntegers[5][4], sum[5][2], prod[5][2];
	int deleteIndex,len;
	int key, searchIndex,n;
	
	menu:
	do
	{
	printf("\n------------------------------------------------------------------");
	printf("\nCHOOSE ");
	printf("\n1. INSERT RECORDS");
	printf("\n2. DISPLAY THE TABLE");
	printf("\n3. DISPLAY THE 2D ARRAY");
	printf("\n4. LINEAR SEARCH");
	printf("\n5. DELETION");
	printf("\n6. INSERTION");
	printf("\n7.EXIT\n");
	printf("------------------------------------------------------------------\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
	case 1:
	printf("Enter the number of records :\t");
    scanf("%d",&n);
	for(i=0;i<n;i++)
	{ 
	    printf("\n\t\t--------------------PASSENGER %d-------------------------------",i+1);
		printf("\n\nEnter seat number :");
		scanf("%d",&b[i].seatNumber);
		printf("Enter if seat is confirmed y-yes n-no :");
		scanf(" %c",&b[i].isBooked);
		printf("Enter passenger name :");
		scanf("%s",&b[i].passengerName);
		printf("Enter place of departure :");
		scanf("%s",&b[i].departure);
		printf("Enter place of detination :");
		scanf("%s",&b[i].destination);
		printf("Enter departure time :");
		scanf("%s",&b[i].departureTime);
		printf("Enter arrival time :");
		scanf("%s",&b[i].arrivalTime);
		printf("Enter bus fare :");
		scanf("%d",&b[i].fare);
		
	     extractedIntegers[i][0] = b[i].seatNumber;
         extractedIntegers[i][1] = b[i].fare;
    }
    break;
    
    case 2:
        disptable(b,n);
		break;
		
    case 3:
        printf("\n2D Array of Extracted Integers:\n");
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",extractedIntegers[i][0],extractedIntegers[i][1]);
    }
    
    do
    {
    printf("\n------------------------------------------------------------------\n");
    printf("\nCHOOSE:");
    printf("\n11. MATRIX ADDITION");
    printf("\n22. MATRIX SUBTRACTION");
    printf("\n33. GO BACK\n");
    printf("------------------------------------------------------------------\n");
    scanf("%d",&ch1);
     switch(ch1)
     {
    case 11:
	    for(i = 0; i < n; i++)
	    {
	        for(j = 0; j < 2; j++)
	        {
	            sum[i][j] = extractedIntegers[i][j] + extractedIntegers[i][j];
	            prod[i][j]= extractedIntegers[i][j] - extractedIntegers[i][j];
	        }
	    }
	
	    printf("\nMatrix Additon\n");
	    for(i = 0; i < n; i++)
	    {
	        for(j = 0; j < 2; j++)
	        {
	            printf("%d ", sum[i][j]);
	            
	            if(j == 1)
	                printf("\n");
	        }
	    }
	    break;
    
    
    case 22:
        printf("\nMatrix Subtraction\n");
	    for(i = 0; i < n; i++)
	    {
	        for(j = 0; j < 2; j++)
	        {
	            printf("%d ", prod[i][j]);
	            
	            if(j == 1)
	                printf("\n");
	        }
	    }
	    break;
	case 33:
		goto menu;
	}
    printf("\n\nENTER 1-CONTINUE\t :");
	scanf("%d",&c1);
    }while(c1==1);
	break;
	
	
	case 4:
	    
	 
	    printf("\nEnter the seat number to be searched: ");
	    scanf("%d", &key);
	    searchIndex = linearSearch(b, n, key);
	    if (searchIndex != -1) {
	        printf("Seat number %d found at index %d.\n", key, searchIndex);
	        printf("DETAILS OF SEAT NO. %d\n",key);
	        printf("\nSeat No. : %d\n IsBooked : %c\nPassengerName : %s\n Departure : %s\n Destination : %s\n Departure Time : %s\n Arrival Time : %s\n Fare :%d\n",b[searchIndex].seatNumber,b[searchIndex].isBooked,b[searchIndex].passengerName,b[searchIndex].departure,b[searchIndex].destination,b[searchIndex].departureTime,b[searchIndex].arrivalTime,b[searchIndex].fare);
	    } else {
	        printf("Seat number %d not found.\n", key);
	    }
	    break;
    	
    case 5: 
               printf("\nEnter the seat number to be deleted: ");
                scanf("%d", &key);
                deleteRecord(b, &n, key);
                disptable(b, n);
                break;
	      
    case 6:
    	insertRecord(b, n); 
	    printf("Record inserted successfully.\n");
	    disptable(b,n+1);
	    break;
	case 7:
		exit(0);
}
	printf("\n\nENTER 1-CONTINUE, 0-EXIT \t :");
	scanf("%d",&c);
}while(c==1);

}



