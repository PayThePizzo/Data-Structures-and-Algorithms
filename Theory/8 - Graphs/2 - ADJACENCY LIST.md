# Adjacency List
For this implementation we use a **vector**, with $n = |V|$ cells and multiple
linked-lists

Every cell:
* Is numbered and their number reflects the ones given in the graph.
* Has a pointer to a linked-list
  * The linked list contains an element for every edge that goes from 
  a vertex $u$, represented by the cell $x$ of the vector, to another vertex $v$
  
Example: this graph right here, would be implemented like this

![AdjacencyList](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/AdjacencyList.png?raw=TRUE)

## Space

| Case         	| Space $S(n)$                                            	|
|--------------	|---------------------------------------------------------	|
| Sparse Graph 	| $S(n) = \mathcal{O} (\|V\|+\|E\|) = \mathcal{O} (n+m)$  	|
| Dense Graph  	| $S(n) = \mathcal{O} (n^{2})$                            	|

## Time
Verifying adjacency in the case of a long linked-list, takes more time.

---


### Conclusions
Because the adjacency-list representation provides a compact way to represent sparse graphs, it is usually the method of choice

Pros:
* Works best with sparse graphs 

Cons:
* Dense graphs might require very large space 
* Verifying adjacency in case of a long linked list, takes more time