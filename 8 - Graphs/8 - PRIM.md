# Prim

#### First difference 
In Kruskal's algorithm, the beginning it may look like the growing data structure, 
looks like a forest and eventually becomes a tree. Here, instead, we **start from a tree with a single
vertex**, the root of the final tree. Consequently, we start adding edges to the tree.
* The invariant is, the structure is **always a tree**.

#### Second difference
While in Kruskal we find a structure A, containing the edges of our MST, in Prim there is no explicit
structure since we consider a **structure of predecessors** pointing to their fathers.

![struct prim](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exstructprim.png?raw=TRUE)

#### Third difference
The resulting tree has a particular vertex, the root. So it is a 
**rooted tree**.
* This is why we have a vertex in input.
  * Changing vertex, changes the ST that we can find.
  
#### Fourth Difference
∀u∈V[G], Prim keeps to field up to date at every iteration for each vertex:
* key[u], for a vertex it represents the minimum weight out of all the edges **crossing 
the cut** and that are incident to that particular vertex.
    * Numeric field used in the P.Q.
    * If the vertex u has no edge that crosses the cut, key[u]=inf()
* π[u], "predecessor"
    * Pointer

Prim manages a priority queue Q⊆V[G], which utilizes the key field. Can be implemented through a binary heap.
* Contains the **vertices to select/extract**. While Kruskal extracts edges.

At every iteration, the graph is cut into two halves.
* V\Q, the set containing the already selected vertices
* Q, the set containing the rest of the vertices.

There surely are edges going from V\Q to Q. like here:

![exsetprim](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exsetprim.png?raw=TRUE)



## The algorithm


```python
MST_PRIM(Graph G, Function w, Vertex r)
    Q <- V[G]
    for each u in V[G]
        key[u] <- inf
        pi[u] <- NIL
    key[r] <- 0
    while Q is not empty do
        u <- extractMin(Q)
        for each v in adj[u]
            if v in Q and w(u,v) < key[v]
                pi[v] <- u
                key[v] <- w(u,v)
    return A = {(u, pi[u]) in E | u in V\{r}}
```
**Final Time Complexity**: T(n) = O(m * log(n))

### 1 - Complexity Demonstration



#### CPU improvements


### 2 - Correctness Demonstration