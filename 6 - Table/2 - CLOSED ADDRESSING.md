# Closed Addressing
It is also known as *Open Hashing*

The main table containing the co-domain's indexes is a sequence of "buckets".
A **bucket**, as previously stated, is an index of the table and/or the result of the hashing function.

In this case a key is always stored in the **bucket** it's hashed to.
* We find an arbitrary number of keys per bucket.

Collisions are dealt with using **separate data structures**

### Implementation Techniques
1. Separate chaining using linked lists 
2. Separate chaining using dynamic arrays 
3. Using self-balancing binary search trees

We will deal with the first one.

### Separate chaining using linked lists

Resolving the collisions by inserting all the elements mapped on the same cell,
into a linked-list.
* The cell j contains a pointer to the head of the list (containing all the elements mapped to j)
* If there are no elements mapped to *j*, then j contains NULL

![Closed Addressing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/ClosedAddressing.png?raw=TRUE)

What kind of list is best for the operations we need to perform? 

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

### Chained Hash Search

```python
chain_hash_search(T, k)
    search for an element with key k in list T[h(k)]
```
**Final Time Complexity**: T(n) = O(T[h(k)].length)
* It is proportional to the length of the list in the cell h(k)

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
No theoretical maximum load factor.

Performance degrades as load factor grows.

---

## Conclusion

Pros:
* Easier removal (no need for deleted markings)
* Typically performs better with high load factor. 
* No issues with clustering.

Cons: