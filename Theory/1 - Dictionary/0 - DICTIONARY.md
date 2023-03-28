# Dictionary

In computer science, a dictionary is a data structure that allows for efficient storage and retrieval of key-value pairs. 
It is also known as an associative array or a map.

In a dictionary, each key is associated with a corresponding value. 
The keys are used to index and retrieve the associated values. Keys must be unique, while values can be duplicated.


## Mathematical View 
> A dictionary represents the mathematical concept of unique relation between a set $D$ and a set $C$

$$\mathbb{R} : D \rightarrow C$$

Each element of a dictionary is composed of:

```math
\text{Element } \lbrace k:v \rbrace = \left\{\begin{matrix}
\text{Key } &\textbf{k} \in D \\
\text{Value } & \textbf{v} \in C \\
\end{matrix}\right.
```

---

## Dynamic Sets - Let's ask ChatGPT!

A dynamic set is a data structure that allows efficient storage and retrieval of a collection of distinct elements. 
It is called "dynamic" because it can be modified at runtime by adding or removing elements.

The dynamic set data structure is typically implemented using one of two approaches:
1. Array-based: In this approach, the elements are stored in an array, which is dynamically resized as needed to 
accommodate new elements. When an element is added, the array is resized if necessary, and the new element is 
inserted at the next available position. When an element is removed, the array is updated by shifting the 
remaining elements over to fill the gap. 
2. Linked-list based: In this approach, the elements are stored as nodes in a linked list. 
When an element is added, a new node is created and added to the list. When an element is removed, the corresponding 
node is deleted from the list.

Both array-based and linked-list based implementations have their advantages and disadvantages. Array-based 
implementations are generally faster for random access, while linked-list based implementations are 
better for insertion and deletion operations.

The dynamic set data structure can be used to implement a variety of algorithms and data structures, 
such as hash tables, search trees, priority queues, and graphs. It is a fundamental building block of many computer programs 
and is used extensively in computer science and software engineering.

---

## Primitive Operations

| **Operation**                                    	| **Pre-Condition** 	| **Post-Condition**                                                              	|
|--------------------------------------------------	|-------------------	|---------------------------------------------------------------------------------	|
| `Search(Dictionary S, Key K) -> Value`           	| -                 	| Returns the value associated with the Key $k$ if present inside $S$, else $NIL$ 	|
| `Insert(Dictionary S, Element V, Key K) -> void` 	| -                 	| Associates the Key $k$ with the Value $v$ in $S$, $\lbrace k:v \rbrace \in S$   	|
| `Delete(Dictionary S, Key k) -> void`            	| $k \in S$         	| Deletes the pair $\lbrace k:v \rbrace$ from $S$                                 	|

---

## Implementation type
1. Sorted Arrays
2. Connected Structures
3. Priority Queues
4. Hash Tables
5. ...
