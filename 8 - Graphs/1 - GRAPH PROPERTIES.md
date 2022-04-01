# Graph Properties and Definitions 
Here we regroup some definitions which are fundamental to get started on graph theory.

---
## Density

### Dense/Tight Graph
Simply put, a **dense/tight** graph are those for which |E| is close to |V|^2.

### Sparse Graph
Simply put, a **sparse** graph are those for which |E| is much less 
than |V|^2 (usually close to |V|).

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
3. (x(i-1), x(i)) ∈ E, for every i = 1, ..., q.
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

## Connected Graph
For every u,v ∈ V, there exists at least one path from u to v.

## Disconnected Graph

![ex disc path](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exdiscpath.png?raw=TRUE)

