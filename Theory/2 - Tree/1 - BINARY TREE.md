# Binary Tree

## Recursive Definition

|              	| **Binary Tree**                                                                                                                       	| **Notes**          	|
|--------------	|---------------------------------------------------------------------------------------------------------------------------------------	|--------------------	|
| _Base Case_  	| An empty tree is a binary tree                                                                                                        	|                    	|
| _Definition_ 	| A tree having a root node and two binary subtrees (respectively left subtree and right subtree, which can be empty) is a binary tree. 	| At most 2 children 	|
| Height       	| $\mathcal{O}(log(n)) \leq h \leq \mathcal{O}(n)$                                                                                      	|                    	|

### Central node
> A BT's node *x* is said to **Central** when the count of its subtree's leaves is equal to the sum of the nodes' keys belonging to the $path(root, x)$.

### Full, Complete, and Perfect binary trees
Depending on how nodes are arranged in a binary tree, it can be full, complete and perfect:
* Full binary tree: each node has exactly 0 or 2 children (but never 1).
* Complete binary tree: when all levels except the last oneare full of nodes.
* Perfect binary tree: when all the levels (including the last one) are full of nodes.


---

## K-ary Tree
It is the generalization of a Binary Tree.

A k-ary tree is a tree where the children of a node are labeled with distinct positive integers $i \in \mathbb{N}^{+} \wedge i \in [1,k]$.
* No labels larger than **k** are present.
* A binary tree is a K-ary tree with k = 2.

## Complete K-ary Tree
It is a K-ary tree where 
1. All the leaves have the same depth
2. All the internal nodes $u$ have $deg(u) = k = #children$.

Let us call $f(T)$ the count of leaves, and $i(T)$ the count of internal nodes of a tree with height $h = h(T)$ 

It can be demonstrated that for a Complete K-ary Tree:

| Tree                                	| Count of leaves $f(T)$ 	| Count of internal nodes $i(T)$ 	| Height $h(T)$       	|
|-------------------------------------	|------------------------	|--------------------------------	|---------------------	|
| Complete K-Ary Tree with height $h$ 	| $f(T) = k^{h}$         	| $i(T) = k^{h}-1/k-1$           	| $h(T) = log_{k}(n)$ 	|

### Demonstration $f(h) = k^{h}$

### Demonstration $f(h) = k^{h}-1/k-1$

### Conclusion $h(T) = log_{k}(n)$

### Extra: $f(T) = (n+1)/2$ for a non-empty 2-ary complete tree with n nodes


---

## Balanced Binary Tree
> A tree is a balanced tree if its height is: $h(T) = \mathcal{O}(log(n))$

A Complete Binary Tree is a Balanced Binary Tree (but the opposite is not always true)

It is important to keep binary tree's height as close to $\mathcal{O}(log(n))$

---

## Binary Search Tree (BST)
Binary Search Trees or BST for short are a particular application of binary trees.

BST has at most two nodes (like all binary trees). However, the values are so that the left 
children value must be less than the parent, and the right children must be higher.

Duplicates: Some BST doesn’t allow duplicates while others add the same values 
as a right child. 
Other implementations might keep a count on a case of duplicity 
(we are going to do this one later).**


