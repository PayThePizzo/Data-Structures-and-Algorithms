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
  * Post: Associates the value V with the Key K
* **Delete(Dictionary S, Key k)**
  * Pre: K must be present inside S
  * Post: Deletes the pair(K,V) from S

## Implementation type
1. Sorted Arrays
2. Connected Structures

## Sorted Arrays
Array of lenght *n* containing records with two fields
(key, info).

The array is sorted on the **keys**

A.lenght contains the dimension of the array.

* Space Complexity: S(n) = Theta(n)

### Search
* Pre: P & R must be between 0 and A.lenght
```python

# Binary Search - Divide et Impera
# P is the start index, R is the end index
search_index(Dictionary A, Key K, int p, int r)
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
search(Dictionary A, Key K)
    i = search_index(A, K, 1, A.length)
    if(i == -1):
        return NULL;
    else
        return A[i].info
```
* T(n) search_index = O(log(n)) 
  * Since we do not have any lower limit, we might find immediately what we are looking for!
* T(n) search = Theta(1)

**T(n) = O(log(n))**

### Insert


```

```

### Delete

## Connected Structures
Records and Pointers