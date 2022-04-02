# Graph Properties and Definitions pt2
Here we regroup some definitions which are fundamental to get started on graph theory.

--- 

## Let's consider Vertices

### Neighborhood
We can also consider it as the count of direct neighbors of the vertex u, 
as the count of vertex that can be directly reached with one edge from u.

Formally, given u ∈ V
* N(u)={v∈V | (u,v) ∈ E}

### Degree of vertex - Undirected graphs
Given an undirected graph G=(V,E), if we consider one of its vertices u ∈ V,
the number of edges incident to/enter u is the degree of that vertex.
* deg(u) = |N(u)|, with **deg(u) ∈ [0,n-1]**
  * If the vertex has a degree of 0, then it is an isolated vertex.
  * Since there are no self-loops the maximum deg(u) is n-1.

It is not possible to construct an undirected graph where all the vertices' degrees are 
distinct.

### Out-Degree of vertex - Directed graphs

### In-Degree of vertex - Directed graphs

---

## Handshake Lemma
Let G be an undirected graph G=(V,E), with n=|V| and m=|E|
* `sum(deg(u))` with u∈V `sum(deg(u))= 2m`
  * We always obtain an **even** number for a sum of every degree
  * Also, it is two times the number of edges
* `m = 1/2 * sum(deg(u))`

Why is this true?