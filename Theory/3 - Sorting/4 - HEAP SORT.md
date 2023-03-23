# Heap Sort

| **Operation** 	| **Method**             	| **Time**               	| **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|---------------	|------------------------	|------------------------	|---------------	|---------------	|-------------	|-------------	|
| _Heap sort_   	| Selection, Incremental 	| $\mathcal{O}(nlog(n))$ 	| **Y**         	| **Y**         	| **Y**       	| N           	|

---

## Idea

Heap sort belongs to a particular category of algorithms where some data structure were precisely thought 
in order to simplify the sorting problem. In this case, the data structure is called [Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/4%20-%20Heap/0%20-%20HEAP.md)

---

## The Algorithm
Steps:
1. The heapsort algorithm starts by using `Build_Max_Heap` to build a max-heap on the input array $A[1 \ldots n]$, 
where $n = A.length$. 
2. Since the maximum element of the array is stored at the root $A[1]$, we can put it into its correct final position
by exchanging it with $A[n]$. If we now discard node $n$ from the heap (and we can do so by simply decrementing 
$A.heapsize$) we observe that the children of the root remain max-heaps, but the new root element might violate 
the max-heap property. 
3. All we need to do to restore the max-heap property, however, is call `Max_Heapify(A,1)`, which leaves a max-heap 
in $A[1 \ldots n-1]$. 
4. The heapsort algorithm then repeats this process for the max-heap of size $n-1$ down to a heap of size $2$


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
    for(int i = 0; i < arr.length; i++){
        swap(arr, i, 0);
        arr.heap_size = arr.heap_size - 1;
        max_heapify(arr, 0);
    }
}

```

Example:

![heapsortex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/heapsortex.png?raw=TRUE)

### Invariant

```math 
INV \equiv \left\{\begin{matrix}
\text{The subarray } A[1 \ldots i] \text{ is a max-heap }& \wedge \\
\text{The subarray } A[1 \ldots i] \text{ contains the smallest } i \text{ elements of the starting vector }& \wedge \\
\text{The subarray } A[i+1 \ldots n] \text{ contains the largest } n-i \text{ sorted elements of the starting vector } & \\
\end{matrix}\right.
```

This is true since:
* Initialization: checked
* Preservation: checked
* Conclusion: $i=1$ at the end of the for block
  * $A[1]$ is a max_heap and  the smallest element of the starting vector
  * $A[2 \ldots n]$ is a vector containing the $n-1$ largest elements of the starting vector, sorted
  by value. 
  * This means, the vector is sorted.

```math
INV[1/i] \equiv \left\{\begin{matrix}
\text{The subarray } A[1 \ldots i]=A[1] \text{ is a max-heap }& \wedge \\
\text{The subarray } A[1 \ldots i]=A[1] \text{ contains the smallest element of the starting vector } A[1 \ldots n] & \wedge \\
\text{The subarray } A[i+1 \ldots n]=A[2 \ldots n] \text{ contains the largest } n-1 \text{ sorted elements of the starting vector } A[1 \ldots n] & \wedge \\
\text{The resulting vector is correctly sorted } & \\
\end{matrix}\right.
```

### Time Complexity 

$$T(n) = T_{build} + T_{for}(n-1) \cdot T_{heapify} = \mathcal{O}(n) + \mathcal{O}(nlog(n)) =  \mathcal{O}(nlog(n))$$

> Theorem: Heapsort sorts in-place $n$ elements, executing $\mathcal{O}(nlog(n))$ comparisons in the worst case.

---

### Conclusions

Quicksort is usually faster when optimized (except the worst case).