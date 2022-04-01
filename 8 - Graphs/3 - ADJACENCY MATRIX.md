# Adjacency Matrix
For this implementation we use a **matrix**, with `n x n = |V| x |V|` elements a(i,j)

Every element a(i,j):
* 0 if between i and j there is NO edge
* 1 if between i and j there is an edge


Example: this graph right here, would be implemented like this

![ex graph AL](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exgraphAL.png?raw=TRUE)

![ex matrix AL](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exmatrixAL.png?raw=TRUE)

---

### Conclusions

Pros:
* Works best with dense graphs
* Verifying adjacency, regardless of the graph's density, takes T(n) = O(1)

Cons:
* May occupy more space if the graph is sparse 