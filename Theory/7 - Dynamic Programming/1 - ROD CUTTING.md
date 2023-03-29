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

How many ways can be used to cut a rod of length `n` (in pieces > 0)? `2**(n-1)`
* Since from i = 1 to i = n-1, we can either cut or not (two choices). 
* This means a brute force approach will imply an exponential T(n).

The maximum return for a rod of length n can be expressed in the following way:
* r0 = 0
* <mark>rn = `max{pn, r(1) + r(n-1), r(2) + r(n-2), ... , rn-1 + r1}` </mark>
  * pn is the price of not cutting it.

The optimal solution can be defined as the combination of optimal sub-solutions. Here we find the **property of the optimal substructure**.

---

## Step 2 - Recursively define the value of an optimal solution.

Change of perspective!
* In a related, but slightly simpler, way to arrange a recursive structure for the 
rod-cutting problem, we view a decomposition as consisting of a **first piece of length i**
cut off the left-hand end, and then a right-hand **remainder** of length n = i.
* **Only the remainder**, and not the first piece, **may be further divided**

We may view every decomposition of a length-n rod in this way: <mark>as a first piece followed by some
decomposition of the remainder</mark>

---

## Step 3 - Compute the value of an optimal solution.

We may view every decomposition of a length-n rod in this way: <mark>as a first piece followed by some
decomposition of the remainder</mark>. So rn, the maximum revenue can be re-designed:
* rn
  * r0 = 0
  * rn = `max{pi + r(n-i)}`, with `1<=i<=n`
    * pi, the first piece of length i
    * r(n-i), the remainder to be further divided.
    * i, the position of the cut. When **i = n, there is no cut**

---

## Step 4 - pt.1 Sub-Optimal Solution
Construct an optimal solution from computed information.

Cut_Rod(p,n):
* Input: 
  * A **vector p** containing the prices
    * p[i] price of a rod of length i
  * **n**, the length of the rod
* Output: 
  * q, the maximum revenue

```python
cut_rod(p,n)
    if(n == 0):
        return 0;
    else:
        q = -1; #or MIN_INT of neg_infinity()
        for(i=1 to n):
            q = max(q, p[i] + cut_rod(p, n-i));  
        return q;
```
**Final Time Complexity** T(n) = Θ(2**n)
* T(n) as the count of cut_rod calls. n, as the second parameter in cut_rod
  * n = 0, then 1
  * n > 0, then `1 + sum(T(j), j=0 to j=n-1)`
    * The initial 1 is for the call at the root, and the term T(j) counts the number of calls
    (including recursive calls) due to the call cut_rod(p, n-i) where j=n-i.

Why is CUT-ROD so inefficient? 
* The problem is that CUT-ROD calls itself recursively over and over again with the same parameter values
* It solves the same sub-problems repeatedly.

## Step 4 - pt.2 Optimal Solution

If we <mark>save the solution of n sub-problems we can improve the complexity</mark> from exponential to polynomial.
* We avoid repeated computations by saving the solution
  * Through a vector r which saves the maximum revenues for each length i
  * p[i] >= 0 
* Distinct sub-problems are very rare (usually are #n)
  * If the count of sub-problems is polynomial, then each one of them can be solved in a polynomial time.

### Top-Down

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
**Final Time Complexity**: T(n) = `sum(j, j=1 to n)` = `(n*(n+1))/2` = θ(n**2)
* A call for a problem that has already been solved has constant time.
* Plus, we only need to compute the result once for each problem.

### Bottom-Up

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
**Final Time Complexity**: T(n) = θ(n**2)

### Bottom-Up v2
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
**Final Time Complexity**: T(n) = θ(n**2)
