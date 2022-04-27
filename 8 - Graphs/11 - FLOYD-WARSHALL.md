# Floyd-Warshall
Floyd-Warshall's algorithm solves the **Multiple-Source, Multiple-Destination** 
shortest-paths problem on a weighted, directed graph G=(V,E, w) in the general case
where there could be negative weights, but we assume that there are **no negative-weight cycles**.

So the algorithm finds all the distances for all pairs, also called all-pairs shortest-path.

We assume that:
1. Let G = (V,E, `w:E->R`)
2. Each vertex has a number like so V={1,2,...,n}.
3. We accept negative edges
4. No negative cycles 
   1. Even though the algorithm can be used to locate negative cycles

Since the algorithm performs operation in a matrix-like data structure, represent the
entry graph as a matrix. The algorithm, takes a matrix W for input and returns a matrix D
in output, which is the <mark>matrix of distances</mark>. Another version of the 
algorithm returns the function of predecessors.

---
### Introduction
With the _tools_ we have used until now, can we find a solution for this problem?
We could be design Dijkstra or a BF algorithm for all-pairs like so:

```python
Iterated_Dijkstra(G, w)
    for (u in G.V):
        Dijkstra(G, w, u); 
```

Complexity 
1) Iterated_Dijkstra_arr()
   1) Sparse: T(n) = O(n**3)
   2) Dense: T(n) = O(n**2)
2) Iterated_Dijkstra_heap()
   1) Sparse: T(n) = O(n**2 log(n))
   2) Dense: T(n) = O(n**3 log(n))
3) Iterated_BF()
   1) Sparse: T(n) = O(n**3)
   2) Dense: T(n) = O(n**4)

But can we improve this?

---

## Data Structures
As stated before, the algorithm performs operation in a matrix-like data structure, 
represent the entry graph as a matrix.

The matrix, <mark>W = (wij) ∈ R(nxn)</mark>
* **0**, if `i==j`
  * Main diagonal
* **weight w(i,j)**, if `i!=j AND (i,j)∈E`
  * If there is an edge
* **+inf()**, if `i!=j AND (i,j)∉E`

---

## Algorithm

```python
FLOYD_WARSHALL(W)
    n = W.rows
    D[0] = W
    for(k=1 to n):
        D[k] = 
        for(i=1 to n):
            for(j=1 to n):
    return D[n]
```


### 1 - Complexity Demonstration

### 2 - Correctness Demonstration

---

#### Example

---

#### CPU Improvement

---

#### Problems

---

## Conclusions