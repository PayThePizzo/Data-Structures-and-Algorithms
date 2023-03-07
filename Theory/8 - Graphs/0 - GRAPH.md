# Graph
When we talk about graphs we make a fundamental distinction between
directed and undirected graphs.

Also, when dealing with graphs we assume:
* $V$ is always finite ($|V| = n < \infty$)
* We use sets $\{ 3,4 \}$, rather than pairs $(3,4)$

---

## Directed Graph
A directed graph **G** is a pair $G = (V, E)$ where:
* **V** is vertex (node) set, which we assume is **finite** ($|V| = n$)
  * A vertex is represented by a circle
* $E \subseteq V \times V$ is edge (arch) set
  * An edge is a binary relation on V and is represented by an arrow
  * Self-loops are allowed
  * $|E| \in \[ 0,n^{2} \]$

![directed graph ex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/directedgex.png?raw=TRUE)

At high level, a graph is a binary relation between a certain number of objects (vertices).
Furthermore, a binary relation on a certain set A, is the **sub-set of the cartesian product** of that same set A.
* $E \subseteq V \times V$

This means the maximum number of edges can be found when $E \subseteq V \times V = V^{2}$. 
If we say that $|V| = n$, then $|E| = n^{2}$

---

## Undirected Graph
A directed graph **G** is a pair $G=(V, E)$ where
* **V** is vertex (node) set, which we assume is **finite** ($|V| = n$)
* **E** is edge (arch) set, which consists of **unordered pairs of vertices**
  * An edge between $(u,v) \in E \leftrightarrow (v,u) \in E$
    * It is like there is a symmetric relation between the vertices $u$ and $v$
    * If this was a directed graph, there must be one arrow that goes $u \rightarrow v$ and one $u \leftarrow v$
  * An edge is a set ${u,v}$ where $v \in V$ and $u \neq v$
    * Self-loops **are not allowed**, this is why $u \neq v$
  * $|E| \in \[ 0, \frac{n^{2}-n}{2} \]$

![undirected graph ex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/undirectedgex.png?raw=TRUE)

---

Many definitions for directed and undirected graphs are the same, 
although certain terms have slightly different meanings in the two contexts

### Adjacency - Vertices' POV
Two vertices u,v **are adjacent** if there is an edge that connects them.
* The vertex v is adjacent to vertex u.

### Incidence - Edge's POV
For an edge, we would say that the edge (u,v) 
is **incident** from vertex u, and is **incident** to vertex v.

---

## Implementations
In computer science, regardless of the type of graph used,
the most common implementations to represent these data structures are:
1. Adjacency List
   1. Best for sparse graphs
2. Adjacency Matrix
   1. Best for tight/dense graphs
3. Incidence Matrix
   1. Best for sparse graphs

![Example implementation](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/eximplem.png?raw=TRUE)