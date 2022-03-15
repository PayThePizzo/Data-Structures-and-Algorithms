# Open Addressing
It is also known as *Close Hashing*

Collisions are dealt with by searching for another empty buckets within the hash table array itself.

At most one key per bucket.

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

The size of the hash table array must always be at least as large as the number of keys in the hash table.

---

## Conclusion

Pros:
* No size overhead apart from the hash table array. 
* Better memory locality and cache performance. 
All elements laid out linearly in memory. 
* Performs better than closed addressing when the number of keys is known in 
advance and the churn is low.

Cons: