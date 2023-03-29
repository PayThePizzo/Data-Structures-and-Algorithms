# Open Addressing
It is also known as *Close Hashing*

$$n \leq m \wedge \alpha \leq 1$$

In Open Addressing Hashtables, **all elements occupy the hash table itself**. That is, each table entry 
contains either an element of the dynamic set (one key per bucket) or NIL. 

When searching for an element, we systematically examine table slots until either we find the desired
element or we have ascertained that the element is not in the table. No lists and no elements are stored outside 
the table, unlike in chaining. Thus, in open addressing, the hash table can “fill up” so that no further insertions 
can be made; one consequence is that the load factor can never exceed 1 $\alpha \leq 1$.

Of course, we could store the linked lists for chaining inside the hash table, in
the otherwise unused hash-table slots, but the advantage of open addressing is that it avoids pointers altogether. 

Instead of following pointers, we compute the sequence of slots to be examined. The extra memory freed by not
storing pointers provides the hash table with a larger number of slots for the same amount of memory, 
potentially yielding fewer collisions and faster retrieval.

---

## Properties

### Load Factor $alpha \leq 1$
Theoretical maximum load factor of 1.

The size of the hash table array must always be at least as large as the number of keys in the hash table.

### Collisions 
To sum up, collisions are dealt with by **searching for another empty bucket** within the hash table array itself.
* There is **NO** help from external data structures.

The hash functions used are slightly different from the ones in the closed addressing, but they still respect the SUHA. 
We face this topic in the next section.

#### Hash functions


![Open Addressing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/OpenAddressing.png?raw=TRUE)

## Implementation Techniques
To perform insertion using open addressing, we successively examine, or **probe**, the hash table until we find an 
empty slot in which to put the key. The most common types of probing are:
1. **Linear Probing** 
2. **Quadratic Probing** 
3. **Double hashing** 
4. Hopscotch hashing 
5. Robin Hood hashing 
6. Cuckoo hashing 
7. 2-Choice hashing

---

## Operations
We assume all the elements $x$ are made solely with the key $k$ (for simplicity).

### Search/ Inspection/ Probing
To search, inspect or probe an open addressing hashtable all mean the same: 

> Given an element $k$, a hash function $h(k)$ is computed and its result is a cell's address inside the given hashtable
> T, such that $h(k) \in T$. The content of the cell is, then, examined (usually for insertion purposes).

Since all the possible elements are in the table, the table must be as large as $n$ at most, $S(n) = \mathcal{O}(n)$. 
However, this does not mean the table is always full, nor that the elements are in some kind of order, beside the one
dictated by the hash function and the solutions of possible collisions.

For this reason when probing we **always start from** the index $i = 0$ and in the worst case we might need to examine 
the whole table, which might require $T(n) = \Theta(n)$ if there is a way to keep track of the cells previously
visited.

After computing the hash function $h(k)$ and getting to some address, we mainly face 3 cases:
1. Successful Search: If the cell $h(k)$ **contains** $k$, the search **succeeded**.
2. Unsuccessful Search: Else if the cell $h(k)$ **contains** $NIL$ and the search **failed**. 
3. Busy Cell: Else if the cell $h(k)$  **contains a key different from** $k$ 
   1. We compute another cell's index, based on $k$, the **order** of inspection $0, 1, 2,\ldots , m-1$, and the
   previously inspected cells.

We keep inspecting 
1. Until we happen to be in the first two cases, 
2. Or we have already scanned the whole table: $m$ inspections.

