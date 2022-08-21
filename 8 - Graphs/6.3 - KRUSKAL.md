# Kruskal
This greedy algorithm uses a set A, which is initially empty. 
It selects an edge, and adds it to A as long as there are no cycles.
* The order for edge selection is based on the weight of the edges (from the minimum weight).

At the beginning it may look like the growing data structure, looks like a forest
and eventually becomes a tree.

## The algorithm

```python
MST_KRUSKAL(Graph G, Function w)
    A = ∅
    for (Vertex v in G.V):
        make_set(v);    #initialize the sets
    sort(G.E)       #sorts non-decreasing order by w(u,v)
    for (each Edge (u,v) in G.E):   #extracts non-decreasing order by w(u,v)
        if(find_set(u) != find_set(v)): #if it does not create a cycle
            union(u,v);
            A = A U {(u,v)};
    return A;
```
**Final Time Complexity**: T(n) =  O(m*log(m))

### 1 - Complexity Demonstration
Given a connected graph G=(V,E) where 
* n = |V|
* m = |E|
* m >= n-1

1. First cycle = O(n)
2. Sorting: O(m*log(m))
   1. We cannot do better than this, since we are sorting edges
3. Second cycle and operations = O(m * log(m))
   1. FIND_SET() and UNION() both: O(log(m))
   2. Implemented through trees

In total T(n) = O(n + m * log(m) + m * log(m)) =  O(m*log(n))
* n is dominated by m, as we know by hypothesis

#### CPU improvements
The following improvements, change a bit the complexity from a CPU p.o.v but does not impact asymptotically 
the complexity

1. **A** could be a minimum weight edge, we save a step.
2. In the second cycle we could stop when we find an MST.
   1. Stop when |A| = n-1
   2. It is hard to realize.

### 2 - Correctness Demonstration
It is trivially true by the fundamental theorem of MST, because Kruskal's algorithm is a direct
consequence of the [MST Theorem](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/8%20-%20Graphs/6.1%20-%20MST.md#fundamental-theorem-of-mst). So if your professor asks you to demonstrate the correctness
of Kruskal, just demonstrate the correctness of this theorem

Thanks to the _Corollary 23.2_ we know that:
1. A, initially empty, is contained in some MST, trivially.
2. For each iteration, the **cut is represented by the extraction of a safe light edge (u,v)**, which is added to A.
  * Edges are sorted and extracted in non-decreasing order, the lightest first.
  * `find_set(u) != find_set(v)` ensures (u,v) is safe and does not create a cycle.
3. **A becomes an MST and G(A) becomes a forest by the end of the algorithm**.
   * UNION(u,v) creates CCs by uniting different sets of vertices (respecting the conditions), and A includes the edge connecting them.
   * G(A) is acyclic graph and its CCs are trees (undirected, connected and acyclic graphs), trivially.

--- 

Example:

![ex kruskal](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exkruskal.png?raw=TRUE)

![ex kruskal 2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exkruskal2.png?raw=TRUE)

