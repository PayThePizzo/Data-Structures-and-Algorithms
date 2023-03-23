# Quick Sort

| **Operation** 	| **Method**                     	| **Time**                                                                             	      | **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|---------------	|--------------------------------	|---------------------------------------------------------------------------------------------|---------------	|---------------	|-------------	|-------------	|
| _Quick sort_  	| Divide et Impera, Partitioning 	| $T_{b}(n) = \Theta(nlog(n)), T_{avg}(n) = \mathcal{O}(nlog(n)), T_{w}(n) = \Theta(n^{2})$ 	 | N             	| **Y**         	| N           	| N           	|

---

## Idea

Quick sort belongs to a class of algorithms which use a Divide-et-Impera approach.

![Quick Sort](https://raw.githubusercontent.com/PayThePizzo/DataStrutucures-Algorithms/main/Resources/quicksort.png?raw=TRUE)

---

## The Algorithm - Divide et Impera
1. **Divide**: After choosing a pivot element from $A$ such that $pivot(A) = A[q]$, the vector is partitioned in two sub-vectors $A[p \ldots q-1]$ and $A[q+1 \ldots r]$ (can be empty), such that 
   1. $\forall A[i] \in A[p \ldots q-1] \ni' A[i] \leq A[q]$
   2. $\forall A[j] \in A[q+1 \ldots r] \ni' A[j] \geq A[q]$
   3. $A[q]$ is the *pivot*, the element used to create the partitions and every element that is smaller or larger, is shifted to one of the sub-arrays (so that the conditions are respected).
2. **Impera**: sorts the sub-vectors recursively through quicksort, unless the input is trivially small ($0 \vee 1$ element).
3. **Merge**: in this case there is no merge phase, because the algorithm sorts in place

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

### Invariant

```math
INV \equiv \left\{\begin{matrix}
x=A[r] \text{ is always true}& \wedge \\
\forall k \in [p \ldots i] \ni' A[k] \leq x & \wedge \\
\forall k \in [i+1 \ldots j-1] \ni' A[k] > x& \wedge \\
p \leq j \leq r & \wedge \\
p-1 \leq i \leq j-1 \\
\end{matrix}\right.
```

We can confirm this is holds true at all times:
1. Initialization 
2. Preservation 
3. Conclusion:
   * At the end of the for block $j = r$
   * This means: $p \leq r \leq r$ and $p − 1 \leq r \leq r − 1$.
   * Furthermore, the last two lines of code in the partition function, insert the pivot in the right position by changing it with the leftmost element larger than x.

```math
INV[r/j] \equiv \left\{\begin{matrix}
x=A[r] \text{ is always true}& \wedge \\
\forall k \in [p \ldots i] \ni' A[k] \leq x & \wedge \\
\forall k \in [i+1 \ldots j-1] \ni' A[k] > x& \wedge \\
p \leq r \leq r & \wedge \\
p-1 \leq i \leq r-1 \\
\end{matrix}\right.
```

![invariantquicksort](https://raw.githubusercontent.com/PayThePizzo/DataStrutucures-Algorithms/main/Resources/invariantquicksort.png?raw=TRUE)

### Time Complexity

```math
T_{partition}(n) = \Theta(n) = \left\{\begin{matrix}
\mathcal{O}(1) & \text{ assignments }\\
\Theta(n) & \text{ for block } r-p-1=n  \\
\end{matrix}\right.
```

And

```math
T_{quicksort}(n) = \left\{\begin{matrix}
c & n \leq 1\\
T(k)+T(n-k-1)+ \Theta(n) & n>1  \\
\end{matrix}\right.
```

Where 
* $k$ is the count of elements of the first sub-array
* $n-k-1$ is the count of elements of the second sub-array (excluding the pivot $-1$)

$T_{quicksort}(n)$ depends on the partitioning method of the subarray

```math
T_{quicksort}(n) = \left\{\begin{matrix}
T_{worst}(n)& \Theta(n^{2}) \\
T_{best}(n) &\Theta(nlog(n))  \\
T_{average-constant}(n) & \mathcal{O}(nlog(n))  \\
T_{average-non-constant}(n)& \Theta(nlog(n))  \\
\end{matrix}\right.
```

#### Demonstration - Worst Case
In the worst case the sub-arrays are highly unbalanced

$$T_{worst}(n) = T(n-1) + T(0) + \Theta(n), \text{ since } |sub_{1}|=n-1 \wedge |sub_{2}|=0$$

![wcquicksort](https://raw.githubusercontent.com/PayThePizzo/DataStrutucures-Algorithms/main/Resources/wcquicksort.png?raw=TRUE)

$$T_{worst}(n) = T(n-1) + c + \Theta(n) \Rightarrow T_{worst}(n) = T(n-1) + \Theta(n) = T(n-1)+cn $$

$$T_{worst}(n) = T(0) + \sum_{i=1}^{n}ci = T(0) + c\sum_{i=1}^{n}i = T(0)+c \frac{(n+1)n}{2} = \Theta(n^{2})$$

#### Demonstration - Best Case
In the best case the sub-arrays contain exactly almost half of the total elements respectively 

$$T_{best}(n) = 2T(n/2) + \Theta(n), \text{ since } |sub_{1}|=n/2 \wedge |sub_{2}|=(n/2)-1$$

By the Master Theorem

$$f(n) = \Theta(n^{log_{b}(a)}) = \Theta(n) \stackrel{2_{nd}} \Longrightarrow T_{best} = \Theta(nlog(n))$$

#### Demonstration - Average Case (constant)
In the average case, we find a constant repartition of the subarrays for example $9:1$ :

$$T_{average-constant}(n) = T(n/10) + T(9n/10) + cn$$

By the Occurrences Tree method we find that:

![avg1quicksort](https://raw.githubusercontent.com/PayThePizzo/DataStrutucures-Algorithms/main/Resources/avg1quicksort.png?raw=TRUE)

So:
1. The height of the tree is $h = log_{10}(n)$
2. The longest path from the root, to a leaf here is found by keep going right, $log_{10/9}(n)$
   1. Which is where the recursion stops
3. The maximum cost of a level is $cn$
   1. Every level has cost $cn$ until we reach the depth $log_{10}(n)$ where it becomes the upperbound for the cost of a level

Then:

$$T_{average-constant}(n) \leq cn \cdot log_{10/9}(n) \Rightarrow T_{average-constant}(n) = \mathcal{O}(nlog(n)) $$

From this we can generalize that:

```math 
T(n) = T(\alpha n) + T(n(1- \alpha)) + cn \text{, where } 0 < \alpha < 1 \wedge c > 0 \text{ } \Longrightarrow T(n) = \Theta(nlog(n))
```

#### Demonstration - Average Case (non-constant)
In the average case where there are two options that keep repeating:
* We assume that the input's permutations are i.i.d

```math 
T_{average-non-constant}(n) = \left\{\begin{matrix}
T_{lucky}(n)\rightarrow L(n) = 2U(n/2)+\Theta(n) \\
T_{unlucky}(n)\rightarrow U(n)=L(n-1)+\Theta(n)  \\
\end{matrix}\right.
```

Then:

$$L(n) = 2( L(\frac{n}{2}-1) + \Theta(\frac{n}{2})) + \Theta(n) =  2L(\frac{n}{2}-1) + 2\Theta(\frac{n}{2})) + \Theta(n)$$

$$L(n) =  2L(\frac{n}{2}-1) + 2\Theta(\frac{n}{2})) + \Theta(n) =  2L(\frac{n}{2}-1)+ \Theta(n)$$

$$L(n) =  2L(\frac{n}{2}-1)+ \Theta(n) = \Theta(nlog(n))$$

---

## Avoiding Worst Case: Randomized Version
Instead of choosing $A[r]$ as pivot, we use a random pivot in $A[p \ldots r]$
* We assume all the keys are distinct

```python
#returns random integer between p and r
int randomized_partition(int arr[], int p, int r)
    int i = random(p,r); 
    swap(&arr, i, r); #swap arr[i] and arr[j]
    return partition(arr, p, r);

randomized_quicksort(int arr[], int p, int r)
    if(p < r):
        q = randomized_partition(arr, p, r);
        randomized_quicksort(arr, p, q - 1);
        randomized_quicksort(arr, q + 1, r);
```

$$T_{avg}(n) = \Theta(nlog(n)) \wedge T_{w}(n) = \Theta(n^{2})$$

Pros:
1. $T(n)$ does not depend on the input's order
2. No assumption on the input's distribution.
3. No specific input can define the worst case 
4. The random number generator defines the worst case
5. It is 3 to 4 times faster than the normal version.

---

## Optimization - Insertionsort on small vectors
By using a value m `5 <= m <= 25` to have a range of cases where the insertion sort overrides the main algorithm
can help to improve the average case scenario.

Case 1: We can either sort it only if the input is in range
```python
quicksort(int * arr, int p, int r)
   if(r - p <= M):
      insertionsort(arr);
```

Case 2: 
```python
quicksort(int * arr, int p, int r)
   if(r - p <= M):
      return;

sort(int * arr, int p, int r)
    quicksort(arr, p, r); # partially sorted vectors
    insertionsort(arr); # we sort the rest with insertion sort
```

## Optimization 2 - Median as pivot
Using a value $m$ the pivot for the quicksort means, 
1. Choosing the median out of three elements inside an unsorted vector:
   * A leftmost element
   * A rightmost element
   * A center element
2. Swapping it with $A[r]$
3. Applying the algorithm


## Optimization 3 - Dutch Flag (Tri-Partition)
When we find duplicates, not even randomizing the choice of the pivot can help much.

Instead, of dividing the vector in 2 parts we divide it in 3 parts:
1) Partition with elements $i < x$
2) Partition with elements $i > x$
3) Partition with elements $i = x$

