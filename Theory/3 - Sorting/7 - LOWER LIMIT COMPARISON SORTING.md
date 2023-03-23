# Lower limit for sorting algorithms based on comparisons

**Theorem: Any comparison sorting algorithm must perform Ω(nlog(n)) comparisons in the worst case**

Dem: We need to find the height of a tree that for n distinct numbers to sort

Hypothesis
* Input of n distinct elements

Given any comparison sorting algorithm, we can construct a decision tree (binary Y/N) for each n, that models all possible permutations
1. Every internal node is labeled from i to j, with i,j in {1...n}
    * L-subtree, includes the following comparisons if ai<=aj;
    * R-subtree, includes the following comparisons if ai>aj;
2. Every leaf represents a permutation
    * Permutation such that every element is sorted by some criteria;
    * Every permutation must appear at least once **f>=n!**, trivially
    * A **2-ary** tree has **2^h leaves at most!**, true by lemma
    * **2^h>= f >=n!**
    * Then h>=log(n!)
3. Execution time is the length of path from the root to a leaf.
    * In the worst case it represents the **height** of the tree (longest path).
    * **h >= log(n!)**
    * n! = sqrt(2pi*n) (n/e)^n (1 + Θ(1/n))
        * Asymptotically we consider **(n/e)^n**
    * **h >= log(n!) >= nlog(n)**
    * **h =  Ω(nlog(n))**

### Corollary
Heapsort and Mergesort are asymptotically efficient comparison sorting algorithms.
