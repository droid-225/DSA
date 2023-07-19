#include <stdio.h>
#include <math.h>

void sort(int [],int); /*selection sort*/

void display(int list[10], int n) {
    int i;
    for (i = 0; i < n; i++) { 
        printf("%d ", list[i]);
    }
    printf("\n") ;
}

void main(void) {
    int i,n = 10;    
    int list[10];

    for (i = 0; i < n; i++) { /*randomly generate numbers */
        list[i] = rand() % 100;
        printf ("%d ", list[i]);
    }
    printf("\n");

    sort(list, n);
    printf("\nSorted array:\n");
    display(list, n); /* print out sorted numbers */
}

void sort(int list[],int n) {
    int i, j, min, temp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(list[j] < list[min]) {
                min = j;
                temp = list[i];
                list[i] = list[min];
                list[min] = temp;
            }
        display(list, n);
        }
    }
}