Now we can see the hash function, must avoid traversing the whole table for each probe operation. 
not only depends on the **key** but also on the **order of inspection**.
This is section is specified in the section [Hash Function - Open Addressing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Theory/6%20-%20Table/4%20-%20HASH%20FUNCTION.md#how-do-we-hash---open-addressing)

```python
hash_search(T,k)
    i = 0 
    found = false
    repeat: 
        j = h(k, i) # Compute the hash function
        if T[j] == k:
            found = true
        else:
            i=i+1
    until found or T[j]==NIL or i==m 
    if found:
        # Key in table
        return j
    else:
        # Key not in table
        return NIL 
```

**Final Time Complexity**: $T(n) = $ 

### Hash Insert
Now that we defined how to search, we can proceed with insertion.

```python
hash_insert_v1(T, k)
    i = 0
    found = false
    repeat:
        j = h(k, i)  # Compute the hash function
        if T[j] == NIL: 
            T[j] = k # We can insert only if it's an empty cell
            found = true #Set to true
        else:
            i=i+1
    until found or i==m
    if found:
        return j
    else:
       raise_error ("overflow hash table")
```

**Final Time Complexity**: $T(n) = \mathcal{O}(n)$
* The worst case is upon insertion of an element, when table is already full.
* Usually, when the table reaches a certain low percentage of empty cells, we need to restructure the table and 
re-insert all the keys. 
* By changing $m$, all the keys also change position and this heavily impacts the performances.

### Delete

Deletion from an open-address hash table is difficult.

#### Deletion Problem

When we delete a key from slot $i$, we cannot simply mark that slot as empty by storing $NIL$ in it. If
we did, we might be unable to retrieve any key $k$ during whose insertion we had probed slot $i$ and found it occupied.

We can solve this problem by marking the slot, storing in it the special value $DELETED$ instead of $NIL$, where $DELETED \neq NIL$.
We would then modify the procedure `hash_insert` to treat such a slot as if it were empty so that we can insert a
new key there.

We do not need to modify `hash_search`, since it will pass over $DELETED$ values while searching.
When we use the special value $DELETED$, however, search times no longer depend on the load factor $\alpha$, and for
this reason chaining is more commonly selected as a collision resolution technique when keys must be deleted.

Example: Say we want to perform these operations in order
* `hash_insert_v1(T,k=118)`
* `hash_delete(T, k=39)`
* `hash_search(T, k=118)`

with $T$ as

| index $i$ 	| key $k$  	|
|-----------	|----------	|
| $0$       	| $15$     	|
| $1$       	| $25$     	|
| $2$       	| $NIL$    	|
| $3$       	| $NIL$    	|
| $\ldots$  	| $\ldots$ 	|
| $5$       	| $NIL$    	|
| $6$       	| $NIL$    	|
| $7$       	| $39$     	|
| $\ldots$  	| $\ldots$ 	|
| $n$       	| $NIL$    	|

Would result in:
1. $h(118,0) = 2$, Collision
2. $h(118,0) = 7$, Collision
3. $h(118,0) = 3$, Empty
    1. We proceed with insertion

| index $i$ 	| key $k$  	|
|-----------	|----------	|
| $0$       	| $15$     	|
| $1$       	| $25$     	|
| $2$       	| $NIL$    	|
| $3$       	| **118**  	|
| $\ldots$  	| $\ldots$ 	|
| $5$       	| $NIL$    	|
| $6$       	| $NIL$    	|
| $7$       	| $39$     	|
| $\ldots$  	| $\ldots$ 	|
| $n$       	| $NIL$    	|

Now, we want to remove the key $k=39$

| index $i$ 	| key $k$  	|
|-----------	|----------	|
| $0$       	| $15$     	|
| $1$       	| $25$     	|
| $2$       	| $NIL$    	|
| $3$       	| **118**  	|
| $\ldots$  	| $\ldots$ 	|
| $5$       	| $NIL$    	|
| $6$       	| $NIL$    	|
| $7$       	| ~39~     	|
| $\ldots$  	| $\ldots$ 	|
| $n$       	| $NIL$    	|

And finally we look for $k=118$:
1. $h(k,0) = 2$, is not the right one
2. $h(k,1) = 7 \Rightarrow NIL$
    1. Then $k=118 \notin T$ since we used the value $NIL$ to substitute the previous one upon deletion.
    2. By construction of the algorithm this stops the search.

### Rewriting Insert

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

**Final Time Complexity**: $T(n) = \mathcal{O}(n)$

---

## Analysis of Open Addressing 

We will use the following assumptions:
1. Simple Uniform Hashing 
2. No deletions

The analysis will be done in terms of load factor $0 < alpha \leq 1$ because we only have the cells in our table. Otherwise,
we would have an overflow.

### Theorem - Unsuccessful Search
Given an open-address hash table with load factor $\alpha = n/m < 1$, the expected
number of probes in an **unsuccessful search** is at most $1/(1-\alpha)$, assuming uniform hashing

#### Demonstration

$$\alpha < 1 \Rightarrow \text{ There are some empty cells } \Rightarrow \text{ Search stops when we find one }$$

If we consider the number of inspections at each iteration:
1. First one, $1$
2. Second one, $\frac{n}{m} = \alpha$
3. Third one, $\frac{n}{m} \cdot \frac{n-1}{m-1} \leq \alpha^{2}$
   1. Where $\frac{n-1}{m-1} \leq \alpha$
4. n-th one,  $\frac{n}{m} \cdot \frac{n-1}{m-1}$

Then, we can find the total inspections as the geometric series

$1 + \alpha + \alpha^{2} + \ldots  \leq \sum_{i=0}^{\infty} \alpha^{i} stackrel{|\alpha|<1} \Rightarrow \sum_{i=0}^{\infty} \alpha^{i} = \frac{1}{1-\alpha}$

#### Interpretation
If $\alpha$ is constant an unsuccessful search is executed $T_{avg}(n)= \Theta(1)$
* If the table is half full, $\alpha = 0.5 = 1/2 \Rightarrow \text{ Average Inspections } = 1/(1-(1/2)) = 2$
* If the table is $90%$ full, $\alpha = 0.9 = 9/10 \Rightarrow \text{ Average Inspections } = 1/(1-(9/10)) = 10$

#### Corollary 11.7
Inserting an element into an open-address hash table with load factor $\alpha$ requires at most $1/(1-\alpha)$ 
probes on average, assuming uniform hashing.

Demonstration: An element is inserted only if there is room in the table, and thus $\alpha < 1$. Inserting a key 
requires an unsuccessful search followed by placing the key into the first empty slot found. 
Thus, the expected number of probes is at most $1/(1-\alpha)$ as the previous theorem states.

### Theorem - Successful Search
Given an open-address hash table with load factor $\alpha = n/m < 1$, the expected
number of probes in an **unsuccessful search** is at most $\frac{1}{\alpha} \cdot ln(\frac{1}{1-\alpha})$, assuming 
uniform hashing and assuming that each key in the table is equally likely to be searched for.

#### Interpretation
If $\alpha$ is constant a successful search is executed $T_{avg}(n)= \Theta(1)$
* If the table is half full, $\alpha = 0.5 = 1/2 \Rightarrow \text{ Average Inspections } \leq 1.387$
* If the table is $90%$ full, $\alpha = 0.9 = 9/10 \Rightarrow \text{ Average Inspections } \leq 2.559$

---

## Restructuring

When $\alpha > 0.5$ we double its size, and proceed with inserting the currently existing elements into the new table. 
This may call for:
* Rehashing of all these key values
* Transferring all the records

This is because the average time for operations can become quite substantial.

Subsequent dictionary operations will be more efficient and can more than make up for the overhead in creating 
the larger table. Usually it doubles the size. [1]

---

### Conclusions

Pros:
* No size overhead apart from the hash table array. 
* Better memory locality and cache performance. All elements laid out linearly in memory. 
* Performs better than closed addressing when the number of keys is known in 
advance and the churn is low.

Cons:
* Chaining results better performing than this implementation ($\alpha > 2$ )

--- 
### Extra Credits
* [1] [Restructuring](https://gtl.csa.iisc.ac.in/dsa/node51.html)