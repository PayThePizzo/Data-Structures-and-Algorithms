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

The hashing function reduces the interval of table's indexes.

![Hashing Function](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/hashfun.png?raw=TRUE)

---

### Problem: Collisions

Being `n < ω` we might find some conflicts called "Collisions".
* It **can happen** when |U|>m, this means two different keys can be mapped to the same cell.
* It **surely** happens when |K|>m

Example: upon insertion of an element k2, h(k2) is occupied by k1. 
* h(k1) = h(k2), k1 != k2

## Collision Solving
1. Closed Addressing
2. Open Addressing

---

## Load Factor

The Load factor is a measure that decides when to increase the HashTable capacity 
to maintain the search and insert operation complexity of O(1). [1]

load-factor(alpha) = n/k
* alpha is the load factor
* n, the number of entries occupied in the hash table (i.e. the keys)
* k, the number of buckets (a.k.a. the cells)

The performance of the hash table **worsens** in relation to the load factor **as alpha approaches 1**
* In the case of Closed Addressing approach, alpha can be larger than one since we use separate datastructures

In this case we resize the hash table, in a process called "rehashing"

---

## Rehashing

Repeated insertions cause the number of entries in a hash table to grow, 
which consequently increases the load factor; 

To maintain the amortized O(1) performance of the lookup and insertion operations, a hash table is 
dynamically resized and the items of the tables are rehashed into the buckets of the new hash table, 
since the items cannot be copied over as varying table sizes results in different hash value due to 
modulo operation.

Resizing may be performed on hash tables with fewer entries compared to its size to avoid 
excessive memory usage.[2]

---

## Operations

Many applications need a dynamic set which supports 3 fundamental operations:
* Insert 
* Delete 
* Search

---

### Extra Credits
* [Prof. Alberto Montresor - Tabelle Hash](http://www.cs.unibo.it/~donat/07-hashing.pdf)
* [Prof. Massimo Franceschet - Tabelle Hash](https://www.sci.unich.it/~meo/didattica/courses/asdI/lucidi/hash.pdf)
* [Prof. Maria Rita di Berardini, Prof. Emanuela Merelli - Tabelle Hash](https://computerscience.unicam.it/merelli/algoritmi06/%5B04%5DTabelleHash.pdf)
* [2] [Wikipedia - Hash Table](https://it.wikipedia.org/wiki/Hash_table)
* [Programming Guide - Open vs Closed Addressing](https://programming.guide/hash-tables-open-vs-closed-addressing.html)
* [1] [Scaler - Load Hashing](https://www.scaler.com/topics/data-structures/load-factor-and-rehashing/)