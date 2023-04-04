# Rod Cutting

Serling Enterprises buys long steel rods and cuts them into shorter rods, which it then sells.
Each cut is free (not relevant) and the cost of the rods is directly proportional to its length.

The management of Serling Enterprises wants to know **the best way to cut up the rods**.

## Problem Statement

Input:
* A rod $j$ of length $n$ inches
* A table of prices $p[i]$ with $1 \leq i \leq n$

Output:
* Determine the maximum revenue $r_{n}$ obtainable by cutting up the rod and selling the pieces.
    * Note that if the price $p[n]$ for a rod of length $n$ is large enough,
      an optimal solution may require no cutting at all.

Example:

![rodcuttingexample](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/rodcuttingexample.png?raw=TRUE)

![rodcuttingexample2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/rodcuttingexample2.png?raw=TRUE)

---

## Step 1 - Characterize the structure of an optimal solution.

How many ways can be used to cut a rod of length $n$ (in pieces $> 0$)? $2^{n-1}$
* Since from $i = 1 \ldots n-1$, we can either cut or not (two choices).
* This means a brute force approach will imply an exponential $T(n)$.

The maximum return for a rod of length $n$ can be expressed in the following way:

```math
\text{ Maximum Revenue } = 
\left\{\begin{matrix}
r_{0} = 0 \\
r_{n} = max \lbrace p_{n}, r_{1}, r_{2} + r_{n-2}, \ldots, r_{n-1} + r_{1} \rbrace  \\
\end{matrix}\right.
```

Where $p_{n}$ is the price of not cutting the rod.

The optimal solution can be defined as the combination of optimal sub-solutions.
Here we find the **property of the optimal substructure**.


---

## Step 2 - Recursively define the value of an optimal solution.

Change of perspective!
* In a related, but slightly simpler, way to arrange a recursive structure for the
  rod-cutting problem, we view a decomposition as consisting of a **first piece of length** $i$
  cut off the left-hand end, and then a right-hand **remainder** of length $n-i$.
* **Only the remainder**, and not the first piece, **may be further divided**

We may view every decomposition of a length $n$ rod in this way: as a first piece followed by some
decomposition of the remainder. So $r_{n}$, the maximum revenue can be re-designed:

```math
r_{i} = 
\left\{\begin{matrix}
r_{0} = 0 & i=0 \\
r_{n} = max \lbrace p_{i} + r_{n-i} \rbrace & 1 \leq i \leq n \\
\end{matrix}\right.
```

Where:
* $p_{i}$, the first piece of length $i$
* $r_{n-i}$, the remainder to be further divided
* $i$, the position of the cut
    * $i=n$, there is no cut.

---

## Step 3 - Find the state to memorize and choose an optimal data structure.

We already have a vector $p[i]$ where all the prices by length are memorized.

---

## Step 4 - pt.1 Sub-Optimal Solution
Compute the value of an optimal solution.

| _Operation_ 	| `Cut_Rod(Vector p[], Integer n) -> Integer`                                                          	|
|-------------	|------------------------------------------------------------------------------------------------------	|
| **Input**   	| A vector $p[1, \ldots, n]$ of prices, The length of a rod $n \geq 0$                                 	|
| **Output**  	| The maximum revenue $q$, given by $q = max_{1 \leq i \leq n}(p_{i} + \text{CUT-ROD}(p, n-i))$        	|
| **Notes**   	| $p[i]$ is the price of a rod of length $i$, and if negative we use `MIN_INT` or $- \infty()$ for `q` 	|

```python
Cut_Rod(p,n)
    if(n == 0):
        return 0
    else:
        #or MIN_INT of neg_infinity()
        q = -1
        # summation(from i = 1, to n) 
        for(i=1 to n):
            # 1 + T(n-i)
            q = max(q, p[i] + cut_rod(p, n-i));
        return q;
```

### Final Time Complexity
$T(n)$ is the total number of calls to `Cut_Rod` when the second parameter is $n$

```math
T(n) = \left\{\begin{matrix}
1 & n=0 \\
1+\sum_{i=1}^{n}T(n-i) & n >0  \\
\end{matrix}\right.
```

So we can change the variable:

$$T(n) = 1+\sum_{i=1}^{n}T(n-i) \stackrel{j=n-i} \Longrightarrow  1+\sum_{j=0}^{n-1}T(j) = 2^{n} $$

Where the initial $1$ is for the call at the root, and the term $T(j)$ counts the number of calls
(including recursive calls) due to the call `Cut_Rod(p, n-i)` where $j=n-i$.

$$T(n) = \Theta(2^{n})$$

#### Demonstration

By Induction on $n$:
* Base Case: $n=0 \Rightarrow T(n=0) = 1 = 2^{0} = 2^{n}$, by definition
* Inductive Hypothesis: We assume this is true for $n$
* Inductive Step: We demonstrate it for $n+1$, namely we ask $T(n+1) = 2^{n+1}$ ?
  * $T(n+1) =  1+\sum_{j=0}^{n}T(j) =  1+\sum_{j=0}^{n-1}T(j) + T(n)$, trivially
  * $1+\sum_{j=0}^{n-1}T(j) + T(n) = T(n) + T(n)$, by definition
    * $T(n) = 2^{n}$, by inductive hypothesis
  * $T(n) + T(n) =  2^{n} +  2^{n} = 2 \cdot  2^{n}$, trivially
  * $2 \cdot  2^{n} = 2^{n+1}$

