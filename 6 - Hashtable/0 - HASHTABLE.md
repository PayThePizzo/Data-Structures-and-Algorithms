# Hash Tables
A Hash-Table is a data structure which optimizes the concept of dictionaries.
In fact, it is implemented in a way such that T(n) for searches are on average O(1) and
O(n) in the worst case.

A Hash Table is a direct-access dictionary-like table.
1. The keys go from 0 to ω
2. 

Many applications need a dynamic set which supports 3 fundamental operations:
* Insert
* Delete
* Search.

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

