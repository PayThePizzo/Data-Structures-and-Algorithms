
# Sorted Arrays

### Data

Array of length *n* containing records with two fields
(key, info).

The array is sorted on the **keys**


### Attributes

A.length contains the dimension of the array.

A[i].key is the k for a pair at index i

A[i].info is the v for a pair at index i

**Space Complexity**: S(n) = Θ(n)

---

## Search
**Pre**: P & R (start, stop index) must be between 0 and A.length

Steps:
1. Find index
2. Return A[index].info

```python

# Binary Search - Divide et Impera
# P is the start index, R is the end index
search_index(Dictionary A, Key k, int p, int r)
    if(p > r):
        return -1; #Empty
    else:
      med = ⌊(p+r)/2⌋ #Floor Division
        
        if(A[med].key == k):
            return med;
        else if (A[med].key > k):
            return search_index(A, K, p, med-1) 
        else:
            return search_index(A, K, med+1, r)
    
# Search with Aux Function
search(Dictionary A, Key k)
    i = search_index(A, K, 1, A.length)
    if(i == -1):
        return NULL;
    else
        return A[i].info
```
Final Time Complexity: <mark>T(n) = O(log(n))</mark>
* T(**search_index**) = <mark>O(log(n)))</mark>
    * Since we do not have any lower limit, we might find immediately what we are looking for!
* T(n) search = Θ(1)

---

## Insert
**Post**: Keeping the array **sorted**

Steps:
1. Retrieve the right position
2. Insertion
    1. Direct update of v if k is present
    2. Copying A to a new Array of dim A.length+1

Auxiliary Function: **reallocate(Dictionary A, int length)**
* Creates a new array with the length specified and copies
  the content of the Dictionary A.
    * If A.length <= length, it creates a new array and copies the content of the array
    * If A.length > length, it creates a new array that omits the last pair


```python
insert(Dictionary A, Element v, Key k)
    i = 1
    while (i <= A.length && A[i].key < k):
        i++;
    if (i <= A.length && A[i].key == k):
        A[i].info = v; #Key is present, update value
    else:
        reallocate(A, A.length+1)
        A.length += 1 #Can be omitted if implemented in reallocate()
        for(j = A.lenght downto i++)
            A[j] = A[j-1] #Shift elements to right
        A[i].key = k;
        A[i].info = v;
```
Final Time Complexity: <mark>T(n) = O(n)</mark>

Why?
* T(cost) = Θ(1)
* T(while) = O(i*d) 
  * *d* being the computational cost of the body
* T(reallocate) = <mark>O(n)</mark>
* T(for) = (n-i+1)

It is not Θ(n) because there is a case where we just need to update the value

---

## Delete
**Pre**: k is present inside A

Steps:
1. Retrieve Index - Binary Search
2. Delete & Reallocate - shift left

```python

delete(Dictionary A, Key k)
    i = search_index(A, k, 1, A.length)
    for(j = i to A.length-1)
        A[j] = A[j+1]
    reallocate(A, A.length-1)
    A.length -= 1 #Can be omitted if implemented in reallocate()

```

Final Time Complexity: <mark>T(n) = O(n)</mark>

Why?
* T(search_index) = O(log(n))
* T(for) = (n-1)*d
* T(reallocate) = O(n)

It is not Θ(n) because we could find the index right away

---

## Reallocate - Doubling & Halfing strategy

Idea: 
1. Doubling the area of the vector when saturated
2. Halving the area of the vector when the space in use is less than the half 

T(n) is constant at the beginning, then it will be proportional to the cost of building a new
vector of length n.

### Conditions
Invariant: Array of dim *h*, where for every *n*>0: <mark> n<= h < 4n</mark>
* S(n) = Θ(h) = Θ(n)


### Structure
The first *n*-cells of the array contain the elements of the collection, 
while the content of the remaining cells is undefined.
* Initally
  * n = 0
  * h = 1 
* When n > h
  * Doubling: the array is reallocated, by doubling its dimension
* When n = h/4
  * Halving: the array is reallocated, by halving its dimension (`h /= 2`)
---

## Conclusion

Pro: Efficient for searches - O(log(n))

Con: Not efficient for insertions and deletes - O(n)


