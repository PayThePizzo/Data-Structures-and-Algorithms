# Adjacency Matrix
For this implementation we use a **matrix**, with `n x n = |V| x |V|` elements a(i,j)

Every element a(i,j):
* 0 if between i and j there is NO edge
* 1 if between i and j there is an edge


Example: this directed graph right here, would be implemented like this

![ex graph AM](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exgraphAL.png?raw=TRUE)

![ex matrix AM](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exmatrixAM.png?raw=TRUE)

Example: this undirected graph right here, would be implemented like this

![ex un graph AM](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exUngraphAM.png?raw=TRUE)

![ex un matrix AM](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exUnmatrixAM.png?raw=TRUE)

We can easily that self-loops are absent since all the elements where i = j, are represented by 0.
* It also a symmetric matrix because edges do not have a direction. 
* a(i,j) = a(j,i) for every i,j = 1...n.

---

### Conclusions

Pros: 
* Works best with dense graphs
* Verifying adjacency, regardless of the graph's density, takes T(n) = O(1)

Cons:
* May occupy more space if the graph is sparse 