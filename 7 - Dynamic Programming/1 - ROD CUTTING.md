# Rod Cutting

Serling Enterprises buys long steel rods and cuts them
into shorter rods, which it then sells. Each cut is free (not relevant) and the cost of the rods is directly proportional 
to its length. 

The management of Serling Enterprises wants to know **the best way to cut up the rods**.

---
### Problem Statement

Input: 
* A rod of length `n` inches 
* A table of prices `pi` with `1 <= i <= n`

Output:
* <mark>Determine the maximum revenue **rn** obtainable </mark>by cutting up the rod and selling the pieces. 
  * Note that if the price pn for a rod of length n is large enough, 
  an optimal solution may require no cutting at all.
  
---
## Step 1
Characterize the structure of an optimal solution.

How many ways can be used to cut a rod of length `n` (in pieces > 0)? `2**(n-1)`
* Since from i = 1 to i = n-1, we can either cut or not (two choices).

A brute force approach will imply an exponential T(n).

## Step 2
Recursively define the value of an optimal solution.
* r0 = 0
* <mark>rn = max{pn, r(1) + r(n-1), r(2) + r(n-2), ... , rn-1 + r1} </mark>
  * pn is the price of not cutting it.

The optimal solution is the combination of optimal sub-solutions.
* Property of the optimal substructure.


In a related, but slightly simpler, way to arrange a recursive structure for the 
rodcutting problem, we view a decomposition as consisting of a first piece of length i
cut off the left-hand end, and then a right-hand remainder of length n = i. 

Only the remainder, and not the first piece, may be further divided

We may view every decomposition of a length-n rod in this way: as a first piece followed by some
decomposition of the remainder
* rn
  * r0 = 0
  * rn = max{pi + r(n-i)} with `1<=i<=n`

## Step 3
Compute the value of an optimal solution.



## Step 4
Construct an optimal solution from computed information.