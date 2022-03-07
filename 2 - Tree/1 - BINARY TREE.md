# Binary Tree

Recursive Definition:
* Base Case: an <mark>empty tree</mark> is a binary tree
* Definition: A tree having a root node and two binary subtrees (respectively left subtree and right subtree) is a binary tree.

Trees nodes can have zero or more children. However, 
when a tree has at the most two children, then it’s called binary tree.
* A BT's node *x* is said to **Central** when the count of its subtree's leaves is equal to the sum of the nodes' keys belonging to the path(Root, x).

Full, Complete, and Perfect binary trees
Depending on how nodes are arranged in a binary tree, it can be full, complete and perfect:

* Full binary tree: each node has exactly 0 or 2 children (but never 1).
* Complete binary tree: when all levels <mark>except the last one</mark> are full of nodes.
* Perfect binary tree: when all the levels (including the last one) are full of nodes.

---

## K-ary Tree
It is a generalization of a Binary Tree.

It is a Tree <mark>where the children of a node are labeled with positive integers</mark>.
Labels larger than **k** are not present.

* A binary tree is a K-ary tree with k = 2.

## Complete K-ary Tree
It is a K-ary tree where all the leaves have the same depth
* All the internal nodes have _degree = k_.
* The total number of leaves of complete k-ary tree is `k**h`

---

## Balanced Binary Tree
A balanced tree is a tree if its height is such that: <mark>h = O(log(n))</mark>

A Complete Binary Tree is a Balanced Binary Tree (but the opposite is not always true)



---

## Binary Search Tree (BST)
Binary Search Trees or BST for short are a particular application of binary trees.

BST has at most two nodes (like all binary trees). However, the values are so that the left children value must be less than the parent, and the right children must be higher.

Duplicates: Some BST doesn’t allow duplicates while others add the same values 
as a right child. 
Other implementations might keep a count on a case of duplicity 
(we are going to do this one later).**


