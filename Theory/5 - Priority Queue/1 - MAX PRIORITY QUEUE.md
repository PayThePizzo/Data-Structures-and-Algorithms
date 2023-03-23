# Max Priority Queue (Max Heap)

This version is based on [Max Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Theory/4%20-%20Heap/1%20-%20MAX%20HEAP.md). 
This is the reason why the implementation of PQ's primitive functions will be named as "heap_+[operation name]".

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
Max_Heap_Maximum(Heap A)
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
    if(A.heapsize < 1):
        raise_error("heap underflow");
    max = A[1];
    A[1] = A[A.heapsize]
    A.heapsize--;
    Max_Heapify(A, 1);
    return max;
```

**Final Time Complexity**: $T(n) = \mathcal{O}(log(n))$
* Is bounded by the `Max_Heapify`

---

## Heap Increase Key

| **Operation**                                                	| **Time**                     	| **Pre-Condition**                                           	| **Post-Condition**                              	|
|--------------------------------------------------------------	|------------------------------	|-------------------------------------------------------------	|-------------------------------------------------	|
| `Max_Heap_Increase_Key(MaxHeap A, Node i, Elem key) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $x \in A$ , $x.key \leq k$ 	| Substitutes the old key of $x$ with $x.key = k$ 	|

```python
Max_Heap_Increase_Key(Heap A, Node x, Elem k)
    if(k < A[i]):
        raise_errr("Key < A[" + i + "]"); # Smaller key than current one
    A[i] = k;
    while(i > 1 && A[parent(i)]<A[i]):
        swap(A[i], A[parent(i)])
        i = parent(x)
```

### Invariant


### Time Complexity

**Final Time Complexity**: T(n) =  O(log(n))

---

## Max Heap Insert

| **Operation**                                  	| **Time**                     	| **Pre-Condition**                  	| **Post-Condition**                                                    	|
|------------------------------------------------	|------------------------------	|------------------------------------	|-----------------------------------------------------------------------	|
| `Max_Heap_Insert(MaxHeap A, Elem key) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap and $\|A\| \geq 1$ 	| $A = A \cup \lbrace x \rbrace$ and does not violate Max Heap property 	|

```python
Max_Heap_Insert(Heap A, Elem k)
    A.heapsize++;
    A[A.heapsize] = neg_infinity(); #Returns smallest value
    Max_Heap_Increase_Key(A, A.heapsize, k);
```

### Time Complexity

**Final Time Complexity**: T(n) =  O(log(n))

---

## Heap Delete

| **Operation**                                	| **Time**                     	| **Pre-Condition**                                           	| **Post-Condition**                             	|
|----------------------------------------------	|------------------------------	|-------------------------------------------------------------	|------------------------------------------------	|
| `Max_Heap_Delete(MaxHeap A, Node i) -> void` 	| $T(n) = \mathcal{O}(log(n))$ 	| $A$ is Max Heap, $\|A\| \geq 1$, $1 \leq i \leq A.heapsize$ 	| Removes the first element $x$ with $x.key = k$ 	|

```python
Max_Heap_Delete(Heap A, Node i)
    if(A.heapsize == 1):
        A.heapsize--;
    else:
        val = A[i];
        A[i] = A[A.heapsize];
        A.heapsize--;
        if (A[i] < val):
            Max_Heapify(A, i);
        else: 
            while(i > 1 && A[i]>A[parent(i)])
                swap(A[i], A[parent(i)]);
                i = parent(i);
```

#### Time Complexity 

**Final Time Complexity**: T(n) =  O(log(n))

---

### Conclusions

Pros: All operations are efficient: $T(n) = \mathcal{O}(log(n))$