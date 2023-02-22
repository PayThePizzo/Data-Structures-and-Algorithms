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

or

```math 
T(n) = \left\{\begin{matrix}
1 & \text{ if }n=1\\ 
T(n) = d \cdot T(g(n)) + d \cdot T(h(n)) + \ldots + c \cdot f(n) & \text{ if }n > 1
\end{matrix}\right.
```

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

### 2 - Analyze the balance of the tree
We want to focus on some characteristics before computing the complexity. We need focus on our tree and its nodes 
to try to answer the following questions:
* Do the weights of nodes decrease homogeneously in between levels? Do the nodes have the same weight at a level $i$?
  * If so, the weight is decreasing homogeneously. 
    * **Identify the weight of a node at level $i$** 
    * **Identify the decreasing factor**: How fast does the tree decrease in sub-problem size? What is the size at level $i=k$?
  * Else, the tree will be **unbalanced**, and some branches are going to stop first. 
    * **Identify the maximum possible weight of a level** 
    * **Identify the longest path from the root**: How far from the root do we reach a boundary condition? What is the maximum height of the three?


### 3 - Create a table for the analysis
The table has three parts:
* _The number of the level_, $i \in [0, h+1]$ with $h$ as the height of the tree
  * $i = 0, \ldots, h+1$
* _The total count of nodes for that level_, expressed as a power of the number of branches for each subtree. How many nodes can we see at a level $i$? 
  * ex: 2 for binary trees which are usually the case.
  * $2^0 = 1$, $2^1 = 2$, $2^2 = 4$, where $f(i) = i \text{  } \forall i=0,\ldots,h+1$
* _Weight of the level_, the sum of the weight of each node expressed as a function of n.

| Level $i$ 	 | Total Nodes at level $i$ 	| Weight of level $i$ 	|
|-------------|--------------------------	|---------------------	|
| 0         	 | $2^{f(i)}$               	| f(n)                	|
| 1         	 |                          	|                     	|
| 2         	 |                          	|                     	|
| 3         	 |                          	|                     	|
| ...       	 | ...                      	| ...                 	|
| h+1       	 | $2^{f(i)}$               	| Cost of the leaves  	|


### 4 - Guess the case:
| Case                                                        	| Weight                                                	| Formula                                                                 	|
|-------------------------------------------------------------	|-------------------------------------------------------	|-------------------------------------------------------------------------	|
| 1 - Balanced Tree, with non-changing weight                 	| Every level has the same weight                       	| $T(n) = d \cdot T() + c \cdot f(n)$                                     	|
| 2 - Balanced Tree, with homogeneously decreasing weight     	| Every level decreases in weight                       	| $T(n) = d \cdot T(\frac{n}{a}) + c \cdot f(n)$                          	|
| 3 - Unbalanced Tree, with heterogeneously decreasing weight 	| Like above, but every node can get a different weight 	| $T(n) = d \cdot T(\frac{n}{a}) + d \cdot T(\frac{n}{b}) + c \cdot f(n)$ 	|


### 5 - Solve
In the first case we can directly solve it by multiplying a weight of one level by the number of levels. 
* $w_{i}$ as the weight of a level $i$
* $l$ as the total number of levels

$$T(n) = \text{ Weight of a level } \cdot \text { Total number of levels } = w_{i} \cdot l = \sum^{l}_{i=1} w_{i}$$


In the second case we need to compute the cost of the nodes and the cost of the leaves.
* $h = log_{a}(n) \rightarrow i \in [0, log_{a}(n)]$ is the height of the tree
* $h+1$, the total number of levels
* $f(T_{n}) = d^{h} = d^{log_{a}(n)} = n^{log_{a}(d)}$, the total number of leaves for the Tree $T$
* $T(1)$, is the cost of the function when $n=1$ (_it can be discarded asymptotically_) and represents the contribution of each leaf node.
* $\sum d^{k} \cdot cf(n/a^{i})$, with $k=0, \ldots, h-1$ is the cost of the internal nodes

$$T(n) = \text{ Cost of internal nodes } + \text{ Cost of leaves } = \sum^{h-1}_{k=0}(w_{k}) + \theta(n^{log_{a}(d)} * T(1))$$

$$T(n) = \sum^{h-1}_{k=0}(d^{k} \cdot cf(n/a^{k})) + \theta(n^{log_{a}(d)} * T(1))$$


