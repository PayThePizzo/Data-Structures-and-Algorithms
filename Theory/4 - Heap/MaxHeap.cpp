//
// Created by PayThePizzo on 4/4/2023.
//

#include "iostream"
#include "vector"
#include "math.h"

using namespace std;


//Utils

void print_vector(vector<int> array){
    for(int val: array){
        cout << " " << val;
    }
}

//MaxHeap

class MaxHeap{
private:
    vector<int> heap;

    void max_heapify(vector<int> a, int i){
        int l = left(i);
        int r = right(i);
        int max = i;

        // Determine the maximum value between
        // the parent (i) or its children
        if(l <= a.size() && a[l] > a[i]){
            max = l;
        }else{
            max = i;
        }

        if(r <= a.size() && a[r] > a[max]){
            max = r;
        }

        // If i is not the maximum value already, make
        // the new maximum value float up
        if(i!=max){
            swap(a[i], a[max]);
            max_heapify(a, i);
        }
    }

    // Start from half the array back to the first position
    // Since it can be demonstrated that half of the nodes are leaves
    vector<int> build_max_heap(vector<int> array){
        for(int i = array.size()/2; i>=1; i++){
            max_heapify(array, i);
        }
        return array;
    }

public:

    // Constructor
    MaxHeap(vector<int> array){
        this->heap=build_max_heap(array);
    }

    //Basic Operations
    int left(int index){
        return 2*index;
    }

    int right(int index){
        return left(index)+1;
    }

    int parent(int index){
        return floor(index/2);
    }

    void print_heap(){
        print_vector(this->heap);
    }

    vector<int> heap_copy(){
        return this->heap;
    }

    // Heapsort
    void heapsort(){

    }

    //Max Priority Queue Operations

    //Theta(1)
    int maxheap_maximum(){
        return this->heap[0];
    }

    //O(n)
    int maxheap_minimum(){
        return 0;
    }

    int maxheap_extract_max(){
        return 0;
    }

    int maxheap_extract_min(){
        return 0;
    }

    void maxheap_increase_key(int node_index, int new_key){

    }

    void maxheap_insert(int new_key){

    }

    void maxheap_delete(int node_index){

    }

    /**
     * Deletes the whole heap
     *
     */
    void heap_delete(){

    }

    // Dictionary
    int search(int key){
        return 0;
    }


};


void test_operation(vector<int>input, vector<int> expected, vector<int> output){
    cout << "Input vector: \n";
    print_vector(input);

    cout << "Expected output MaxHeap: \n";
    print_vector(expected);

    cout << "Output MaxHeap: \n";
    print_vector(output);
}


void test_creation1(){
    vector<int> a = {3,2, 4, 5, 6, -1, 1}; // random
    vector<int> b = {10 ,9 , 8, 5, 6, -1, 1, 20}; // last element is the largest
    vector<int> c = {10, 9, 8, 7, 6, 5, 4}; // non-increasing
    vector<int> d = {1, 2, 3, 4,5,}; // non-increasing
    vector<int> e = {1}; // 1 element
    vector<int> f = {1, 2}; // 2 element

}

void test_creation2(){

}


int main(){


    return 0;
}