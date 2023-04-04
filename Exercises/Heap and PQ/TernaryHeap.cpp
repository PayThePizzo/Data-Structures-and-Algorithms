//
// Created by PayThePizzo on 4/4/2023.
//

#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

class TernaryHeap{
    vector<int> heap;

public:
    TernaryHeap(vector<int> a){
        this->heap=a;
    }

    int parent(int index){
        return floor(index/3);
    }

    int left(int index){
        return (2*index)+(index-1);
    }

    int center(int index){
        return (2*index)+index;
    }

    int right(int index){
        return (2*index)+index+1;
    }

    bool is_empty(){
        return this->heap.empty();
    }
};

class MinHeap: private TernaryHeap{

private:

public:
    MinHeap(){
        build_min_heap(this->heap);
    }
};