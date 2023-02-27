# Incidence Matrix
For this implementation we use a **matrix** $n \times m = |V| \times |E|$ 
* $n$ rows, representing the vertices
* $m$ columns, representing the edges
  * For every column j, we put a 1 in the row i corresponding to the vertices
  connected by edge represented by the column j (ex: e1)

Example: this undirected graph right here, would be implemented like this

![ex Un graph ML](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exUngraphIM.png?raw=TRUE)

![ex un Matrix ML](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exUnmatrixIM.png?raw=TRUE)

All the columns are different from each other, since they represent different kind of 
information.

In the case we face a directed graph:
* -1 if the edge is **incident** from/ leaves vertex u, 
* +1 if the edge is **incident** to/ enters vertex v.

---

### Conclusions
Best for sparse graphs