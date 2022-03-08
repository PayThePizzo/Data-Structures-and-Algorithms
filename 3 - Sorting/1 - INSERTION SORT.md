# Insertion Sort
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing 
cards in your hands. 

The array is virtually split into a **sorted** and an **unsorted part**. 
Values from the unsorted part are picked and placed at the correct position in the sorted part

![Insertion Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/insertionsort.png?raw=TRUE)

Characteristics:
* Incremental
* In-Loco Sorting

--- 

## Incremental Technique 
The array is virtually split into a  k **sorted** and an  A.length-k **unsorted part**.

Initially,`k = 1`. Our goal is to extend the sorted part of the array from k to k+1 
by placing in the correct position an element from the unsorted section at each iteration.

---

## In-Loco sorting
This algorithm sorts in-place, namely with an external additional space S(n)= O(1).

---

## Invariant
The sub-array A[1 .. j-1] is made of the sorted elements which were in A[1...j-1] originally.
1) _Initialization:_ This is trivially true before the *for block*
2) _Preservation_: It is respected
3) _Conclusion_: After the for block, j stops at **j = A.length-1** 

**INV[(A.length+1)/j]** ≡ The subarray A[1... A.length+1-1] is composed of sorted elements which were originally in
A[1...A.length+1-1]

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

```python
insertion_sort(Array A)
    for j = 2 TO A.length #Array starts from 1
        key = A[j]
        i = j-1
        while i > 0 AND A[i] > key
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
```
**Final Time Complexity** =  <mark>Θ(n**2)</mark>
* Best =  Θ(n)
  * Sorted Array
* Worst =  Θ(n**2)
  * Unsorted Array
* Average =  Θ(n**2)

---

### Conclusion
Pros: 
* Works well with small vectors 
* It is sensitive to unordered input

--- 

### Extra Credits

* [GfG - Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)