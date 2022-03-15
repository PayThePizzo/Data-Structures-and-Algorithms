# Hash Tables

A Hash-Table is a data structure which optimizes the concept of dictionaries.
In fact, it is implemented in a way such that T(n) for searches are on average O(1) and
O(n) in the worst case.

### Why the change?

Let's say there's a set *U* which contains **all** the keys, and it can be represented 
by an array from 0 to ω-1, where `ω =|U|`

Now let's consider K as the set containing the keys we want to save.
|K| **is the count of keys we really need**, which means `|K| = n < |U| = n < ω`
* We must reduce memory waste!
* We want to have a table with a space S(n) = Θ(|K|)

### How?
Instead of saving the elements with key k, into A[k], we use a function *h()* and we save the element
in the cell A[h(k)]

Hashing Function
* A hashing function is a non-invertible function <mark>*h()*: U → {0,1,...,m-1}</mark>
  * m, being the size of the hash table, usually very small compared to |U|

![Hashing Function](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/hashfun.png?raw=TRUE)

Being `n < ω` we might find some conflicts called "Collisions".
* It happens when h(k1) = h(k2), k1 != k2

### Collision Solving
1. Close Hashing - Open Addressing
2. Open Hashing - Separate Chaining/ Close Addressing

---

## Operations

Many applications need a dynamic set which supports 3 fundamental operations:
* Insert 
* Delete 
* Search








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

Clearly, this is space-inefficient. However, when the set of keys K is much smaller than U, 
we can use *hash tables*.

