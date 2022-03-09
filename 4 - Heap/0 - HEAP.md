# Heap
Put it simply, a heap is an almost-complete binary tree. 
Given a height `h` for a heap: 
* at **h-1** the heap is a complete binary tree
* at h, is almost-complete BT with all the leaves on the **left side**.

[1] ![Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/heap.png?raw=TRUE)

---

## Heap - Array Implementation

Thanks to its main feature, it is easy to use an array as implementation.

**Basic Characteristics**: 
* A.length: #elements of the **array**
* A.heapsize: #elements of the **heap**
  * If `1 <= i <= A.heapsize`, A[i] is an element of the heap
* A[1] is the root 

**Operations**:
```python
Node left_child(Node i)
    return A[ 2*i ]
```

```python
Node right_child(Node i)
    return A[ 2*i+1 ]
```

```python
Node parent(Node i)
    return A[ ⌊i/2⌋ ]
``` 

---

Based on what properties are satisfied by the nodes we can consider two types of 
heap

## Max Heap
<mark>Max Heap Property</mark>: for every node i, except the root, we have `A[parent(i)] >= A[i]`
* The root is the largest element

## Min Heap
<mark>Min Heap Property</mark>: for every node i, except the root, we have `A[parent(i)] <= A[i]`
* The root is the smallest element

---

## Properties
<mark>Lemma 1.</mark> **h = ⌊log(n)⌋**, with n the #elements

<mark>Lemma 2.</mark> In the array implementation of a heap with n elements, the leaves
are nodes with index `⌊n/2⌋+1 <= i <= n`
* This means half of the nodes are leaves

<mark>Lemma 3.</mark> The are maximum `⌈n/(2**(h+1)⌉` nodes of height h in a heap of n elements
* If the #leaves = n/2, the h of leaf is 0


---

## Operations 

Heapify(A,i):
* Pre: Given i, index of the array A, we suppose 
  * A[i]'s children are heap too
  * A[i] must be smaller of at least one of its children
* Post: A[i] is moved in a lower position of the tree (implemented through an Array A like a heap)
* Variant: max_heapify()

Build-Heap(A):
* Pre: A is an unsorted array 
* Post: Returns a heap built from A
* Variant: build_max_heap()

Heapsort(A):
* Pre: A is an unsorted array
* Post: Sorts A

Max(A):
* Pre: A is a Heap
* Post: Returns the largest element of A (The root if it is a Max Heap)

Insert(A,x):
* Pre: A is an Heap
* Post: x is inserted in A, in a way that the condition of heap is not violated

---
## Conclusion

Pros:
* All the operations on the heap, have T(h) = O(log(n))

Cons:

---

### Extra Credits
* [1] [Simple Dev Code - Heap](https://simpledevcode.wordpress.com/2015/08/05/the-heap-data-structure-c-java-c/)