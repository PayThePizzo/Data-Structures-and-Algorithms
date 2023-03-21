# Insertion Sort

| **Operation**    	| **Method**             	| **Time**                   	| **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|------------------	|------------------------	|----------------------------	|---------------	|---------------	|-------------	|-------------	|
| _Insertion sort_ 	| Insertion, Incremental 	| $T_{w}(n) = \Theta(n^{2})$ 	| **Y**         	| **Y**         	| **Y**       	| **Y**       	|

---

## Idea

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing 
cards in your hands. The array is virtually split into a **sorted** and an **unsorted part**. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.

![Insertion Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/insertionsort.png?raw=TRUE)


## Incremental Technique 
The array is virtually split into a $k$ **sorted** and an $A.length-k$ **unsorted part**.

```math
\text{ int A }[\text{ }] = \left\{\begin{matrix}
A[1, \ldots, j] & \text{ k sorted elements} \\
A[j+1, \ldots, A.length]& \text{A.length-k elements to sort} \\
\end{matrix}\right.
```

Initially,`k = 1`. Our goal is to extend the sorted part of the array from k to k+1 
by placing in the correct position an element from the unsorted section at each iteration.


## In-Loco sorting
This algorithm sorts in-place, namely with an external additional space $S(n) = \mathcal{O}(1)$.

## Adaptive
The algorithm is sensitive about the input's order, or better it is **adaptive**.

---

## The Algorithm

Idea: 
* A first cycle to go through all the cards, a second one to 
* We start from an index i = 2, since the first card is sorted for definition.

To sort an array of size n in ascending order:
* 1: Iterate from arr[1] to arr[n] over the array.
* 2: Compare the current element (key) to its predecessor.
* 3: If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.

Pseudocode:
```python
insertion_sort(Array A)
    for j=2 TO A.length #Array starts from 1
        key = A[j]; 
        i = j-1; 
        while i > 0 AND A[i] > key #Modify predecessor when we find a smaller element
            A[i+1] = A[i];
            i = i-1;
        A[i+1] = key;
```

Implementation in C and C++:
```c++
void insertion_sort_c(int *arr, int size){
    for(int j = 1; j<size; j++){
        int i = j-1;
        int key = *(arr+j);
        while(i>=0 && *(arr+i)> key){
            *(arr+i+1)= *(arr+i);
            i-=1;
        }
        *(arr+i+1)=key;
    }
}

void insertion_sort_cpp(std::vector<int> &array){
    for(int j = 1; j<array.size(); j++){
        int i = j-1;
        int key = array.at(j);
        while(i>=0 && array.at(i)>key){
            array.at(i+1) = array.at(i);
            i-=1;
        }
        array.at(i+1)=key;
    }
}
```

### Invariant of the for-cycle
$$INV  = \text{The subarray } A[1 \ldots j-1] \text{ is made of the sorted elements which were originally in } A[1 \ldots j-1]$$

This is true:
1) _Initialization:_ This is trivially true before the *for block*
   1) By construction, $j=2 \rightarrow A[1]$
2) _Preservation_: It is respected before any iteration
3) _Conclusion_: After the for block, j stops at **j = A.length+1**
   1) Then $A[1 \ldots j-1]$ is sorted
   2) Which means $A[1 \ldots A.length + 1-1]$ is made of the sorted elements which were originally in $A[1 \ldots A.length+1-1]$

### Complexity: Theorem - $T(n) = \Theta(n^{2}) \wedge S(n) = \mathcal{O}(1)$
The insertion sort algorithm sorts in-place $S(n) = \mathcal{O}(1)$, and executes $\Theta(n^{2}) comparisons in 
the worst case. 

#### Demonstration
The algorithm sorts **in-place** as it only requires one additional variable aside from the input array.

The for cycle is executed exactly $n-1$ times and the number of comparisons executed in the inner cycle (while),
is $j-1$ in the worst case.
* We assume the comparisons to be the fundamental operation in this algorithm.

$$\sum_{j=2}^{n}(j-1) \stackrel{k=j-1} \Longrightarrow \sum_{k=1}^{n+1}k = \frac{(n-1)(n-1+1)}{2} = \frac{(n-1)n}{2} = \Theta(n^{2})$$

Where $n = A.length$

**Final Time Complexity** = $T(n) = \Theta(n^{2})$
* $T_{best}(n) =  \Theta(n)$
  * Array sorted in a non-decreasing manner 
* $T_{avg}(n) = \Theta(j/2)$
* $T_{worst}(n) =  \Theta(n^{2})$
  * Array sorted in a non-increasing manner

We conclude that the algorithm is sensitive about the input's order, or better it is **adaptive**.

---

### Conclusion
Pros: 
* Works well with small vectors

--- 

### Extra Credits

* [GfG - Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)