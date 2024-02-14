# (Rooted) Tree
There are many ways to define trees as a data structure

### Recursive Definition
> A (rooted) tree $T$ consists of a root, and zero or more subtrees $T_{1}, T_{2}, \ldots , T_{k}$ such that there is 
> an edge from the root of the tree $T$ to the root of each subtree.

<br>

### Traditional Definition
It is a pair

$$T = (N, A) $$

where
* $N$ is a finite _set of nodes_, $|N| < \infty$
  * In particular, we identify $r \in N$ as the **root node**
* $A \subseteq N \times N$ is a finite _set of arches or edges_, $|A| \leq |N|^{2}$
  * Where arches or edges are pairs of nodes $(u,v) \in A$ where $u,v \in N$, which represent a link between two nodes.

In a tree every node (except for the root $r$) $v \in N$ has exactly 1 parent or father node $u \in N$, 
such that $(u,v) \in A$ 

<br>

### Graph Theory Definition 
> A rooted tree is a free tree (an undirected, connected and acyclic graph) in which one of the vertices (called the 
> root node) is distinguished from the others.
* In other words, a connected graph that does not contain even a single cycle is called a tree. 
* A tree represents hierarchical structure in a graphical form

<br>

### Data Structure Definition
A tree is **non-linear** and a **hierarchical** data structure consisting of a collection of nodes such that each node
of the tree stores a value, a list of references to nodes.

---

<br>

## Terminology

![Tree example](https://github.com/PayThePizzo/DataStrutucures-Algorithms//blob/main/Resources/tree-parts.jpg?raw=TRUE)

**Root Node**: The topmost node of a tree or the node which **does not have any parent node** is called the root node.
* A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.

**Parent Node**: The node which is a predecessor of a node is called the parent node of that node. 
* Every node has a parent node, unless it is the Root Node
* Usually noted as $u$

**Child Node**: The node which is the immediate successor of a node is called the child node of that node.
* Usually noted as $v$
* A node $u$ can have $0+$ children $v$ such that $(u,v) \in A$

**Siblings**: Children of the same parent node are called siblings.

### Path

A **Path** from a node $u \in N$ to a node $u' \in N$ is a sequence of nodes 

$$p = < n_{0}, n_{1}, \ldots, n_{k} >$$ 

Such that:
* $u = n_{0}$
* $u' = n_{k}$ 
* Each pair of consecutive nodes $\forall < n_{i-1}, n_{i} > \in N \Rightarrow (n_{i-1}, n_{i}) \in A$ with $i = 1, \ldots, k$

```math
p(u, u') = \text{ } < n_{0}, n_{1}, \ldots, n_{k} > \quad \text { where} \left\{\begin{matrix}
 n_{0}=u \\
 n_{k}=u \\
 < n_{i-1}, n_{i} > \Rightarrow (n_{i-1}, n_{i}) \in A, \forall i=1, \ldots, k\\
\end{matrix}\right. 
```

**Length of a path**: is the count of arches of the path or the count of the nodes composing the path $-1$.
* There is always a path from *u* to *u* of length 0

```math
length(p(u, u')) = 
\left\{\begin{matrix}
count((u,v)\in p(u,u')) = count(v \in p(u,u')) -1 &  u \neq u' \\
0 & else
\end{matrix}\right.
```

### Level, Degree, Depth and Height

**Degree of a Node**: The total count of subtrees/children attached to that node is called the degree of the node.
* The degree of a leaf node must be 0.
* The degree of a tree is the degree of its root.

```math
deg(u \in T) = \begin{Bmatrix}
count(children(u)) & \text{ if } u \text{ is not a leaf } \\
0 & \text{ else } \\
\end{Bmatrix}
```

**Depth or Level of a node**: The length of the path from the root node to that node.
* The root node has level 0.
* Level $n$ inside of a tree $T$: All the nodes in $T$ at level $n$

```math
level(u \in N)= length(p(root, u)) = 
\left\{\begin{matrix}
count((u,v)\in p(root,u)) = count(v \in p(root,u)) -1 &  u \neq root \\
0 & else
\end{matrix}\right.
```

**Height of a node**: The number of edges/branches on the **longest path** from that node to a leaf.

```math
h(u \in N) = max(length(p(u, leaf))) 
```

**Height of a tree**: The count of edges/branches from the root to the deepest node or the height of its root.
* The longest path from the root to a leaf node of the tree T.
* An empty tree has height equal to -1.
* A tree with one node has height 0.

```math
h(T) = 
\left\{\begin{matrix}
-1 & \text{ if } |N|=0 \\
 0 & \text{ if } |N|=1\\
h(r \in N) & else \\
\end{matrix}\right.
```

**Balanced tree**: A tree with $h = \mathcal{O}(log(n))$

### Generalizing

* **Ancestor of a Node**: Any predecessor nodes on the path of the root to that node are called Ancestors of that node. 
  * If x is a node in a tree T (with T having nodes from its root r), any node y in a path (r,x) is an ancestor.
* **Descendant**: Any successor node on the path from the leaf node to that node.
  * If y is ancestor of x, x must be descendant of y.
* **Proper** Ancestor/Descendant: Since every node is ancestor and descendant of itself, we must imply that the node x does not coincide with y
* **Subtree**: Any node of the tree along with its descendant
* Subtree with root in $x$: The induced subtree by the descendants of $x$, with root in $x$
* **Internal node**: A node with at least one child is called Internal Node. 
* **Leaf Node or External Node**: The nodes which do not have any child nodes are called leaf nodes.
* **Neighbour of a Node**: Parent or child nodes of that node are called neighbors of that node. 
  * Any node connected to u through a direct edge.


---

## Data
Tree, a set of nodes and a set of arches

---

## Operations

| **Operation**              	| **Pre-Condition** 	| **Post-Condition**                      	|
|----------------------------	|-------------------	|-----------------------------------------	|
| `NewTree()`                	| -                 	| Returns a Tree                          	|
| `Treempty(Tree t)`         	| -                 	| Returns true if t is empty, else false. 	|
| `Father(Tree t, Node u)`   	| $u \in T$         	| Returns father of $u$                   	|
| `Children(Tree t, Node u)` 	| $u \in T$         	| Returns a list of the children of $u$   	|

---
## Implementation Type
1. Fathers' Vector
2. Positional Vector
3. **Pointers to Children** - CS
   1. For binary trees
4. Children List - CS
5. **Left Child, Right Sibling** - CS
   1. For general trees

---

### Credits
* [Geeks for Geeks - Trees](https://www.geeksforgeeks.org/)
* [Adrian Mejia - Trees](https://adrianmejia.com/data-structures-for-beginners-trees-binary-search-tree-tutorial/)
