//
// Created by PayThePizzo on 2/27/2023.
//

#include "dictionary.h"
#include <math.h>

using namespace std;


class DictionarySA{
public:
    // Vector of length n, of pairs k:v
    std::vector<std::pair<int, int>> A;

    DictionarySA(std::vector<std::pair<int, int>> vec){
        if(!vec.empty()){
            A = vec;
        }
    }

    // Pre: P and R in range(0, A.length), array sorted on the keys
    int search_index(int k, int left, int right){
        if(left > right){
            return -1; // Empty
        }else{
            int med = floor((left + right)/2);
            if(this->A[med].first == k){
                return med;
            }else if(this->A[med].first > k){
                return search_index(k, left, med-1);
            }else{
                return search_index(k, med+1, right);
            }
        }
    }

    int search(int k){
        int i = search_index(k, 0, this->A.size()-1);
        if(i==-1){
            return NULL;
        }else{
            return this->A[k].second;
        }
    }

    // Pre
    // Post: keep the array sorted
    void insert(int k, int v){
        int i = 1;
        //
        while(i<= this->A.size()-1 && this->A[i].first < k){
            i++;
        }
        // Key is present -> Update value
        if(i <= this->A.size()-1 && this->A[i].first == k){
            A[i].second = v;
        }else{
           // Create new array with A.size()+1 elements
           // Copy the elements and keep them sorted

        }
    }

    void key_delete(int k){

    }
};

