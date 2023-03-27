# Max Heap

---

## Max Heap in a nutshell - Let's ask ChatGPT!

> "Explain the max heap data structure"

A max heap is a complete binary tree in which every node has a value greater than or equal to the values of its children.
This means that the root node has the largest value in the heap.

Max heaps are commonly used to implement priority queues, where the highest-priority item is always at the front
of the queue.

The most common implementation of a max heap is an array, where the parent-child relationship of the tree
is defined as follows:
* The **parent** of the node at index i is located at index $floor(\frac{i-1}{2})$
* The **left child** of the node at index i is located at index $2*i + 1$
* The **right child** of the node at index i is located at index $2*i + 2$

To **insert** a new element into the max heap, it is added to the end of the array and then
"bubbled up" by swapping it with its parent until the parent is larger or until the new
element reaches the root node.

To **remove** the largest element from the max heap (i.e., the root node), it is replaced with
the last element in the array and then "bubbled down" by swapping it with its larger child until
it is greater than or equal to both of its children or until it reaches a leaf node.

The time complexity of insert and remove operations in a max heap is O(log n), where n is the number
of elements in the heap. The time complexity of finding the maximum element is O(1).

> Implement Max Heap Data Structure in C++

Here's an example implementation of a max heap data structure in C++ using an array to store the elements:

```c++
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper functions
    int parent(int i) { return (i-1)/2; }
    int leftChild(int i) { return 2*i+1; }
    int rightChild(int i) { return 2*i+2; }

    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heap.size() && heap[l] > heap[maxIndex])
            maxIndex = l;
        int r = rightChild(i);
        if (r < heap.size() && heap[r] > heap[maxIndex])
            maxIndex = r;
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    // Constructor
    MaxHeap() {}

    // Heap operations
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size()-1);
    }

    int extractMax() {
        int result = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return result;
    }

    int size() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printHeap() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.printHeap(); // Output: 30 20 5 10
    cout << maxHeap.extractMax() << endl; // Output: 30
    maxHeap.printHeap(); // Output: 20 10 5
    return 0;
}
```

In this implementation, the `MaxHeap` class has a private vector to store the heap elements. 
The `siftUp` function is used to move a new element up the heap after it is inserted, and the `siftDown` function 
is used to move an element down the heap after the maximum element is extracted.

The `insert`, `extractMax`, `size`, and `isEmpty` functions are used to perform basic heap operations. 
The `printHeap` function is used to print the heap elements for debugging purposes.

The main function shows an example usage of the `MaxHeap` class.

---

## Max Heap Property

> For every node i, except the root, we have $A[parent(i)] \geq A[i]$ (as the root is the largest element)

```math
\forall i \in A \ni' i \neq root(A) : A[parent(i)] \geq A[i]
```

By induction, through the property of transitivity of $\leq$, it is possible to demonstrate that
1. The root of a Max Heap contains the largest element of a Max Heap
2. The root of a subtree of a Max Heap contains the largest element in that subtree
    1. The elements of that subtree are not greater than the root of that subtree

---

## Operations

| **Operation**                               	| **Time**                     	| **Pre-Condition**                                                                             | **Post-Condition**                   	|
|---------------------------------------------	|------------------------------	|-----------------------------------------------------------------------------------------------|--------------------------------------	|
| `Max_Heapify(Array A[], int i) -> Max_Heap` 	| $T(n) = \mathcal{O}(log(n))$ 	| $i \in A$ and the binary trees with root in $left-child(i)$ and $right-child(i)$ are Max Heap | The tree rooted in $i$ is a Max Heap 	|
| `Build_Max_Heap(Array A[]) -> Max_Heap`     	| $T(n) = \mathcal{O}(n)$      	| $A$ is an array                                                                               | $A$ is a Max Heap                    	|

---

## Max Heapify

| **Operation**                               	| **Time**                     	| **Pre-Condition**                                                                             	| **Post-Condition**                   	|
|---------------------------------------------	|------------------------------	|-----------------------------------------------------------------------------------------------	|--------------------------------------	|
| `Max_Heapify(Array A[], int i) -> Max_Heap` 	| $T(n) = \mathcal{O}(log(n))$ 	| $i \in A$ and the binary trees with root in $left_child(i)$ and $right_child(i)$ are Max Heap 	| The tree rooted in $i$ is a Max Heap 	|

In order to maintain the max-heap property, we call the procedure `Max_Heapify`. 
Its inputs are an array $A$ and an index $i$ into the array. 

When it is called, `Max_Heapify` assumes that the binary trees rooted at $left_child(i)$ and $right_child(i)$ are max-heaps, 
but that $A[i]$ might be smaller than its children, thus violating the max-heap property. 

`Max_Heapify` lets the value at $A[i]$ _float down_ in the max-heap so that the subtree rooted at index $i$ 
obeys the max-heap property.

### The process

At each step, 
1. The largest of the elements $A[i], A[left_child(i)], A[right_child(i)]$ is determined, and its index is
stored in `max`. 
   1. If $A[i]$ is largest, then the subtree rooted at node $i$ is already a
   max-heap and the procedure terminates. 
   2. Otherwise, one of the two children has the largest element, and $A[i]$  is swapped with $A[max]$, which causes node 
   $i$ and its children to satisfy the max-heap property. 
      1. The node indexed by $max$, however, now has the original value $A[i]$, and thus the subtree rooted at largest might 
      violate the max-heap property. Consequently, we call `Max_Heapify` recursively on that subtree.

