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

In graph theory, a tree is an undirected, connected and acyclic***graph***

In other words, a connected graph that does not contain even a single cycle is called a tree. 
A tree represents hierarchical structure in a graphical form

## Terminology
Basic

* **Root Node**: The <mark>topmost node</mark> of a tree or the node which does not have any parent node is called the root node.
  * A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
* **Parent Node**: The node which is a predecessor of a node is called the parent node of that node. 
  * Every node has a parent node, unless it is the Root Node
* **Child Node**: The node which is the immediate successor of a node is called the child node of that node.
* **Siblings**: Children of the same parent node are called siblings.

---
Levels

* **Degree of a Node**: The total count of subtrees/children attached to that node is called the degree of the node. 
  * The degree of a leaf node must be 0. 
  * The degree of a tree is the degree of its root.
* **Depth of a node**: The count of edges from the root to the node.
* **Height of a node**: The number of edges on the longest path from that node to a leaf.
* **Height of a tree**: The height of a tree is the height of the root node i.e the count of edges from the root to the deepest node.
* **Level of a node**: The count of edges on the path from the root node to that node.
    * The root node has level 0.

---
Generalizing

* **Ancestor of a Node**: <mark>Any predecessor</mark> nodes on the path of the root to that node are called Ancestors of that node. 
* **Descendant**: <mark>Any successor</mark> node on the path from the leaf node to that node.
* **Subtree**: Any node of the tree along with its descendant

* **Internal node**: A node with at least one child is called Internal Node. 
* **Leaf Node or External Node**: The nodes which do not have any child nodes are called leaf nodes.

* **Neighbour of a Node**: Parent or child nodes of that node are called neighbors of that node. 

---

## 
