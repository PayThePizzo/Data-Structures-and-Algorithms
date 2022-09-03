# Sorting Recap

|                |         Method         |            T(n)            | Adaptive? | In-Place? | Stable? | Online? |
|----------------|:----------------------:|:--------------------------:|-----------|-----------|---------|---------|
| Insertion sort | Insertion, Incremental |           Θ(n^2)           |     Y     |     Y     |    Y    |    Y    |
| Merge sort     | Merging*               | avg: O(nlog(n)), w: O(n^2) |     N     |     N     |    Y    |    N    |
| Quick sort     | Partitioning*          |           O(n^2)           |     N     |     Y     |    N    |    N    |
| Heap Sort      | Selection, Incremental |         O(n*log(n))        |     Y     |     Y     |    Y    |    N    |
| Counting sort  | Non-Comparison         |   Θ(n)<= Θ(n+k)<= Θ(n^2)   |     N     |     N     |    N    |    N    |
| Radix sort     | Non-Comparison         |         Θ(d*(n+k))         | **        | **        | **      | **      |

**Depends on subroutine, `d` is the number of iterations in the function

---

## Insertion sort

![Insertion Sort Gif]()

## Merge sort

## Quick sort

## Heap sort

## Counting sort

## Radix sort




---