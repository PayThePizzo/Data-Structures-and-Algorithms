# Hash Tables

A Hash-Table is a data structure which optimizes the concept of dictionaries.
In fact, it is implemented in a way such that $T(n)$ for searches are on average $\mathcal{O}(1)$ and
$\mathcal{O}(n)$ in the worst case.

---

## The problem of Direct Addressing

Let's say we need have:
1. A dynamic set with the operations `Insert`, `Delete` and `Search`
2. Where every element of the set has a key $k$ from a universe $U = \lbrace 0, 1, \ldots, \omega-1 \rbrace$
3. And every key $k$ is distinct, but their value can appear multiple times.

We could use an array $T$, whose indices go from $0 \ldots \omega-1$, where $\omega =|U|$
* Every cell corresponds to a key in $U$
* If there is an element $x$ with $x.key = k$
  * Then, $T[k]$ contains a pointer to $x$
  * Else, $T[k] = NIL$

![diraddtable](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/diraddtable.png?raw=TRUE)


The operations would look like 

```python
direct_add_search(Array T[], Key k):
    return T[k]
    
direct_add_insert(Array T[], Elem x):   
    T[x.key] = x
    
direct_add_delete(Array T[], Elem x):
    T[x.key] = NIL
```

**Final Time Complexity**: $T(n) = \Theta(1)$
* For all procedures 

**Final Space Complexity**: $S(n) = \Theta(\omega)$
* The space used is proportional to $\omega$ and not the actual elements needed

We must reduce memory waste! We want to have a table with a space $S(n) = \Theta(|K|)$


### How?

When the count of keys needed is significantly smaller than the universe $U$, we use hash tables
* $S(n) = \Theta(|K|)$
* $T_{avg}(search) = \Theta(1)$

Now let's consider $K$ as the set containing the keys we want to save.
* $|K| = n$ **is the count of keys we really need**, which means $|K| < |U| \Rightarrow n < \omega$

Instead of saving the elements with key $k$, into $A[k]$, we use a function $h()$ and we save the element
in the cell $A[h(k)]$

![hashtablemap2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/hashtablemap2.png?raw=TRUE)

---

## Hashing Function 

> A hashing function is a non-invertible function $h() : U \rightarrow \lbrace 0,1, \ldots ,m-1 \rbrace$ 
> where $m$ is size of the hash table, usually very small compared to $|U|$

The hashing function reduces the interval of table's indexes.

![Hashing Function](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/hashfun.png?raw=TRUE)


### Problem: Collisions
Being $n < \omega$ we might find some conflicts called "Collisions".

> Collisions are conflicts which happen upon insertion of an element $x$ in a cell that is not empty.

Example: upon insertion of an element $k_{2}$, $h(k_{2})$ is occupied by $k_{1}$.
* $h(k_{1}) = h(k_{2}) \wedge k_{1} \neq k_{2}$


Generally, if two different keys can be mapped to the same cell, collisions are inevitable.

When do they happen?
* It **can happen** when $|U| > m$
* It **surely** happens when $|K|>m$


### Collision Solutions
1. Closed addressing or _lists of collisions_
2. Open addressing

---

## Load Factor $\alpha$

The Load factor is a measure that decides when to increase the HashTable capacity 
to maintain the search and insert operation complexity of $\mathcal{O}(1)$. [1]

```math
\alpha = \frac{n}{k}, \text{ with }
\left\{\begin{matrix}
n & \text{ Count of keys or entries occupied in the hashtable} \\
k & \text{ Count of cells or buckets} \\
\end{matrix}\right.
```

The performance of the hash table **worsens** in relation to the load factor **as alpha approaches 1** $\alpha \approx 1$
* In the case of Closed Addressing approach, alpha can be larger than one since we use separate datastructures

In this case we resize the hash table, in a process called "rehashing"

---

## Rehashing

Repeated insertions cause the number of entries in a hash table to grow, which consequently increases the load factor; 

To maintain the amortized $\mathcal{O}(1)$ performance of the lookup and insertion operations, a hash table is 
dynamically resized and the items of the tables are rehashed into the buckets of the new hash table, 
since the items cannot be copied over as varying table sizes results in different hash value due to 
modulo operation.

Resizing may be performed on hash tables with fewer entries compared to its size to avoid 
excessive memory usage.[2]

---

## Operations

Many applications need a dynamic set which supports 3 fundamental operations:
* `Insert`
* `Delete` 
* `Search`

---

### Extra Credits
* [Prof. Alberto Montresor - Tabelle Hash](http://www.cs.unibo.it/~donat/07-hashing.pdf)
* [Prof. Massimo Franceschet - Tabelle Hash](https://www.sci.unich.it/~meo/didattica/courses/asdI/lucidi/hash.pdf)
* [Prof. Maria Rita di Berardini, Prof. Emanuela Merelli - Tabelle Hash](https://computerscience.unicam.it/merelli/algoritmi06/%5B04%5DTabelleHash.pdf)
* [2] [Wikipedia - Hash Table](https://it.wikipedia.org/wiki/Hash_table)
* [Programming Guide - Open vs Closed Addressing](https://programming.guide/hash-tables-open-vs-closed-addressing.html)
* [1] [Scaler - Load Hashing](https://www.scaler.com/topics/data-structures/load-factor-and-rehashing/)