```python
max_heapify(Heap A, Node i)
    l = left_child(i);
    r = right_child(i);
    if (l <= A.heap_size && A[l]>A[i]):
        max = l;
    else:
        max = i;
    if (r <= A.heap_size && A[r] > A[max]):
        max = r;
    if (i != max):
        swap(A[i],A[max]);
        max_heapify(A, max);
```

Example: `Max_Heapify(A, 2)` with $A.heapsize = 10$


![maxheapifyex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/maxheapifyex.png?raw=TRUE)

**(a)** The initial configuration, with $A[2]$ at node $i = 2$ violating the max-heap property since it is not larger than
both children. The max-heap property is restored for node 2 in **(b)** by exchanging $A[2]$ with $A[4]$, which destroys 
the max-heap property for node $4$. The recursive call `Max_Heapify(A, 4)` now has $i = 4$. 
After swapping $A[4]$ with $A[9]$, as shown in **(c)**, node $4$ is fixed up, and the recursive call
`Max_Heapify(A, 9)` yields no further change to the data structure.

### Time Complexity

$$T(n) = T(h) = \mathcal{O}(h) = \mathcal{O}(log(n)), \text{ by Lemma 1}$$

At every recursive call we go down one level, and by Lemma 1, the worst possible complexity is dictated 
by $\lfloor log(n) \rfloor$

---

## Build Max Heap

| **Operation**                           	| **Time**                	| **Pre-Condition** 	| **Post-Condition** 	|
|-----------------------------------------	|-------------------------	|-------------------	|--------------------	|
| `Build_Max_Heap(Array A[]) -> Max_Heap` 	| $T(n) = \mathcal{O}(n)$ 	| $A$ is an array   	| $A$ is a Max Heap  	|

### Process 

We can use the procedure `Max_Heapify` in a bottom-up manner to convert an array $A[1 \ldots n]$, where $n = A.length$,
into a max-heap. By Lemma 2, half of the nodes are leaves so each is a 1-element max-heap to begin with. The procedure
`Build_Max_Heap` goes through the remaining nodes of the tree and runs `Max_Heapify`on each one.

```python
build_maxheap(Array A)
    A.heap_size = A.length
    for (i = ⌊A.length/2⌋ down to 1):
        max_heapify(A, i);
```

Example:

![buildmaxheapex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/buildmaxheapex.png?raw=TRUE)


### Invariant

$$INV \equiv \text{ every node in } i+1, i+2, \ldots, n=A.length \text{ is root of a max-heap }$$

In particular:
* $i=n/2$ is the first node that is not a leaf. 
* So we start from there since $i=(n/2)+1$ is already a leaf and trivially max-heap (like the following nodes).

This is true since:
* Initialization: checked
* Preservation: checked
* Conclusion: At the end of the for block $i = 0$.
  * The invariant tells us that every node is a root of max_heap
  * Specifically, the node $A[i]$ with $i=1$, the root node, is a max-heap.

$$INV[0/i] \equiv \text{ every node in } i=1 \ldots n \text{ is the root of a max-heap} \wedge i=1 \Rightarrow root $$

The root is also a max-heap.

### Time Complexity

From a simple analysis we can derive 

$$T(n) = T_{for} \cdot T_{calls} = \mathcal{O}(nlog(n))$$

But this is not a very asymptotically tight upperbound. We can derive a tighter bound by observing that the time 
for `Max_Heapify` to run at a node **varies with the height of the node** in the tree, and the heights of most
nodes are small. Our tighter analysis relies on the properties that an $n$ element heap has height 
$\lfloor log(n) \rfloor$ and at most nodes $\lceil \frac{n}{2^{h+1}} \rceil$ of any height $h$

The time required by `Max_Heapify` when called on a node of height $h$ is $\mathcal{O}(h)$, and so we can express 
the total cost of `Build_Max_Heap` as being bounded from above by (thanks to Lemma 3):

```math
\sum_{h=0}^{\lfloor log(n) \rfloor} \lceil (n/2^{h+1}) \rceil \mathcal{O}(h) = \mathcal{O}(n \sum_{h=0}^{\lfloor log(n) \rfloor} h/2^{h})
```

We evaluate the last summation by substituting $x = 1/2$ in the formula, yielding

```math
\sum_{h=0}^{\infty}  h/2^{h} = 1/2 \cdot \frac{1}{(1-\frac{1}{2})^{2}} = 4/2 = 2
```

Thus, we can bound the running time of `Build_Max_Heap` as

```math
T(n) = \mathcal{O}(n \sum_{h=0}^{\lfloor log(n) \rfloor} h/2^{h}) \leq  \mathcal{O}(n \sum_{h=0}^{\infty} h/2^{h}) \leq \mathcal{O}(2n) \leq \mathcal{O}(n)
```

**Final Time Complexity** $T(n) = \mathcal{O}(n)$

---
