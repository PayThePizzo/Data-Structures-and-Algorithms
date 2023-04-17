# Greedy Clique
The Maximum Clique is an untreatable problem. For let's just see whether a greedy strategy works with 
this kind of problem. Let's design an algorithm!

```python
Greedy_Clique(Graph G):
    # sort vertices by some criteria
    C = {} #empty set
    for Vertex v in G.V extracted by Criteria:
        if(C U {v} IS_CLIQUE()):
            C = C U {v}
    return C
```

We have three problems here:
* How to order $G.V$ ?
    * We could order by the vertices' degree (Highest to lowest)
    * A large clique, the degree of all vertices inside the clique will be at least
      `>=` than the cardinality of the clique plus some other element.
* How to tell if a union $C \cup \lbrace U \rbrace$ is a clique*
    * `IS_A_CLIQUE(C, u) -> BOOL` if $C \cup \lbrace U \rbrace$ is a clique, it returns `TRUE`
    *  If every vertex $u$ is adjacent to all the other vertices in $C$, then $C$ is a clique.

```python
IS_CLIQUE(Clique C, Vertex u):
    for each Vertex v in C.V:
        if (u,v)∉ C.E:
            return False;
    return True;
```

The resulting operation looks like:

```python
IS_CLIQUE(Clique C, Vertex u) -> Bool:
    # Theta(n)
    for each Vertex v in C.V:
        #O(1) with adj matrix
        if (u,v)∉ C.E:
            return False;
    return True;

Greedy_Clique(Graph G):
    # O(n log(n))
    G.V.sort(v.degree, DESC); #sort by descending degree order
    C = {}; #empty set
    # Theta(n)
    for Vertex v in G.V :
        # O(n)
        if (IS_CLIQUE(C, u)):
            C.add(v);
    return C;
```
**Final Time Complexity**: $T(n) = \mathcal{O}(n^{2}) = \mathcal{O}(n \cdot log(n) + n^{2})$

### Complexity Demonstration
1) Sorting : at least $\mathcal{O}(n \cdot log(n))$
2) For each: $\Theta(n)$
    1) `IS_A_CLIQUE()`: $\mathcal{O}(n)$

### Correctness Demonstration - This algorithm fails to return a maximum clique!
If a graph has a maximum clique, and some vertices out of that particular clique
having a high degree, this could undermine the correctness of our algorithm.

![failgreedy](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/failgreedy.png?raw=TRUE)

It always returns a maximal clique **but not always a maximum clique**!

#### Focus on sorting
Sorting is crucial to get results with these kinds of algorithms. So naturally we could
argue we chose a bad way to sort the vertices.

We should focus on those vertices which form the highest count of triangles inside the Graph they
are in. They can also be considered as being part of many 3-vertices-cliques or 3-vertices-loop.
Vertices.

Simply put, we should sort the vertices by descending order of the count of incident 3-vertices-clique
to a particular vertex

![threecliquev](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/threecliquev.png?raw=TRUE)

But we still have cases where the algorithm will fail.

![failthreec](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/failthreec.png?raw=TRUE)

We could still try many things, but in the end we must admit that no greedy algorithm 
can be efficient. The problem is indeed, an **NP-complete problem**.





