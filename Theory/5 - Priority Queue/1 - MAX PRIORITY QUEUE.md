# Max Priority Queue (Max Heap)

This version is based on [Max Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Theory/4%20-%20Heap/1%20-%20MAX%20HEAP.md). 
This is the reason why the implementation of PQ's primitive functions will be named as "heap_+[operation name]".


---

## Max Priority Queue in a nutshell - Let's ask ChatGPT!

> "Explain the Max Priority Queue Data Structure"

A max priority queue data structure is a variation of a priority queue **where the highest priority element is always 
the one that is removed first**. It is similar to a regular priority queue, but with the added property that the elements 
are ordered in such a way that **the maximum element is always at the front**.

A priority queue is an abstract data type that provides two main operations: insert and extractMax (or removeMax). 
The insert operation adds an element to the priority queue, while the extractMax operation removes the highest priority 
element from the priority queue.

In a max priority queue, the highest priority element is always the one that is removed first when calling the 
extractMax operation. This means that the elements in the queue are ordered in decreasing order of priority, 
with the maximum element at the front.

The max priority queue can be implemented using various data structures, such as an array, a linked list, or a heap. 
The heap implementation is the most commonly used data structure for implementing a max priority queue, as it provides 
efficient insert and extractMax operations in O(log n) time complexity, where n is the number of elements in the 
priority queue.

Applications of the max priority queue data structure include job scheduling in operating systems, data compression 
algorithms, and event-driven simulations.

> "Implement Max Priority Queue Data Structure in C++"

Here's an example implementation of a max priority queue data structure in C++ using a heap to store the elements:

```c++
#include <iostream>
#include <vector>

using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int l = left(i);
        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }
        int r = right(i);
        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    MaxPriorityQueue() {}

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        int result = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0);
        return result;
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(30);
    pq.insert(20);

    cout << "Max element: " << pq.extractMax() << endl; // Output: Max element: 30

    cout << "Elements in queue: ";
    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " "; // Output: Elements in queue: 20 10 5
    }

    cout << endl;
    return 0;
}
```

In this implementation, the `MaxPriorityQueue` class has a private `vector<int>` to store the elements. 
The `siftUp` and `siftDown` methods are used to maintain the heap property of the vector, ensuring that the maximum 
element is always at the front.

The `insert` operation adds an element to the priority queue, while the `extractMax` operation removes the highest 
priority element from the priority queue. The `isEmpty` and `size` methods are used to check if the priority queue 
is empty and to get the size of the priority queue, respectively.

In the `main` function, we create an instance of `MaxPriorityQueue`, insert some elements, extract the maximum 
element, and then remove the remaining elements from the priority queue.

---

## Attributes
* $A.length$: length of the array
* $A.heapsize$: #elememts of the heap saved inside the array

---

## Operations

All the following operations are described inside the Priority Queue section

| **Operation**                                                	| **Time**                     	| **Pre-Condition**                                           	| **Post-Condition**                                                                  	|
|--------------------------------------------------------------	|------------------------------	|-------------------------------------------------------------	|-------------------------------------------------------------------------------------	|
| `Max_Heap_Maximum(MaxHeap A) -> Elem x`                      	| $T(n) = \Theta(1)$           	| $A$ is Max Heap and $\|A\| \geq 1$                          	| Returns the first element $x$ with the largest key in $A$, in this case is the root 	|
| `Max_Heap_Extract_Max(MaxHeap A) -> Elem x`                  	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap and $\|A\| \geq 1$                          	| Returns and removes the first element $x$ with the largest key                      	|
| `Max_Heap_Increase_Key(MaxHeap A, Node i, Elem key) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $x \in A$ , $x.key \leq k$ 	| Substitutes the old key of $x$ with $x.key = k$                                     	|
| `Max_Heap_Insert(MaxHeap A, Elem key) -> void`               	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap and $\|A\| \geq 1$                          	| $A = A \cup \lbrace x \rbrace$ and does not violate Max Heap property               	|
| `Max_Heap_Delete(MaxHeap A, Node i) -> void`                 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $1 \leq i \leq A.heapsize$ 	| Removes the first element $x$ with $x.key = k$                                      	|

---

## Heap Maximum

| **Operation**                           	| **Time**           	| **Pre-Condition**                  	| **Post-Condition**                                                                  	|
|-----------------------------------------	|--------------------	|------------------------------------	|-------------------------------------------------------------------------------------	|
| `Max_Heap_Maximum(MaxHeap A) -> Elem x` 	| $T(n) = \Theta(1)$ 	| $A$ is Max Heap and $\|A\| \geq 1$ 	| Returns the first element $x$ with the largest key in $A$, in this case is the root 	|

```python
Max_Heap_Maximum(MaxHeap A)
    if(A.heapsize < 1):
        raise_error("heap underflow");
    return A[1];
