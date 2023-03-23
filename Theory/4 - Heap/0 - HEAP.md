# Heap
> Put it simply, a heap is an almost-complete binary tree. 

Given a height $h$ for a heap: 
* at level $h-1$ the heap is a complete binary tree
* at level $h$, is **almost-complete BT** with all the leaves on the **left side**.

[1] ![Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/heap.png?raw=TRUE)

---

## General Array Implementation

Thanks to its main feature, it is easy to use an array as implementation.

**Basic Characteristics**: 
* $A.length$ : #elements of the **array**
* $A.heapsize$ : #elements of the **heap** saved in the array
  * $A.heapsize \leq A.length$
  * If $1 <= i <= A.heapsize$, then $A[i]$ is an element of the heap
* $A[1]$ is the root 

### Operations
The following basic operations all have 

$$T(n) = \mathcal{O}(1)$$

| **Operation**                 	| **Pre-Condition** 	| **Post-Condition**                               	|
|-------------------------------	|-------------------	|--------------------------------------------------	|
| `left_child(Node i) -> Node`  	| $i \in A$         	| Returns the left child of the Node $i$ or $NIL$  	|
| `right_child(Node i) -> Node` 	| $i \in A$         	| Returns the right child of the Node $i$ or $NIL$ 	|
| `parent(Node i) -> Node`      	| $i \in A$         	| Returns the parent of the Node $i$ or $NIL$      	|

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

## Types of heap

Based on what properties are satisfied by the nodes we can consider two types of heap

### Max Heap

> Max Heap Property: for every node i, except the root, we have $A[parent(i)] \geq A[i]$ (as the root is the largest element)

```math
\forall i \in A \ni' i \neq root(A) : A[parent(i)] \geq A[i]
```

By induction, through the property of transitivity of $\leq$, it is possible to demonstrate that 
1. The root of a Max Heap contains the largest element of a Max Heap
2. The root of a subtree of a Max Heap contains the largest element in that subtree
   1. The elements of that subtree are not greater than the root of that subtree


### Min Heap

> Min Heap Property</mark>: for every node i, except the root, we have $A[parent(i)] \leq A[i]$ (as the root is the smallest element)

```math
\forall i \in A \ni' i \neq root(A) : A[parent(i)] \leq A[i]
```

By induction, through the property of transitivity of $\leq$, it is possible to demonstrate that 
1. The root of a Min Heap contains the smallest element of a Min Heap
2. The root of a subtree of a Min Heap contains the smallest element in that subtree.
   1. The elements of that subtree are not smaller than the root of that subtree

---

## Heap properties

### Lemmma 1

```math
\text{ The height of a heap of } n \text{ elements is } h(Heap_{n}) = h = \lfloor log(n) \rfloor
```

#### Demonstration
A Heap is an almost complete binary tree. Thus, if its height is some $h$ then: 

$$2^{h} \leq n \leq 2^{h+1} - 1$$

![heapdem1](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/heapdem1.png?raw=TRUE)

$$2^{h} \leq n \leq 2^{h+1} - 1 < 2^{h+1} \Rightarrow 2^{h} \leq n < 2^{h+1}$$

By applying a logarithm

$$h \leq log(n) < h+1 \Rightarrow h = \lfloor log(n) \rfloor$$

We can assume that all the operations on the heap $T(n) = \mathcal{O}(h) = \mathcal{O}(log(n))$

#### Lemma 2

In array of $n$ elements, which represents a Heap of $n$ elements $Heap_{n}$, all the leaves are nodes whose 
indices $i = \lfloor \frac{n}{2} \rfloor +1, \lfloor \frac{n}{2} \rfloor + 2, \ldots, \lfloor \frac{n}{2} \rfloor + j, n $

This means half of the nodes are leaves, and they are found on those indices of the array $A[]$.

#### Demonstration

Demonstration by induction on the count of $n$ nodes: ad absurdum, if a leaf node had a child, its index would be larger than the maximum index for the given array.

#### Lemma 3

In a Heap of $n$ elements, there are maximum $\lceil \frac{n}{2^{h+1}} \rceil$ nodes of height $h$
* There are many nodes with small heights

Remark: if $h=0 \Rightarrow f(Heap_{n}) \leq \lceil \frac{n}{2} \rceil \Rightarrow f(Heap_{n}) = \lceil \frac{n}{2} \rceil$ 
* $f(h=0) = n/2$ is the count of leaves

---

## Operations 

| **Operation**                       	| **Time**                      	|
|-------------------------------------	|-------------------------------	|
| `Heapify(Array A[], int i) -> Heap` 	| $T(n) = \mathcal{O}(log(n))$  	|
| `Build_Heap(Array A[]) -> Heap`     	| $T(n) = \mathcal{O}(n)$       	|
| `Heapsort(Array A[]) -> void`       	| $T(n) = \mathcal{O}(nlog(n))$ 	|

However they can only be implemented in two versions for the Max Heap and the Min Heap

---
## Conclusion

Pros:
* All the operations on the heap, have $T(h) = \mathcal{O}(log(n))$

---

### Extra Credits
* [1] [Simple Dev Code - Heap](https://simpledevcode.wordpress.com/2015/08/05/the-heap-data-structure-c-java-c/)