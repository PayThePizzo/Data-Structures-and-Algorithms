# Tree

---

## Terminology

| **Terms**                                 	| **Definition**                                                                                 	| **Notes**                                      	|
|-------------------------------------------	|------------------------------------------------------------------------------------------------	|------------------------------------------------	|
| _Root_                                    	| The topmost node of a tree, which any non-empty tree must have                                 	| $r$ has no parents, $level(r \in T) = 0$       	|
| _Parent_                                  	| Immediate predecessor of a node $v$                                                            	| if $u$ is the predecessor, then $(u,v) \in A$  	|
| _Child_                                   	| Immediate successor of a node $u$                                                              	| if $v$ is the successor, then $(u,v) \in A$    	|
| _Siblings_                                	| Children of the same parent node                                                               	|                                                	|
| _Path_ $p$ from a node $u$ to a node $u'$ 	| $p = < n_{0}, n_{1}, \ldots, n_{k} >$ where $< n_{i-1}, n_{i} > \in A$ with $i = 1, \ldots, k$ 	|                                                	|
| _Length of a path_                        	|                                                                                                	| There is always a path from u to u of length 0 	|
| _Degree of a node_                        	|                                                                                                	|                                                	|
| _Level of a node_                         	|                                                                                                	|                                                	|
| _Depth of a node_                         	|                                                                                                	|                                                	|
| _Height of a node_                        	|                                                                                                	|                                                	|
| _Depth of a tree_                         	|                                                                                                	|                                                	|
| _Height of a node_                        	|                                                                                                	|                                                	|
| _Ancestor of a node_                      	|                                                                                                	| Every node is an ancestor of itself            	|
| _Descendant of a node_                    	|                                                                                                	| Every node is a descendant of itself           	|
| _Proper ancestor_                         	|                                                                                                	|                                                	|
| _Proper descendant_                       	|                                                                                                	|                                                	|
| _Subtree_                                 	|                                                                                                	|                                                	|
| _Induced subtree_                         	|                                                                                                	|                                                	|
| _Internal node_                           	|                                                                                                	|                                                	|
| _Leaf/external node_                      	|                                                                                                	|                                                	|
| _Terminal node_                           	|                                                                                                	|                                                	|
| _Neighbour of anode_                      	|                                                                                                	|                                                	|
---

## Trees

| **Tree**               	| **Defintion** 	| **Notes** 	|
|------------------------	|---------------	|-----------	|
| _Rooted tree_          	|               	|           	|
| _Binary tree_          	|               	|           	|
| _K-ary tree_           	|               	|           	|
| _Complete k-ary tree_  	|               	|           	|
| _Balanced binary tree_ 	|               	|           	|
| _Binary search tree_   	|               	|           	|

---

## Visits


| Visit      | Order                         |
|------------|-------------------------------|
| Pre-Order  | Root > L-Child > R-Child      |
| Symmetric  | L-Child > Root > R-Child      |
| Post-Order | L-Child > R-Child > Root      |
| BFS        | At each level, go from L to R |

---

## Things that are useful for the exams

|            	| Height 	|   	|
|------------	|--------	|---	|
| Empty Tree 	| $-1$   	|   	|
|            	|        	|   	|
|            	|        	|   	|
|            	|        	|   	|
|            	|        	|   	|
|            	|        	|   	|



---

## Exam:
The implicit implementations for the exams are the following ones:
* General Trees, [Left Child, Right Sibling](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/2%20-%20Tree/4.3%20-%20CONNECTED%20STRUCTURES.md)
* Binary Trees, [Pointers to Children](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/2%20-%20Tree/4.1%20-%20CONNECTED%20STRUCTURES%20.md)
* 