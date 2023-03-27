# Counting Sort

| **Operation**   	| **Method**     	| **Time**                                        	| **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|-----------------	|----------------	|-------------------------------------------------	|---------------	|---------------	|-------------	|-------------	|
| _Counting sort_ 	| Non-Comparison 	| $\Theta(n) \leq \Theta(n+k) \leq \Theta(n^{2})$ 	| N             	| N             	| **Y**       	| N           	|

---

## Idea

Counting sort is a sorting algorithm that works by counting the number of occurrences of each unique element in the
input array and then using these counts to determine the position of each element in the sorted output array.

---

## Pre-Conditions
1. The numbers to sort are **integers** in an interval of $0 \ldots k$
   1. $k \in \mathbb{Z}^{+}$
---

## The Algorithm

Requirements:
* **Input**:
  * $A[1 \ldots n]$ where $A[j] \in [0 \ldots k], \forall j \in \lbrace 1 \ldots n \rbrace$
  * $n$ is the size of the array
  * $k$ is the upper bound integer of the range $0 \ldots k$ to sort
* **Output**: $B[1 \ldots n]$ is a sorted vector in a non-decreasing manner
* **Auxiliary Data Structure** $C[0 \ldots k]$ is the vector of the occurrences of size $k+1$,
with possible indices $i \in 0 \ldots k$

Steps:
1. Allocation and Initialization of a vector of occurences $C$ of size $k+1$ with indices in $0 \ldots k$
2. Populate $C$ starting from $0$:**count the occurrences** of elements with same keys in $A$.
   1. Es: $C[A[i]]$, with $i=3$ is the count of times $A$ contains the number three.
3. Cumulative prefixed sum of values in C starting from $i=1$: **count how many elements precede the current one**
   1. $i$ represents the index of the element $C[i]$ in the new sorted array
   2. For each element in $C$, increase its value by the value in the previous index. This helps us find the right position
   in $B$
4. Populate $B$ from $n$ to $1$, to achieve stability.
   1. Because an element might be repeated, we decrement the value of $C[i]$ every time it is read.

```python
void countingsort(array A, array B, int n, int k) {
    Allocation C[0...k]; #aux data structure
    #O(k)
    for (i = 0 to k):  #Initialization of C to 0
        C[i] = 0;
    #Theta(n)
    for (i = 1 to n): # count occurrences of elements in A
        C[A[i]]++;
    #Theta(k)
    for (i = 1 to k):
        C[i] = C[i] + C[i-1] #prefixed sums
    #Theta(n)
    for (i = n down to 1):
        B[--C[A[i]]] = A[i]; #insert and avoid duplicates or insertion in same position
```

Example: 

![countingsortex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/countingsortex.png?raw=TRUE)

**Final Time Complexity**: $T(n) = \Theta(n+k)$
* Usually best when $k = \mathcal{O}(n) \Rightarrow T(n) = \Theta(n+k)$

--- 

## Conclusions
Pro:
* If $k = \mathcal{O}(n) \Rightarrow T(n) = \Theta(n+k)$
* It is a **stable sorting algorithm**, if we start from the end.

Cons:
* **Not** in-place (we use an auxiliary vector C[0..k])
* Only sorts numbers between 0 and k, **restricted integer spectrum**.
* If the interval of numbers go from 0 to $n^2$ then it is not efficient: $T(n) =\Theta(n+ n^{2}) = \Theta(n^{2})$
