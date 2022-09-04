//
// Created by PayThePizzo on 9/4/2022.
//

#ifndef ASD_HEAP_H
#define ASD_HEAP_H
#include <iostream>
#include <vector>
#include <algorithm>

class Heap {

private:
    int length;
    int size;
    int root;
    int key;
    int degree;
    int parent;
    int height;

public:
    int get_lenght();

    int get_heapsize();

    int get_root();

    int get_height;

    int left_child();

    int right_child();

    int get_parent();

    class MaxHeap{
    public:

        max_heapify(std::vector<int> arr, int index);
    };

    class MinHeap{


    };

};


#endif //ASD_HEAP_H
