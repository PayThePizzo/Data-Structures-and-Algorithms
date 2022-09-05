# Sorting Recap

|                |         Method         |           T(n)            | Adaptive? | In-Place? | Stable? | Online? |
|----------------|:----------------------:|:-------------------------:|-----------|-----------|---------|---------|
| Insertion sort | Insertion, Incremental |          Θ(n^2)           |     Y     |     Y     |    Y    |    Y    |
| Merge sort     | Merging*               |        Θ(nlog(n))         |     N     |     N     |    Y    |    N    |
| Quick sort     | Partitioning*          | avg:O(nlog(n)), w: O(n^2) |     N     |     Y     |    N    |    N    |
| Heap Sort      | Selection, Incremental |        O(n*log(n))        |     Y     |     Y     |    Y    |    N    |
| Counting sort  | Non-Comparison         |  Θ(n)<= Θ(n+k)<= Θ(n^2)   |     N     |     N     |    N    |    N    |
| Radix sort     | Non-Comparison         |        Θ(d*(n+k))         | **        | **        | **      | **      |

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

Pseudo Code:
```python
insertion_sort(Array A)
    for j=2 TO A.length #Array starts from 1
        key = A[j]
        i = j-1
        while i > 0 AND A[i] > key #Modify predecessor when we find a smaller element
            A[i+1] = A[i] #Shifts forward
            i = i-1
        A[i+1] = key # Finds position in the sorted array
```

In C/C++:
```c++
void insertion_sort(int *arr, int size){
    for(int j = 1; j<size; j++){
        int i = j-1, key = *(arr+j);
        while(i>=0 && *(arr+i)> key){
            *(arr+i+1)= *(arr+i);
            i-=1;
        }
        *(arr+i+1)=key;
    }
}
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
int R[n2] = create_arrR(n2); # R = [1 .. n2+1] Aux Vector

# Copy in L & R, all the elements.
for (i = 1 to n1):
    L[i] = A[p+i-1];
for (j = 1 to n2):
    R[j] = A[q+j];

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

```c++
void merge(int arr[], int left, int center, int right){
    // Initialize Aux Arrays
    int left_size = center - left + 1, right_size = right - center;
    int aux_l[left_size], aux_r[right_size];

    for(int i = 0; i<left_size; i++)
        aux_l[i] = arr[left+i];
    for(int j = 0; j<right_size; j++)
        aux_r[j] = arr[center+1+j];
    
    int i = 0, j = 0, k = left;
    // Insert Smallest
    while(i<left_size && j<right_size) {
        if (aux_l[i] <= aux_r[j]) {
            arr[k] = aux_l[i];
            i++;
        } else {
            arr[k] = aux_r[j];
            j++;
        }
        k++;
    }
    // Insert the rest
    while (i < left_size) {
        arr[k] = aux_l[i];
        i++;
        k++;
    }
    while (j < right_size) {
        arr[k] = aux_r[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right){
    if(left<right){
        int center = left +((right-left)/2);
        merge_sort(arr, left , center);
        merge_sort(arr, center+1, right);
        merge(arr, left, center , right);
    }
}
```


---

## Quick sort

![Quick Sort Gif](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/quicksortgif.gif)

```python
partition(Array A, int p, int r)
x = A[r];   #Last element
i = p-1;
for (j = p to r-1):
    if (A[j] <= x): #Swap if the invariant holds true
        i++;
        swap(A[i], A[j]);
swap(A[i+1], A[r]); #Put pivot back to the right position
return i+1;

quick_sort(Array A, int p, int r)
    if(p < r):
        q = Partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
```

```c++
void swap(int *a, int *b){
    int temp = *a;
    *a =  *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    // pivot is the last element
    int pivot = arr[right];
    // i is the u
    int i = left-1;
    //stop before considering pivot
    for(int j = left; j<right; j++) {
        //only swap elements that <= pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    //move pivot between subarrays
    //arr[left ... i]<= pivot < arr[i+2...right]
    swap(&arr[i+1], &arr[right]);
    //return pivot index
    return i+1;
}

void quicksort(int arr[], int left, int right){
    if(left < right){
        // Not included inside the sub arrays
        int q = partition(arr, left, right);
        //arr[p...q-1] contains arr[i]<=arr[q]
        quicksort(arr, left, q-1);
        //arr[p...q-1] contains arr[i]>arr[q]
        quicksort(arr, q+1, right);
    }
}
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
1. Allocation and Initialization of a vector C of lenght k
2. Count the occurrences of elements in A.
    1. Es: C[A[i]], with i=3 is the count of times A[] contains the number three.
3. Cumulative sum of values in C
    1. `i` represents the index of the element C[i] in the new sorted array
4. Because an element might be repeated, we decrement the value of C[i] every time it is read.

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

```c++
void counting_sort(int *input, int *output, int n, int k){
    int aux[k+1];
    for(int i = 0; i<=k; i++) 
        aux[i]=0;
    for(int i = 0; i<n; i++) 
        aux[*(input+i)]++;
    for(int i = 1; i<=k; i++) 
        aux[i]+=aux[i-1];
    for(int i = n-1; i>=0; i--) 
        *(output+(--aux[(*(input+i))])) = *(input+i);
}
```

---

## Radix sort
Sorts an array `A` of elements with `d` digits, from the less significant one.
* Ex: A={31, 13, 22} 
  * After sorting on last digit, A = {31, 22, 13}
  * After sorting on the first digit, A = {13, 22, 31}

```python
radixsort(array A, int d)
    for (i = 1 to d):
        Apply to A, a stable sorting algorithm that sorts it on i-th digit
```

---


Check out [this website](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html) for more algorithm visualization!