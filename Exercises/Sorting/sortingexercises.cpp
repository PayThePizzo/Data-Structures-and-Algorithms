//
// Created by PayThePizzo on 9/3/2022.
//
#include <iostream>
#include <cmath>

/**
 * Given an array of numbers, and p,q,r such that: 1 <= p <= r <= q <= n (n is the size of the array)
 *
 * @param arr
 * @param p
 * @param r
 * @param q
 */
void QuickSelect(int *arr, int p, int r, int q){

}

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


void merge(int *arr, int left, int center, int right){
    //Initialize Aux Arrays
    int left_size = center-left+1, right_size = right-center;
    int aux_l[left_size], aux_r[right_size];
    int i = 0, j = 0;
    //2) Fill them with elements
    for( i = 0; i<left_size; i++)
        aux_l[i]=*(arr+i);

    for(j = left_size; j<right; j++)
        aux_r[j]=*(arr+j);


    //Guard
    i = 0, j = 0;

    for(int k = left; k<right; k++){
        if(aux_l[i]<= aux_r[j]){
            *(arr+k) = aux_l[i];
            i++;
        }else{
            *(arr+k) = aux_r[j];
            j++
        }
    }


}

void merge_sort(int *arr, int left, int right){
    if(left<right){
        int center = (int)floor((left+right)/2);
        merge_sort(arr, left , right);
        merge_sort(arr, center+1, right);
        merge(arr, left, center , right);
    }
}


int main(){
    int arr[] = {0, 2, -2, 5, 20, 5, -29, -4, 7, 9};
    int size = 10;

    insertion_sort(&arr[0], size);
    merge_sort(&arr[0], 0, size);

    for(int i = 0; i<size; i++){
        std::cout<< arr[i] << std::endl;
    }

}