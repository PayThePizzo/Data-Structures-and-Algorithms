# Lower limit for sorting algorithms based on comparison

How fast can we sort $n$ elements? 

Until now, we covered some algorithms which base their decision on the comparisons between keys but we had no assumption 
regarding the input's nature.

So what is the inferior limit, when it comes to these algorithms? 
* A quick and wrong answer would be that the best time would be $\Omega(n)$, but this is wrong

$$\text{Theorem: Any comparison sorting algorithm must perform } \Omega(nlog(n)) \text{ comparisons in the worst case }$$


```math
\left\{\begin{matrix}
Thesis & \text{ Inferior limit is } \Omega(nlog(n)) \\
Hypothesis & \text{ All elements in input are distinct}  \\
\end{matrix}\right.
```


## 1 - Decision Tree as a representation

Let us use a decision tree to represent the comparisons done by a comparison sorting algorithm, given a generic input:

![inflimsort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/inflimsort.png?raw=TRUE)

We notice that:
1. Every internal node is labeled from $i \text{ to } j$, with $i,j \in 1, \ldots, n$
   * It means we need to compare $a_{i}$ and $a_{j}$
   * L-subtree, includes the following comparisons if $a_{i} \leq a_{j}$;
   * R-subtree, includes the following comparisons if $a_{i} > a_{j}$;
2. Every leaf represents a permutation $< \pi_{1}, \ldots, pi_{n} >$
    * Such that $a \pi_{1} \leq  a \pi_{2} \leq \ldots \leq a \pi_{n}$
      * A permutation such that every element is sorted by some criteria;

Given any comparison sorting algorithm, and some input of size $n$, we can construct a decision tree (binary tree Y/N)
for each $n$, that models all possible permutations and comparisons:
* Given any comparison sorting algorithm we can build a tree for every $n$
  * Each tree maps all the possible execution paths
* The execution time $T(n)$, which equals the count of comparisons, is the length of a path in the tree
  * The worst execution time is given by the height of the tree $T_{worst}(n) = height(T) = h$

> The inferior limit on the heights of all the decisions trees (where each permutation appears like a leaf) behaves like the 
> inferior limit of the execution time of any comparison sorting algorithm

Since it is a binary tree, we can use its height to find out the number of permutations which are exactly the number of
leaves in the tree! 

## 2 - How many leaves $f()$ can a decision tree, like the one we just mentioned, have? 

### 2.1 - $f(T) \geq n!$
Every permutation must appear at least once, trivially

### 2.2 Lemma: a binary tree of height $h$ has at most $2^{h}$ leaves 

#### Demonstration

Induction on $h$:
1. Base Case: $h=0$, a tree with just one node which is both root and leaf
   * $f(T) = f(h=0) = 1$
2. Inductive Hypothesis: We assume this is true for any tree of height $k < h$
3. Inductive Step: We show it for $h$
   * Tree with one child 
     * $f(T)$ is equal to $f(T_{1})$ which has height $h-1$, $f(T) = f(T_{1})$ 
     * Then, by Inductive Hypothesis, $f(T) = f(T_{1}) \leq 2^{h-1} \leq 2^{h} \Rightarrow f(T)$
   * Tree with both children
     * $f(T) = f(T_{1}) + f(T_{2})$, the leaves of the tree $T$ equals the sum of its children's leaves
     * Let $h_{1}, h_{2} < h$ be the height of the children
     * Then, by Inductive Hypothesis,
       * $f(T_{1}) \leq 2^{h_{1}} \wedge f(T_{2}) \leq  2^{h_{2}}$
       * $f(T) = f(T_{1}) + f(T_{2}) \leq 2^{h_{1}} + 2^{h_{2}} \leq 2 \cdot 2^{max(h_{1},h_{2})} \leq 2^{h}$
       * $2 \cdot 2^{max(h_{1},h_{2})} = 2^{1+max(h_{1},h_{2})} \Rightarrow h=1+max(h_{1},h_{2})$
       * $2^{1+max(h_{1},h_{2})} = 2^{h}$
       * The property is demonstrated as $f(T) \leq 2^{h}$

## 3: Theorem

> Any comparison sorting algorithm requires $T_{worst}(n) = \Omega(nlog(n))$ comparisons

### Demonstration
We need to determine the height of a binary decision tree where each permutation appears as a leaf. Let us consider a 
decision tree with height $h$ and $l$ leaves which represents the sorting process of a comparison sorting algorithm given
$n$ elements:

$$2^{h} \geq l \geq n! \rightsquigarrow log(2^{h}) \geq log(n!) \rightsquigarrow h \geq log(n!)$$

### Stirling's approximation for $n!$

$$n! \approx \sqrt{2 \pi n} (\frac{n}{e})^{n} (1+ \Theta(\frac{1}{n}))$$

If $n$ is sufficiently large, we can get the dominant term and substitute it with $n$

$$h \geq log(n!) \geq log((\frac{n}{e})^{n}) \Rightarrow nlog(n/e) = n(log(n)-log(e))$$

$$h \geq nlog(n) \Rightarrow h = \Omega(nlog(n))$$

---

### Corollary
Heapsort and Mergesort are asymptotically efficient comparison sorting algorithms.
