# Binary Search Tree
It is a tree that satisfies the following <mark>search property</mark>:
Let **x** be a node in a BST
* If *y* is a node in the **LEFT-subtree** of x, then `y.key <= x.key`
* If *y* is a node in the **RIGHT-subtree** of x, then `y.key >= x.key`

This ensures that symmetric visit the order of the returned key 
will not be decreasing.

Example:

![BST Tree](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/BST.png?raw=TRUE)

For the second one the property does not stand, in fact all the keys in the right subtree should
be larger than 3.


### Balancing Trees
They are not necessarily balanced, the **balancing principle** (as we stated before)
implies that the height of the tree is such that: <mark>h = O(log(n))</mark>

This is very important since it will help us optimize our algorithms.

---

## Tree Search
* Pre: //
* Post: Returns node 𝑢 with the key k if present (starting from the Node x). Else, returns NULL.

### Recursive
```python
tree_search_rec(Node x, Key k)
    if(x == NULL || x.key == k):
        return x;
    if(x.key > k):
        return search(x.left, k);
    else:
        return search(x.right, k);
```
**Final Time Complexity**: T(n) = O(h)
* h being the height of the tree
* If it is a balanced tree, it will be more likely to be O(log(n))
* If it is highly unbalanced, it will be more likely to be Θ(n)

### Iterative
```python
tree_search_iter(Node x, Key k)
    while(x != NULL && x != k):
        if(x.key > k):
            x = x.left;
        else:
            x = x.right;
    return x;
```
**Final Time Complexity**: T(n) = O(h)
* Basically, it is like we are walking down a path from the root of the tree and as we know,
the longest path is equal to the tree's height.

---

## Tree Max
* Pre: x can be found in T
* Post: Returns node 𝑢 with the largest key k (if present & tree is NOT empty). 
Else, returns NULL.

Idea:
* If x.right == NULL, every key k in the right subtree is such that: `k <= x.key`;
    * So x.key must be the maximum.
* Else, we can find larger keys in the right subtree;
    * The maximum must be in this subtree.

### Recursive
```python
tree_maximum_rec(Node x)
    if(x != NULL && x.right != NULL): #Max can be found on the right-subtree
        x = x.right;
    return x;
```
**Final Time Complexity**: T(n) = O(h)

### Iterative
```python
tree_maximum_iter(Node x)
    while(x.right != NULL):
        x = x.right;
    return x;
```
**Final Time Complexity**: T(n) = O(h)

---

## Tree Minimum
* Pre: x can be found in T
* Post: Returns node 𝑢 with the smallest key k (if present & tree is NOT empty).
Else, returns NULL.

Idea:
* If x.left == NULL, every key k in the left subtree is such that: `k >= x.key`;
  * So x.key must be the minimum.
* Else, we can find smaller keys in the left subtree;
  * The minimum must be in this subtree.

### Recursive
```python
tree_ minimum_rec(Node x)
    if(x != NULL && x.left != NULL): #Min can be found on the left-subtree
        x = x.left;
    return x;
```
**Final Time Complexity**: T(n) = O(h)

### Iterative
```python
tree_minimum_iter(Node x)
    while(x.left != NULL): 
        x = x.left;
    return x;
```
**Final Time Complexity**: T(n) = O(h)

---

## Intro
Given a Node x of BST, we want to find the successor and the predecessor by following
the order of a <mark>Symmetric Visit</mark>

## Symmetric Visit
A Symmetric visit for a BST of n nodes can be implemented by
1. Finding the tree_minimum()
2. n-1 calls to tree_successor()

**Final Time Complexity**: T(n) = Θ(n)
* n calls to the procedures, which requires T(n) = Ω(n)
* Iterating through every n-1 arch two times at most, which requires T(n) = O(n)


## Successor
A successor for a node x in a BST, is the node who follows x in a symmetric visit
* Pre: Node 𝑢 can be found in T
* Post: Returns the successor through a symmetric visit of the node 𝑢

If all the keys are distinct the successor of u is the node v with the smallest key
such that `v.key > u.key`

We distinguish two cases here:
1. If x has a right child
   1. The successor is the minimum of the RIGHT-SubT
2. Else, the successor is the minimum ancestor of x, whose left child is also
an ancestor of x


![Succ](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/Succ.jpg?raw=TRUE)


```python
tree_successor_iter(Node x){
    if(x != NULL && x.right != NULL):
        return tree_minimum(x.right);
    else:
        Node y = x.parent;
        # x is right child of x.parent 
        while(y != NULL && x == y.right):
            # Keep going up
            x = y;
            y = y.parent;
        return y;
```
**Final Time Complexity**: T(n) = O(h)
* becomes O(n) if T is a highly unbalanced tree
* becomes O(log(n)) if T is balance

---

## Predecessor
A predecessor for a node x in a BST, is the node who precedes x in a symmetric visit

* Pre: Node 𝑢 belongs to the tree T
* Post: Returns the predecessor through a symmetric visit of the node 𝑢

The procedure is specular to the one of the successor.

```python
predecessor(Node x)
    if(x != NULL && x.left != NULL):
        return maximum(x.left);
    else:
        # If x is left child of
        Node y = x.p;
        while(y != NULL && x == y.left):
            # Keep going up
            x = y;
            y = y.parent;
        return y;


```
**Final Time Complexity**: T(n) = O(h)
* h as the height
* becomes O(n) if T is a highly unbalanced tree
* becomes O(log(n)) if T is balanced

---

## Tree Transplant
* Pre: Nodes u and v belong to tree T
* Post: Substitutes the T's subtree with root in u,
with the subtree with root in v

![Transplant](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/Transplant.png?raw=TRUE)

```python
transplant(Tree t, Node u, Node v)
    if(u.parent == t.root):
        t.root = v; # If u is the root, we need to change the root
    else if(u == u.parent.left): # Verify if u is left or right child, to keep it that way
        u.parent.left = v; 
    else:
        u.parent.right = v;
    if(v != NULL): # update v.parent
        v.parent = u.parent;
```

## Tree Delete Node
* Pre: z ∈ T
* Post: Delete node z, ensures T remains a BST.

When deleting a node, we can encounter three cases:
1. Node z is **childless**
   1. We need to modify the father by transplanting z with NULL;
   2. z.p = NULL
2. Node z has **only one** child
   1. We remove z and we connect z.child with z.parent
   2. z.parent = z.child.parent 
3. Node z has two children
   1. We need to look for a successor `y`, such that `successor(z): y`, and we replace z with y
   2. y does not have a left-child

```python
remove(Tree t, Node z){
    if(z.left == NULL): # No left child/ z is leaf -> Replace z with its right child
        transplant(t, z, z.right); 
    else if(z.right == NULL): # No right child/ z is leaf -> Replace  z with its left child
        transplant(t, z, z.left); 
    else: # Both children > find successor
        Node y = tree_minimum(z.right); 
        if(y.parent != z):  # z successor's parent != z
            transplant(t, y, y.right);  # Now y right child is z's right child
            y.right = z.right; 
            z.right.parent = y;
        transplant(t, z, y);    # Change z with y (z's successor)
        y.left = z.left;  # Now left child of y is z's leftchild
        y.left.parent = y;   
```
**Final Time Complexity**: T(n) = O(h)

---

## Tree Insert
* Pre: z is a node such that z.key = v and z.left = z.right = NULL
* Post: Node z is inserted in T

```python
tree_insert(Tree t, Node z)
    Node y = NULL;
    Node x = t.root;
    while(x != NULL)
        y = x; # When we go deeper we save the parent
        if(z.key < x.key):
            # x equal to its left child
            x = x.left;
        else:
            # x equal to its right child
            x = x.right;    
    z.parent = y;
    if(y == NULL): #T is empty from the start
        t.root = z;
    else if(z.key < y.key):
        y.left = z;
    else:
        y.right = z;
```
**Final Time Complexity**: T(n) = O(h)
* h as the height
* becomes O(n) if T is a highly unbalanced tree
* becomes O(log(n)) if T is balance


## BST Tree Build
Using a vector v. which contains the key we want to insert in T

### Iterative
```python
bst_build(int v[], int dim)
    Tree t = newtree();
    for(i=0 to v.length):
        u = newnode(v[i]);
        tree_insert(t, u);
    return t;
```
**Final Time Complexity**: T(n) = O(n**2)
* If input is unordered we have a very time consuming algorithm

This is too expensive, but we can do better.

### Divide et Impera - Vector
Using a **sorted** vector v and a Divide-et-Impera algorithm.

Idea: If v is sorted, we can start from the half of the array and take the element in the middle.
* Left Side: elements that we find at the left of the central element
* Right Side: the rest

```python
tree_buildBST_optim(int v[], int dim)
    Tree t = newtree();
    t.root = buildAux_optim(v, 0, dim - 1, NULL);
    return t;

Node buildAux_optim(int v[], int start, int end, Node parent)
    if(start > end):
        return NULL;
    else:
        int med = ⌊(start + end)/2⌋ ;
        Node x = newnode(v[med]);
        x.parent = parent;
        x.left = tree_buildBST_optim(v, start, med - 1, x);
        x.right = tree_buildBST_optim(v, med + 1, end, x);
    return x;
```
**Final Time Complexity**: T(n) = Θ(n log(n))
1. Sort the vector -> Θ(n log(n))
2. Apply the tree_buildBST_optim() function -> Θ(n)

The tree is kept balanced!

---

## Conclusion

The implementation through dynamic sets can perform most operations in T(n) = O(h):
* Min
* Max
* Successor
* Predecessor

However:
* If the tree is unbalanced **h -> n** 
* If the tree is kept balanced **h -> log(n)**

So what we ought to do is to keep the tree we are working with, balanced.
_But how do we do just that?_ There are some implementations of trees that might be interesting to cover
in order to discover it:
1. AVL Trees
2. B-Trees
3. RB-Trees