This slightly changes the invariant, but the main idea stays the same.

Partition:
1. Permutation of the elements in $A[p \ldots r]$
2. Returns $q$ and $t$, $p \leq q \leq t \leq r$
   1. $\forall A[i] \in A[q \ldots t] \ni' A[i=q] = A[i+1] = \ldots = A[t=i+n]$
   2. $\forall A[i] \in A[p \ldots q-1] \ni' A[i] < A[q]$
   3. $\forall A[i] \in A[q+1 \ldots r] \ni' A[i] > A[q]$
3. $T(n) = \Theta(r-p)$

```python
partition(int * arr, int p, int r)
    int x = arr[r];
    int min = p, eq = p, max = r;

    # Theta(r-p)
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
    return [min, max]; #pair

    
quicksort(int * arr, int p, int r)
    if(p < r):
        int[] qt = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, t + 1, r);
```

### Invariant

```math
INV \equiv 
\left\{ \begin{matrix}
x=A[r] \text{ is always true} & \wedge \\
\forall k \in [p \ldots min) \ni' A[k] \leq x & \wedge \\
\forall k \in [min \ldots eq) \ni' A[k] = x & \wedge \\
\forall k \in [max \ldots r) \ni' A[k] > x & \wedge \\
p \leq min \leq eq \leq max \leq r & \wedge \\
\end{matrix}\right.
```

We obtain something like this: 

`| < x | = x | ? | > x | x |`

`|p    |min  | eq| max | r |`

We can confirm this is holds true at all times:
1. Initialization
2. Preservation
3. Conclusion: When the execution ends, we have $eq = max$
   1. The last two lines swap the pivot $A[r]$ with the first element larger than $x$
   2. We obtain the desired partition

```math
INV[max/eq]\equiv 
\left\{ \begin{matrix}
x=A[r] \text{ is always true} & \wedge \\
\forall k \in [p \ldots min) \ni' A[k] \leq x & \wedge \\
\forall k \in [min \ldots max) \ni' A[k] = x & \wedge \\
\forall k \in [max \ldots r) \ni' A[k] > x & \wedge \\
p \leq min  \leq max \leq r & \wedge \\
\end{matrix}\right.
```

The result is: 

`| < x | = x | > x | x |`

`|p    |min  | max | r |`

### Complexity
If all the elements are equal

$$T(n) = \Theta(n=r-p+1)$$

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
* Not adaptive: slow when input is already sorted (asc/desc) or all the elements have equal values

---

### Extra Credits
* [1] [CSE Stack - Quick Sort](https://www.csestack.org/quicksort/)