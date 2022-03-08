#ifndef ASD_SORTING_H
#define ASD_SORTING_H
#include stdlib.h
#include time.h
#include math.h
#include assert.h
#include stdio.h
#include string.h

void insertionSort(int arr[]);

void mergesort(int arr[], int p, int r);

void merge(int arr[], int p, int q, int r);

void heapSort(int * arr);

void countingsort(int arr1[], int arr2[], int n, int k);

void radixsort(int arr[], int d);

void partition(int arr[], int p, int r);

void randomized_partition(int arr[], int p, int r);

void quicksort(int arr[], int p, int r);

#endif //ASD_SORTING_H