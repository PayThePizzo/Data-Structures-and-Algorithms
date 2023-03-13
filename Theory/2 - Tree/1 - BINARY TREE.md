# Binary Tree

## Recursive Definition
* Base Case: an empty tree is a binary tree
* Definition: A tree having a root node and two binary subtrees (respectively left subtree and right subtree, which can be empty) is a binary tree.

Trees nodes can have zero or more children. However, when a tree has at most two children, then it’s called binary tree.
* A BT's node *x* is said to **Central** when the count of its subtree's leaves is equal to the sum of the nodes' keys belonging to the path(Root, x).

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

Let us call

It can be demonstrated that for a Complete K-ary Tree:
* Count of leaves $f(h_{k})$ at height h for k-ary tree, $f(h_{k}) = k^{h}$
* Count of internal nodes $i(h)$  at height h for k-ary tree, $f(h_{k}) = k^{h}-1/k-1$
* Height, **$h = log(k,n)$**

#

---

## Balanced Binary Tree
A balanced tree is a tree if its height is such that: <mark>h = O(log(n))</mark>

A Complete Binary Tree is a Balanced Binary Tree (but the opposite is not always true)

---

## Binary Search Tree (BST)
Binary Search Trees or BST for short are a particular application of binary trees.

BST has at most two nodes (like all binary trees). However, the values are so that the left 
children value must be less than the parent, and the right children must be higher.

Duplicates: Some BST doesn’t allow duplicates while others add the same values 
as a right child. 
Other implementations might keep a count on a case of duplicity 
(we are going to do this one later).**


