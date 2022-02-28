#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <string.h>


void merge(int* a, int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *l, *r; //temporary arrays

    l = malloc(sizeof(int) * (n1 + 1));
    r = malloc(sizeof(int) * (n2 + 1));

    l[n1] = r[n2] = INT_MAX;

    /* copy data to temp arrays */
    for (i = 0; i < n1; i++)
        l[i] = a[low + i];
    for (j = 0; j < n2; j++)
        r[j] = a[mid + 1 + j];

    for (k = low, i = j = 0; k <= high; k++)
    {
        if (l[i] < r[j])
        {
            a[k] = l[i++];
        }
        else
        {
            a[k] = r[j++];
        }
    }

    free(l);
    free(r);
}

void mergesort(int* a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


void populatearray(int *a , int dim){
    int i;
    srand(time(NULL));
    for(i=0;i<dim;i++){
        int n = rand();
        a[i] = n % 1024;
    }
}

int main(){
    int *a;
    int l;
    
    l = 20;
    a = malloc(sizeof(int) * l);
    populatearray(a, l);
    for(int i = 0 ; i < l ; i++){
        printf("%d ", *(a+i));
 
    }
    printf("\n");

    mergeSort(a,0, l-1);

    for(int i = 0 ; i < l ; i++){
        printf("%d ", *(a+i));
 
    }
    printf("\n");
    free(a);
    return 0;
}