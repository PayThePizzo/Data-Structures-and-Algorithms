//
// Created by PayThePizzo on 9/5/2022.
//

#include "iostream"
#include "cmath"
#include "stdlib.h"
#include "vector"
#include <bits/stdc++.h>>
#include <functional>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/***
 * Returns the global min difference of all
 *
 * @param punteggi array of integers
 * @param n size of arr, must be even
 * @return
 */
int scarto_cpp(std::vector<int> v, int n){
    //Even by assumption
    if(n>=2){
        //Automatically sorts input
        //Logarithmic insertion and extraction
        priority_queue<int, vector<int>, greater<int>> minPQ(v.begin(), v.end());
        int sum = 0;
        while(!minPQ.empty()){
            int first = minPQ.top();
            minPQ.pop();
            int second = minPQ.top();
            minPQ.pop();
            sum+=abs(first-second);
        }
        return sum;
    }
    return 0;
}
// T(n) = O(nlog(n))
// n< 2 --> O(1)
// n>=2 --> Theta(nlog(n)) + Theta(n/2 * 2log(n)) = Theta(nlog(n))

int scarto_c(int punteggi[], int n){
    if(n>=2){
        //Sort input non decreasing way


        int sum = 0, i = 0;
        while(i<n){
            sum+= abs(punteggi[i]-punteggi[i+1]);
            i+=2;
        }
        return sum;
    }
    return 0;
}


void swap(int *a, int *b){
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

int triplo(int arr[], int n, int *x, int *y){
    int i, j, stop;
    quick_sort(arr, 0, n-1);
    i = j = stop = 0;
    while(!stop && j<n){
        if(arr[j]<arr[i]*3){
            j++;
        }else if(arr[j]==arr[i]*3){
            stop = 1;
            *x = i;
            *y = j;
        }else{
            i++;
        }
    }
    return stop;
}


int main(){
    int arr[] = {0, 2, 3, -4  };
    std::vector<int>v = {0 , 2 , 3, -4};
    int n = 4;

//    quick_sort(arr, 0, n-1);
//    for(int i = 0; i<n ; i++){
//        cout<< arr[i] << endl;
//    }

    int minimo = scarto_cpp(v, n);
    cout << "Minimo Scarto fra i giocatori: " << minimo << endl;


}