

```python
MSTK(G, w)
    A <- {}
    for each v in V[G]
        MAKE-SET(v)
        #ordina gli archi di E per w non decrescente
    for each (u,v) in E #in ordine
        if FIND-SET(u) != FIND-SET(v) then
            A <- A U {(u,v)}
            UNION(u,v)
    return A
```