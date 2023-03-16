# Balanced Trees
Trees are optimal data structures for dynamic sets as their implementation allows us to reduce $T(n)$ to $\mathcal{O}(h)$

We can use some declinations of the binary tree to improve its balance

---

## AVL Trees
AVL trees are BST that **are always balanced**.

For every node $u$ in the tree $T$ $\forall u \in T $:
* A key of any kind, $u.key$
* **Balancing Factor** (BF), $u.BF = h(u.left)-h(u.right) \in \mathbb{N}$
  * An integer indicating the difference between the height of the left-subtree and the height of the right-subtree.
  * In an AVL Tree, for each node $u$ $|u.BF| \leq 1$ for every node x.

This complicates the operations of insertion and extraction because we need to maintain the BF.

---

## B-Trees
B-Trees are balanced BST of degree t (with t>=2). They are not necessarily binary trees. 

However, they must satisfy the following conditions: 
1. Every leaf has the same depth
2. Every node (except for the root) saves $k(v)$ sorted keys.
   1. $key_{1}(v) \leq key_{2}(v) \leq \ldots \leq key_{kv}(v)$
   2. Where $t-1 \leq k(v) \leq 2t-1$, with  $t \geq 2$
3. Every node $u$ (except for the root) have $deg(u) = t$
4. The root saves $1 \leq n leq 2t-1$ ordered keys
5. Every internal node $v$, has $k(v)+1$ children
6. The keys $i(v)$ separates the intervals of keys saved in each subtree:
   1. If $c(i)$ is a key in the i-ary subtree of a node $v$, then $c(1) \leq v.key(1) \leq c(2) \leq \ldots \leq x.v(k)$ with $1 \ldots k$ as the number of the children.


![BTrees](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/BTrees.png?raw=TRUE)

The keys being ordered reduced to a cost $\mathcal{O}(log(n))$ the cost for most operations.

--- 

## Red and Black Trees
Red and black trees are BST *almost* balanced.

Their main feature is that their nodes contain one more piece of information about themselves: the **color of the node**.
* Black 
* Red

They must also respect the following conditions:
1. Every node is either black or red
2. The root node is **initially black**
3. Every leaf is **black** and contains **NULL**
4. Both children of a red node, are black
5. Every path from a node x to a leaf (contained in x's subtree) has the same number of black nodes.

If all these conditions are to be found in a BST, then a RB Tree also guarantees the following invariant: The longest path of the tree cannot be longer than double the smallest path.

$\text{ Longest Path } \leq 2 \cdot \text{ Shortest Path }$

Here again, most operations have a reduced cost equal to $\mathcal{O}(log(n))$.
