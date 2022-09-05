//
// Created by PayThePizzo on 9/4/2022.
//
#include "sorting.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>

using namespace std;

void insertion_sort(int *arr, int size){
    for(int j = 1; j<size; j++){
        int i = j-1, key = *(arr+j);
        while(i>=0 && *(arr+i)> key){
            *(arr+i+1)= *(arr+i);
            i-=1;
        }
        *(arr+i+1)=key;
    }
}

void merge(int arr[], int left, int center, int right){
    int left_size = center - left + 1, right_size = right - center;
    int aux_l[left_size], aux_r[right_size];

    for(int i = 0; i<left_size; i++)
        aux_l[i] = arr[left+i];
    for(int j = 0; j<right_size; j++)
        aux_r[j] = arr[center+1+j];

    int i = 0, j = 0, k = left;

    while(i<left_size && j<right_size) {
        if (aux_l[i] <= aux_r[j]) {
            arr[k] = aux_l[i];
            i++;
        } else {
            arr[k] = aux_r[j];
            j++;
        }
        k++;
    }
    while (i < left_size) {
        arr[k] = aux_l[i];
        i++;
        k++;
    }
    while (j < right_size) {
        arr[k] = aux_r[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right){
    if(left<right){
        int center = left +((right-left)/2);
        merge_sort(arr, left , center);
        merge_sort(arr, center+1, right);
        merge(arr, left, center , right);
    }
}

int myswap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    // pivot is the last element
    int pivot = arr[right];
    // i is the u
    int i = left-1;
    //stop before considering pivot
    for(int j = left; j<right; j++) {
        //only swap elements that <= pivot
        if (arr[j] <= pivot) {
            i++;
            myswap(&arr[i], &arr[j]);
        }
    }
    //move pivot between sub-arrays
    //arr[left ... i]<= pivot < arr[i+2...right]
    myswap(&arr[i+1], &arr[right]);
    //return pivot index
    return i+1;
}

void quick_sort(int arr[], int left, int right){
    if(left < right){
        // Not included inside the sub arrays
        int q = partition(arr, left, right);
        //arr[p...q-1] contains arr[i]<=arr[q]
        quick_sort(arr, left, q-1);
        //arr[p...q-1] contains arr[i]>arr[q]
        quick_sort(arr, q+1, right);
    }
}

/**
 * Return the largest integer inside an array of n elements
 *
 * @param arr input array of integers
 * @param n size of array, n>0
 * @return max integer
 */
int get_max(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++)
        if(max<arr[i])
            max = arr[i];
    return max;
}

/**
 * Returns the smallest integer inside an array of n elements
 *
 * @param arr input array of integers
 * @param n size of array, n>0
 * @return min integer
 */
int get_min(int arr[], int n){
    int min = arr[0];
    for(int i = 0; i<n; i++)
        if(min>arr[i])
            min = arr[i];
    return min;
}

/**
 * Returns count of digits of the largest element inside an array of n integers
 *
 * @param arr input array of integers
 * @param n size of array, n>0
 * @return integer representing the count of digits of the largest element
 */
int max_count_digits(int arr[], int n) {
    return n>0 ? to_string(get_max(arr, n)).size() : 0;
}

/**
 * Traditional Counting Sort for array A of n positive integer values
 *
 * @param A input array
 * @param B output array
 * @param n size of A and B
 * @param max upperbound of integers A[i] in [0...max]
 */
void counting_sort(int A[], int B[], int n, int max){
    int C[max+1];
    for(int i = 0; i<=max; i++)
        C[i]=0;
    for(int i = 0; i<n; i++)
        C[A[i]]++;
    for(int i = 1; i<=max; i++)
        C[i]+=C[i-1];
    for(int i = n-1; i>=0; i--)
        B[--C[A[i]]] = A[i];
}

/**
 * Counting sort that handles negative integers, by finding min and max values and indexing C[A[i]+abs(min)] for occurrences
 *
 * @param A array of integers
 * @param n size of array (n>0)
 */
void counting_sort_range(int A[], int n){
    // Max, Min, Size
    int max = get_max(A, n), min = get_min(A, n), size = abs(max - min) + 1;
    // Aux, Output Vector
    int C[size], B[n];
    // Init Aux
    for (int i = 0; i < size; i++)
        C[i] = 0;
    // Count occurrences
    for (int i = 0; i < n; i++)
        C[A[i] + abs(min)]++;
    // Prefixed Sums
    for (int i = 1; i <= size; i++)
        C[i] += C[i - 1];
    // Actual Sorting
    for (int i = n - 1; i >= 0; i--)
        B[--C[A[i] + abs(min)]] = A[i];
    // Copy B into A
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

/**
 * Radix sort for array of integers
 *
 * @param arr array of n integers
 * @param n size of arr, n>0
 */
void radix_sort(int arr[], int n){
    // Sort positive part of the array [0..max]
    int max = get_max(arr, n), min = get_min(arr, n), d = max_count_digits(arr, n);
    int size = abs(max-min)+1;
    //Array of positive integers
    if(min>=0){
        //Traditional radix sort
        for(int i = 1; i<d; i++){
            counting_sort(arr, int d);
        }
    }else{
        // Split [min ... 0[ and [0 .. max]
        int index = get_last_negative(arr[], n);
        //Sort Positive
        radix_sort(arr, n);
        // Sort negative numbers, for their absolute values

    }
}



int main(){
    int arr[] = {1, 3, -5, 9, -10};
    int size = 5;
    counting_sort_range(arr, size);

    for(int i = 0; i<size; i++){
        cout<< arr[i]<<endl;
    }

    return 0;
}