# LCS
A strand of DNA consists of a string of molecules called bases, 
where the possible bases are adenine, guanine, cytosine, and thymine.

Representing each of these bases by its initial letter, we can express a strand
of DNA as a string over the finite set {A, C, G, T}.

One reason to compare two strands of DNA is to determine how “similar” the two strands are, as some
measure of how closely related the two organisms are. For example, we can say that two DNA strands are
similar if one is a substring of the other.

### Problem Statement
In the longest-common-subsequence problem
* Input
    * `X = [x1, x2, ..., xm]`
    * `Y = [y1, y2, ..., yn`
* Output:
    * `W`
        * A <mark>maximum length common subsequence of X and Y.</mark>

---

### Formal definitions

Formally, given a sequence `X = [x1, x2, ..., xm]`, another sequence `Z = [z1, z2, ..., zk]` is
a <mark>subsequence</mark> of X if there exists a **strictly increasing** sequence [i1, i2, ..., ik] of indices
of X such that for all `j = 1,2,...,k`, we have xij = z(j);
* So it is not mandatory for them to be consecutive elements.
* For example, Z={B, C, D, B} is a subsequence of X={A, B, C, B, D, A, B}
with corresponding index sequence {2,3,5,7}

Formally, given a sequence `X = [x1, x2, ..., xm]` we define the i-th <mark>prefix</mark> of X,
(for i=0 to m) as `Xi = [x1, x2, ..., xi]`
* For example, if X={A, B, C, B, D, A, B}, then X(4)={A,B,CB} and X(0) is the empty sequence
* Also, when i=m, the prefix corresponds to the whole sequence.

We define a set LCS(X, Y) which represents the set containing all the longest common 
subsequences given two sequences X and Y.
* There might be **multiple distinct subsequences of the same length**,
even though they are the longest.

---
## Step 1
Characterizing the longest common subsequence

In a brute-force approach to solving the LCS problem:
1. We would enumerate all subsequences of X
2. Check each subsequence to see whether it is also a subsequence of Y 
3. Keep track of the longest subsequence we find. 

However, this has T(n) = O(2**m)
* Every character xi can be either included or not.

Remember, we can apply dynamic programming here if we can express the solution in a polynomial count
of sub-problems. So let's try and find a better approach:

As we shall see, the natural classes of sub-problems correspond to pairs of “prefixes”
of the two input sequences.<mark> **So we can reduce the problem to the mere prefixes** of X and Y</mark>.
* The alphabet is limited, this means our complexity goes down to O(m*n) sub-problems.
  * In general `X = [x1, x2, ..., xm]` has m+1 prefixes

Let's define an optimal sub-structure for LCS.

### Optimal Sub-Structure for LCS

![Theroem 15.1](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/optimalstrLCS.png?raw=TRUE)

Let X, Y be two sequences such that:
* X = [x1, x2, ..., xm]
* Y = [y1, y2, ..., yn]

Let W = [w1, w2, ..., wk] any LCS(X, Y), we express its content as sub-problems 
utilizing prefixes of X and Y. We consider LCS() as the optimal solution of the problem, if it does
not apply to the main problem, it could still be valid for a smaller one.
1. If `x(m) = y(m)`, the last characters of LCS coincide, w(k) = x(m) = y(m)
   1. The prefix of this common sequence, W(k-1) belongs to LCS(X(m-1), Y(n-1))
2. If `x(m) != y(m)`
   1. If `w(k) != x(m)`, then W belongs to LCS(X(m-1), Y)
   2. If `w(k) != y(n)`, then W belongs to LCS(X, Y(n-1))

---

Demonstration:
1. w(k) = x(m) = y(m), else I could build a sequence by chaining x(m) to W, resulting in 
W(x(m)) which is still a subsequence of X,Y.
   1. But, this means there should be a subsequence longer than |W|.
   2. **Absurd** because W belongs to LCS(X,Y), so it is already an optimal solution.
2. W(k-1) it's a subsequence of X(m-1) and Y(n-1), since last char are equal. We want to demonstrate
that W(k-1) belongs to LCS(X(m-1), Y(n-1)) since we know it is a subsequence and the longest possible too.
   3. If this was not true, it would exist W' belonging to LCS(X(m-1), Y(n-1))
   4. And we would have |W'| > |W(k-1)| = k-1
3. With w(k) = x(m) = y(m)
   1. |W'(w(k))| > |Wk-1(w(k))|, which means they still are subsequences of X,Y (by chaining a common w(k))
   2. But |W'(w(k))| > W is absurd since W is an optimal LCS.

---

Thanks to this we managed to express the LCS(X,Y) in terms of sub-problems, now we have
a polynomial way to construct our solution.
 
The way that Theorem 15.1 characterizes the longest common subsequences tells
us that an <mark>LCS of two sequences contains within it an LCS of prefixes of the two
sequences.</mark>
* This means we can start from prefixes of length i=1, and then proceed towards i=m (m as the last index)

Thus, the LCS problem has an optimal-substructure property. A recursive solution also has 
the overlapping sub-problems property, as we shall see in a moment.

## Step 2 
A recursive solution
1. If x(m)=y(n)
   1. Find an LCS(X(m-1), Y(n-1))
   2. Appending x(m)=y(m), to this LCS yields an LCS(X,Y)
2. Else, we must solve two subproblems
   1. Finding an LCS(X(m-1), Y)
   2. Finding an LCS(X, Y(n-1))
   3. The longest is an LCS(X,Y) and this exhaust all possibilities recursively.

