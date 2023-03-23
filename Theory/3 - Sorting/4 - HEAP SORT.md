# Heap Sort


Characteristics:
* In-Loco
* Based on Heap
* Efficient

---

## Idea

Heap sort belongs to a particular category of algorithms where some data structure were precisely thought 
in order to simplify the sorting problem. In this case, the data structure is called [Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/4%20-%20Heap/0%20-%20HEAP.md)

---

## Invariant
* The sub-array A[1..i] is a max_heap containing the `i` smallest values of the vector of
start
* The sub-array A[i+1..n] contains `n-i` largest elements of the vector of start, sorted
by value
  
INV:
* Initialization: checked
* Preservation: checked
* Conclusion: `i=1` at the end of the for block
  * A[1] is a max_heap, and is the smallest element of the starting vector
  * A[2..n] is a vector containing the `n-1`largest elements of the vector of start, sorted
  by value 
  * This means, the vector is sorted
  
---

## The algorithm

```python
Heap_sort(Array A)
    build_maxheap(A);
    for (i = A.length down to 2):
        swap(A[i], A[1]);
        A.heapsize = A.heapsize-1;
        max_heapify(A, 1);
```

```c++
max_heapify(Heap a, Node i){
    Node left = left(i);
    Node right = right(i);
    Node max;
    if(left <= a.heap_size && a[l] > a[i]){
        max = left;
    } else {
        max = i;
    }

    if(r <= a.heap_size && a[r] > a[max]){
        max = r;
    }

    if(i != max){
        swap(a, i, max);
        max_heapify(a, max);
    }
}

build_max_heap(A){
    A.heap_size = A.length;
    for(int i = A.length / 2; i > 0; i--){
        max_heapify(A, i);
    }
}

heapSort(int * arr){
    build_max_heap(arr);
// sapendo che la radice è sempre l’elemento massimo
// possiamo andare ad estrarre la radice e inserirla in un nuovo array
// in modo da ordinarlo
    for(int i = 0; i < arr.length; i++){
// inseriamo la radice nell’array ordinato
        swap(arr, i, 0);
// andiamo a rimuovere la radice dell'heap
        arr.heap_size = arr.heap_size - 1;
        max_heapify(arr, 0);
    }
}

```

### Invariant



### Time Complexity 

**Final Time Complexity** T(n) = O(n * log(n))
* T(max_heapify()) = O(log(n))

Theorem: Heapsort sorts in-place n elements, executing O(nlog(n)) comparisons
in the worst case.
* Quicksort is usually faster when optimized (not in the worst case).