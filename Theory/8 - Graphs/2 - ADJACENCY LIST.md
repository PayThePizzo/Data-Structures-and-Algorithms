# Adjacency List

For this implementation 
* We use a **vector** $Adj[]$, of length $|V| = n$.
* Each cell $Adj[u]$, $\forall u \in V$.
  * Is **labeled** in a way that reflects the given graph
  * Contains a pointer to a linked list, where each element of the list represents
  a vertex $v \in V$ adjacent to $u$, such that $(u,v) \in E$
    * Those elements are labeled too.

Furthermore
* For vertex-weighted graphs, $Adj[u]$ also contains the weight $w(u)$
* For edge-weighted graphs, each element of the linked list has additional information for the weight $w(u)$


Example: this graph right here, would be implemented like this

![AdjacencyList](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/AdjacencyList.png?raw=TRUE)

---

## Space

| Case         	| Space $S(n)$                                            	|
|--------------	|---------------------------------------------------------	|
| Sparse Graph 	| $S(n) = \mathcal{O} (\|V\|+\|E\|) = \mathcal{O} (n+m)$  	|
| Dense Graph  	| $S(n) = \mathcal{O} (n^{2})$                            	|

## Time
Verifying adjacency in the case of a long linked-list, takes more time.

---

### Conclusions

Because the adjacency-list representation provides a compact way to represent sparse graphs, it is usually the method
of choice.

| **Pros**                                                   	| **Cons**                                                     	|
|------------------------------------------------------------	|--------------------------------------------------------------	|
| Best for sparse graphs                                     	| Worst for dense graphs                                       	|
| Space complexity is not fixed to $\Theta(n^{2})$           	| Can worsen with dense graphs and large $n$                   	|
| Flexible structure for both undirected and directed graphs 	| Verifying adjacency when the lists are long, takes more time 	|
e