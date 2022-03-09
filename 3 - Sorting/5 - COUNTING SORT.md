# Counting Sort

```python
void countingsort(array A, array B, int n, int k) {
    Alloco C[0...k];
    for (i = 0 to k):  #Initialization of C to 0
        C[i] = 0;
    for (i = 1 to n): # count occurrences of elements in A
        C[A[i]]++;
    for (i = 1 to k):
        C[i] = C[i] + C[i-1] #prefixed sums
    for (i = n down to 1):
        B[C[A[i]]] = A[i]; #sort
        C[A[i]]--; #remove one from the occurrence of A[i]
```

--- 

### Conclusion

---

### Extra Credits: