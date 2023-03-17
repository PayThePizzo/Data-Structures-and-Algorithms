# Binary Search Tree
It is a tree that satisfies the following **search property**:
Let **x** be a node in a BST
* If *y* is a node in the **LEFT-subtree** of x, then `y.key <= x.key`
* If *y* is a node in the **RIGHT-subtree** of x, then `y.key >= x.key`

> The search property allows us to list in a non-decreasing way the keys in a binary search tree when we perform a symmetric visit of the tree

```math
\forall x \in N = 
\left\{\begin{matrix}
y\in N \text{ is in the left-subtree} & \Leftrightarrow y.key \leq x.key 
\\y\in N \text{ is in the right-subtree} & \Leftrightarrow y.key \geq x.key
\\\end{matrix}\right. 
```

Example:

![BST Tree](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/BST.png?raw=TRUE)

For the second one the property does not stand, in fact all the keys in the right subtree should be larger than 3.

## Operations

The clue aspect of a BST is the efficiency, as the tree can improve its performance when balanced.

The idea here is to exploit the search property (which is universal) as most of the time we will compare the given value 
to all the keys in order to find our answers. Thus, it is like going down the path starting from the root and stopping 
when we find the right node, or we reach the leaves. This implies that the worst case is getting on the longest path 
from the root to the leaves, which is the exact definition of **height of a tree**.

The latter depends on how the leaves are distributed, which means we might find a tree where all the nodes only have 
a left-child, which implies it is very unbalanced. Verifying a universal condition under these circumstances would 
require visiting the whole tree (namely covering all the nodes) which takes $T(n=h) = \Theta(n=h) = \Theta(n)$ 
(keep in mind we allow some slight abuse of notation).

The good news is that we can also define a lower bound, for the case where the tree is balanced, and we just need to 
explore $\frac{1}{2}$ of the tree. As we know from the fact that the nodes are not infinite, and that for each internal 
node we have at most $2$ children, we can define the best case as $T(n=h) = \mathcal{O}(h) = \mathcal{O}(log(n))$ when the tree is balanced. 
This is possible when we split all the nodes into two subtrees which are also balanced.

We conclude that for most operations of BST:

```math
T(n=h)= \mathcal{O}(h) = 
\left\{\begin{matrix}
\mathcal{O}(log(n)) & \text{ if tree is balanced } \\
\Theta(n) &  \text{ else }\\
\end{matrix}\right.
```

| **Operation**                             	| **Pre-Condition**                             	| **Post-Condition**                                                                               	| **Time** $T(n) = T(h)$                                   	| _Notes_                                                                                              	|
|-------------------------------------------	|-----------------------------------------------	|--------------------------------------------------------------------------------------------------	|----------------------------------------------------------	|------------------------------------------------------------------------------------------------------	|
| `tree_search(Node x, Elem k) -> Node`     	| -                                             	| Returns a node $u$ with $u.key = k$ or $NIL$ if none is present (or the tree is empty)           	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| Depends if the tree is balanced                                                                      	|
| `tree_max(Node x) -> Node`                	| $x \in T$                                     	| Returns a node $x$ with $x.key$ as the largest key inside the BST or $NIL$ if the tree is empty  	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| $x$ is the rightmost node                                                                            	|
| `tree_min(Node x) -> Node`                	| $x \in T$                                     	| Returns a node $x$ with $x.key$ as the smallest key inside the BST or $NIL$ if the tree is empty 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| $x$ is the leftmost node                                                                             	|
| `tree_predecessor(Node x) -> Node`        	| $x \in T$                                     	| Returns a predecessor node $y$ with $y.key<=x.key$ or $NIL$ if none is present                   	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| Given $x \in T$ the predecessor of $x$ is the node $y \in T$ which precedes $x$ in a Symmetric visit 	|
| `tree_successor(Node x) -> Node`          	| $x \in T$                                     	| Returns a successor node $y$ with $y.key>=x.key$ or $NIL$ if none is present                     	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| Given $x \in T$ the successor of $x$ is the node $y \in T$ which succeeds $x$ in a Symmetric visit   	|
| `tree_insert(Tree t, Node z)`             	| $z.key = value \wedge z.left = z.right = NIL$ 	| Inserts z in the Tree t, $z \in T$                                                               	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|                                                                                                      	|
| `tree_transplant(Tree t, Node u, Node v)` 	| t is a BST                                    	| Substitutes the subtree having $root = u$ with the subtree having $root = v$                     	| $\mathcal{O}(1)$                                         	|                                                                                                      	|
| `tree_delete(Tree t, Node z)`             	| $z \in T$                                     	| $z \notin T$, $z$ is removed from $T$                                                            	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	| Three cases: z is a leaf, z has only one child, z has two children                                   	|

---

## Tree Search
For the search operation we keep comparing the given key to the ones present in the tree and switching of branch until
we reach a target or the leaves.

| Operation                                  	| **Pre-Condition** 	| **Post-Condition**                                              	| **Time** $T(n) = T(h)$                                                	|
|--------------------------------------------	|-------------------	|-----------------------------------------------------------------	|----------------------------------------------------------	|
| `tree_search_rec(Node x, Elem k) -> Node`  	| -                 	| Returns a node $u$ with $u.key = k$ or $NIL$ if none is present 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|
| `tree_search_iter(Node x, Elem k) -> Node` 	| -                 	| (As above)                                                      	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|

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

---

## Tree Max

If we want to find the largest key in a BST, by the search property it is the rightmost node's key.
* If x.right == NULL, every key k in the right subtree is such that: `k <= x.key`;
    * So x.key must be the maximum.
* Else, we can find larger keys in the right subtree;
    * The maximum must be in this subtree.

| Operation                  	| **Pre-Condition** 	| **Post-Condition**                                                                              	| **Time** $T(n) = T(h)$                                                 	|
|----------------------------	|-------------------	|-------------------------------------------------------------------------------------------------	|----------------------------------------------------------	|
| `tree_max(Node x) -> Node` 	| $x \in T$         	| Returns a node $x$ with $x.key$ as the largest key inside the BST or $NIL$ if the tree is empty 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|

### Recursive

```python
tree_maximum_rec(Node x)
    if(x.right == NULL):
        return x;
    else:
        return tree_maximum_rec(x.right); 
```

### Iterative

```python
tree_maximum_iter(Node x)
    while(x.right != NULL):
        x = x.right;
    return x;
```

#### Demonstration
This is true since
* if $x.right = NIL$, then every key in the left subtree is less or equal than $x.key$ which is the maximum, by the search property.
* if $x.right \neq NIL$, then there must be a larger key in that right subtree.

---

## Tree Minimum

If we want to find the smallest key in a BST, by the search property it is the leftmost node's key.
* If x.left == NULL, every key k in the left subtree is such that: `k >= x.key`;
  * So x.key must be the minimum.
* Else, we can find smaller keys in the left subtree;
  * The minimum must be in this subtree.

| Operation                  	| **Pre-Condition** 	| **Post-Condition**                                                                               	| **Time** $T(n) = T(h)$                                                 	|
|----------------------------	|-------------------	|--------------------------------------------------------------------------------------------------	|----------------------------------------------------------	|
| `tree_min(Node x) -> Node` 	| $x \in T$         	| Returns a node $x$ with $x.key$ as the smallest key inside the BST or $NIL$ if the tree is empty 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|

### Recursive

```python
tree_minimum_rec(Node x)
    if(x.left == NULL):
        return x;
    else:
        return tree_minimum_rec(x.left);    
```

### Iterative

```python
tree_minimum_iter(Node x)
    while(x.left != NULL): 
        x = x.left;
    return x;
```

#### Demonstration
This is true since
* if $x.left = NIL$, then every key in the right subtree is greater or equal than $x.key$ which is the minimum, by the search property.
* if $x.left \neq NIL$, then there must be a smaller key in that left subtree.

---

## Symmetric Visit
A Symmetric visit for a BST of n nodes can be implemented by
1. Finding the $tree_minimum()$
2. n-1 calls to $tree_successor()$

**Final Time Complexity**: T(n) = Θ(n)
* n calls to the procedures, which requires T(n) = Ω(n)
* Iterating through every n-1 arch two times at most, which requires T(n) = O(n)

---

## Successor
Given $x \in T$ the successor of $x$ is the node $y \in T$ which precedes $x$ in a Symmetric visit
* Remember: if all the keys are distinct the successor of u is the node v with the **smallest key** such that `v.key > u.key`

We distinguish two cases here:
1. $x.right \neq NIL \Longrightarrow successor(x) = minimum(x.right)$, 
   1. If $x$ has a right child, the successor is the minimum of the right subtree
2. Else, the successor is the minimum ancestor of $x$, whose left child is also an ancestor of $x$
   1. To find it we proceed upwards towards the root, and take the first node to the right.

| Operation                        	| **Pre-Condition** 	| **Post-Condition**                                                           	| **Time** $T(n) = T(h)$                                       	           | Notes                                                                             	|
|----------------------------------	|-------------------	|------------------------------------------------------------------------------	|------------------------------------------------------------|-----------------------------------------------------------------------------------	|
| `tree_successor(Node x) -> Node` 	| $x \in T$         	| Returns a successor node $y$ with $y.key>=x.key$ or $NIL$ if none is present 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	 | Given $x \in T$ the successor is the node which succeeds $x$ in a Symmetric visit 	|


![Succ](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/Succ.jpg?raw=TRUE)

```python
tree_successor_iter(Node x){
    if(x.right != NULL):
        return tree_minimum(x.right); # O(h)
    else:
        Node y = x.parent;
        # x is right child of x.parent 
        while(y != NULL && x == y.right):
            # Keep going up
            x = y;
            y = y.parent;
        return y;
```



---

## Predecessor
Given $x \in T$ the predecessor of $x$ is the node $y \in T$ which precedes $x$ in a Symmetric visit

The procedure is specular to the one of the successor.

We distinguish two cases here:
1. $x.left \neq NIL \Longrightarrow predecessor(x) = maximum(x.left)$,
    1. If $x$ has a left child, the successor is the maximum of the left subtree
2. Else, the predecessor is the minimum ancestor of $x$, whose right child is also an ancestor of $x$
    1. To find it we proceed upwards towards the root, and take the first node to the left.


| Operation                        	| **Pre-Condition** 	| **Post-Condition**                                                           	| **Time** $T(n) = T(h)$                                       	           | Notes                                                                             	|
|----------------------------------	|-------------------	|------------------------------------------------------------------------------	|------------------------------------------------------------|-----------------------------------------------------------------------------------	|
| `tree_successor(Node x) -> Node` 	| $x \in T$         	| Returns a successor node $y$ with $y.key>=x.key$ or $NIL$ if none is present 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	 | Given $x \in T$ the successor is the node which succeeds $x$ in a Symmetric visit 	|

```python
predecessor(Node x)
    if(x.left != NULL):
        return tree_maximum(x.left);
    else:
        # If x is left child of
        Node y = x.parent;
        while(y != NULL && x == y.left):
            # Keep going up
            x = y;
            y = y.parent;
        return y;
```

---

## Tree Insert

| **Operation**                 	| **Pre-Condition**                             	| **Post-Condition**                 	| **Time** $T(n) = T(h)$                                   	|
|-------------------------------	|-----------------------------------------------	|------------------------------------	|----------------------------------------------------------	|
| `tree_insert(Tree t, Node z)` 	| $z.key = value \wedge z.left = z.right = NIL$ 	| Inserts z in the Tree t, $z \in T$ 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|

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

#### Demonstration
If a node $x \in T$ (where $T$ is a BST) has two children, then its successor does not have a left child and its predecessor
does not have right child.

Let $x$ be a node with two children. Through a symmetric visit, the nodes in the left subtree precede $x$ and those in the
right subtree follow $x$. Thus, the $x$ 's predecessor is in the left subtree.

Let $s$ be the successor of $x$, we assume that $s$ has a left child $y$, $s.left = y$. Naturally $y$ follows $x$ in a
symmetric visit since it is in the right subtree. However, $y$ must precede $s$ in the symmetric visit as $y$ is in the left
subtree of $s$.

This is absurd! In this case $s \neq successor(x)$, so the existence of $y$ is absurd.

We conclude the successor $s$ ha no left child. In a specular way we can demonstrate that a predecessor $p$ has no right child.

---

## Tree Transplant

| **Operation**                             	| **Pre-Condition** 	| **Post-Condition**                                                           	| **Time** $T(n) = T(h)$ 	|
|-------------------------------------------	|-------------------	|------------------------------------------------------------------------------	|------------------------	|
| `tree_transplant(Tree t, Node u, Node v)` 	| t is a BST        	| Substitutes the subtree having $root = u$ with the subtree having $root = v$ 	| $\mathcal{O}(1)$       	|

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

| **Operation**                 	| **Pre-Condition** 	| **Post-Condition**                    	| **Time** $T(n) = T(h)$                                   	|
|-------------------------------	|-------------------	|---------------------------------------	|----------------------------------------------------------	|
| `tree_delete(Tree t, Node z)` 	| $z \in T$         	| $z \notin T$, $z$ is removed from $T$ 	| $\mathcal{O}(log(n)) \leq \mathcal{O}(h) \leq \Theta(n)$ 	|

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
**Final Time Complexity**: $T(n) = \Theta(n log(n))$
1. Sort the vector -> Θ(n log(n))
2. Apply the tree_buildBST_optim() function -> Θ(n)

The tree is kept balanced!

---

## Conclusion

The implementation through dynamic sets can perform most operations in $T(n) = O(h)$:
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
