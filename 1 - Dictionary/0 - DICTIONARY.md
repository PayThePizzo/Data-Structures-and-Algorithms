# Dictionary
A dictionary represents the mathematical concept of unique relation
between a set *D* and a set *C*

`R:D --> C`
* **Keys** represent the elements of D
* **Values** represent the elements of C


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
