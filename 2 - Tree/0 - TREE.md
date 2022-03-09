# Tree
_Recursive Definition_: <mark>A tree consists of a root, 
and zero or more subtrees</mark> T1, T2, … , Tk such that there is an edge 
from the root of the tree to the root of each subtree.

It is a couple `T = (N, A)`</mark>
* N is a finite _set of nodes_
  * It contains `r` called Root Node
* A is a finite _set of arches_
  * It is a set of pairs of nodes called **Arches** 
  * The set of all Arches is called **A** 

A tree is **non-linear** and a **hierarchical** data structure consisting of a collection of nodes such that each node 
of the tree stores a value, a list of references to nodes.

In graph theory, a tree is an undirected, connected and acyclic ***graph***

In other words, a connected graph that does not contain even a single cycle is called a tree. 
A tree represents hierarchical structure in a graphical form

![Tree example](https://github.com/PayThePizzo/DataStrutucures-Algorithms//blob/main/Resources/tree-parts.jpg?raw=TRUE)

## Terminology

* **Root Node**: The <mark>topmost node</mark> of a tree or the node which does not have any parent node is called the root node.
  * A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
* **Parent Node**: The node which is a predecessor of a node is called the parent node of that node. 
  * Every node has a parent node, unless it is the Root Node
  * Usually noted as *u* 
* **Child Node**: The node which is the immediate successor of a node is called the child node of that node.
  * Usually noted as *v* 
* **Siblings**: Children of the same parent node are called siblings.

---
### Path
A Path from a node *u* to a node *u'* is a sequence of nodes <n0, n1,...nk> such that:
1. u = n0 
2. u' = nk
3. <n(i-1), n(i)> belong to A  (with i from 1 to k) 

* **Length**: the number of arches of the path or the count total of the nodes composing the path minus one.
  * There is always a path from *u* to *u* of length 0

---
### Levels

* **Level of a node**: The count of edges on the path from the root node to that node.
  * The root node has level 0.
* **Degree of a Node**: The <mark>total count of subtrees/children</mark> attached to that node is called the degree of the node. 
  * The degree of a leaf node must be 0. 
  * The degree of a tree is the degree of its root.
* **Depth of a node**: The count of edges/branches from the root to the node.
  * The length of the path from the root to the node x.
* **Height of a node**: The number of edges/branches on the **longest path** from that node to a leaf.
* **Height of a tree**: The count of edges/branches from the root to the deepest node.
  * The longest path from the root to a leaf node of the tree T.
  * An empty tree has height equal to -1.
  * A tree with one node has height 0.

---
### Generalizing

* **Ancestor of a Node**: <mark>Any predecessor</mark> nodes on the path of the root to that node are called Ancestors of that node. 
  * If x is a node in a tree T (with T having nodes from its root r), any node y in a path (r,x) is an ancestor.
* **Descendant**: <mark>Any successor</mark> node on the path from the leaf node to that node.
  * If y is ancestor of x, x must be descendant of y.

**Proper** Ancestor/Descendant: Since every node is ancestor and descendant of itself, 
we must imply that the node x does not coincide with y 

* **Subtree**: Any node of the tree along with its descendant

* **Internal node**: A node with at least one child is called Internal Node. 
* **Leaf Node or External Node**: The nodes which do not have any child nodes are called leaf nodes.
* **Neighbour of a Node**: Parent or child nodes of that node are called neighbors of that node. 

---
## Data
Tree, a set of nodes and a set of arches

---
## Operations
NewTree():
* Pre: //
* Post: Returns a Tree.

Treempty(Tree t):
* Pre: //
* Post: Returns true if t is empty, else false.

Father(Tree t, Node u):
* Pre: 𝑢 ∈ 𝑇 
* Post: Returns father of 𝑢.
  
Children(Tree t, Node u):
* Pre: 𝑢 ∈ 𝑇 
* Post: Returns a list of the children of 𝑢.
  
Visits 

---
## Implementation Type
1. Fathers' Vector
2. Positional Vector
3. Pointers to Children - CS
4. Children List - CS
5. Left Child, Right Sibling - CS

---
### Credits
* [Geeks for Geeks - Trees](https://www.geeksforgeeks.org/)
* [Adrian Mejia - Trees](https://adrianmejia.com/data-structures-for-beginners-trees-binary-search-tree-tutorial/)
