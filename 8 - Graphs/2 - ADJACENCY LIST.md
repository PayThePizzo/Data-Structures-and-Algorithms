# Adjacency List
For this implementation we use a **vector**, with `n = |V|` cells and multiple
linked-lists

Every cell:
* Is numbered and their number reflects the ones given in the graph.
* Has a pointer to a linked-list
  * The linked list contains an element for every edge that goes from 
  a vertex u, represented by the cell `x` of the vector, to another vertex `v`


Example: this graph right here, would be implemented like this

![ex graph AL](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exgraphAL.png?raw=TRUE)


![ex list AL](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exlistAL.png?raw=TRUE)


---

### Conclusions

Pros:
* Works best with sparse graphs since S(n) = O(n+m) = O(|V| + |E|)

Cons:
* Dense graphs might require very large space and verifying adjacency in case of a long linked list, takes more time