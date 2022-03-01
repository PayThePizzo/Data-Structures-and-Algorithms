# Hash Tables
consider a piece of software that needs a dynamic set which supports 3 operations: insert, delete and search.
Each element of the set has a unique key, the latter belonging to the universe set U = {0,1,2,...,*w*-1}, with *w* not too big.

for this we *could* use direct address tables

## Direct Address Tables
### Operations
```python
  direct_address_search(Array T, Key k):
    return T[k]
  direct_address_insert(Array T, Key k):
    T[x.key] = k
  direct_address_delete(Array T, Key k):
    T[x.key] = NIL
```

### pros and cons
**Pros:** all operations have constant time complexity

**Cons:**
* the space complexity is proportional to *w* and not the number *n* of keys
* keys **must** be integers in [0, *w*-1]

Clearly, this is space-inefficient. However, when the set of keys K is much smaller than U, we can use *hash tables*.

