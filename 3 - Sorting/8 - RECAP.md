# Sorting Recap

|                |         Method         |            T(n)            | Adaptive? | In-Place? | Stable? | Online? |
|----------------|:----------------------:|:--------------------------:|-----------|-----------|---------|---------|
| Insertion sort | Insertion, Incremental |           Θ(n^2)           |     Y     |     Y     |    Y    |    Y    |
| Merge sort     | Merging*               | avg: O(nlog(n)), w: O(n^2) |     N     |     N     |    Y    |    N    |
| Quick sort     | Partitioning*          |           O(n^2)           |     N     |     Y     |    N    |    N    |
| Heap Sort      | Selection, Incremental |         O(n*log(n))        |     Y     |     Y     |    Y    |    N    |
| Counting sort  | Non-Comparison         |   Θ(n)<= Θ(n+k)<= Θ(n^2)   |     N     |     N     |    N    |    N    |
| Radix sort     | Non-Comparison         |         Θ(d*(n+k))         | **        | **        | **      | **      |

**Depends on subroutine, `d` is the number of iterations in the function

---

## Insertion sort
The array is virtually split into a **sorted** and an **unsorted part**.
* At beginning A[1] is sorted, by definition is like an array of one element
* A[2..n] is unsorted, or at least know nothing a-priori

At each array-position, it checks the value there against the largest value in the sorted list (which happens to be next
to it, in the previous array-position checked). If larger, it leaves the element in place and moves to the next. 
If smaller, it finds the correct position within the sorted list, shifts all the larger values up to make a space, 
and inserts into that correct position.


![Insertion Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/insertionsortgif.gif)

```python
insertion_sort(Array A)
    for j=2 TO A.length #Array starts from 1
        key = A[j]
        i = j-1
        while i > 0 AND A[i] > key #Modify predecessor when we find a smaller element
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key 
```

---

## Merge sort

![Merge Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesortgif.gif)

```python
merge(Array A, int p, int q, int r)
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

        
merge_sort(Array A, int p, int r)
    if (p<r): # A contains at least two elements
        q = ⌊(p+r)/2⌋;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
```

---

## Quick sort

![Quick Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/quicksortgif.gif)

```python
partition(int * arr, int p, int r)
    int x = arr[r];
    int min = p, eq = p, max = r;
    while(eq < max):
        if(arr[eq] < x):
            swap(arr, min, eq);
            eq++;
            min++;
        else if(arr[eq] == x):
            eq++;
        else:
            max--;
            swap(arr, max, eq);

    swap(arr, r, max);
    return [min, max];

    
quicksort(int * arr, int p, int r)
    if(p < r):
        int[] qt = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, t + 1, r);
```

---

## Heap sort

![Heap Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/heapsortgif.gif)

```python

max_heapify(Heap A, Node i)
l = left(i);
r = right(i);
if (l <= A.heap_size && A[l]>A[i]):
    max = l;
else:
    max = i;
if (r <= A.heap_size && A[r] > A[max]):
    max = r;
if (i != max):
    swap(A[i],A[max]);
    max_heapify(A, max);

    
build_maxheap(Array A)
A.heap_size = A.length
for (i = ⌊A.length/2⌋ down to 1):
    max_heapify(A, i);
    
    
Heap_sort(Array A)
    build_maxheap(A);
    for (i = A.length down to 2):
        swap(A[i], A[1]);
        A.heapsize = A.heapsize-1;
        max_heapify(A, 1);
```

---

## Counting sort

![Counting Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/countingsortgif.gif)


```python
void countingsort(array A, array B, int n, int k) {
    Allocation C[0...k]; #aux data structure
    for (i = 0 to k):  #Initialization of C to 0
        C[i] = 0;
    for (i = 1 to n): # count occurrences of elements in A
        C[A[i]]++;
    for (i = 1 to k):
        C[i] = C[i] + C[i-1] #prefixed sums
    for (i = n down to 1):
        B[C[A[i]]] = A[i]; #insert
        C[A[i]]--; #to avoid duplicates or insertion in same position
```

---

## Radix sort

```python
radixsort(array A, int d)
    for (i = 1 to d):
        sort(A, i)
```

---


Check out [this website](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html) for more algorithm visualization!