In the third case we need to try and find the maximum cost of a level and the length of the longest path, as some leaves
are deeper than others.
* The **Max Cost of a level** is considered to be the maximum value such that $w_{i} \leq cf(n) \rightarrow w_{i} = O(f(n))$
  * It can be required to show a demonstration, but it is not usually the case.
* The **length of the longest path** is given by the branch which diminishes the slowest among all the other ones.

$$T(n) = O(\text{Max Cost of a level}) \cdot O(\text{Length of the longest path})$$


#### Example


---


## Iteration Method

### Example

---

## Master Theorem
The master theorem is a powerful way to solve the occurrences of **divide et impera** algorithms:

$$T(n) = T_{split}(n) + T_{merge}(n) + T_{solve}(n)$$

Where:
* $T_{split}(n)$ and $T_{merge}(n)$ are not recursive.
  * $f(n) = T_{split}(n) + T_{merge}(n)$ and $f(n) \geq 0$
* $T_{solve}(n)$ can be expressed as summation of the time needed to solve the sub-problems 
  * $\sum T(n_{i}) \text{ for } i=1,\ldots, k$ which is equal to $a \cdot f(n/b)$

### Conditions
We need to express the $T(n)$ of the algorithm we want to analyze through the following form:

$$T(n) = a \cdot T(n/b) + f(n)$$

Plus, the following conditions must stand true:
* $a \geq 1$, is a constant expressing the number of occurrences 
* $n/b$, the dimension of the sub-problem is constant
* $b > 1$
* $f(n) \geq 0$ for n sufficiently large

If the conditions are met, then we can add the following notation:
* $d = \log_{b}(a)$
* $g(n) = n^{d} = n^{log_{b}(a)}$

Identify the right case:

| _Case_ 	| **Condition**        	| Asymptotic Notation                                             	| Procedure                                                                                                                	| **Solution**                   	|
|--------	|----------------------	|-----------------------------------------------------------------	|--------------------------------------------------------------------------------------------------------------------------	|--------------------------------	|
| _1_    	| $f(n) \leq n^{d}$    	| $f(n) = \mathcal{O}(n^{d- \varepsilon})$ with $\varepsilon > 0$ 	| Find $\varepsilon$                                                                                                       	| $T(n) = \Theta(n^{d})$         	|
| _2_    	| $f(n) \approx n^{d}$ 	| $f(n) = \Theta(n^{d})$                                          	| None needed                                                                                                              	| $T(n) = \Theta(n^{d} \log(n))$ 	|
| _3_    	| $f(n) \geq n^{d}$    	| $f(n) = \Omega(n^{d+ \varepsilon})$ with $\varepsilon > 0$      	| Find the **only** $\varepsilon$, then find the $c$ such that $\exists c<1 \ni'$ for n suffic. large $af(n/b) \leq cf(n)$ 	| $T(n) = \Theta(f(n))$          	|

## Master Theorem Demonstration
Let's introduce briefly what we want to do.

We know that for a divide-et-impera algorithm, we can rewrite its complexity as:

$$T(n) = T_{split}(n) + T_{merge}(n) + T_{solve}(n) = f(n) + T_{solve}(n) = f(n) + aT(n/b)$$

And if the conditions mentioned above are met, we can focus on comparing $f(n)$ with $g(n) = n^{d}$.

<b style='color:red;'> But why do we want to do this? </b>

This is what the demonstration is for.

We know that $T_{solve}(n)$ can be thought as:
* The total complexity of all levels
* $\text{ Complexity of internal nodes } + \text{ Complexity of the leaves }$
* $\text{ Complexity of internal nodes } + \text{ Count of leaves } \cdot T(1)$, which is the best approach.
  * This is because the leaves represent the case where the recursion ends: $T(n=1) = \Theta(1)$
  * Since they all have the same known complexity, we can just multiply them by the number of leaves
  * While for the internal nodes we need to sum their complexity from the level 0 to the second-last.
  
  
### 1 - Rewrite $T(n)$ 
Through the occurrences tree we try to rewrite $T(n)$ in an **explicit way**, that is **non-recursive**.

![mastertheoremdem]()

And we want to focus on finding out:
* $a \geq 1$, the number of sub-problems of dimension $n/b$ with $b > 1$
* $a^{i}$, the number of nodes at a level $i$
* $n/b^{i}$, the dimensionality of the sub-problems at a level $i$
* $f(n/b^{i}) \text{  with } i \geq 0$, the contribution of one call at a level $i$ to the total complexity
* $a^{i} \cdot f(n/b^{i})$, the complexity of all internal nodes at a level $i$

