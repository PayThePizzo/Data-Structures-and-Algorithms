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
            swap(&arr[i], &arr[j]);
        }
    }
    //move pivot between sub-arrays
    //arr[left ... i]<= pivot < arr[i+2...right]
    swap(&arr[i+1], &arr[right]);
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

void counting_sort(int *input, int *output, int n, int k){
    int aux[k+1];
    for(int i = 0; i<=k; i++) aux[i]=0;
    for(int i = 0; i<n; i++) aux[*(input+i)]++;
    for(int i = 1; i<=k; i++) aux[i]+=aux[i-1];
    for(int i = n-1; i>=0; i--) *(output+(--aux[(*(input+i))])) = *(input+i);
}

void radix_sort(int arr[], int d){
    for(int i = 0; i<d; i++){
        counting_sort(&arr[0], )
    }
}


void_maxheapify(std::vector<int> heap, Node i){

}

std::vector<int> build_maxheap(std::vector<int> arr){

}


void heap_sort(std::vector<int> arr){
    build_maxheap(arr);
    for(int i = arr.size(); i>=2; i--){
        swap(arr[i], arr[1]);
        arr.size()-=1;
        max_heapify(arr, 1);
    }
}