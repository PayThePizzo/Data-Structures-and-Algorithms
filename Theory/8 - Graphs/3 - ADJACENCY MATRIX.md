# Adjacency Matrix
For this implementation we use a $|V| \times |V| = n \times n$ **matrix** $A_{G} = a_{i,j}$, where:

```math
a_{i,j} = 
\left\{\begin{matrix}
0 & (i,j) \notin E & \text{ No edge between i and j} \\
1 & (i,j) \in E & \text{Edge between i and j} \\
\end{matrix}\right.
```

Example for directed and undirected graphs:

![adjmat](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/adjmat.png?raw=TRUE)

As we can see, for undirected graphs:
* $a_{i,j} = 0$ when $i = j$ 
  * Since self-loops are absent, the main diagonal is filled with 0
* $A^{T} = A$, the matrix is symmetric 
  * Because edges do not have a direction. 
* $a_{i,j} = a_{j,i} \forall i,j = 1,2, \ldots, n$.
* $deg(a_{i,j}) = \sum_{j=1, \ldots, n}a_{i,j}$
  * The degree of a vertex is given by the sum of the i-th row

Example for weighted graphs:

![wadjmat](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/wadjmat.png?raw=TRUE)

---

### Matrix Multiplication
Given two matrices $A = n \times m$ and $B = m \times k$, $A \times B = C = n \times k$ since $m = m$

$$c_{i,j} = \sum_{l=1}^{m}a_{i,l} \cdot b_{l,j}$$

with $i = 1, \ldots, n$ and $j = 1, \ldots, k$ 

---

## Matrix manipulation and graph properties - Undirected Graphs
Let G be an undirected graph $G=(V,E)$, let's consider its Adjacency Matrix $A$ and see if we can find 
any properties 

### $A^{2} = A \times A$
We can do $A \times A$ which is product of two matrices.

$$$$

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
  
### $A^{k}$
1. ∀i = 1 to n, with i!=j: <mark>a(i,j)∈(A^k)</mark> is the count of path of length **k**, between i and j.

---

## Matrix manipulation and graph properties - Directed Graphs

### $A^{2}$
The elements represent

### $A^{k}$
The elements represent

---

### Conclusions
We may prefer an adjacency-matrix representation, when the graph is dense or when we need to be able to tell quickly
if there is an edge connecting two given vertices

Pros: 
* Works best with dense graphs
* Verifying adjacency, regardless of the graph's density, takes $T(n) = \mathcal{O}(1)$ 

Cons:
* May occupy more space if the graph is sparse, as it will always require $S(n) = \mathcal{O}(n^{2})$