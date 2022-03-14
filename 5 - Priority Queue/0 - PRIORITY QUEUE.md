# Priority Queues
This version is based on the heap data structure, 
which is not rare since data access is relatively efficient.

It is a data structure that maintains a _dynamic set_ in which each element is a record 
**{key:weight}**
* These keys follow a policy of total order

Types:
1. Maximum Priority Queue (MaxPQ)
2. Minimum Priority Queue (MinPQ)

Their primitive operations are specular. Their common precondition is that S, the 
dynamic set, must be priority queue

---
## Max PQ
* insert(Queue S, Elem x)
  * Inserts x in S: _S = S U {x}_
* delete(Queue S, Key k)
  * Removes the first element x with x.key = k
* maximum(Queue S)
  * Returns the element with the **largest key** in S
* extract_max(QueueS)
  * Returns and **removes** the element with the **largest key** in S
* increase_key(Queue S, Elem x, Key k)
  * Substitutes x.key with the new value of k.
  * x.key = k, with _k >= x.key_ usually

It is best suited as scheduler of processes

---

## Min PQ
* insert(S, x)
  * x.key = k, with _k <= x.key_ usually
* delete(S, k)
    * Removes the first element x with x.key = k
* minimum(S)
  *  Returns the element with the **smallest key** in S
* extract_min(S)
  * Returns and **removes** the element with the **smallest key** in S
* decrease_key(S, x, k)
  * Substitutes x.key with the new value of k.
  * x.key = k, with _k <= x.key_ usually

It is best suited for algorithm design


