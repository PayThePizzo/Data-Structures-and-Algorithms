# Connected Structures
Records and Pointers

### Data
Collection **L** of n records

### Attributes
Basically we are constructing a series of n lists, each one composed of these 4 elements: 
* L.next is the pointer to the next record of the collection
* L.prev is the pointer to the previous record of the collection
* L.key
* L.info

_L.head_ is the pointer to the first element of the collection 
  * If it is L.head == NULL, then it's an _empty_ list
  * So L starts with the first list *p* if p is empty then there are no other elements

**Space Complexity** : S(n) = Θ(n)

---

## Insert - Prepend style
Steps:
1. Create new record *p* with key k and value v
2. Make p.next point to L.head (the previously first elem of L)
3. Switch L.head to p, which is now the first element of L
```python
insert(Dictionary L, Element v, Key k)
    p.next = L.head #points to the head
    if (L.head != NULL):
        L.head.prev = p #points now to the newer first elem
    L.head = p
    p.prev = NULL
```
Final Time Complexity: <mark>T(n) = O(1)</mark>
* Assuming that the time for creation of a new record is constant
* Before using the lists it was linear, now it is constant

---

## Search - First occurrence
Steps:
1. Iterate through L
2. If k is found, and is not empty, return info
```python
search(Dictionary L, Key k)
    x = L.head
    while(x != NULL && x.key != k):
        x = x.next
    if (x != NULL): #did we find the elem?
        return x.info
    else:
        return NULL
```

Final Time Complexity: <mark>T(n) = O(n)</mark>
* T(while) = O(n) 
* T(blocks) = O(1)

We take the first element encountered, so we can reduce the T(n) to O rather than Θ.

---

## Delete - Remove all occurrences
1. Iterate through L
2. If x.key == k
   1. Remove the elem
   2. Reconnect the structures in between
3. When x == NULL, stop

```python
delete(Dictionary L, Key k)
    x = L.head
    while(x != NULL):
        if (x.key == k):
            if(x.next != NULL):
                x.next.prev = x.prev
            if(x.prev != NULL):
                x.prev.next = x.next
            else:
                L.head = x.next
            temp = x
            x = x.next
            remove(temp)
        else:
            x = x.next
```
Final Time Complexity: <mark>T(n) = Θ(n)</mark>
* We always iterate through the whole list

---

## Conclusion

Pro: Efficient insert

Con: Not efficient on delete and search