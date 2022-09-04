#ifndef ASD_SORTING_H
#define ASD_SORTING_H
#include <cmath>

struct Node{
    int key;
    Node *left;
    Node *right;
};


void insertion_sort(int *arr, int size);

void merge(int arr[], int left, int center, int right);

void merge_sort(int arr[], int left, int right);

void heap_sort(int * arr);

void swap(int *a, int *b);

int partition(int arr[], int left, int right);

void quick_sort(int arr[], int left, int right);

/***
 * Implementation of Counting sort, can be modified for negative numbers
 *
 * @param input input array of integers
 * @param output output array of integers, sorted in a non decreasing way
 * @param n size of arr1 and arr2
 * @param k upper bound of integer numbers range [0 to k]
 */
void counting_sort(int *input, int *output, int n, int k);

void radix_sort(int arr[], int d);



#endif //ASD_SORTING_H