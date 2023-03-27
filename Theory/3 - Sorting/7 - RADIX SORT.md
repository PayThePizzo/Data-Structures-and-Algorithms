# Radix Sort

| **Operation** 	| **Method**     	| **Time**         	| **Adaptive?** 	| **In-Place?** 	| **Stable?** 	| **Online?** 	|
|---------------	|----------------	|------------------	|---------------	|---------------	|-------------	|-------------	|
| _Radix sort_  	| Non-Comparison 	| $\Theta(d(n+k))$ 	| **            	| **            	| **          	| **          	|

---

## Idea

The main idea is to sort $n$ elements with $d$ figures, which range $0 \ldots k$ , where:
* $1$ is the less significant figure(rightmost), the one we start with.
* $d$ is the most significant figure (leftmost)

The result is sorting by starting from the rightmost figure to the leftmost one.

![Radix Sort ex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/radixsortex.jpg?raw=TRUE)

---

## The Algorithm

```python
radixsort(array A, int d)
    for (i = 1 to d):
        sort(A, i) #Use a stable sorting algorithm on the i-th figure
```

---

### Correctness Demonstration

Demonstration by induction on the target column to sort
1. Base Case: $i=1$, we sort the only column
2. Inductive Hypothesis: We assume the figures of the columns $1 \ldots i-1$ are sorted
3. Inductive Step: We demonstrate that a stable algorithm on the $i$-th column, keeps the columns $1,2 \ldots k$ sorted
   1. If two figures in position $i$ are equal, by the principle of stability, they remain in the same order as they
   were given. Plus, by Inductive Hypothesis they are sorted.
   2. If two figures in position $i$ are not equal, the algorithm sorts them on the $i$-th column and puts them in the right
   position.

---

### Lemma
Given $n$ numbers of $d$ figures, where each figure can have $k$ possible values, the procedure correctly sorts them in
time $\Theta(d(n+k))$. If the sorting algorithm used is stable, the procedure takes $\Theta(n+k)$

### Time Complexity Demonstration
For each iteration the cost is $\Theta(n+k)$, which means that given $d$ iterations we have $\Theta(d(n+k))$

**Final Time Complexity**: $T(n) = \Theta(d(n+k))$
* `sort()` is a stable sorting algorithm to order the array, based on $i$
  * In this case $T(n) = \Theta(n+k)$
* If $k = \mathcal{O}(n)$, $T(n) = \Theta(d*n)$
* If $k = \mathcal{O}(n)$ and $d = \mathcal{O}(1)$, $T(n) = \Theta(n)$

---

### Space Complexity Demonstration - Not In-Place
Let us suppose to have $n$ integers of $b$ bits, such that $\forall x, x \in [0 \ldots 2^{b}-1]$

We can divide every integer in $\lceil \frac{b}{r} \rceil$ figures $c$ of exactly $r$ bits, $c \in [0 \ldots 2^{r}-1]$ 

The time of execution of the radix sort is $\Theta(d(n+k)) = \Theta(\frac{b}{r}(n+2^{r}))$, then $k = 2^{r}$

Given the values of $n$ and $b$, we choose the value of $r$ such that $r \leq b$, to minimize the function
$\frac{b}{r}(n+2^{r})$

#### Case 1 - $b < \lfloor log(n) \rfloor$
Then, for every value of $r \leq b$

$$n+2^{r} = \Theta(n)$$

$$r \leq b \Rightarrow 2^{r} \leq 2^{b} < n$$

In this case we choose $r=b$ and we get:

$$T(n) = \frac{b}{b}(n+2^{b})=\Theta(n)$$

#### Case 2 - $b \geq \lfloor log(n) \rfloor$
Then,
* $b/r \cdot n \approx r$ must be large
* $b/r \cdot 2^{r} \approx r$ must be small, else it would be dominant on $n$

The best choice is $2^{r} = n \Rightarrow r = log(n)$ and we get:

$$T(n) = \frac{b}{log(n)}(n+2^{log(n)}) = \Theta(\frac{bn}{log(n)})$$

--- 

### Conclusions
In general we use the radix sort when the input is made of integers in the interval $[0 \ldots n^{c}]$ where c is constant