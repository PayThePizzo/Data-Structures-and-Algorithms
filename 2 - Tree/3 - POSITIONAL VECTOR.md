# Positional Vector
We specifically use this type of implementation with **Complete K-Ary Trees** with `k>=2`

Every node has a specific position inside the structure.

Let **T = (N, A)** be a complete k-ary tree with n nodes.
 * Leaves have the same depth
 * Every node has k children
 
Example:

![Positional Vector Tree](https://github.com/PayThePizzo/ASD/blob/main/Resources/PV-Tree.jpg?raw=TRUE)

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
1. Create list
2. See if the first child has index >= n, if so it is a leaf
3. Else we iterate through the vector to insert children into the list 
```python
children(Tree P, Node v)
    l = create_list()
    if (k*v+1 >= n): #First child of 
        return l; #Child is a leaf
    else:
        for (i=0 to k-1):
            insert((k*v+1+i), l);
    return l;
```
Final Time Complexity: <mark>T(n) = O(k)</mark>
* k being the degree of the tree
* We suppose create_list() and insert() have constant T(n)
---


### Conclusion
Pro: We can find in constant time the position of the parent 
and children of a specific node.

Cons: 
* We can use it only for Full/Complete K-ary Trees
* It is difficult to delete and insert elements inside trees using 
vectors (arrays)