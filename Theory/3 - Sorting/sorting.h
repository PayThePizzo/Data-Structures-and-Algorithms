//
// Created by PayThePizzo on 3/21/2023.
//

#ifndef ASD_SORTING_H
#define ASD_SORTING_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
#include <bits/stdc++.h>

/**
 * Prints array
 *
 * @param arr integer array
 * @param n upperbound or length
 */
void print_arr(int arr[], int n);

/**
 * Prints integer vector
 *
 * @param arr integer vector
 */
void print_vec(std::vector<int> arr);

// +++++++++++++++++++++++++++++++++++++++++++++++
// INSERTION SORT

/**
 * Classic Insertionsort - C style
 *
 * @param arr integer array
 * @param size upperbound, length
 */
void insertion_sort(int *arr, int size);

/**
 * Classic Insertionsort - C++ style
 *
 * @param array integer vector
 */
void insertion_sort_cpp(std::vector<int> &array);

// +++++++++++++++++++++++++++++++++++++++++++++++
// MERGE SORT

/**
 * Auxiliary function for Mergesort
 *
 * @param arr
 * @param left
 * @param center
 * @param right
 */
void merge(int arr[], int left, int center, int right);

/**
 * Classic Mergesort
 *
 * @param arr integer array
 * @param left
 * @param right sizeof(arr)-1
 */
void merge_sort(int arr[], int left, int right);

// +++++++++++++++++++++++++++++++++++++++++++++++
// QUICK SORT

int partition(int arr[], int left, int right);

/**
 * Classic Quicksort
 *
 * @param arr
 * @param left
 * @param right
 */
void quick_sort(int arr[], int left, int right);

// +++++++++++++++++++++++++++++++++++++++++++++++
// HEAP SORT FOR MAX HEAP

void max_heapify(int arr[], int n, int index);

void build_max_heap(int arr[], int n);

/**
 * Classic Heapsort for Max Heap
 *
 * @param arr
 * @param n
 */
void heapsort(int arr[], int n);

// +++++++++++++++++++++++++++++++++++++++++++++++
// COUNTING SORT

/**
 * Largest key getter for integer arrays of size n
 *
 * @param arr integer array
 * @param n size of the array
 * @return the largest integer inside the array
 */
int get_max(int arr[], int n);

/**
 * Smallest key getter for integer arrays of size n
 *
 * @param arr integer array
 * @param n size of the array
 * @return the smallest integer inside the array
 */
int get_min(int arr[], int n);

/**
 * Returns count of digits of the element which satisfies the condition of the function
 *
 * @param arr input array of integers
 * @param n size of array, n>0
 * @return count of digits
 */
int max_count_digits(int arr[], int n);

/**
 * Classic Countingsort
 *
 * @param A
 * @param B
 * @param n
 * @param max
 */
void counting_sort(int A[], int B[], int n, int max);

/**
 * Counting sort that handles negative integers, by finding min and max values and indexing C[A[i]+abs(min)] for occurrences
 *
 * @param A array of integers
 * @param n size of array (n>0)
 */
void counting_sort_range(int A[], int n);

// +++++++++++++++++++++++++++++++++++++++++++++++
// RADIX SORT

void counting_sort_exp(int A[], int n, int exp);

/**
 * Classic Radixsort with Countisort Exp
 *
 * @param arr
 * @param n
 */
void radix_sort(int arr[], int n);

#endif //ASD_SORTING_H
