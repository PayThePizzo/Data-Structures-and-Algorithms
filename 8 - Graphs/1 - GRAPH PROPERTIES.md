# Graph Properties and Definitions 
Here we regroup some definitions which are fundamental to get started on graph theory.

---

## Let's consider Edges

### Dense/Tight Graph
Simply put, a **dense/tight** graph are those for which |E| is close to |V|^2.

### Sparse Graph
Simply put, a **sparse** graph are those for which |E| is much less 
than |V|^2 (usually close to |V|).

TBC...

---

## Let's consider Vertices

### Degree of a graph

TBC...

---

## Subgraph
A subgraph H is a pair composed of a **subset of vertices** and a **subset of edges**

A subgraph G' = (V', E') is a subgraph of G = (V,E) if:
* V' ⊆ V
* E' **⊆** E ⋂ V' x V'
  * Not all edges

## Induced Subgraph
A subgraph induced by a subset V'⊆ V, <mark>G[V']</mark>, is a subgraph G' = (V', E') such that:
* V' ⊆ V
* E' **=** E ⋂ V' x V'
  * All the edges from the subset

---

## Path
Let:
* G = (V,E) 
* Two vertices u,v ∈ V

A <mark>path is a sequence of vertices `<x0, x1, ..., xq>`</mark> where
1. x0 = u
2. xq = v
3. (x(i-1), x(i)) ∈ E, ∀ i = 1, ..., q.
   1. They all must be connected by arches
   
Here we find an example: 

![ex path](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/expath.png?raw=TRUE)

### Simple Path
A simple path is a path in a graph which **does not have repeating vertices**.

### Non-Simple Path
A simple path is a path in a graph which **has repeating vertices**.

This means that given two vertices we can find multiple ways to go from the first to another.

### Unique Path
A unique path is path in which **there is only one way to get to a vertex from another**.

### Reachability
Reachability refers to the ability **to get from one vertex to another within a graph**.
* We say v is reachable from u, if there exists a path from u to v.

---

## Connectivity 
When we talk about connectivity and graphs we use the topological point of view.

### Connected Graph
A graph G=(V,E) is said to be connected i.f.f. there exists at least one path from u to v.

### Disconnected Graph
A graph that is not connected is said to be disconnected.

![ex disc path](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exdiscpath.png?raw=TRUE)

### Connected Components - CC
A C.C. is a subset of vertices V'⊆ V, for which some properties stand true:
1. G[V'] is connected
   1. If we take one component, the subgraph induced by the component is **connected**
2. V' is **not strictly contained** in a connected subset of V.
   1. Each component is **maximal**, is not contained in any larger subgraph, that also is connected.

Observation: The C.C. of a graph, are a partition of V.

---

## Density
For a graph, the **density** is a real number ∈ [0,1] given by the function `δ(G) = |E|/max(E)`, with max(E) as the maximum number
of edges possibly existing for that particular graph. Let n = |V|, m = |E|

There are two main cases to distinguish in order to find max(E):
1. G is an **undirected graph**
   1. δ(G) = m/binom(n,2) = <mark>`(2m)/(n(n-1))`</mark>
2. G is a **directed graph**
   1. δ(G) = <mark>`m/n^2`</mark>

### Empty Graph
An empty graph is a graph G=(V,E), where E = ∅
* There can be vertices but **no edges**
* The density is 0

### Complete Graph
An empty graph is a graph G=(V,E), where E = V x V
* E contains **all the possible edges** between the vertices in V.
* It is trivially a connected graph. Although the opposite is not true. 
* The density is 1

Notation: a complete graph on **n vertices** is <mark>K(n)</mark>

---

## Cyclicality
Cyclicality refers to the presence of a cycle in a graph.

### Cyclic Graph
A cyclic graph is a graph containing at least one graph cycle.
In other words, some number of vertices connected in a closed chain. 
* The cycle graph with n vertices is called Cn. 
* The number of vertices in Cn equals the number of edges
* Every vertex has degree 2
  * That is, every vertex has exactly two edges incident with it.

When it comes to directed graphs, there must be at least three vertices.

### Acyclic Graph
A graph that is not cyclic is said to be acyclic. 

### Unicyclic Graph
A cyclic graph possessing exactly one (undirected, simple) cycle is called a unicyclic graph.

---

## Bipartite Graph
A graph G=(V,E) is bipartite if
* V = V(L) U V(R), V(L) ∩ V(R) = ∅
  * Dividing V in two subsets V-left and V-right, which have no common vertex.
* G[V(L)], G[V(R)] are empty
  * The only edges present leave one vertex of a subset, and enters another vertex of the opposite vertex.
  * No edges between vertices of the same subset.