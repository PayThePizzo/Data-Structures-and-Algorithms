# Radix Sort
The main idea is to sort **n** elements with **d** figures, which range (0-**k**) , where:
* 1 is less significant (rightmost)
* d-ary are more significant (leftmost)

The result is sorting by starting from the rightmost figure to the leftmost one.

![Radix Sort ex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/radixsortex.jpg?raw=TRUE)

---

## The Algorithm

```python
radixsort(array A, int d)
    for (i = 1 to d):
        sort(A, i)
```
**Final Time Complexity**: T(n) = Θ(d*(n+k))
* sort() is a stable sorting algorithm to order the array, based on `i`
  * In this case T(n) = Θ(n+k)
* If k = O(n), T(n) = Θ(d*n)
* If k = O(n) and d = O(1), T(n) = Θ(n)
--- 

### Conclusion

---

### Extra Credits: