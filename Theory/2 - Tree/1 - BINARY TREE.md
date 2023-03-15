# Binary Tree

## Recursive Definition
> Base Case: an empty tree is a binary tree;
> Definition: A tree having a root node, and two binary subtrees (respectively left subtree and right subtree, which can be empty) is a binary tree.


### Central node
> A BT's node *x* is said to **Central** when the count of its subtree's leaves is equal to the sum of the nodes' keys belonging to the $path(root, x)$.

### Full, Complete, and Perfect binary trees
Depending on how nodes are arranged in a binary tree, it can be full, complete and perfect:


* Full binary tree: each node has exactly 0 or 2 children (but never 1).
* Complete binary tree: when all levels, except the last one, are full of nodes.
* Perfect binary tree: when all the levels (including the last one) are full of nodes.

### Height
The height of binary tree is 

$$\mathcal{O}(log(n)) \leq h(T) \leq \mathcal{O}(n)$$



---

## K-ary Tree
It is the generalization of a Binary Tree.

A k-ary tree is a tree where the children of a node are labeled with distinct positive integers $i \in \mathbb{N}^{+} \wedge i \in [1,k]$.
* No labels larger than **k** are present.
* A binary tree is a K-ary tree with k = 2.

## Complete K-ary Tree
It is a K-ary tree where 
1. All the leaves have the same depth
2. All the internal nodes $u$ have $deg(u) = k = count(children)$.

Let us call $f(T)$ the count of leaves, and $i(T)$ the count of internal nodes of a tree with height $h = h(T)$ 

It can be demonstrated that for a Complete K-ary Tree:

| Tree                                	| Count of leaves $f(T)$ 	| Count of internal nodes $i(T)$ 	| Height $h(T)$       	|
|-------------------------------------	|------------------------	|--------------------------------	|---------------------	|
| Complete K-Ary Tree with height $h$ 	| $f(T) = k^{h}$         	| $i(T) = k^{h}-1/k-1$           	| $h(T) = log_{k}(n)$ 	|

### Demonstration $f(h) = k^{h}$ 

By definition, a complete k-ary tree has exactly $k$ children per internal node

| **Level** 	   | **Children**             	 |
|---------------|----------------------------|
| $0$         	 | $1 = k^{0}$              	 |
| $1$         	 | $k = k^{1}$              	 |
| $2$         	 | $k \cdot k= k^{2}$       	 |
| $\ldots$  	   | $k \cdot k \cdot \ldots$ 	 |
| $h$         	 | $k^{h}$                  	 |

![demcompkt-f](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/demcompkt-f.png?raw=TRUE)

The root has exactly $k$ children, and each one of the will have exactly $k$ children, unless we reach the leaves.

#### Demonstration by induction: $f(h) = k^{h}$ for a complete k-ary tree

Base case: $h=0 \rightarrow k^{0}=1$, trivially true since we have the root in a non-empty complete k-ary tree

Inductive Hypothesis: We assume that $f(h) = k^{h}$ is true for a complete k-ary tree of height $h$

Inductive Step: By inductive hypothesis a tree with $h+1$

![demcompkt-i](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/demcompkt-i.png?raw=TRUE)

Since the tree is a complete k-ary tree, 
* At step $h$, $f(h) = k^{h}$
* At step $h+1$, $f(h+1) = k^{h} \cdot k = k^{h+1}$ as each internal node at level $h$ has exactly $k$ children.

### Demonstration $i(h) = k^{h}-1/k-1$

Given the previous result we can think of the same tree with one more level, which means this last level only has leaves.

```math
T_{n} = i(h) + f(h) = \sum_{i=0}^{h-1}k^{i} + k^{h}
```

To compute count of internal nodes we can use the geometric series

```math
\sum_{i=0}^{h-1}k^{i} < \sum^{\infty}k^{i} \Rightarrow \sum_{i=0}^{h-1}k^{i}= \frac{k^{h-1+1}-1}{k-1} = \frac{k^{h}-1}{k-1}, \text{ }k \neq 1
```

### Demonstrate $h(T) = log_{k}(n)$

We know that $f(h) = k^{h}$ for a complete k-ary tree

Then if the we have $n = f(h)$ leaves, we find $n = k^{h} \Leftrightarrow h = log_{k}(n)$ 


### Extra: $f(T) = (n+1)/2$ for a non-empty 2-ary complete tree with n nodes

Demonstration that, for a non-empty 2-ary complete tree with n nodes, the count of leaves is exactly $\frac{n+1}{2}$.
In this case we only consider the second case: $n > 0$. We start by using induction on the hypothesis $f(T_{n}) = \frac{n+1}{2}$

Induction
1. Base Case: $n = 1 \Longrightarrow f(T_{n}) = (1+1)/2 = 1$
   1. Only the root is present, trivially true
2. Inductive Hypothesis:
   1. We suppose that $f(T_{n}) = \frac{n+1}{2}$ is true at step $n=h-1 \Longrightarrow f(T_{n}) = \frac{n(h-1)+1}{2}$
   2. We assume that $\forall k$ with $1 \leq k <n$, the property is true. 
3. Inductive step: we need to demonstrate for any $n>0$ 
   1. We exclude $n=0$ by definition

For a non-empty complete binary tree $f(T_{k}) = \frac{k+1}{2}$ and the total count of nodes, can be written as 

$$nodes(T_{n}) = nodes(T_{left}) + nodes(T_{right}) + root = \frac{n-1}{2} + \frac{n-1}{2} + 1$$

Since the two subtrees are complete and have less nodes than $T_{n}$, we can apply the inductive hypothesis
* Trivially, $f(T_{left}) = \frac{((n-1)/2)+1}{2}< n$
* Trivially, $f(T_{right}) = \frac{((n-1)/2)+1}{2} < n$
* Trivially $f(T_{left})= f(T_{right})$ and $f(T_{left}) + f(T_{right}) < n$

$$f(T_{n}) = f(T_{left}) + f(T_{right}) = 2 \cdot \frac{((n-1)/2)+1}{2} = \frac{n-1+2}{2} = \frac{n+1}{2}$$

---


## Balanced Binary Tree
> A tree is a balanced tree if its height is: $h(T) = \mathcal{O}(log(n))$

### Complete Binary Tree is balanced
A Complete Binary Tree is a Balanced Binary Tree (but the opposite is not always true)

### Performances
It is important to keep binary tree's height as close to $\mathcal{O}(log(n))$ when performing operations on it as it will
improve the performances.

---

## Binary Search Tree (BST)
Binary Search Trees or BST for short are a particular application of binary trees.

BST has at most two nodes (like all binary trees). However, the values are so that the left 
children value must be less than the parent, and the right children must be higher.

Duplicates: Some BST doesn’t allow duplicates while others add the same values 
as a right child. 
Other implementations might keep a count on a case of duplicity 
(we are going to do this one later).**


