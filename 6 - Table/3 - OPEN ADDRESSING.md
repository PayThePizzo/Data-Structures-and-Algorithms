# Open Addressing
It is also known as *Close Hashing*

Collisions are dealt with by <mark>searching for another empty bucket within the hash table array itself.</mark> 
There is no help from external data structures.
* There is, at most, one key per bucket.
* If the bucket is empty, it contains NULL.

![Open Addressing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/OpenAddressing.png?raw=TRUE)

### Implementation Techniques
1. Linear Probing 
2. Quadratic Probing 
3. Double hashing 
4. Hopscotch hashing 
5. Robin Hood hashing 
6. Cuckoo hashing 
7. 2-Choice hashing

---
## Load Factor

Theoretical maximum load factor of 1.

The size of the hash table array must always be at least as large as the 
number of keys in the hash table.

---
## Operations

### Search
1. <mark>Inspection</mark>: compute `h(k)` and check its content.
2. There are three cases now:
   1. CASE 1: If the cells **contains k**, the search succeeded. 
      1. We stop here.
   2. CASE 2: Else if the cell **contains NULL** and the search failed. 
      1. We stop here.
   3. CASE 3: Else if the cell **contains a key different from k**
      1. We compute another cell's index, based on k and the order of inspection (0, 1, 2,...m-1).

We keep inspecting until we happen to be in the first two cases, or we already 
scanned the whole table.

Now we can se the hash function, not only depends on the key but also on the number of 
inspections.

---

## Conclusion

Pros:
* No size overhead apart from the hash table array. 
* Better memory locality and cache performance. 
All elements laid out linearly in memory. 
* Performs better than closed addressing when the number of keys is known in 
advance and the churn is low.

Cons: