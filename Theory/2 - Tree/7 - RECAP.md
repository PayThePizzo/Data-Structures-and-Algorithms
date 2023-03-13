# Tree


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

| **Tree**               	| **Defintion**                                                                                                                                                           	| **Notes**                                                 	|
|------------------------	|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|-----------------------------------------------------------	|
| _Rooted tree_          	| It is a pair $T = (N, A)$ with $\|N\| < \infty$ a finite set of nodes and $A \subseteq N \times N$ is a finite set of edges                                             	|                                                           	|
| _Binary tree_          	| An empty tree is a binary tree. A tree having a root node and two binary subtrees (respectively left subtree and right subtree) is a binary tree                        	|                                                           	|
| _K-ary tree_           	| A tree where the children of a node are labeled with **distinct** positive integers $i \in \mathbb{N}^{+} \wedge i \in [1,k]$ and no labels larger than $k$ are present 	| Binary tree is a 2-ary tree                               	|
| _Complete k-ary tree_  	| A k-ary where all the leaves have the same depth and all the internal nodes $u$ have exactly $deg(u) = k$                                                               	| $f(h=k) = k^{h}$, $i(h=k)= k^{h}-1/k-1$, $h = log_{k}(n)$ 	|
| _Balanced binary tree_ 	|                                                                                                                                                                         	|                                                           	|
| _Binary search tree_   	|                                                                                                                                                                         	|                                                           	|

---

## Data Structures

| Data Structure                               	| S(n)         	| `Parent(Tree t, Node v)` 	| `Children(Tree t, Node v)` 	|
|----------------------------------------------	|--------------	|--------------------------	|----------------------------	|
| _Father's Vector_                            	| $\Theta(n)$  	| $T(n) = \mathcal{O}(1)$  	| $T(n) = \Theta(n)$         	|
| _Positional Vector_ with complete k-ary tree 	| $\Theta(n)$  	| $T(n) = \mathcal{O}(1)$  	| $T(n) = \mathcal{O}(k)$    	|
| _Pointers to Children_ with binary tree      	| $\Theta(nk)$ 	| $T(n) = \mathcal{O}(1)$  	| $T(n) = \mathcal{O}(1)$    	|
| _List of Pointers to Children_               	| -            	| -                        	| -                          	|
| _Left Child Right Sibling_                   	| $\Theta(n)$  	| $T(n) = \mathcal{O}(1)$  	| $T(n) = \Theta(deg(v))$    	|
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

### Decompose and Recombine
For divide-et-impera algorithms where we need to evaluate or verify some properties of the trees we have a blueprint

```c++

int recomb(Node u, Node v){
    // Combine answers
    // Return
}

int decomp(Node u){
    // BASE CASES: Empty Tree or Leaf, or any other given case...
    if(u == nullptr){
        // immediate answer
    }
    // DIVIDE ET IMPERA
    else{
        result_sx = decomp(u->left);     
        result_dx = decomp(u->right);
        // evaluate some more more conditions...
        
        //COMBINE
        return recomb(result_sx, result_dx);
    }
}
```

```math
T(n)= \left\{\begin{matrix}
 T(k)+T(n-k-1)+d & n>0 \\
 c & n=0 \\
\end{matrix}\right.
```

### Demonstration 


---

## Exam:
The implicit implementations for the exams are the following ones:
* General Trees, [Left Child, Right Sibling](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/2%20-%20Tree/4.3%20-%20CONNECTED%20STRUCTURES.md)
* Binary Trees, [Pointers to Children](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/2%20-%20Tree/4.1%20-%20CONNECTED%20STRUCTURES%20.md)
* 