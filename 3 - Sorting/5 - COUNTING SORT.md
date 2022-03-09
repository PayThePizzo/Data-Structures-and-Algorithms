# Counting Sort

Hypothesis: The number to sort are integers in a interval of `[0..k]` 
* k as some random integer.
* We can use an array for the occurrences if we know them.

---

**Input**: A[1..n] where A[j] ∈ [0..k], for every j ∈ {1,..,n}
* n, k are the parameters of the algorithm

**Output**: B[1..n] sorted in a non-decreasing manner
* B is a different vector

---

## The Algorithm

```python
void countingsort(array A, array B, int n, int k) {
    Allocation C[0...k]; #aux data structure
    for (i = 0 to k):  #Initialization of C to 0
        C[i] = 0;
    for (i = 1 to n): # count occurrences of elements in A
        C[A[i]]++;
    for (i = 1 to k):
        C[i] = C[i] + C[i-1] #prefixed sums
    for (i = n down to 1):
        B[C[A[i]]] = A[i]; #insert
        C[A[i]]--; #to avoid duplicates or insertion in same position
```
**Final Time Complexity**: T(n) = Θ(n+k) 
* Usually best when k = O(n), then T(n) = Θ(n)

--- 

## Conclusion
Pro:
* T(n) = Θ(𝑛 + 𝑘)
* Stable Algorithm, with start from the end

Cons:
* Does not sort in-place (we use an auxiliary vector C[0..k])
* Only sorts numbers between 0 and k, restricted integer spectrum.
* If the interval of numbers go from 0 to `n**2` then it is not efficient: T(n) = Θ(n**2)
