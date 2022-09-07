//
// Created by PayThePizzo on 9/4/2022.
//
#include "sorting.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void print_arr(int arr[], int n){
    for(int i = 0; i<n; i++){
        std::cout<< arr[i] << "\t";
    }
    std::cout<< "\n" << std::endl;
}

// INSERTION SORT +++++++++++++++++++++++++++++++++++

/// Classic Insertionsort
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

// MERGE SORT +++++++++++++++++++++++++++++++++++++++

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

/// Classic Mergesort, right = sizeof(arr)-1
void merge_sort(int arr[], int left, int right){
    if(left<right){
        int center = left +((right-left)/2);
        merge_sort(arr, left , center);
        merge_sort(arr, center+1, right);
        merge(arr, left, center , right);
    }
}

// QUICK SORT +++++++++++++++++++++++++++++++++++++++

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
            std::swap(arr[i], arr[j]);
        }
    }
    //move pivot between sub-arrays
    //arr[left ... i]<= pivot < arr[i+2...right]
    std::swap(arr[i+1], arr[right]);
    //return pivot index
    return i+1;
}

/// Classic Quicksort
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

// HEAP SORT +++++++++++++++++++++++++++++++++++++++

void max_heapify(int arr[], int n, int index){
    int left_index = (index*2)+1;
    int right_index = (index*2)+2;
    int max_index = index;

    if(left_index < n && arr[left_index] > arr[max_index])
        max_index = left_index;

    if(right_index < n && arr[right_index] > arr[max_index])
        max_index = right_index;

    if(max_index != index){
        std::swap(arr[index], arr[max_index]);
        max_heapify(arr, n, max_index);
    }
}

void build_max_heap(int arr[], int n){
    for(int i = (n-1)/2; i >=0; i--)
        max_heapify(arr, n, i);
}

/// Classic Heapsort for Max Heap
void heapsort(int arr[], int n){
    build_max_heap(arr, n);
    for(int i = n-1; i>=0; i--){
        std::swap(arr[i], arr[0]);
        max_heapify(arr, i , 0);
    }
}

// COUNTING SORT +++++++++++++++++++++++++++++++++++++++

/// Returns largest integer inside the array
int get_max(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++)
        if(max<arr[i])
            max = arr[i];
    return max;
}

/// Returns the smallest integer inside the array
int get_min(int arr[], int n){
    int min = arr[0];
    for(int i = 0; i<n; i++)
        if(min>arr[i])
            min = arr[i];
    return min;
}

/**
 * Returns count of digits of the element which satisfies the condition of the function
 *
 * @param arr input array of integers
 * @param n size of array, n>0
 * @return count of digits
 */
int max_count_digits(int arr[], int n) {
    return n>0 ? to_string(get_max(arr, n)).size() : 0;
}

/// Classic counting sort
void counting_sort(int A[], int B[], int n, int max){
    int C[max+1];
    for(int i = 0; i<=max; i++) //Init
        C[i]=0;
    for(int i = 0; i<n; i++)    //Occurrences
        C[A[i]]++;
    for(int i = 1; i<=max; i++) //Pre Fixed Sums
        C[i]+=C[i-1];
    for(int i = n-1; i>=0; i--) //Sorting
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
    for (int i = 0; i < size; i++)  //Init
        C[i] = 0;
    for (int i = 0; i < n; i++)     //Occurrences
        C[A[i] + abs(min)]++;
    for (int i = 1; i <= size; i++) // Prefixed Sums
        C[i] += C[i - 1];
    for (int i = n - 1; i >= 0; i--)//Sorting
        B[--C[A[i] + abs(min)]] = A[i];
    for (int i = 0; i < n; i++)     // Copy B into A
        A[i] = B[i];
}

// RADIX SORT +++++++++++++++++++++++++++++++++++++++

void counting_sort_exp(int A[], int n, int exp){
    int max = 10, C[max], B[n];
    for(int i=0; i<n; i++)
        C[i]=0;
    for(int i=0; i<n; i++)
        C[(A[i]/exp)%10]++;
    for(int i=1; i<max; i++)
        C[i]+=C[i-1];
    for(int i=0; i<n; i++)
        B[--C[(A[i]/exp)%10]]= A[i];
    for(int i=0; i<n; i++)
        A[i]=B[i];
}

/// Classic radix sort
void radix_sort(int arr[], int n){
    int max = get_max(arr, n);
    for (int exp = 1; max/exp >0; exp*=10) {
        counting_sort_exp(arr, n, exp);
    }
}

/**
 * Radix sort for array of integers
 *
 * @param arr array of n integers
 * @param n size of arr, n>0
 */
void radix_sort_gen(int arr[], int n) {

    int aux[n]; //Divides positive from negative
    for(int i=0; i<n; i++){
        int j = n-1-i;
        if(arr[i]>=0){
            aux[j]=arr[i];
        }else{
            aux[i]=arr[i];
        }
    }

    int pos_begin = 0; //Find first positive value
    while(aux[pos_begin]<0){
        pos_begin++;
    }

    // Transform negative into positive
    for(int i=0; i<pos_begin; i++){
        aux[i] = abs(aux[i]);
    }

    //Apply radix_sort on first part



    //Array of positive integers
    if (min >= 0) {
        //Traditional radix sort
        radix_sort(arr, n);
    } else {
        // Split [min ... 0[ and [0 .. max]
        int index = get_last_negative(arr[], n);
        //Sort Positive
        radix_sort(arr, n);
        // Sort negative numbers, for their absolute values

    }


}


int main(){
    int arr[] = {1, 3, -5, 9, -10, -10, 9};
    int arr1[] = {1, 3, 5, 9, 10, 5, 1};
    int arr2[] = {20, 10, 19, 18, 1 , -5 , 7};
    int size = 7;

    print_arr(arr, size);
    insertion_sort(arr, size);
    print_arr(arr, size);

    return 0;
}