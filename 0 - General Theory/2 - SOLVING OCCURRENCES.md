# Solving Occurrences
The objective of solving occurrences is to find out what the $T_{worst}(n)$ is for a certain algorithm.

## Induction

### Example

---

## Substitution Method

### Example

---
## Recursion Tree
Although you can use the substitution method to provide a succinct proof that 
a solution to a recurrence is correct, you might have trouble coming up with a good guess.

In a recursion tree, each node represents the cost of a single sub-problem  
somewhere in the set of recursive function invocations. We sum the costs within 
each level of the tree to obtain a set of per-level costs, and then we sum all the 
per-level costs to determine the total cost of all levels of the recursion. [1]

We focus on formulas such as:

$$T(n) = d \cdot T(g(n)) + d \cdot T(h(n)) + c \cdot f(n)$$

where $g(n)$ and $h(n)$ are usually diminishing functions (i.e. division or subtractions), and $d,c \in \mathbb{R}$ 
are constants.


### 1 - Construct a tree with $[0-2]$ levels
Start by drawing a tree where you apply the formula to the variable $n$

```c++
                    [n]                        // Level 0
            /               \
        [g(n)]                [h(n)]           // Level 1
      /       \             /        \
 [g(g(n))]  [h(g(n))]  [g(h(n))]  [h(h(n))]    // Level 2
```

### 2 - Analyze the characteristics 
* **Balancing**: 
  * Will it **always** be balanced? 
  * Is there a branch that stops first? 
  * What's the maximum height? 
* **Weight of a level** (sum of the nodes): 
  * Does it change? 
  * Does it decrease homogeneously? 
  * What is the maximum weight it can reach?

### 3 - Create a table for the analysis
The table has three parts:
* The number of the level $i = 0, \ldots, n$
* The total nodes for that level, expressed as a power of 2 (since usually we have binary trees).
* Weight of the level, the sum of the weight of each node expressed as a function of n.

| Level $i$ 	| Total Nodes at level $i$ 	| Weight of level $i$ 	|
|-----------	|--------------------------	|---------------------	|
| 0         	| $2^{k}$                  	|                     	|
| 1         	|                          	|                     	|
| 2         	|                          	|                     	|
| 3         	|                          	|                     	|
| ...       	| ...                      	| ...                 	|
| n         	|                          	|                     	|

### 4 - Guess the case:
| Case                                                        	| Weight                                                	| Formula                                                                 	|
|-------------------------------------------------------------	|-------------------------------------------------------	|-------------------------------------------------------------------------	|
| 1 - Balanced Tree, with non-changing weight                 	| Every level has the same weight                       	| $T(n) = d \cdot T() + c \cdot f(n)$                                     	|
| 2 - Balanced Tree, with homogeneously decreasing weight     	| Every level decreases in weight                       	| $T(n) = d \cdot T(\frac{n}{a}) + c \cdot f(n)$                          	|
| 3 - Unbalanced Tree, with heterogeneously decreasing weight 	| Like above, but every node can get a different weight 	| $T(n) = d \cdot T(\frac{n}{a}) + d \cdot T(\frac{n}{b}) + c \cdot f(n)$ 	|


### 5 - Solve
In the first case we can directly solve it by multiplying a weight of one level by the number of levels. 

$$T(n) = \text{ Weight of a level } \cdot \text { Total number of levels } = w_{i} \cdot l = \sum^{l}_{i=1} w_{i}$$

* $w_{i}$ as the weight of a level $i$
* $l$ as the total number of levels


In the second case we need to compute the cost of the nodes and the cost of the leaves.

$$T(n) = \text{ Cost of internal nodes } + \text{ Cost of leaves } = \sum^{i-1}_{k=0}(d^{k} \cdot cf(n/a^{k})) + \theta(n^{log_{a}(d) * T(1))$$

* $h = log_{a}(n)$ is the height of the tree
* $l = h+1$, the total number of levels
* $f(T_{n}) = d^{h} = d^{log_{a}(n)} = n^{log_{a}(d)}$, the total number of leaves for the Tree $T$
* $T(1)$, is a constant representing the single contribution of the leaves 
* $\sum^{h-1}_{k=0} d^{k} \cdot cf(n/a^{i})$, The cost of the internal nodes


In the third case we need to try and find the maximum cost of a level and the length of the longest path, as some leaves
are deeper than others. Case 3: 

$$T(n) = O(\text{Max Cost of a level}) \cdot O(\text{Length of the longest path})$$



#### Example


---


## Iteration Method

### Example

---

## Master Theorem

### Example

---

#### Credits
* [1] [Introduction to Algorithms, Third Edition](https://dl.acm.org/doi/book/10.5555/1614191) 
  * Publisher: The MIT Press
  * Authors: Cormen, Thomas H. and Leiserson, Charles E. and Rivest, Ronald L. and Stein, Clifford
* 