# Open Addressing
It is also known as *Close Hashing*

Collisions are dealt with by <mark>searching for another empty bucket within the hash table array itself.</mark> 
There is no help from external data structures.
* There is, at most, one key per bucket.
* If the bucket is empty, it contains NULL.

The hash functions used are slightly different from the ones in the closed addressing. We face this topic
in the next section.

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
1. <mark>Probe</mark>: compute `h(k)` and check its content.
   1. When inspecting <mark> we always start from the index `i = 0`!</mark>
   2. Every key has its own path, that is why we start from 0
   3. <mark>The maximum number of inspections represents the worst time in time complexity.</mark>
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

```python
hash_search(T,K){
    int i = 0, found = 0, j; #We can set found to a boolean too

    do:
        j = h(K, i); # Compute the hash function
        if(T[j] == K):
            found = 1;
        else:
            i++;
    while(T[J] != NULL && i != m && !found); # like (found || T[j] == NULL || i == m)
   
    if(found):
        return j;
    else:
        return NULL;
```
**Final Time Complexity**: T(n) =  Θ(m)
* m being the count of the indexes

### Hash Insert

```python
hash_insert_v1(T, k)
    int i = 0, found = 0; #We can set found to a boolean too
    
    do:
        int j = h(k, i);  # Compute the hash function
        if(T[j] == NULL): 
            T[j] = k; #We can insert only if it's an empty cell
            found = 1; #Set to true/1
        else:
            i++;
    while(i != m && !found); # same as (i==m || found)
    
    if(found):
        return j;
    else:
       raise_error (“overflow hash table”);
```

* Usually, when the table is _X_% full, we need to restructure the table and re-insert all the keys
   * We change m, so the positions change
* This heavily impacts on the performances

```python
hash_insert_v2(T, k)
    int i = 0, found = 0; #We can set found to a boolean too
    
    do:
        int j = h(k, i);  # Compute the hash function
        if(T[j] == NULL || T[j] == DELETED): 
            T[j] = k; #We can insert only if it's an empty cell
            found = 1; #Set to true/1
        else:
            i++;
    while(i != m && !found); # same as (i==m || found)
    
    if(found):
        return j;
    else:
       raise_error (“overflow hash table”);
```
**Final Time Complexity**: T(n) =  Θ(m)
* m being the count of the indexes

### Delete

It is hard to delete keys from the table since if we delete a cell, it is automatically set to NULL.
This means we 

So we introduce a constant **"deleted"** that tells us if a cell used to contain a key.
* This impacts lightly the insertion
* `DELETED != NULL`

So we need to modify the insert, but the search does not need any modifications. 
However, this means the load factor is not the primary actor in the time complexity of the search, 
and closed addressing through chaining has better performances in case of many deletions.

---

## Conclusion

Pros:
* No size overhead apart from the hash table array. 
* Better memory locality and cache performance. 
All elements laid out linearly in memory. 
* Performs better than closed addressing when the number of keys is known in 
advance and the churn is low.

Cons: