# Dictionary
A dictionary represents the mathematical concept of unique relation
between a set *D* and a set *C*
* **Keys** represent the elements of D
* **Values** represent the elements of C

```
R:D --> C
```

## Data
The logical idea is to have a set of pairs *{key:value}*

## Operations
* **Search(Dictionary S, Key K)**
  * Pre: None
  * Post: Returns the value associated to the key K if it is present inside S. Else, it returns NULL
* **Insert(Dictionary S, Element V,Key K)**
  * Pre: None
  * Post: Associates the value V with the Key K,
* **Delete(Dictionary S, Key k)**
  * Pre: K must be present inside S
  * Post: Deletes the pair(K,V) from S

## Implementation type
1. Sorted Arrays
2. Connected Structures

## Sorted Arrays
Array of length *n* containing records with two fields
(key, info).

The array is sorted on the **keys**

---
**Key Elements**

A.length contains the dimension of the array.

A[i].key is the k for a pair at index i

A[i].info is the v for a pair at index i

---
**Allocation**
* Space Complexity: S(n) = Theta(n)



### Search
* Pre: P & R (start, stop index) must be between 0 and A.length
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
* T(n) search_index = O(log(n)) 
  * Since we do not have any lower limit, we might find immediately what we are looking for!
* T(n) search = Theta(1)


### Insert
Post: Keeping the array **sorted**
1. Retrieve the right position
2. Insertion
   1. Direct update of v if k is present
   2. Copying A to a new Array of dim A.length+1 

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
            A[j] = A[j-1]
        A[i].key = k;
        A[i].info = v;
```

Auxiliary Function: **reallocate(Dictionary A, int length)**
* Creates a new array with the length specified and copies 
the content of the Dictionary A.
  * If A.length <= length, it creates a new array and copies the content of the array
  * If A.length > length, it creates a new array that omits the last pair



### Delete

## Connected Structures
Records and Pointers