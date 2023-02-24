# Positional Vector
We specifically use this type of implementation with **Complete K-Ary Trees** with `k>=2`

Every node has a specific position inside the structure.

Let **T = (N, A)** be a complete k-ary tree with n nodes.
 * Leaves have the same depth
 * Every node has k children
 
Example:

![Positional Vector Tree](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/PV-Tree.jpg?raw=TRUE)

--- 

## Data
We use a vector v, of length n.

### Attributes
* P[v] <mark>contains the information associated with the node *v* </mark>
  * v = 0 is the root
  * The i-ary child of v is in position **kv+1+i** with i ∈ {0, k-1}
    * We must add 1 to avoid the root
* P.length is the length of the vector
* P[v].k is the degree of each node

Parent of *f* can be found in the position ⌊**(f-1)/k**⌋

---
## Parent
```python
parent(Tree P, Node v)
    if(v == 0):
        return NULL
    else:
        return ⌊**(v-1)/P.k**⌋
```
Final Time Complexity: <mark>T(n) = O(1)</mark>

--- 
## Children

```python
children(Tree P, Node v)
    l = create_list()
    if (k*v+1 >= n):
        return l;
    else:
        for (i=0 to k-1):
            insert((k*v+1+i), l);
    return l;
```
Final Time Complexity: <mark>T(n) = O(k)</mark>
* k being the degree of the tree

---


### Conclusion
Pro: We can find in constant time the position of the parent and children of a specific node.

Con: We can use it only for Full/Complete K-ary Trees
