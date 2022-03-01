# Fathers' Vector
Tree based on arrays

## Data
Let **T = (N, A)** 

<mark>P</mark> is the vector of length n and whose cells contain records/ pairs: (info, parent)
* *info* 
* *parent* which stores the index of the this cell's parent.

_Encoding for Parent:_
* **-1**: is the root Node
* **n** : Indexes represent the nodes
  * They go from 0 to n (total number of nodes)

Example: 

| info   | a  | b | c | d | e | f | g | h | i |
|--------|----|---|---|---|---|---|---|---|---|
| parent | -1 | 0 | 0 | 0 | 1 | 1 | 3 | 6 | 6 |
| P[i]   | 0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |


### Attributes
For every node v ∈ [0, n-1]
* P[v].info
* P[v].parent
  * **P[v].parent = u** 
    * i.f.f. there exists an arch (u, v) ∈ A
  * P[v].parent = -1 
  
**Space Complexity**: Θ(n)

---

## Father
Be cautious: nodes are the indexes here.

```python
parent(Tree P, Node v)
    if(P[v].parent) == -1: #Root has no parent
        return NULL;
    else:
        return P[v].parent;
```
Final Time Complexity: <mark>T(n) = O(1)</mark>

---

## Children
1. Iterate through the WHOLE array
2. Verify the condition of being the child of v.
3. Insert inside the list
```python
tree(Tree P, Node v)
    l = create_list()
    for(i=0 to n-1): 
        if(P[i].parent == v): #
            insert(i, l);
    return l;

#**insert(), and create_list() 
# are two auxiliary functions, and are constant
# for educational purposes 

#First index is 0, if the first was 1, we would
#start from one to n-1
```
Final Time Complexity: <mark>T(n) = Θ(n)</mark>
* It is expensive since the complexity depends on the iteration, and the iteration covers the whole array

---

## Conclusion
Pro: Constant time to find parent

Con: It is expensive to find children