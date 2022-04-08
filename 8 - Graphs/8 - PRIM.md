# Prim

#### First difference 
In Kruskal's algorithm, the beginning it may look like the growing data structure, 
looks like a forest and eventually becomes a tree.

Here, instead, we **start from a tree with a single
vertex**, the root of the final tree. Consequently, we start adding edges to the tree.
* The invariant is, at every moment the structure is **always a tree**.
* The resulting tree has a particular vertex, the root. So it is a **rooted tree**.
  * This is why we have a vertex in input.
  * Changing the vertex, changes the ST that we can find.

#### Second difference
While in Kruskal we find a structure A that looks like a set, containing the edges of our MST, in Prim there is no explicit
structure since we consider a **structure of predecessors** pointing to their fathers. However, we chose to use
the implementation through a priority queue.

### Implementation
Prim manages a structure V\Q and a **priority queue** Q⊆V[G], which utilizes the key field. This can be implemented through a binary heap.
* Contains the **vertices to select/extract**. While Kruskal extracts edges.

∀u∈V[G], Prim keeps a field up to date at every iteration for each vertex:
* key[u], for a vertex it represents the minimum weight out of all the edges **crossing 
the cut** and that are incident to that particular vertex.
    * Numeric field used in the P.Q.
    * If the vertex u has no edge that crosses the cut, key[u]=inf()
* π[u], "predecessor" is the vertex on the other side of the cut, the tree on the other side, connected to the light edge
    * Pointer Q -> V\Q
    * If key[u] = inf(), π[u] = NULL
    

## The algorithm
At every iteration, the graph is cut into two halves.
* V\Q, the set containing the already selected vertices
* Q, the set containing the vertices to be selected.

There surely are edges going from V\Q to Q. like here:

![exsetprim](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exsetprim.png?raw=TRUE)

In Q, every vertex u has already all the info necessary!
1. Easy to find light edge at every step, because its minimum(u.key, u∈Q)
   * extract_min()
     * Update the vertices adjacent to the selected, before extracting it
       * At the beginning we look at the vertices adjacent to the root.
     * Extracts min element from the priority queue
     * Keeps the binary heap balanced (tree-like structure)
       * Since the root is the min element, we remove the root and re-update the tree to keep it balanced and efficient
2. We perform a cut and update the data inside Q.
   * We look for every vertex adjacent to u (the vertex we just selected) 
   * If they are in Q, and the

How we start:

```python
MST_PRIM(Graph G, Function w, Vertex r)
    Q = V.G
    for(u in G.V):                  #initialization
        key[u] = inf();
        pi[u] = NULL;
    key[r] = 0;
    while (Q != ∅):                 #extraction
        u <- extract_min(Q)         
        for (v in adj[u]):     #update data structures
            if (v in Q and w(u,v)<key[v]):
                pi[v] = u
                key[v] = w(u,v)
    return A = {(u, pi[u]) in E | u in V\{r}} #return
```
**Final Time Complexity**: T(n) = <mark>**O(m * log(n))**</mark>
* |V| = n
* |E| = m

### 1 - Complexity Demonstration
1. Initialization: T(n) = **Θ(n)**
   1. For, n times
   2. is constant
2. Extraction: T(n) = O(m* log(n)) =**O(n) + O(n * log(n)) + (m * log(n))**
   1. While: T(n) = O(n)
   2. Extract_min(): T(n)= O(log(n))
   3. For: T(n) = Θ(m) = Θ(2m)
      1. deg(u1)+deg(u2)+...+ deg(un) = sum(deg(u(i)), i= 1 to n) = 2m
      2. However, this cycle is not constant. It is in function of adj[u] and we cannot have a fixed number.
   4. key[v] = w(u,v): T(n) = O(log(n))
      1. Since we are working on the key field, which is part of the priority queue and we must
      operate to keep it balanced too.
3. Return: is constant

### 2 - Correctness Demonstration
Will it end correctly? Do the loops end?
* They are all finite
  * For, trivially true
  * While, true because the Q data structure must end at some point

By Corollary 23.2, this rule adds only edges that are safe for A; therefore, when the algorithm terminates, 
the edges in A form a minimum spanning tree.
* To demonstrate this we must demonstrate the fundamental theorem

This strategy qualifies as greedy since at each step it adds to the tree an edge that contributes the 
minimum amount possible to the tree’s weight.

---

Example: 

![ex prim](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exprim.png?raw=TRUE)

---

To represent formally the iterations of the algorithm we should use a table such as:
* As many rows as the iterations
* As many columns as the main data structures (the ones that vary)
  * i.e. Q={r, a, b, c, d, e} and the set V\Q={} at the beginning
 
| #step | V\Q | a.key | a.pi | b.key | b.pi | c.key | c.pi | d.key | d.pi | r.key | r.pi |
|-------|-----|-------|------|-------|------|-------|------|-------|------|-------|------|
| 1     | {}  |       |      |       |      |       |      |       |      |       |      |
|       |     |       |      |       |      |       |      |       |      |       |      |
|       |     |       |      |       |      |       |      |       |      |       |      |
|       |     |       |      |       |      |       |      |       |      |       |      |