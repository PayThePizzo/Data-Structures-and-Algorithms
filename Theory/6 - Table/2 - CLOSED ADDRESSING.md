# Closed Addressing
It is also known as *Open Hashing*

Collisions are dealt with using **separate data structures**

The main table containing the co-domain's indexes is a sequence of "buckets".

> A **bucket**, as previously stated, is an index of the table and/or the result of the hashing function.

In this case a key is always stored in the **bucket** it's hashed to.
* We find an arbitrary number of keys per bucket.

## Implementation Techniques
1. Separate chaining using linked lists 
2. Separate chaining using dynamic arrays 
3. Using self-balancing binary search trees

We will deal with the first one.

---

### Let's Ask ChatGPT!

Closed addressing, also known as open hashing, is a technique used in hash tables to resolve collisions that may 
occur when two or more keys are mapped to the same index. In this technique, each slot in the hash table is actually 
a pointer to a linked list of elements that have been mapped to that particular slot.

When a new key is to be inserted into the hash table, its hash value is first calculated, and then the linked list 
at the corresponding slot is traversed to check if the key already exists in the table. If the key is found, its value 
is updated; otherwise, a new element is added to the linked list with the new key-value pair.

When searching for a key in the hash table, its hash value is computed and the linked list at the corresponding slot 
is traversed to check if the key exists in the table. If the key is found, its value is returned; otherwise, the search 
continues until the end of the linked list is reached.

In closed addressing, each slot in the hash table can store multiple key-value pairs, which makes it more 
memory-efficient than open addressing, where each slot can only store one key-value pair. However, this efficiency 
comes at the cost of increased complexity in the insertion, deletion, and search operations, as the linked lists 
must be traversed to find the correct location for the key-value pair.

---

## Separate chaining using double linked lists

Resolving the collisions by inserting all the elements mapped on the same cell, into a linked-list.
* The cell $j$ contains a pointer to the head of the list (containing all the elements mapped to $j$)
* If there are no elements mapped to $j$, then $j$ contains $NIL$

![Chaining Collisions](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/chainingcollisions.png?raw=TRUE)


---

## Operations

### Chained Hash Insert

```python
chained_hash_insert(T, x)
    Insert x at the head of list T[h(x.key)];
```

**Final Time Complexity**: 

```math
T(n) =
\left\{\begin{matrix}
\mathcal{O}(1) & \text{ If } T_{h()} = \Theta(1) \wedge x \notin \text{ list at } T[h(x.key)] \\
\mathcal{O}(T_{search}) & \text{ Else, } \\
\end{matrix}\right.
```

This means that we can achieve the best result if:
* The time to compute the result of the hashing function is constant 
* The element to insert, is not present in the list (elements with distinct keys)

Else, we need to verify whether an element with key $k = x.key$, the cost would grow similar to a `search`.

If the keys of the elements are ordered, it's efficient to insert the item by maintaining the order when the 
key is comparable either numerically or lexically, thus resulting in faster termination of insertions and 
unsuccessful searches.

---

### Chained Hash Search

```python
chain_hash_search(T, k)
    search for an element with key k in list T[h(k)]
```

**Final Time Complexity**: $T(n) = \Theta(T[h(k)].length) = \Theta(n)$
* It is **proportional to the length of the list in the cell** $T[h(k)]$
  * So the worst case is when all keys are **mapped to the same cell**
* Average case (given that [SUHA](https://en.wikipedia.org/wiki/SUHA_(computer_science))) depends on
the length of the list $T[h(k)]$

---

### Chain Hash Delete 
We have a pointer x to the element that we want to delete.

```python
chain_hash_delete(T, x)
    delete x from the list T[h(x.key)]
```
**Final Time Complexity**: $T(n) = \mathcal{O}(1)$
* Only if using, double-linked-list
* If we are using linked-lists, T(n) grows since we need to find the predecessor of $x$ in $T[h(x.key)]$


---

With SUHA: $nj$ as $T[j].length$
* $T$ is the table
* $j$ is the list index

The average value of nj is `sum(n0 to nm-1)/m` = `n/m` = alpha


## Analysis of hashing with chaining 
Let $T$ be a closed addressing hashtable with $m$ cells, and $n$ stored elements. With this implementation we can 
think of the load factor $\alpha$ as the average number of elements saved inside a certain list. If $\alpha >1$ the keys
are stored in auxiliary data structures.

### 1 - Worst Case
The worst case happens when **all the keys are mapped to the same cell**. This results in a single linked-list of length $n$
mapped to a particular cell.

$$T(n) = \Theta(n) + T_{hash-function} \stackrel{constant} \Rightarrow \Theta(n) + \Theta(1) = \Theta(n)$$

### 2 - Average Case
The average case depends on **how the hash functions distributes the keys** between the $m$ cells. 

#### Hypothesis 1: Uniform Hashing Function
We assume that we are in the case of Uniform Hashing Function, which states that

> Uniform Hashing Function guarantees that all elements have equal probabilities to be mapped in any of the $m$ cells 
> independently of where the previous elements were mapped to. $Q[i]$ is the probability that an element is mapped to the
> cell $i$

$$\forall i \in [0 \ldots m-1] Q[i] = \frac{1}{m}$$

Under this hypothesis we consider
* $\alpha = n/m$ the load factor
* $T[j].length = nj$ the length of the list
  * The average value of $nj$ is $avg(nj) = \frac{n_{0} + n_{1} + \ldots +n_{m-1}}{m} = \frac{n}{m} = \alpha$
  * Which means that on average, $T[j].length = \alpha$ in case of chaining.

#### Hypothesis 2: Hash function has an execution time of $\mathcal{O}(1)$

$$T_{h()} = \mathcal{O}(1)$$

#### Rewrite the assumption
> We assume the time complexity of a `Search`, given an element with key $k$, depends on the length $n_{h(k)}$ of the list $T[h(k)]$

From these premises we derive two theorems:

### Theorem - Average Case [Unsuccessful Research]
In a Hash Table, where the collisions are solved by chaining, an unsuccessful search requires on average 
(under the Uniform Hashing Assumption):

$$T(n) = \Theta(1 + alpha) = \Theta(1 + n/m)$$

Intuition:
* Compute $j = h(k)$ is $\Theta(1)$
* Access $T[j]$ is $\Theta(1)$
* Traverse the list $T[j]$ is $\Theta(\alpha)$ on average

### Theorem - Average Case [Successful Research]
In a Hash Table, where the collisions are solved by chaining, a successful search requires on average 
(under the Uniform Hashing Assumption):

$$T(n) = \Theta(1 + alpha/2) = \Theta(1 + alpha) = \Theta(1 + n/m)$$

Intuition
* Compute $j = h(k)$ is $\Theta(1)$
* Access $T[j]$ is $\Theta(1)$
* Traverse the list $T[j]$ is approximately $\Theta(\alpha/2)$ on average
  * On average the element is in the middle of the list

## Conclusion - All operations, on average, have $T(n) = \Theta(1)$

$$\text{if } n = \mathcal{O}(m) \Rightarrow \alpha = \frac{n}{m} = \frac{\mathcal{O}}{m} = \Theta(1)$$

---

## Hashing
Check out the following methods at [Hash Function](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Theory/6%20-%20Table/4%20-%20HASH%20FUNCTION.md):
1. Closed Addressing - Division Hashing
2. Closed Addressing - Multiplicative Hashing
3. Closed Addressing - Universal Hashing

---

## Conclusion

Pros:
* Easier removal (no need for deleted markings)
* Typically, performs better with high load factor. 
* No issues with clustering.

Cons: