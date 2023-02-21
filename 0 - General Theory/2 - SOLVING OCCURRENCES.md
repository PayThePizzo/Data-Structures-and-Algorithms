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


1. Construct a tree with $[0-2]$ levels

```c++
        []
      /    \ 
    []      []
   /  \    /  \
 []  []    []  []
```

2. Analyze the characteristics 
   * Balancing: Will it **always** be balanced? Is there a branch that stops first? What's the maximum height?
   * Weight of a level (sum of the nodes): Does it change? Does it decrease homogeneously? What is the maximum weight it can reach?
3. Create a table for the analysis

| Level $i$ 	| Count of nodes 	| Weight 	|
|-----------	|----------------	|--------	|
|           	|                	|        	|

4. Guess the case:
   1. Balanced Tree, with non-changing weight 
   2. Balanced Tree, with homogeneously decreasing weight
   3. Unbalanced Tree, with heterogeneously decreasing weight



### Example

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