# Priority Queues

> A priority queue is a data structure for maintaining a dynamic set $S$ of elements, each with an associated value called a 
> $key$ or weight which follow a policy of total order

Priority queues are based on the heap data structure, which is not rare since data access is relatively efficient.

There are mainly two types of Priority Queue, depending on the underling type of heap used:
1. Maximum Priority Queue (Max PQ), which is based on Max Heap
2. Minimum Priority Queue (Min PQ), which is based on Min Heap

Their primitive operations are specular and their common precondition is that $S$, the 
dynamic set, **must be priority queue**.

---

## Max PQ - Operations

> It is best suited as scheduler of processes

| **Operation**                                  	| **Pre-Condition**                                         	| **Post-Condition**                                             	|
|------------------------------------------------	|-----------------------------------------------------------	|----------------------------------------------------------------	|
| `Insert(MaxPQ S, Elem x) -> void`              	| $S$ is Max PQ and $\|S\| \geq 1$                          	| $S = S \cup \lbrace x \rbrace$                                 	|
| `Delete(MaxPQ S, Key k) -> void`               	| $S$ is Max PQ, $\|S\| \geq 1$                             	| Removes the first element $x$ with $x.key = k$                 	|
| `Maximum(MaxPQ S) -> Elem x`                   	| $S$ is Max PQ and $\|S\| \geq 1$                          	| Returns the first element $x$ with the largest key in $S$      	|
| `Extract_Max(MaxPQ S) -> Elem x`               	| $S$ is Max PQ and $\|S\| \geq 1$                          	| Returns and removes the first element $x$ with the largest key 	|
| `Increase_Key(MaxPQ S, Elem x, Key k) -> void` 	| $S$ is Max PQ, $\|S\| \geq 1$, $x \in S$ , $x.key \leq k$ 	| Substitutes the old key of $x$ with $x.key = k$                	|

---

## Min PQ - Operations

> It is best suited for algorithm design

| **Operation**                                  	| **Pre-Condition**                                         	| **Post-Condition**                                              	|
|------------------------------------------------	|-----------------------------------------------------------	|-----------------------------------------------------------------	|
| `Insert(MaxPQ S, Elem x) -> void`              	| $S$ is Max PQ and $\|S\| \geq 1$                          	| $S = S \cup \lbrace x \rbrace$                                  	|
| `Delete(MaxPQ S, Key k) -> void`               	| $S$ is Max PQ, $\|S\| \geq 1$                             	| Removes the first element $x$ with $x.key = k$                  	|
| `Minimum(MaxPQ S) -> Elem x`                   	| $S$ is Max PQ and $\|S\| \geq 1$                          	| Returns the first element $x$ with the smallest key in $S$      	|
| `Extract_Min(MaxPQ S) -> Elem x`               	| $S$ is Max PQ and $\|S\| \geq 1$                          	| Returns and removes the first element $x$ with the smallest key 	|
| `Decrease_Key(MaxPQ S, Elem x, Key k) -> void` 	| $S$ is Max PQ, $\|S\| \geq 1$, $x \in S$ , $x.key \geq k$ 	| Substitutes the old key of $x$ with $x.key = k$                 	|

