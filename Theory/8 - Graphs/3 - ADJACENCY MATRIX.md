# Adjacency Matrix
For this implementation we use a **matrix** $A_{G}$, with $n^{2} = |V| x |V|$ elements $a_{i,j}$

Every element a(i,j):
* 0 if between i and j there is NO edge
* 1 if between i and j there is an edge

```math
a_{i,j} = 
\left\{\begin{matrix}
0 & (i,j) \notin E & \text{ No edge between i and j} \\
1 & (i,j) \in E & \text{Edge between i and j} \\
\end{matrix}\right.
```


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

## Matrix manipulation and graph properties - Undirected
Let G be an undirected graph G=(V,E), let's consider its Adjacency Matrix A and see if we can find 
any properties 

### A x A
We can do AxA which is product of two matrices.

```python
A = [   [0,1,1,1],
        [1,0,1,0],
        [1,1,0,1],
        [1,0,1,0]]

AxA = [ [3, 1, 2, 1]
        [1, 2, 1, 2]
        [2, 1, 3, 1]
        [1, 2, 1, 2]]
```
The numbers on the main diagonal, [3,2,3,2] represent the degrees of the vertices.
* <mark>∀i = 1 to n: a(i,i)∈(AxA) = deg(i)</mark>
  * a(i,i)∈(AxA) = sum(a(i,l)*a(l,i), l= 1 to n) 
  * a(i,i)∈(AxA) = sum(a(i,l)*a(i,l), l= 1 to n), since they are symmetrical
  * a(i,i)∈(AxA) = sum(a(i,l)^2, i= 1 to n), which is similar to sum(a(i,l), i= 1 to n)
  * Since we only have 1s and 0s sum(a(i,l)^2, i= 1 to n) = sum(a(i,l), i= 1 to n)
  * a(i,i)∈(AxA) = sum(a(i,l), i= 1 to n) = deg(i)

Now, we consider the elements outside the main diagonal. 
* ∀i,j = 1 to n, with i!=j: a(i,j)∈(AxA) <mark>represents the count path of length 2, 
between the vertex i and j.</mark>
  * a(i,j)∈(AxA) = sum(a(i,l)*a(l,j), l = 1 to n), mind that the product is 1 when both are not 0.
  * This is only possible when there exist two edges a(i,l) and a(l,j) 
  
### A^k
1. ∀i = 1 to n, with i!=j: <mark>a(i,j)∈(A^k)</mark> is the count of path of length **k**, between i and j.

---

### Conclusions

Pros: 
* Works best with dense graphs
* Verifying adjacency, regardless of the graph's density, takes T(n) = O(1)

Cons:
* May occupy more space if the graph is sparse 