We can define the total complexity as the sum of the complexity of all levels, as we said before:

```math
T(n) = \text{Total complexity of all levels} = T_{\text{lvl 1}} + T_{\text{lvl 2}} + \ldots + T_{\text{lvl i}} = \sum^{\text{tot lvl}}_{i=0} a^{i}f(n/b^{i})
```

To reach the boundary condition, when the tree stops, we need to set $n/b^{i} = 1$ so that the summation also stops. 

This represents the case where $n = 1$, which results in $T(n=1)$, and we stop with the recursion (we reached the leaves).

$$n/b^{i} = 1 \Longleftrightarrow b^{i} = n \Longleftrightarrow log_{b}(n) = i$$

$i \in \mathbb{N} \text{ or use the ceil integer value}$, represents the levels of the tree.
We can now explicitly write $T(n)$ in a non recursive way:

```math
T(n) = \sum^{log_{b}(n)}_{i=0}a^{i}f(n/b^{i}) = \text{ Total Complexity } = \text{Complexity of internal nodes} + \text{ Complexity of leaves }
```

Since we know that the internal nodes reach maximum depth at $log_{b}(n)-1$, and that all the leaves have complexity $T(1)$,
we can rewrite the complexity as, the complexity of internal nodes and the count of leaves multiplied by $T(1)$. 

```math
T(n) = \sum^{log_{b}(n)-1}_{i=0}a^{i}f(n/b^{i}) + \text{ Count of Leaves } \cdot \text{ Complexity of leaves } = \sum^{log_{b}(n)-1}_{i=0}a^{i}f(n/b^{i}) + (\text{Count of leaves} \cdot T(1))
```

Now, let's quickly proceed with two things
* Finding the count of leaves
* Finding the total count of nodes

### 1.1 Find the count of leaves

Through the property of the logarithms for the change of the base (prop 1) 

$$log_{a}(b) = log_{c}(b) \cdot \frac{1}{log_{c}(a)}$$

and the property of inversion (prop 2)

$$log_{a}(b) = \frac{1}{log_{b}(a)}$$

We obtain

$$log_{b}(n) \stackrel{prop 1}\Longrightarrow log_{a}(n) \cdot \frac{1}{log_{a}(b)} \stackrel{prop 2}\Longrightarrow  log_{a}(n) \cdot log_{b}(a)$$

Then, by definition

$$a^{log_{b}(n)} = a^{ log_{a}(n) \cdot log_{b}(a)} = (a^{log_{a}(n)})^{log_{b}(a)} \stackrel{def}\Longrightarrow  n^{log_{b}(a)} \stackrel{def}\Longrightarrow n^{d}$$

### 1.2 Find the total count of nodes
Now, something curious happens when we find out what is the total count of nodes, namely the number of recursive calls

We can use a geometric series to represent the number of nodes in the tree:

$$\sum^{log_{b}(n)}_{i=0}a^{i}$$ 

By the property of the geometric series:

$$\sum^{k}_{i=0}q^{i} = \frac{q^{k+1}-1}{q-1}$$

Then 

```math
\sum^{log_{b}(n)}_{i=0}a^{i} \stackrel{prop}\Longrightarrow \frac{a^{log_{b}(n)+1}-1}{a-1} = \frac{a^{log_{b}(n)} \cdot a -1}{a-1} = \frac{n^{d} \cdot a -1}{a-1} \approx \Theta(n^{d})
```

### 1.3 Conclusions
The number of total nodes in the tree, namely the occurrences/calls, grows asymptotically with $n^{d}$. 

This precisely why, through the master theorem we compare the dimension of the tree/number of 
recursive calls $n^{d} = g(n)$ with the $T_{\text{split + merge}} = f(n)$: we want to check which one of the terms is 
asymptotically dictating the complexity of the algorithm.


### 2 - Find the right case
In terms of the recursion tree, the three cases of the master theorem correspond to cases in which the total 
cost of the tree is (1) dominated by the costs in the leaves, (2) evenly distributed among the levels of the tree, 
or (3) dominated by the cost of the root

Apply the right demonstration based on the case

#### 2.1 - Case 1

#### 2.2 - Case 2

#### 2.3 - Case 3


### Example

---

#### Credits
* [1] [Introduction to Algorithms, Third Edition](https://dl.acm.org/doi/book/10.5555/1614191) 
  * Publisher: The MIT Press
  * Authors: Cormen, Thomas H. and Leiserson, Charles E. and Rivest, Ronald L. and Stein, Clifford
* 