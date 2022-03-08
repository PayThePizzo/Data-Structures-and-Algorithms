# Merge Sort
Merge sort belongs to a class of algorithms which use a Divide-et-Impera approach.

The MergeSort function repeatedly divides the array into two halves until 
we reach a stage where we try to perform MergeSort on a subarray of size 1.[1]

After that, the merge function comes into play and combines the sorted arrays into larger 
arrays until the whole array is merged.[1]

![Merge Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesort.jpg?raw=TRUE)

---

## Invariant
As we know, the study of the invariant must be completed by analyzing all the iteration cycles.
Here, we will only focus on the third one.

**INV**:
* The sub-vector A[p..k-1] contains the smallest sorted `k-p` elements present in L[1.. n1+1] and
R[1.. n2+1].
* Moreover, L[i] and R[j] are the smallest elements of their vectors respectively (not yet copied into A).

1) Initialization: Respected
2) Preservation: Respected
3) Conclusion: When the for block stops, `k = r+1`

INV[(r+1)/k] ≡
* The sub-vector A[p..r+1-1] contains the smallest sorted `r+1-p` elements present in L[1.. n1+1] and
  R[1.. n2+1].
* Moreover, L[i] and R[j] are the smallest elements of their vectors respectively (not yet copied into A).
* In conclusion, L & R contain `n1+n2+n3 = r-p+3` elements. This means, we copied all the elements into A
and the guards have not been copied.

---
## The Algorithm - Divide et Impera
It sorts a vector limited by two indexes *p*, representing the starting index, and *r*,
representing the ending index.

1. **Divide/Split**: recursively divides the main vector into two sub-vectors A[p .. q] with `q = (p+r)/2` and A[q+1 .. r]
2. **Impera**: recursively sorts the sub-vectors through mergesort. 
   1. If the problem is sufficiently small (0/1 elements), we can compute the result immediately
   2. Else if one of the vectors is empty, we put in the queue the remaining subsequence of the vector.
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

### Merge Sort
* Pre: p,r are valid indexes of A.
* Post: sorts A correctly

```python
merge_sort(Array A, int p, int r)
    if (p<r): # A contains at least two elements
        q = ⌊(p+r)/2⌋;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
```

### Merge
Pre:
* `p <= q <= r`
* A[p..q] is sorted && A[q+1..r] is sorted
* A[p..q] and A[q+1..r] are not empty

Post: 
* Sub-vectors are correctly merged together into a sorted vector.

```python
Merge(Array A, int p, int q, int r)
    #Initialization
    n1 = q - p + 1; # Lower
    n2 = r - q; # Upper
    int L[n1] = create_arrL(n1); # L = [1 .. n1+1] Aux Vector
    int R[n1] = create_arrR(n2); # R = [1 .. n2+1] Aux Vector
    
    # Copy in L & R, all the elements.
    for (i = 1 to n1):
        L[i] = A[p+i-1];
    for (j = 1 to n2):
        R[i] = A[q+j];
    
    # Guard condition
    L[n1+1] = infinity();
    R[n2+1] = infinity();
    i = 1, j = 1;
    
    for (k = p to r)
        if (L[i] <= R[j]):
            A[k] = L[i];
            i++;
        else:
            A[k] = R[j];
            j++;
```
**Final Time Complexity** T(n) = <mark>Θ(n * log(n))</mark>
* Merge: T(n) = Θ(n)
  1) variable initialization: O(1)
  2) for block: Θ(n)
  3) for block: Θ(n)
  4) for block: Θ(n)
* Sort: T(n) = Θ(log(n))

** _Guard condition_: Infinity() is a **technique in pseudocode** used to avoid running out 
of elements inside the two sub-vectors. We never check if one of the two vectors is empty.

---
### Conclusion

Pros:
* More **efficient** than Insertion-Sort even in the worst case, T(n)=Θ(n * log(n))
* It is a **stable** method, numbers with the same value have the same order in the array
of output and input.

Cons:
* Not In-Place
* Not sensitive to order of the input 
  * If the input vector is already sorted, T(n)=Θ(n * log(n)) still.
* Depends on the number of keys to sort

We can optimize it by combining it with different algorithms, in order to handle
a large variety of input.

---

### Extra Credits

* [1] [Programiz - MergeSort](https://www.programiz.com/dsa/merge-sort)