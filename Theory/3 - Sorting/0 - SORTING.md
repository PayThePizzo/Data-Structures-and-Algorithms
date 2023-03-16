# Sorting
Sorting is one of the fundamental problems of Computer Science.

Formally, the output of any sorting algorithm must satisfy two conditions:
1. The output is in monotonic order (each element is no smaller/larger than the previous element, according to the required order).
2. The output is a permutation (a reordering, yet retaining all of the original elements) of the input.

Here we will introduce some main concepts and characteristics of the sorting algorithms we are going to
study in this section [3]:
1. Computational Complexity, T(n)
   1. **Adaptability**
2. Space Complexity, S(n)
   1. **In-Loco** (In-Place) or not
3. Usage of Iteration and/or recursion
4. **Stability**
5. Whether they are a **comparison sort** or not
6. **Method**
   1. Divide et Impera
      1. Merging
      2. Partitioning
   2. Insertion
   3. Selection
   4. Exchanging
7. **Online**
8. Totality
   1. Total Sorting
   2. Partial Sorting
      1. Incremental Sorting

---

## 1 - Computational Complexity
We know an algorithm has a best, an average and a worst time. Here we focus on the latter one, but we will mention any important
details regarding the average case, and the best case when considering adaptive algorithms.

## 1.1 - Adaptability
The algorithm's sensitivity to the "pre-sortedness" of the input. An **adaptive** algorithm's T(n) is **visibly reduced when** its
**input** is already partly or totally **sorted**.

A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input. 
It benefits from the presortedness in the input sequence – or a limited amount of disorder for various definitions 
of measures of disorder – and sorts faster. Adaptive sorting is usually performed by modifying existing sorting algorithms.

The Adaptive sorting algorithms we will cover are:
* Insertionsort
* Heapsort

---

## 2 - Space Complexity

## 2.1 - In-Place
**(Strict) Definition**: An In-Place sorting algorithm is an algorithm which transforms input using **no auxiliary data structure**. [1]

However, a small amount of extra storage space is allowed for auxiliary variables. In this case, **at all times**, 
a space **S(n) = O(1)** (constant) is the **upper bound** for the space that can be used 
**for variables that are external to the input data structure**.

The In-Place sorting algorithms we will cover are:
* Insertionsort
* Quicksort
* Heapsort

---

## 4 - Stability
Stable sort algorithms sort equal elements in the same order that they appear in the input.

More formally, the data being sorted can be represented as a record of values, 
and the part of the data that is used for sorting is called the key.

A sorting algorithm is **stable** if **whenever there are two records R and S with the same key and with R appearing before S
in the original list, R will appear before S in the sorted list**.

The Stable sorting algorithms we will cover are:
* Insertionsort
* Mergesort
* Heapsort

---

## 5 - Comparison Sort
A comparison sort is a type of **sorting algorithm** that **only reads the list elements through** a single abstract **comparison** 
operation (often a "less than or equal to" operator or a three-way comparison) that determines which of 
two elements should occur first in the final sorted list. 

The only requirement is that the operator forms a total preorder over the data, with:
1. If a ≤ b and b ≤ c then a ≤ c (transitivity)
2. For all a and b, a ≤ b or b ≤ a (connexity).

It is possible that both a ≤ b and b ≤ a; in this case either may come first in the sorted list.
In a stable sort, the input order determines the sorted order in this case.

The Comparison sorting algorithms we will cover are:
* Insertionsort
* Mergesort
* Quicksort
* Heapsort

The NON-Comparison sorting algorithms we will cover are:
* Countingsort 
  * It uses key values as indexes into an array and the Ω(n log n) lower bound for comparison sorting will not apply.
* Radixsort (using Countingsort, but depends on subroutine)

The latter ones do not follow any of the methods we will describe here, they operate in their own way.

---

## 6 - Method

### 6.1 - Divide et Impera, Merging, Partitioning
A divide-and-conquer algorithm recursively breaks down a problem into two or more sub-problems 
of the same or related type, until these become simple enough to be solved directly. 
The solutions to the sub-problems are then combined to give a solution to the original problem.

1. Divide/ **Partitioning**: recursively divides the main input in smaller sub-problems
2. **Impera**: recursively solve the sub-problems.
    1. Base Case, immediate answer
    2. Else, find a way to the base case.
3. Combine/ **Merging**: merges the solutions of the smaller sub-problems to return the final answer.

### Partitioning
When the algorithm **does not need** to merge the sub-problems' results, usually because it is **in-place**

### Merging
When the algorithm **needs to combine** the sub-problems' results, usually because it is **NOT-in-place**

The Divide et Impera sorting algorithms we will cover are:
* Mergesort (Merging)
  * Which also Merges 
* Quicksort (Partitioning)
  * Which does not merge

### 6.2 - Insertion, focus on insertion
An **Insertion** sorting algorithm removes one element from the input data, **finds the location 
it belongs** within the sorted list, and inserts it there. It repeats until no input elements remain.

The Insertion sorting algorithms we will cover are:
* Insertionsort

### 6.3 - Selection, focus on extraction
A Selection sorting algorithm, divides its input into a sorted and an unsorted region, and it iteratively shrinks 
the unsorted region by **extracting** the largest element from it and inserting it into the sorted region.

The Selection sorting algorithms we will cover are:
* Heapsort

### 6.4 - Exchanging
An Exchanging sorting algorithm, repeatedly steps through the input list element by element, comparing 
the current element with the one after it, swapping their values if needed. 

These passes through the list are repeated until no swaps had to be performed during a pass, 
meaning that the list has become fully sorted.

---

## 7 - Online 
An online algorithm is one that can process its input piece-by-piece in a serial fashion, i.e., in 
the order that the input is fed to the algorithm, **without having the entire input available from the beginning**.

An online algorithm considers one input element per iteration and produces a partial solution without considering future elements.

The Online sorting algorithms we will cover are:
* Insertionsort

---
## 8 - Totality 

### 8.1 - Total Sorting
Total sorting is the problem of returning a list of items such that its elements all appear in order.

### 8.2 - Partial Sorting
In computer science, partial sorting is a relaxed variant of the sorting problem, namely returning a list of the k smallest
(or k largest) elements in order. The other elements (above the k smallest ones) may also be sorted, as in an in-place
partial sort, or may be discarded.

### 8.2.1 - Incremental Sorting
Incremental sorting is a version of the partial sorting problem where the **input is given up front but k is unknown**:
given a k-sorted array, it should be possible to extend the partially sorted part so that the array becomes (k+1)-sorted.

The Incremental sorting algorithms we will cover are:
* Insertionsort
* Heapsort
    * Heaps lead to an O(n + k log n) solution to incremental partial sorting: first "heapify", in linear time, the
      complete input array to produce a min-heap. Then extract the minimum of the heap k times.[1]


---

### Extra Credits
* [1] Maciej Liśkiewicz and Rüdiger Reischuk. _The Complexity World below Logarithmic Space._ 
Structure in Complexity Theory Conference, pp. 64-78. 1994. Online: p. 3, Theorem 2.
* [2] Alexa Megan Sharp, Dexter Kozen. Incremental algorithms: solving problems in a changing world (2007).
Cornell University.
* [3] Happy Coders, [Sorting Algorithms - Ultimate Guide](https://www.happycoders.eu/algorithms/sorting-algorithms)
* [4] Wikipedia, [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm#Classification)