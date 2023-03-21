# Merge Sort

| **Operation** 	| **Method** 	| **Time**                 	| **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|---------------	|------------	|--------------------------	|---------------	|---------------	|-------------	|-------------	|
| _Merge sort_  	| Merging*   	| $T(n) = \Theta(nlog(n))$ 	| N             	| N             	| **Y**       	| N           	|

---

## Idea 

Merge sort belongs to a class of algorithms which use a Divide-et-Impera approach.

The MergeSort function repeatedly divides the array into two halves until 
we reach a stage where we try to perform MergeSort on a subarray of size 1.[1]

After that, the merge function comes into play and combines the sorted arrays into larger 
arrays until the whole array is merged.[1]

![Merge Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesort.jpg?raw=TRUE)

---

## The Algorithm - Divide et Impera
It sorts a vector $A[]$ limited by two indexes: $p$ the starting index and $r$ the ending index, such that $A[p]$ is the first
element and $A[r]$ is the last element.

1. **Divide/Split**: recursively divides the main vector into two sub-vectors $A[p \ldots q]$ and $A[q+1 \ldots r]$ with $q = \lfloor (p+r)/2 \rfloor$
2. **Impera**: recursively sorts the sub-vectors through mergesort. 
   1. If the problem is sufficiently small ($0$ or $1$ element), we can compute the result immediately.
   2. Else, if one of the vectors is **empty**, we put in the queue the remaining subsequence of the vector.
3. **Merge/Combine**: merges the sorted sub-vectors to create one big sorted vector.
   1. The first elements of the two vectors are compared
      1. If they are different, we add the smallest to the new vector. We will then, recursively continue
      the merge sort on the queue (of the vector which had the smallest element), and on the other vector
      that has remained untouched.
      2. If they are equal, they are both added to the new vector. We will then, recursively continue
      the merge sort on the two queues.

**By queue, we mean a vector without its first element.

![Merge Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesort2.jpg?raw=TRUE)

Let's see the algorithm now.

### Mergesort

| **Operation**                       	| **Pre-Condition**                                                                 	| **Post-Condition**  	|
|-------------------------------------	|-----------------------------------------------------------------------------------	|---------------------	|
| `merge_sort(Array A, int p, int r)` 	| p,r are valid indexes of $A$, $p,r \in \mathbb{Z}^{+} \ni' p,r \in [1, A.length]$ 	| Sorts $A$ correctly 	|

```python
merge_sort(Array A, int p, int r)
    if (p<r): # A contains at least two elements
        q = ⌊(p+r)/2⌋; # O(1)
        merge_sort(A, p, q); # T(n/2)
        merge_sort(A, q+1, r); # T(n/2)
        merge(A, p, q, r); # Theta(n)
```

Normally the first call would be like `merge_sort(int arr[], int p = 1, int r = arr.length)`

### Merge

| **Operation**                         	| **Pre-Condition**                                                                                            	| **Post-Condition**                                                                 	|
|---------------------------------------	|-------------------------------------------------------------------------------------------------------------	|------------------------------------------------------------------------------------	|
| `merge(Array A, int p, int q, int r)` 	| The indices $p \leq q < r$, The subvectors $A[p \ldots q]$ and $A[q+1 \ldots r]$ are sorted and not empty 	| The sub-vectors are correctly merged together into a sorted vector $A[p \ldots r]$ 	|

```python
Merge(Array A, int p, int q, int r):
    # Initialization
    n1 = q - p + 1; # Lower
    n2 = r - q; # Upper
    int L[n1] = create_arrL(n1); # L = [1 .. n1+1] Aux Vector
    int R[n2] = create_arrR(n2); # R = [1 .. n2+1] Aux Vector
    
    # Copy in L & R, all the elements.
    # Theta(n1)
    for (i = 1 to n1):
        L[i] = A[p+i-1];
    # Theta(n2)
    for (j = 1 to n2):
        R[j] = A[q+j];
    
    # Guard condition
    L[n1+1] = infinity();
    R[n2+1] = infinity();
    i = 1, j = 1;
    
    # Theta(r-p+1) = n 
    for (k = p to r)
        if (L[i] <= R[j]):
            A[k] = L[i];
            i++;
        else:
            A[k] = R[j];
            j++;
```

** _Guard condition_: Infinity() is a **technique in pseudocode** used to avoid running out
of elements inside the two sub-vectors. We never check if one of the two vectors is empty.


### Invariant
As we know, the study of the invariant must be completed by analyzing all the iteration cycles.
Here, we will only focus on the third one.

```math
INV \equiv \left\{\begin{matrix}
\text{The sub-vector } A[p \ldots k-1] \text{ contains the smallest } \\ 
\text{ sorted } k-p \text{ elements present in } L[1.. n_{1}+1] \wedge R[1.. n_{2}+1] \\ 
\text{ Furthermore } L[i] \wedge R[j] \text{ are the smallest elements of their } \\
\text{ vectors respectively (not yet copied into A)} \\
\end{matrix}\right.
```

This is true:
1) Initialization: Respected 
2) Preservation: Respected
3) Conclusion: When the for block stops, $k = r+1$

```math
INV[(r+1)/k] \equiv \left\{\begin{matrix}
\text{ The subarray } A[p \ldots r+1-1] \text{ contains the smallest sorted }  \\ 
r+1-p \text{ elements present in } L[1 \ldots n_{1}+1] \wedge  R[1 \ldots n_{2}+1] \\
L[i] \wedge R[j] \text{ are the smallest elements of their vectors respectively (not yet copied into A)}\\
L \wedge R \text{ contain } n_1 + n_2 + n_3 = r-p+3 \text{ elements } \\
\text{ This means, we copied all the elements into A and the guards have not been copied. }\\
\end{matrix}\right.
```

### Time Complexity - Merge

```math
T_{merge}(n) = \Theta(n) = 
\left\{\begin{matrix}
\mathcal{O}(1) & \text{ assignments and array creation} \\
\Theta(n_{1}) & \text{ for}_{1} \\
\Theta(n_{2}) & \text{ for}_{2} \\
\Theta(n)= \Theta(r-p+1) &  \text{ for}_{3} \\
\end{matrix}\right.
```

### Time Complexity - Mergesort

```math
T_{merge_sort}(n) =\left\{\begin{matrix}
\mathcal{O}(1) & n leq 1 \\
2T(n/2)+\Theta(n) & n > 1 \\
\end{matrix}\right.
```

Let's apply the Master Theorem

$$a=2, b=2, d=log_{b}(a) = log_{2}(2)= 1, f(n) = \Theta(n), g(n) = n$$

We are in the second case: 

$$f(n) = \Theta(n^{d}) \Rightarrow T(n) = \Theta(nlog(n))$$

---
### Conclusion

Pros:
* More **efficient** than Insertionsort even in the worst case, $T(n)= \Theta(n log(n))$
* It is a **stable** method, numbers with the same value have the same order in the array of output and input.

Cons:
* Not In-Place
* Not sensitive to order of the input 
  * If the input vector is already sorted, T(n)=Θ(n * log(n)) still.
* Depends on the number of keys to sort

We can optimize it by combining it with different algorithms, in order to handle a large variety of input.

---

### Extra Credits

* [1] [Programiz - MergeSort](https://www.programiz.com/dsa/merge-sort)