# Quick Sort
Quick sort belongs to a class of algorithms which use a Divide-et-Impera approach.

[1] [Quick Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/quicksort.png?raw=TRUE)

---

## Invariant
INV ≡
* x = A[r] is always true at all times
* For every k ∈ [p..i], A[k]<= x
* For every k ∈ [i+1..r], A[k]>= x
* `p <= j <= r`
* `p-1 <= i <= j-1`

We can confirm this is holds true at all times:
1) Initialization
2) Preservation
3) Conclusion: 
   * At the end of the for block `j = r`
   * This means: `p ≤ j ≤ r` and `p − 1 < j < r − 1`.
   * Furthermore, the last two lines of code in the partition function, insert the pivot in the right position.

---

## The Algorithm - Divide et Impera
1. Divide: After choosing a pivot element from A such that `pivot = A[q]`, the vector is partitioned in two sub-vectors 
A[p..q-1] & A[q+1..r] (can be empty), such that:
   1. Every element in A[i] ∈ A[p..q-1] <= A[q]
   2. Every element in A[j] ∈ A[q+1..r] >= A[q]
   3. A[q] is the *pivot*, the element used to create the partitions and every element that is smaller or larger,
   is shifted to one of the sub-arrays (so that the conditions are respected)
3. Impera: sorts the sub-vectors recursively through quicksort, unless the input is trivially small (0/1 element).
4. Merge: in this case there is no merge phase, because the algorithm sorts in place

```python
quick_sort(Array A, int p, int r)
    if(p < r):
        q = Partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);

partition(Array A, int p, int r)
    x = A[r];   #Last element
    i = p-1;
    for (j = p to r-1):
        if (A[j] <= x): #Swap if the invariant holds true
            i++;
            swap(A[i], A[j]);
        swap(A[i+1], A[r]); #Put pivot back to the right position
    return i+1;

```
**Final Time Complexity** T(n) = O(n**2)
* Highly depends on the type of partitions created 
* If sub-vectors are balanced: T(n) = O(n * log(n)) which is the average case

---

## Randomized Version

```python
randomized_partition(int arr[], int p, int r)
    int i = random(p,r); #returns random integer between p and r
    swap(&arr, i, r);
    return partition(arr, p, r);

randomized_quicksort(int arr[], int p, int r)
    if(p < r):
        q = randomized_partition(arr, p, r);
        randomized_quicksort(arr, p, q - 1);
        randomized_quicksort(arr, q + 1, r);
```

---

### Conclusion

Pro:
* In-Loco
* Worst Case is very rare, and normally it is very efficient
* Randomizing the pivot is a solution for when input is sorted
* Tri-partition improves the computing complexity

Con:
* Worst Case T(n) = O(n**2)
* Not Stable
* Slow when input is already sorted (asc/desc) or all the elements have equal values

---

### Extra Credits
* [1] [CSE Stack - Quick Sort](https://www.csestack.org/quicksort/)