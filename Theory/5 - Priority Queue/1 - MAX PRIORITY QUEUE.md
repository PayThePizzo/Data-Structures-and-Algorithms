# Max Priority Queue (Max Heap)

This version is based on max_heap. This is the reason why the implementation of PQ's primitive
functions will be named as "heap_+[operation name]".

### Attributes
* A.length: length of the array
* A.heapsize: #elem saved inside the array

All the following operations are described inside the Priority Queue section

---

## Heap Maximum
Max(A):
* Pre: A is a Heap
* Post: Returns the largest element of A (The root if it is a Max Heap)

```python
heap_maximum(Heap A)
    if(A.heapsize < 1):
        raise_error("heap underflow");
    return A[1]
```
**Final Time Complexity**: T(n) =  Θ(1)

---

## Heap Extract Max

```python
heap_extract_max(Heap A)
    if(A.heapsize < 1):
        raise_error("heap underflow");
    max = A[1];
    A[1] = A[A.heapsize]
    A.heapsize--;
    max_heapify(A, 1);
    return max;
```
**Final Time Complexity**: T(n) =  O(log(n))

---

## Heap Increase Key

```python
heap_increase_key(Heap A, Node x, Elem k)
    if(k < A[i]):
        raise_errr("Key < A[" + i + "]");
    A[i] = k;
    while(i > 1 && A[parent(i)]<A[i]):
        swap(A[i], A[parent(i)])
        i = parent(x)
```
**Final Time Complexity**: T(n) =  O(log(n))

---

## Max Heap Insert
Insert(A,k):
* Pre: A is an Heap
* Post: k is inserted in A, in a way that the condition of heap is not violated


```python
max_heap_insert(Heap A, Elem k)
    A.heapsize++;
    A[A.heapsize] = neg_infinity(); #Returns smallest value
    heap_increase_key(A, A.heapsize, k);
```
**Final Time Complexity**: T(n) =  O(log(n))

---

## Heap Delete

```python
heap_delete(Heap A, Node i)
    if(A.heapsize == 1):
        A.heapsize--;
    else:
        val = A[i];
        A[i] = A[A.heapsize];
        A.heapsize--;
        if (A[i] < val):
            maxheapify(A, i);
        else: 
            while(i > 1 && A[i]>A[parent(i)])
                swap(A[i], A[parent(i)]);
                i = parent(i);
```
**Final Time Complexity**: T(n) =  O(log(n))