# Closed Addressing
It is also known as *Open Hashing*

Collisions are dealt with using **separate data structures**

The main table containing the co-domain's indexes is a sequence of "buckets".
A **bucket**, as previously stated, is an index of the table and/or the result of the hashing function.

In this case a key is always stored in the **bucket** it's hashed to.
* We find an arbitrary number of keys per bucket.

### Implementation Techniques
1. Separate chaining using linked lists 
2. Separate chaining using dynamic arrays 
3. Using self-balancing binary search trees

We will deal with the first one.

---

## Separate chaining using linked lists

Resolving the collisions by inserting all the elements mapped on the same cell,
into a linked-list.
* The cell j contains a pointer to the head of the list (containing all the elements mapped to j)
* If there are no elements mapped to *j*, then j contains NULL

![Closed Addressing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/ClosedAddressing.png?raw=TRUE)

What kind of list is best for the operations we need to perform? 

### Load Factor
With this implementation we can think of the load factor is the mean number of elements 
saved inside a certain list.

With SUHA: nj as T[j].length
* T is the table
* j is the list index

The average value of nj is `sum(n0 to nm-1)/m` = `n/m` = alpha

---

## Operations

### Chained Hash Insert

```python
chained_hash_insert(T, x)
    insert x at the head of list T[h(x.key)];
```
**Final Time Complexity**: T(n) = O(1)
* Hashing Function being constant 
* ki, the element to insert, is not present in the list

If we need to verify whether an element with key k == x.key, the cost would grow similar to a search.

If the keys of the elements are ordered, it's efficient to insert the item by maintaining the order when the 
key is comparable either numerically or lexically, thus resulting in faster termination of insertions and 
unsuccessful searches.

---

### Chained Hash Search

```python
chain_hash_search(T, k)
    search for an element with key k in list T[h(k)]
```
**Final Time Complexity**: T(n) = O(T[h(k)].length) = O(n)
* It is proportional to the length of the list in the cell h(k)
  * Worst case is when all keys are mapped to the same cell
* Average case (given that [SUHA](https://en.wikipedia.org/wiki/SUHA_(computer_science))) depends on
the length n(h(k)) of the list T[h(k)]

---

### Chain Hash Delete 
We have a pointer x to the element that we want to delete.

```python
chain_hash_delete(T, x)
    delete x from the list T[h(x.key)]
```
**Final Time Complexity**: T(n) = O(1)
* Only if using, double-linked-list
* If we are using normal lists, T(n) grows since we need to find the predecessor of x in T[h(x.key)]

---

## Load Factor

### Theorem - Average Case [Unsuccessful Research]
In a Hash Table, where the collisions are solved by chaining, an unsuccessful search
requires:
* T(n) = Θ(1 + alpha) = Θ(1 + n/m) (under SUHA)

### Theorem - Average Case [Successful Research]
In a Hash Table, where the collisions are solved by chaining, a successful search
requires:
* T(n) = Θ(1 + alpha) = Θ(1 + n/m) (under SUHA)

Conclusion
If n = O(m): alpha = n/m = O(m)/n = Θ(1)
* All operations, on average, have T(n) = Θ(1)

---

## Conclusion

Pros:
* Easier removal (no need for deleted markings)
* Typically performs better with high load factor. 
* No issues with clustering.

Cons: