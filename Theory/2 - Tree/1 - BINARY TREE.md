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

| **Level** 	| **Children**             	 |
|-----------	|----------------------------|
| 0         	| $1 = k^{0}$              	 |
| 1         	| $k = k^{1}$              	 |
| 2         	| $k \cdot k= k^{2}$       	 |
| $\ldots$  	| $k \cdot k \cdot \ldots$ 	 |
| h         	| $k^{h}$                  	 |

The root has exactly $k$ children, and each one of the will have exactly $k$ children, unless we reach the leaves.

Demonstration by induction: $f(h) = k^{h}$ for a complete k-ary tree
* Base case: $h=0 \rightarrow k^{0}=1$, trivially true since we have the root in a non-empty complete k-ary tree
* Inductive Hypothesis: We assume that this is true for a complete k-ary tree of height $h$, namely that $f(h) = k^{h}$
* Inductive Step: 
  * At step $h$ we have $f(h) = k^{h}$, by inductive hypothesis
  * Since the tree is a complete k-ary tree, at step $h+1$ we have that each internal node at level $h$ has exactly $k$ children
  * This means that $f(h+1) = k^{h+1} = k^{h} \cdot k$ 

### Demonstration $i(h) = k^{h}-1/k-1$

To compute count of internal nodes we can use the geometric series

```math
\sum_{i=0}^{h-1}k^{i} = \frac{k^{h-1+1}-1}{k-1} = \frac{k^{h}-1}{k-1}, \text{ }k \neq 1
```

### Demonstrate $h(T) = log_{k}(n)$



### Extra: $f(T) = (n+1)/2$ for a non-empty 2-ary complete tree with n nodes


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