```

**Final Time Complexity**: $T(n) =  \Theta(1)$

---

## Heap Extract Max

| **Operation**                               	| **Time**                     	| **Pre-Condition**                  	| **Post-Condition**                                             	|
|---------------------------------------------	|------------------------------	|------------------------------------	|----------------------------------------------------------------	|
| `Max_Heap_Extract_Max(MaxHeap A) -> Elem x` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap and $\|A\| \geq 1$ 	| Returns and removes the first element $x$ with the largest key 	|

```python
Max_Heap_Extract_Max(Heap A)
    if(A.heapsize < 1): #O(1)
        raise_error("heap underflow");
    max = A[1]; # Save element
    A[1] = A[A.heapsize]
    A.heapsize--
    Max_Heapify(A, 1); #O(log(n))
    return max;
```

**Final Time Complexity**: $T(n) = \mathcal{O}(log(n))$
* Is bounded by the `Max_Heapify`

---

## Heap Increase Key

| **Operation**                                                	| **Time**                     	| **Pre-Condition**                                           	| **Post-Condition**                              	|
|--------------------------------------------------------------	|------------------------------	|-------------------------------------------------------------	|-------------------------------------------------	|
| `Max_Heap_Increase_Key(MaxHeap A, Node i, Elem key) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $x \in A$ , $x.key \leq k$ 	| Substitutes the old key of $x$ with $x.key = k$ 	|

The procedure `Max_Heap_Increase_Key` implements the `Increase_Key` operation. 
* An index $i$ into the array identifies the priority-queue element whose key we wish to increase. 
* The procedure first updates the key of element $A[i]$ to its new value. 
* Because increasing the key of $A[i]$ might violate the max-heap property 
  * The procedure then, traverses a simple path from **this node toward the root** to find a proper place for the newly increased key. 
  * As `Max_Heap_Increase_Key` traverses this path, it repeatedly compares an element to its parent,
  exchanging their keys and continuing if the element’s key is larger, and terminating if the element’s key is smaller, 
  since the max-heap property now holds.

```python
Max_Heap_Increase_Key(Heap A, Node i, Elem k)
    if(k < A[i]):
        raise_errr("Key < A[" + i + "]"); # Smaller key than current one
    A[i] = k;
    while(i > 1 && A[parent(i)]<A[i]):
        swap(A[i], A[parent(i)])
        i = parent(x)
```

### Invariant

```math
INV \equiv \left\{\begin{matrix}
A[1 \ldots A.heapsize] \text{ satisfies Max Heap property } \\
\text{ except for a possible variation: } \\
A[1] \text{ could be larger than } A[parent(i)] \\
\end{matrix}\right.
```

This is true since:
* _Initialization_: checked
* _Preservation_: checked
* _Conclusion_: The cycle ends when either:
  * $i=1 \Rightarrow root$, which implies we are considering the root, namely that there is no violation.
  * $A[i] \leq A[parent(i)]$, by the invariant, the only possible violation would be in $i$ but the guard guarantees
  the Max Heap property is respected. The child's key is smaller or equal than the parent's key.


### Time Complexity

**Final Time Complexity**: $T(n) =  \mathcal{O}(log(n))$
* We must consider the length of the longest path from the node $i$ to the root, whose upperbound is exactly $log(n)$

---

## Max Heap Insert

| **Operation**                                  	| **Time**                     	| **Pre-Condition**                  	| **Post-Condition**                                                    	|
|------------------------------------------------	|------------------------------	|------------------------------------	|-----------------------------------------------------------------------	|
| `Max_Heap_Insert(MaxHeap A, Elem key) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap and $\|A\| \geq 1$ 	| $A = A \cup \lbrace x \rbrace$ and does not violate Max Heap property 	|

The procedure `Max_Heap_Insert` implements the `Insert` operation. 
1. It takes as an input the key of the new element to be inserted into max-heap A. 
2. The procedure first expands the max-heap by adding to the tree a new leaf whose key is $- \infty$. 
3. Then it calls `Max_Heap_Increase_Key` to set the key of this new node to its correct value and maintain the max-heap property.

```python
Max_Heap_Insert(Heap A, Elem k)
    A.heapsize++;
    A[A.heapsize] = neg_infinity(); # The ensure the max heap property at all times
    Max_Heap_Increase_Key(A, A.heapsize, k); #O(log(n))
```

### Time Complexity

**Final Time Complexity**: $T(n) =  \mathcal{O}(log(n))$

---

## Heap Delete

| **Operation**                                	| **Time**                     	| **Pre-Condition**                                           	| **Post-Condition**                             	|
|----------------------------------------------	|------------------------------	|-------------------------------------------------------------	|------------------------------------------------	|
| `Max_Heap_Delete(MaxHeap A, Node i) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $1 \leq i \leq A.heapsize$ 	| Removes the first element $x$ with $x.key = k$ 	|



```python
Max_Heap_Delete(Heap A, Node i)
    if(A.heapsize == 1): # O(1)
        A.heapsize--;
    else: # O( ops + max(if,else)) 
        val = A[i];
        A[i] = A[A.heapsize];
        A.heapsize--;
        if (A[i] < val): # O(1)
            Max_Heapify(A, i); # O(log(n))
        else: 
            while(i > 1 && A[i]>A[parent(i)]) # O(log(n))
                swap(A[i], A[parent(i)]);
                i = parent(i);
```

#### Time Complexity 

**Final Time Complexity**: $T(n) = \mathcal{O}(log(n))$


---

### Conclusions

Pros: All operations are efficient: $T(n) = \mathcal{O}(log(n))$