Our recursive solution to the LCS problem involves establishing a recurrence for the value 
of an optimal solution. Let us define c[i,j] 
* If(i=0 || j=0), then `c[i,j] = 0`
* if(i,j>0 && x(i)==y(j)), then `c[i,j] = c[i-1,j-1]+1
  * We add one because we have one more char, so it's longer than our current LCS
* if(i,j>0 && x(i)!=y(j)), then `c[i,j] = max(c[i,j-1], c[i-1,j])`

You see we **rule out** some sub-problems due to how we defined the problem and the possible 
solutions. We have now, _`n*m` subproblems_

## Step 3 & 4 - Bottom Up
Computing the length of an LCS to be the length of an LCS of the sequences X(i), Y(j)

### LCS
Input:
* X, Y

Output:
* b[] and c[] tables, with c[m,n] containing the length of an LCS(X,Y)

Strategy:
* c[0...m,0...n] is a 2D vector that saves the lengths of LCS(x(i),y(j))
* b[i...m,j...n] is a 2D vector that helps us construct an optimal solution
  * b[i,j] points to the table entry corresponding to the optimal sub-problem solution chosen
  when computing c[i,j]

![LCS movement on matrix B](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/lcsmovement.png?raw=TRUE)

```python
BU_LCS(x,y)
    c[0...m+1,0...n+1]
    b[1...m,1...n]
    m = x.length;
    n = y.length;
    for (i = 0 to m): # When i = 0
        c[i,0] = 0;
    for (j = 1 to n): # When j = 0
        c[0,j] = 0;
    for (i = 1 to m): 
        for (j = 1 to n):
            if(x[i] == y[j]): # Equal
                c[i,j] = c[i-1,j-1] + 1;
                b[i,j] = ↖;
            else if (c[i-1, j] >= c[i,j-1]): 
                c[i,j] = c[i-1, j];
                b[i,j] = ↑;
            else:
                c[i,j] = c[i, j - 1];
                b[i,j] = ←;
    return b,c;
```
**Final Time Complexity** T(n)= Θ(n*m)
* Polynomial

![example lcs](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/exlcs.png?raw=TRUE)

Now that we have found the count of an LCS, we want to display which one it could be!

### Printing
Constructing an LCS

Let's print an LCS!
* We start from the i,j position and decrease either i or j
* We only print if there's an oblique arrow.
* Since the recursive call happens before the print, we get to the top from the bottom
and only print at the very end.

```python
printLCSAux(X, b, i, j)
    if(i > 0 && j > 0): #if not an empty string
        if(b[i,j] == ↖): #if we have a common char
            printLCSAux(X, b, i - 1, j - 1); #first we deal with the subproblem
            print(X[i]); 
        else if(b[i,j] == ↑): #if we have NOT a common char
            printLCSAux(X, b, i - 1, j);
        else:
            printLCSAux(X, b, i, j - 1);
```
**Final Time Complexity** T(n)= O(i+j)
* At every function call, we decrease either one of the two parameters.

```python
printLCS(X,Y)
    b,c = BU_LCS(X,Y);
    printLCSaux(X,b, X.length, Y.length);
```
**Final Time Complexity** T(n)= Θ(n*m)
* We need to go through LCS

---

### Improve memory
We can reduce the memory usage through two different optimizations

**First Method**

In the LCS algorithm, for example, we can eliminate the b table altogether.

Given the value of c[i,j], we can determine in O(1) time which of
these three values was used to compute c[i,j] without inspecting table b.
Each c[i,j]  entry **depends on only three other c table entries**:
1. c[i-1,j-1]
2. c[i-1,j]
3. c[i,j-1]

Thus, we can reconstruct an LCS in O(m+n) time using a procedure similar to printLCS.
The order here matters a lot!

```python
printLCSAux(X, c, i, j)
    if(i > 0 && j > 0):
        if(c[i,j] == c[i - 1,j]):
            printLCSAux(X, c, i - 1, j);
        else if(c[i,j] == c[i,j - 1]):
            printLCSAux(X, c, i, j - 1);
        else:
            printLCSAux(X, c, i - 1, j - 1);
            print(X[i]);
```
Although we save `Θ(n*m)` space by this method, the auxiliary 
space requirement for computing an LCS does not asymptotically decrease, since 
we need `Θ(n*m)` space for the c table anyway.


**Second Method**

We can, however, reduce the asymptotic space requirements for LCS-LENGTH,
since it needs only two rows of table c at a time: the row being computed, and the
previous row

This improvement works if **we need only the length of an LCS**; if we need to reconstruct
the elements of an LCS, the smaller table does not keep enough information to
retrace our steps in O(m+n) time.

---

## Step 3 & 4 - Top Down

```python
TD_LCSAux(x, y, c, i, j)
    if(c[i,j] == -1): # Problem not solved
        if(i == 0 || j == 0): 
            c[i,j] = 0;
        else if(x[i] == y[j]):
            c[i,j] = TD_LCSAux(x, y, i - 1, j - 1) + 1;
        else:
            c[i,j] = max(TD_LCSAux(x, y, i - 1, j),
                         TD_LCSAux(x, y, i, j - 1));
    return c[i,j];
```
**Final Time Complexity** T(n)= O(n*m)
* This is directly proportional to the possible sub-problems 

```python
TD_LCS(X, Y)
    m = X.length
    n = Y.length
    c[0..m,0..n] = -1 #initialized with all elements equals to -1
    return TD_LCSAux(X, Y, c, m, n)
```
**Final Time Complexity** T(n)= Θ(n*m)
* If the strings are equivalent, we are in O(m) rather than O(n**2)

![example lcs td](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/exlcstd.png?raw=TRUE)

