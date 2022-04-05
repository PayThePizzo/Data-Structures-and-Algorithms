# Prim


```python
MSTP(G, w, r)
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
**Final Time Complexity**: T(n) =

### 1 - Complexity Demonstration



#### CPU improvements


### 2 - Correctness Demonstration