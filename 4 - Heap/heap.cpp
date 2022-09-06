//
// Created by PayThePizzo on 9/6/2022.
//
#include <vector>
#include <stdexcept>
#include <iostream>

///Simple integer array implementation of a binary heap
class Heap {
private:
    /// Integer array
    std::vector<int> heap;
    /// Length of array
    int length = this->heap.size();
    /// Count of elements
    int heapsize;

    /// Simple vector allocation check
    bool vectorExists() {
        return this->heap.empty() ? false : true;
    }

    /// Simple setter
    void setLength(int length) {
        if (vectorExists())
            this->length = this->heap.size();
    }

    /// Check if index length > i >= 0
    bool indexInRange(int index) {
        return (index < getLength() && index >= 0) ? true : false;
    }


    /**
    * Simple setter
    *
    * @param newHeapSize new count of elements inside the heap
    */
    void setHeapSize(int newHeapSize) {

    }

    void heapify(std::vector<int> arr, int i) {

    }

    void buildHeap(std::vector<int> arr) {
        try {
            if (!arr.empty()) {
                // Initialize heap
                this->heap = std::vector<int>(arr.size());
                setLength(arr.size());
                setHeapSize(arr.size());
                for (int i = getLength() / 2; i >= 0; i--) {
                    heapify(arr, i);
                }
                this->heap.insert(this->heap.begin(), arr.begin(), arr.end());
            }
            throw std::bad_alloc();
        } catch (std::bad_alloc) {
            std::cout << "The array is not allocated" << std::endl;
        }
    }


public:

    /// Simple getter
    int getLength() {
        return this->heap.size();
    }

    /// Simple getter
    int getHeapSize() {
        return this->heapsize;
    }

    /// Simple getter
    int getLeftChildIndex(int parentIndex) {
        int next = 2 * parentIndex + 1;
        return indexInRange(next) ? next : -1;
    }

    /// Simple getter
    int getRightChildIndex(int parentIndex) {
        int next = 2 * parentIndex + 2;
        return indexInRange(next) ? next : -1;
    }

    /// Simple getter
    int getParentIndex(int childIndex) {
        int prev = (childIndex - 1) / 2;
        return (indexInRange(childIndex) && indexInRange(prev)) ? prev : -1;
    }

    /// Simple getter
    int getKey(int nodeIndex) {
        if (indexInRange(nodeIndex)) {
            return this->heap[nodeIndex];
        }
        throw std::out_of_range("Index is not in range, or Node does not exist");
    }

    /// Simple getter
    int getParentKey(int childIndex) {
        return getKey(getParentIndex(childIndex));
    }

    /// Simple getter
    int getRightChildKey(int parentIndex) {
        return getKey(getRightChildIndex(parentIndex));
    }

    /// Simple getter
    int getLeftChildKey(int parentIndex) {
        return getKey(getLeftChildIndex(parentIndex));
    }

    /// Unsorted binary heap constructor
    Heap(std::vector<int> arr) {
        buildHeap(arr);
    }

};

//TODO: MaxHeap
class MaxHeap : Heap{
private:

    void maxHeapify(){

    }

    void buildMaxHeap(){

    }

public:

    MaxHeap(std::vector<int> A){
        buildMaxHeap()
    }

    int max(){

    }

    void insert(){

    }

    int extract(){

    }

    /// Heapsort version with maxHeap
    void maxHeapSort(std::vector<int> A){
        // Invokes buildMaxHeap(A)
        MaxHeap maxHeap = MaxHeap(A);
        //for

        //copy
        for(int i = 0; i<A.size(); i++){
            A[i] = maxHeap.
        }
    }

};

//TODO: MinHeap
class MinHeap : private Heap{
private:

    void minHeapify(){

    }

    void buildMinHeap(){

    }

    void insert(){

    }

    int extract(){

    }

    /// Heapsort version with minHeap
    void minHeapSort(std::vector<int> arr){

    }

};




