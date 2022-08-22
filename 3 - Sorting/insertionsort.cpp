//
// Created by PayThePizzo on 8/22/2022.
//
#include <iostream>
#include <stdexcept>
/**
 * Insertion Sort implementation for Arrays with no controls.
 *
 * @param A
 * @param len
 */
void insertion_sort(int A[], int len){
    if(A || len>0){
        if(len==1){
            return;
        }else{
            for(int j=1; j<len; j++ ){
                int key = A[j], i = j-1;
                while (i>=0 && A[i]>key){
                    A[i+1]= A[i];
                    i-=1;
                }
                A[i+1] = key;
            }
        }
    }else{
        std::cout << "Invalid argument" << std::endl;
        throw std::invalid_argument("Array is null or length <= 0");
    }
}

using namespace std;

int main(){
    int len = 5, A[] = {16, 2, 32, 4, 15};
    insertion_sort(A, len);

    for(int i=0; i<len; i++){
        std::cout<< A[i]<<std::endl;
    }
    return 0;
}