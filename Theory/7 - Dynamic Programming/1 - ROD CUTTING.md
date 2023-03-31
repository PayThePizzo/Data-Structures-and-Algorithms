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

<table style="border-collapse:collapse;border-spacing:0" class="tg"><thead><tr><th style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-style:italic">_Operation_</span></th><th style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="color:#905;background-color:#ddd">`Cut_Rod(Vector p[], Integer n) -&gt; Integer`</span></th></tr></thead><tbody><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:bold">**Input**</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">A vector $p[1, \ldots, n]$ of prices, The length of a rod $n \geq 0$</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:bold">**Output**</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">The maximum revenue $q$, given by $q = max_{1 \leq i \leq n}(p_{i} + \text{CUT-ROD}(p, n-i))$</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:bold">**Notes**</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">$p[i]$ is the price of a rod of length $i$, and if negative we use <span style="color:#905;background-color:#ddd">`MIN_INT`</span> or $- \infty()$ for <span style="color:#905;background-color:#ddd">`q`</span></td></tr></tbody></table>

```python
cut_rod(p,n)
    if(n == 0):
        return 0;
    else:
        q = -1; #or MIN_INT of neg_infinity()
        for(i=1 to n):
            # T(n-i)
            q = max(q, p[i] + cut_rod(p, n-i));  
        return q;
```

### Final Time Complexity 
The final time complexity is given by

$$T(n) = max \lbrace T_{if}, T_{else} \rbrace = $$


**Final Time Complexity** $T(n) = \Theta(2^{n})$
* T(n) as the count of cut_rod calls. n, as the second parameter in cut_rod
  * n = 0, then 1
  * n > 0, then `1 + sum(T(j), j=0 to j=n-1)`
    * The initial 1 is for the call at the root, and the term T(j) counts the number of calls
    (including recursive calls) due to the call cut_rod(p, n-i) where j=n-i.

Why is CUT-ROD so inefficient? 
* The problem is that CUT-ROD calls itself recursively over and over again with the same parameter values
* It solves the same sub-problems repeatedly.

---

## Step 5 - pt.2 Top Down Optimal Solution

If we <mark>save the solution of n sub-problems we can improve the complexity</mark> from exponential to polynomial.
* We avoid repeated computations by saving the solution
  * Through a vector r which saves the maximum revenues for each length i
  * p[i] >= 0 
* Distinct sub-problems are very rare (usually are #n)
  * If the count of sub-problems is polynomial, then each one of them can be solved in a polynomial time.

```python
MCR_Aux (p, j, r)
    if(r[j] < 0): #if r[j]>= 0 it's already solved, return value
        if(j == 0):
            r[j] = 0;
        else:
            q = -1;
            for(i = 1 to j):
                q = max(q, p[i]+ MCR_Aux(p, j-i, r))''
            r[j] = q; 
    return r[j];
```
```python
TD_Cut_Rod(p, n)
    r[n] # A vector with indexes 0 to n
    for(i = 0 to n):
        r[i] = -1 #initialize the array so that the cells are negative
    return MCR_Aux(p, n, r)
```

### Final Time Complexity

**Final Time Complexity**: T(n) = `sum(j, j=1 to n)` = `(n*(n+1))/2` = θ(n**2)
* A call for a problem that has already been solved has constant time.
* Plus, we only need to compute the result once for each problem.

---

## Step 5 - pt.3 Bottom-Up Optimal Solution

```python
BU_Cut_Rod(p, n)
    r[n] # A vector with indexes 0 to n
    for (i = 0 to n):
        r[i] = -1; #initialization
    r[0] = 0;
    for(j = 1 to n):
        q = -1;
        for(i = 1 to j):
            q = max(q, p[i]+r[j-i]);
        r[j] = q;
    return r[n];
```

### Final Time Complexity

**Final Time Complexity**: T(n) = θ(n**2)

## Step 5 - pt.4 Bottom-Up Optimized Optimal Solution
Here is an extended version of BOTTOM-UP-CUT-ROD that computes, for each
rod size j*
* Not only the maximum revenue rj
  * Vector r[0,n] containing the revenues for length `0<= i <= n`
* But also sj , the optimal size of the first piece to cut off:
  * Vector s[1,n] containing the positions of the optimal cuts 

```python
BU_Cut_Rod2(p, n)
    r[0,n], s[1,n]
    for (i = 1 to n):
        r[i] = -1; #initialization
    r[0] = 0
    for(j = 1 to n): #We compute from smaller problems
        q = -1;
        for(i = 1 to j):       
            if(q < p[i] + r[j-i]): #if the max improves
                q = p[i] + r[j-i]; #new max
                s[j] = i; #where to cut for optimality
            r[j] = q;
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

**Final Time Complexity**: T(n) = θ(n**2)
