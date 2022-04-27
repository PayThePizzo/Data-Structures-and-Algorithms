# Floyd-Warshall
Floyd-Warshall's Dynamic Programming algorithm solves the **Multiple-Source, Multiple-Destination** 
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

**INPUT**: The matrix, <mark>W = w(ij) ∈ R(nxn)</mark>
* **0**, if `i==j`
  * Main diagonal
* **weight w(i,j)**, if `i!=j AND (i,j)∈E`
  * If there is an edge
* **+inf()**, if `i!=j AND (i,j)∉E`

**OUTPUT**: The matrix, <mark>D = d(ij) ∈ R(nxn)</mark>
* When the algorithm stops, we expect **d(ij) = δ(i,j)**
* _D_ (ij) is a set of paths
  * _D_ (ij) = {p | p is a **simple** path between i and j}
  * δ(i,j) = min(w(p), p∈_D_ (ij))
    * We want to minimize the distance, the weight of the path 
    * But we could have, again, a path that is not simple. However, the cycle must not be
    negative, and at the same time its weight cannot be more than 0 or it would not be
    a shortest-path. If its total weight is 0 and is a cycle, by excluding the cycle
    we have found another shortest-path that is also simple.
    * So **we cannot state that shortest-paths must all be simple paths**. We can 
    state that in a set of shortest-paths there is at least one simple SP 
    * We can then, focus our attention on simple SP to avoid the presence of cycles.

---

## 2 - Correctness Demonstration

To go from W to D, we need to first add some more notions

#### 1 - Intermediate Vertices
An intermediate vertex of a simple path p=<v1, v2,...vi> is any vertex of p other than v1 or vi,
that is, any vertex in the set {v2, v3, ..., vi-1}

Ex: A path p `1 -> 2 -> 4 -> 7 -> 9`, is a path p∈_D_ (1,9).
* `2 -> 4 -> 7` is the subgraph containing the intermediate vertices

### 2 - D k-limited
For any i,j,k∈V, 
_D_ ^k(ij) = {p | p∈_D_ (ij), where the intermediate vertices are <= k}
* _D_ ^k(ij) ⊆ _D_ ^k+1(ij)
* When k=n, _D_ ^n(ij) = _D_ (ij)

So if we consider d^k(ij) = min(w(p), p∈_D_ ^k(ij))
* If k=n, then the quantity we want to compute is **δ(i,j) = d^n(ij)**
* So computing the real distance equals computing the elements of the matrix _D_

The algorithm FW starts from _D_ ^0 = W, and produces a sequence of matrices: _D_ ^1, _D_ ^2, ..., _D_ ^n
* When _D_ ^n, the final matrix represents the real-distances matrix.
* How do we compute these matrices? Given the matrix _D_ ^k-1, how do we compute _D_ ^k?
  * This equals to computing d^k(ij), given d^k-1(ij)!

#### 3 - An Elementary Set Principle
Given a set X, how do we determine the minimum element of x? 
* Let's partition X into two halves: Y, Z. 
* Now we can express min(X) = min(min(Y), min(Z))

### Demonstration
Since d^k(ij) = min(w(p), p∈_D_ ^k(ij))
* If we partition _D_ ^k(ij) into two halves and try to find the minimum, we would have the
solution!
* We can represent recursively our sets, by diving _D_ ^k(ij) into 2 parts
  * _Ď_ ^k(ij), the set of paths p(i,j) which include a particular node k,
  * _D_ ^k-1(ij), the set of paths p(i,j) which do not include that node k
* For the elementary principle we saw, d^k(ij) = min(w(p), p∈_D_ ^k(ij))
  * d^k(ij) = min{min(w(p), _Ď_ ^k(ij)), min(w(p), _D_ ^k-1(ij))}
    * min(w(p), _D_ ^k-1(ij)) = d^k-1(ij)
      * Elements of the actual matrix, which are already available.
    * min(w(p), _Ď_ ^k(ij)), can be divided into two
      * _D_ ^k-1(ik), paths that go from i to k
        * k-1, since the paths are simple!
      * _D_ ^k-1(kj), paths that go from k to j
        * k-1, since the paths are simple!
  * d^k(ij) = min{min(w(p), p∈_D_ ^k-1(ik)) + min(w(p), p∈_D_ ^k-1(kj)), min(w(p), _D_ ^k-1(ij))}
  * <mark>d^k(ij) = min{d^k-1(ik)+ d^k-1(kj), d^k-1(ij)}</mark>

Finally, d^k(ij) equals to
* w(ij), if k = 0
* min{d^k-1(ik)+ d^k-1(kj), d^k-1(ij)}, else

---

## Algorithm

```python
FLOYD_WARSHALL(W)
    n = count(W.rows);
    D^0 = W;
    for(k=1 to n): #Computes the sequence of D^k
        for(i=1 to n):
            for(j=1 to n):
                d^k(ij) = min{d^k-1(ik)+ d^k-1(kj), d^k-1(ij)};
    return D^n;
```
**Final Time Complexity**: T(n) = Θ(n**3)

### 1 - Complexity Demonstration
1) First operations are constant: O(1)
2) 3 nested for: T(n) = Θ(n**3)
   1) min() can be found in constant time: O(1)

From a spatial point of view, the algorithm generates n matrices of size n^2. 
So in total, S(n) = Θ(n^3). 

Is it necessary to keep track of all of them? We do not need them, at k-th step we just need
the previous one, maybe we just need two. However, we can do even more!
We can use just one matrix and overwrite its content of without conflicts/dirty-write.

#### Property 1
If there are no negative cycles (as for hypothesis), then for every k=1 to n: d^k(ii) = 0

#### Property 2
During the transition from D^k-1 to D^k, the row k and column k do not change.

For i,j,k∈V
* d^k(ik) = d^k-1(ik)
* d^k(kj) = d^k-1(kj)




---

#### Example

---

#### CPU Improvement

---

#### Problems

---

## Conclusions