# Adjacency Matrix
Given that the vertices have distinct numbers as labels, for this implementation we use 
a $|V| \times |V| = n \times n$ **matrix** $A_{G} = a_{i,j}$, where:

```math
a_{i,j} = 
\left\{\begin{matrix}
0 & (i,j) \notin E & \text{ No edge between i and j} \\
1 & (i,j) \in E & \text{Edge between i and j} \\
\end{matrix}\right.
```

---

## Quick Recap - Matrix Operations

### Matrix Multiplication - Dot Product
Given two matrices
* $A = n \times m$ and,
* $B = m \times k$ 

$$\text{i.i.f } m = m \Rightarrow A \times B = C = n \times k$$

and

$$c_{i,j} = \sum_{l=1}^{m}a_{i,l} \cdot b_{l,j}, \text{ with } i = 1, \ldots, n \wedge j = 1, \ldots, k$$


---

## Undirected Graphs

Example for directed and undirected graphs:

![adjmat](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/adjmat.png?raw=TRUE)

### Properties of $A$
Let G be an undirected graph $G=(V,E)$, let's consider its Adjacency Matrix $A$ and see if we can find
any properties

For undirected graphs:
* $a_{i,j} = 0$ when $i = j$ 
  * Since self-loops are absent, the main diagonal is filled with 0
* $A^{T} = A$, the matrix is symmetric 
  * Because edges do not have a direction. 
* $a_{i,j} = a_{j,i} \forall i,j = 1,2, \ldots, n$.
  * As the matrix is symmetric
* $deg(i) = \sum_{j=1, \ldots, n} a_{i,j}$
  * The degree of a vertex is given by the sum of the i-th row

### Properties of $A^{2} = A \times A$
We can do $A \times A = A^{2}$ which is product of two matrices.

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

### 1 - Main diagonal of $A^{2}$
We notice that, the numbers on the main diagonal, $[3,2,3,2]$ represent the degrees of the vertices. More generally:

$$\forall i = 1, \ldots, n : a^{2}_{i,i} \in A^{2} = deg(i)$$

#### Demonstration
By definition of dot product:

$$a^{2}_{i,i} = \sum_{l=1}^{n} a_{i,l} \cdot a_{l,i}$$

Then 

$$a^{2}_{i,i} = \sum_{l=1}^{n} a_{i,l} \cdot a_{l,i} = deg(i)$$

By property of symmetry, since $A$ represents an undirected graph $a_{i,l} = a_{l,i}$

$$a^{2}_{i,i} = \sum_{l=1}^{n} a_{i,l}^{2} =  \sum_{l=1}^{n} a_{l,i}^{2} = deg(i)$$

While, as we stated before, the degree of a vertex $i$ is given by the **sum of the** $i$-th **row**

$$\sum_{l=1}^{n} a_{i,l} = deg(i)$$

Which means

$$a_{i,i}^{2} = \sum_{l=1}^{n} a_{i,l}^{2} = \sum_{l=1}^{n} a_{i,l} = deg(i)$$

Then, since we only have $1$ and $0$ inside $A$ the summation executes exactly the sum of the i-th row's elements.
* The graph is undirected and non-weighted!

$$a_{i,l}^{2} = a_{i,l}$$

In fact,

$$a_{i,l} = 0 \Rightarrow a_{i,l}^{2} = 0  \wedge a_{i,l} = 1 \Rightarrow a_{i,l}^{2} = 1$$

We conclude that:

$a_{i,i}^{2} = \sum_{l=1}^{n} a_{i,l} = deg(i), \forall i = 1, \ldots, n$


### 2 - Elements outside the main diagonal of $A^{2}$
Now, we consider the elements outside the main diagonal

$$\forall i,j = 1, \ldots, n \ni' i \neq j: a_{i,j}^{2} = \text{ count of paths of length 2 between i and j}$$

#### Demonstration
By definition of dot product:

$$a^{2}_{i,j} = \sum_{l=1}^{n} a_{i,l} \cdot a_{l,j}$$

By construction of $A$, $a_{i,j} = 0 \vee a_{i,j} = 1$ for undirected non-weighted graphs. Then,

$$a_{i,l} \cdot a_{l,j} \neq 0 \Leftrightarrow a_{i,l} = a_{l,j} = 1$$

By definition of $A$, this is possible only if there exist two edges 
* One going from $i$ to $l$
* One going from $l$ to $j$

$$a_{i,l} = a_{l,j} = 1 \Leftrightarrow (i,l) \in E \wedge (l,j) \in E$$

![edgeexists](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/edgeexists.png?raw=TRUE)

By definition of path, and length of path, the existence of a sequence of vertices connected through some edges,
defines a path of length equal to the number of edges. In this case, there is a path of length $2$ from $i$ to $j$

We conclude that this is true.

### 3 - Elements outside the main diagonal of $A^{k}$
This previous concept can be generalized to paths of length $k$

$$\forall i,j = 1, \ldots, n \ni' i \neq j: a_{i,j}^{k} = \text{ count of paths of length k between i and j}$$

#### Demonstration by induction
Steps:
1. Base Case: 
2. Inductive Hypothesis: True, check previous section
3. Inductive Step: Demonstration for $k \geq 1$

For $k \geq 1$

Trivially, 

$$A^{k} = A \cdot A^{k-1}$$

By definition of dot product:

$$a^{k}_{i,j} = \sum_{l=1}^{n} a_{i,l}^{1} \cdot a_{l,j}^{k-1}$$

By construction of $A$, $a_{i,l} = 0 \vee a_{i,l} = 1$ for undirected non-weighted graphs. 

By Inductive Hypothesis, the count of paths of length $k-1$ between $l$ and $j$ is given by $a_{l,j}^{k-1}$

We conclude this is true.

---

## Directed Graphs

TODO: Check SP Problems for solutions (FW)

Example for weighted graphs:

![wadjmat](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/wadjmat.png?raw=TRUE)

### Properties of $A$
Let G be an directed graph $G=(V,E)$, let's consider its Adjacency Matrix $A$ and see if we can find
any properties

For directed graphs:
* $in-deg(i) = \sum_{l=1, \ldots, n} a_{i,l}$
* $out-deg(i)= \sum_{l=1, \ldots, n} a_{l,i}$

### Properties of $A^{2} = A \times A$



### Properties of $A^{k}$

$$a_{i,j}^{k} = \sum_{l=1}^{m} a_{i,l} \cdot a_{l,j} = \text{ the count of paths of length k from i to j}$$

---

## Space

Always requires $S(n) = \Theta(n^{2})$

## Time

Access to information is immediate $T(n) = \mathcal{O}(1)$

---

### Conclusions
We may prefer an adjacency-matrix representation, when the graph is dense or when we need to be able to tell quickly
if there is an edge connecting two given vertices

| **Pros**                                          	| **Cons**                                     	|
|---------------------------------------------------	|----------------------------------------------	|
| Best for dense graphs                             	| Waste of memory in case of sparse graphs     	|
| Verifying adjacency is immediate $\mathcal{O}(n)$ 	| Space complexity is fixed to $\Theta(n^{2})$ 	|