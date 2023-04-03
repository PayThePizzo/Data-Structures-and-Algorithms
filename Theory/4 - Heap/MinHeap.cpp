//
// Created by PayThePizzo on 4/3/2023.
//

#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

class MinHeap{

private:
    vector<int> heap;

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

    MinHeap(vector<int> a){
        this->heap = build_min_heap(a);
    }

    int length(){
        return this->heap.size();
    }

    int heapsize(){
        return this->heap.size();
    }

    int root(){
        return 0;
    }

    int left(int i){
        return 2*i;
    }

    int right(int i){
        return left(i)+1;
    }

    int parent(int i){
        return floor(i/2);
    }

    void print(){
        for(int i = 0; i< this->heap.size(); i++){
            cout << " " << this->heap[i];
        }
    }

};

int main(){
    vector<int> a = {35, 42, 2, -1, 27};
    MinHeap b(a);
    b.print();
}