$T(n) \text{ has exponential time}$

Why is `Cut_Rod` so inefficient? The problem is that `Cut_Rod` calls itself recursively over and over again with the same
parameter values; it solves the same sub-problems repeatedly.

Example: $n=4$

![naiverodcuttingtree](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/naiverodcuttingtree.png?raw=TRUE)

By observing the tree, we notice
* We have as many leaves as the ways we can cut the rod, namely $2^{n-1}$
* Which means every path is a different way to cut the rod
* The same sub-problems are solved multiple times
* But the distinct sub-problems are not that many, in this case they are $n$ 
* Then, we can memorize the solutions to obtain polynomial complexity

---

## Step 5 - pt.2 Top Down Optimal Solution

If we save the solution of $n$ sub-problems we can improve the complexity from exponential to polynomial.
* We avoid repeated computations by saving the solution
  * Through a vector $r$ which saves the maximum revenues for each length $i$
  * $p[i] \geq 0$
* Distinct sub-problems are very rare (usually are $n$ )
  * If the count of sub-problems is polynomial, then each one of them can be solved in a polynomial time.

```python
Memoized_CR_Aux (p, j, r)
    if(r[j] < 0): # If we have not yet solved this case
        if(j == 0):
            r[j] = 0
        else:
            q = -1 # Max Revenue
            for(i = 1 to j):
                q = max(q, p[i]+ Memoized_CR_Aux(p, j-i, r))
            r[j] = q;
    return r[j] #if r[j]>= 0 it's already solved
```
```python
Memoized_Cut_Rod(p, n)
    r[n] # Initialize A vector with indexes 0 to n where the maximum revenues are saved
    for(i = 0 to n):
        r[i] = -1 #initialize the array so that the cells are negative
    return Memoized_CR_Aux(p, n, r)
```

### Final Time Complexity

**Final Time Complexity**: $T(n) = \sum_{j=1}^{n}(j) = \frac{n(n+1)}{2} = \Theta(n^{2})$
* The for cycle in `Memoized_Cut_Rod` is executed only once per sub-problem
* A call for a problem that has already been solved has constant time.
  * So in the worst case we reach the `else` branch only once per sub-problem.

####  Demonstration 
The for cycle in `Memoized_Cut_Rod` is executed only once per sub-problem
* A call for a problem that has already been solved has constant time.
* So in the worst case we reach the `else` branch only once per sub-problem.

To solve a problem of size $n$ the cycle executes $n$ iterations

$$T(n) = \Theta(1) + \sum_{j=1}^{n}j \Theta(1)  = \Theta(\sum_{j=1}^{n}j)= \frac{n(n+1)}{2} = \Theta(n^{2})$$

---

## Step 5 - pt.3 Bottom-Up Optimal Solution
We sort the sub-problems in a non-decreasing order.

```python
BU_Cut_Rod(p, n)
    r[0...n] # A vector of revenues with indexes 0 to n  
    #initialization even though is omitted in pseudocode
    for (i = 0 to n):
        r[i] = -1
    r[0] = 0
    for(j = 1 to n):
        q = -1
        for(i = 1 to j): #solve problems
            q = max(q, p[i]+r[j-i])
        r[j] = q
    return r[n]
```

### Final Time Complexity

**Final Time Complexity**: $T(n) = \sum_{j=1}^{n}j \cdot \Theta(1)= \Theta(\frac{n(n+1)}{2}) = \Theta(n^{2})$

Which is better since it avoids recursive calls.

## Step 5 - pt.4 Bottom-Up Optimized Optimal Solution
Here is an extended version of `Bottom_Up_Cut_Rod` that computes, for each rod size $j$
* Not only the maximum revenue $r[j]$
    * Vector $r[0,n]$ containing the revenues for length $0 \leq i \leq n$
* But also $s[j]$ , the optimal size of the first piece to cut off:
    * Vector $s[1 \ldots n]$ containing the positions of the optimal cuts

```python
BU_Cut_Rod2(p, n)
    r[0,n], s[1,n]
    #initialization
    for (i = 1 to n):
        r[i] = -1 
    r[0] = 0
    for(j = 1 to n): #We compute from smaller problems
        q = -1 # Max revenue so far
        for(i = 1 to j):
            if(q < p[i] + r[j-i]): #if the max improves
                q = p[i] + r[j-i] #new max
                s[j] = i #where to cut for optimality
        r[j] = q
    return(r,s);
```

```python
Print_Cut_Rod_Sol(p,n)
    r,s = BU_Cut_Rod2(p, n); #unpacking
    while(n > 0):
        print(s[n]);
        n -= s[n];
```

### Final Time Complexity

**Final Time Complexity**: $T(n) = \Theta(n^{2}) + \mathcal{O}(n) = \Theta(n^{2})$
