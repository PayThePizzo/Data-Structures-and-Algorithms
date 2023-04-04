//
// Created by PayThePizzo on 4/4/2023.
//

#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

// The idea of this module is to implement the Binary Heap, Max Heap and
// Min Heap correctly. So that we can implement Max PQ e Min PQ.
// And finally set operations.

class BinaryHeap{

protected:
    vector<int> heap;

public:
    BinaryHeap();

    BinaryHeap(vector<int> a){
        this->heap = a;
    }

    int parent(int index){
        return floor((index-1)/2);
    }

    int left(int index){
        return (2*index);
    }

    int right(int index){
        return (2*index)+1;
    }

    bool is_empty(){
        return this->heap.empty();
    }

    // Elements of the array
    int length(){
        return 0;
    }

    // Elements of the heap
    // heapsize <= length
    int heapsize(){
        return this->heap.size();
    }

    int root(){
        return this->heap[0];
    }

    int tree_height(){
        return 0;
    }

    // At level h-1 it is a complete binary tree
    // At level h it is an almost complete binary tree
    //  All the leaves are on the left side
    bool is_complete_binary_tree(){
        return false;
    }

    // Root -> L -> R
    void visit_PreOrder(){

    }

    // L -> R -> Root
    void visit_PostOrder(){

    }

    // L -> Root -> Right
    void visit_InOrder(){

    }

    // Level 0 -> Level 1 -> ...
    void visit_BFS(){

    }

    void print_heap(){
        for(int val : this->heap){
            cout << " " << val;
        }
    }

};

class MaxHeap: public BinaryHeap{

protected:
    //TODO: Fix
    void max_heapify(vector<int> a, int i){
        int l = left(i);
        int r = right(i);
        int max = i;

        // Determine the maximum value between
        // the parent (i) or its children
        if(l < a.size() && a[l] > a[max]){
            max = l;
        }

        if(r < a.size() && a[r] > a[max]){
            max = r;
        }

        // If i is not the maximum value already, make
        // the new maximum value float up
        if(max!=i){
            swap(a[i], a[max]);
            max_heapify(a, max);
        }
    }

    // Start from half the array back to the first position
    // Since it can be demonstrated that half of the nodes are leaves
    vector<int> build_max_heap(vector<int> array){
        int start_index = (array.size()/2)-1;
        for(int i = start_index; i>=0; i--){
            max_heapify(array, i);
        }
        return array;
    }

public:

    MaxHeap();

    MaxHeap(vector<int> a):BinaryHeap(build_max_heap(a)){}


    bool is_MaxHeap(){
        return false;
    }

    void heapsort(){

    }

};

class MinHeap: public BinaryHeap{

protected:

    void min_heapify(vector<int> a, int i){
        int l = left(i), r = right(i), min = i;

        if(l < a.size() && a[l] < a[i]){
            min = l;
        }
        if(r < a.size() && a[r] < a[min]){
            min = r;
        }
        if(i != min){
            swap(a[i], a[min]);
            min_heapify(a, min);
        }
    }

    vector<int> build_min_heap(vector<int> a){
        for (int i = a.size()/2; i>0; i--){
            min_heapify(a, i);
        }
        return a;
    }

public:

    MinHeap();


    bool is_MinHeap(){
        return false;
    }

    void heapsort(){

    }
};

class MaxPriorityQueue: public MaxHeap{
public:

    int search(){

    }

    void max_heap_insert(){

    }

    void max_heap_delete(){

    }

    int max_heap_maximum(){

    }

    int max_heap_minimum(){

    }

    int max_heap_extract_max(){

    }

    int max_heap_extract_min(){

    }

    int max_heap_increase_key(){

    }

    int max_heap_decrease_key(){

    }


};

class MinPriorityQueue: public MinHeap{

    int search(){

    }

    void min_heap_insert(){

    }

    void min_heap_delete(){

    }

    int min_heap_maximum(){

    }

    int min_heap_minimum(){

    }

    int min_heap_extract_max(){

    }

    int min_heap_extract_min(){

    }

    int min_heap_increase_key(){

    }

    int min_heap_decrease_key(){

    }
};

// H1 \ H2
MaxHeap set_difference(MaxHeap h1, MaxHeap h2){
}

MaxHeap set_union(MaxHeap h1, MaxHeap h2){
}

MaxHeap set_intersection(MaxHeap h1, MaxHeap h2){
}

void test_operation(vector<int>input, vector<int> expected, vector<int> output){
    cout << "Input vector: \n";

    cout << "Expected output MaxHeap: \n";

    cout << "Output MaxHeap: \n";
}

void test_creation1(){
    vector<int> arr = {3,2, 4, 5, 6, -1, 1}; // random
    vector<int> b = {10 ,9 , 8, 5, 6, -1, 1, 20}; // last element is the largest
    vector<int> c = {10, 9, 8, 7, 6, 5, 4}; // non-increasing
    vector<int> d = {1, 2, 3, 4,5,}; // non-increasing
    vector<int> e = {1}; // 1 element
    vector<int> f = {1, 2}; // 2 element

    MaxHeap max(arr);
    max.print_heap();
    return;
}

int main(){
    test_creation1();
    return 0;
}