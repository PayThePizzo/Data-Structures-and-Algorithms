# LCS
A strand of DNA consists of a string of molecules called bases, 
where the possible bases are adenine, guanine, cytosine, and thymine.

Representing each of these bases by its initial letter, we can express a strand
of DNA as a string over the finite set $\lbrace A, C, G, T \rbrace$.

One reason to compare two strands of DNA is to determine how “similar” the two strands are, as some
measure of how closely related the two organisms are.

## String Similarity
We can, and do, define similarity in many ways. For example, we can say that two DNA strands are
similar:
1. If one is a substring of the other.
2. Alternatively, we could say that two strands are similar if the number of changes needed 
to turn one into the other is small.
3. Yet another way to measure the similarity of strands $S_{1}$ and $S_{2}$ is by **finding a third strand** $S_{3}$
**in which the bases** in $S_{3}$ appear in each of $S_{1}$ and $S_{2}$. 
   1. These bases must appear in the same order, but not necessarily consecutively. 
   2. The longer the strand $S_{3}$ we can find, the more similar $S_{1}$ and $S_{2}$ are.

Example:
* $S_{1} = ACCGGTCGAGTGCGCGGAAGCCGGCCGAA$
* $S_{2} = GTCGTTCGGAATGCCGTTGCTCTGTAAA$
* $S_{3} = GTCGTCGGAAGCCGGCCGAA$

### Subsequence 
We formalize this last notion of similarity as the longest-common-subsequence problem. A subsequence of a 
given sequence is just the given sequence with zero or more elements left out.

> Formally, given a sequence $X = \langle x_{1}, x_{2}, \ldots , x_{m} \rangle$, another sequence 
> $Z = \langle z_{1}, z_{2}, \ldots , z_{k} \rangle$ is a subsequence of $X$ if there exists a strictly 
> increasing sequence $\langle i_{1}, i_{2}, \ldots , i_{k} \rangle$ of indices of X such that for all $j = 1,2, \ldots, k$,
> we have $x_{j} = z_{j}$

$$\text{Given } X = \langle x_{1}, x_{2}, \ldots , x_{m} \rangle, \text{ We have } x_{i_{1}}, \ldots, x_{i_{k}} \text{such that }$$

$$i_{1}, \ldots, i_{k} \in \lbrace 1, \ldots, m \rbrace \wedge i_{1} < i_{2} < \ldots < i_{k}$$

Example: $Z=\langle B,C,D, B \rangle$ is a subsequence of $X=\langle A,B,C,B, D, A, B \rangle$ 
with corresponding index sequence $\langle 2,3,5,7 \rangle$

### Common Subsequence

> Given two sequences $X$ and $Y$, we say that a sequence $Z$ is a common subsequence of $X$ and $Y$ if $Z$ is a 
> subsequence of both $X$ and $Y$

Example: $X=\langle  A,B,C,B,D,A,B \rangle$ is a subsequence of $Y=\langle B,D,C,A,B,A \rangle$, the sequence
$\langle B,C,A \rangle$ is a common subsequence of both $X$ and $Y$. 

The sequence $\langle B,C,A \rangle$ is **not** a longest common subsequence (LCS) of $X$ and $Y$, however, since 
it has length $3$ and the sequence $\langle B,C,B,A \rangle$, which is also common to both $X$ and $Y$ , has length $4$.
The sequence $\langle B,C,B,A \rangle$ is an LCS of $X$ and $Y$ , as is the sequence $\langle B,D,A,B \rangle$
since $X$ and $Y$ have no common subsequence of length $5$ or greater.


### Problem Statement - Longest Common Subsequence
In the longest-common-subsequence problem, we are given two sequences (input)

$$X = \langle x_{1},x_{2}, \ldots, x_{m} \rangle \wedge Y = \langle y_{1}, y_{2}, \ldots, y_{n} \rangle$$

and wish to find a **maximum length common subsequence** of $X$ and $Y$, $W$ (output).

#### Observation 1: Multiple possible LCS

If we define a set $LCS(X, Y)$ which represents the set containing all the longest common
subsequences given two sequences $X$ and $Y$, there might be **multiple distinct subsequences of the same length**,
even though they are the longest.

#### Observation 2: Brute force is not an option $T(n)=\Theta(2^{n})$

In a brute-force approach to solve the LCS problem:
1. We would enumerate all subsequences of $X$
2. Check each subsequence to see whether it is also a subsequence of $Y$
3. Keep track of the longest subsequence we find.

By generating all the possible sequences of $X$, verifying the property of common subsequence of $Y$ and storing the 
longest one, would require an exponential time. This is because at most we have $2^{n}$ subsequences as each character $x_{i}$
could either appear or not.

---

## Step 1 - Characterizing the longest common subsequence
Remember, we can apply dynamic programming here if we can express the solution in a polynomial count
of sub-problems. 

The LCS problem has an optimal-substructure property, however, as the following theorem shows. 
As we shall see, the natural classes of subproblems correspond to pairs of “prefixes” of the two input sequences.

### Prefix

> Given a sequence $X = \langle x_{1},x_{2}, \ldots, x_{m} \rangle$, we define the $k$-th prefix of $X$, 
> for $k \leq m$, as the prefix of $X$ of length $k$, $X^{k} = \langle x_{1},x_{2}, \ldots, x_{k} \rangle$

Example: $X = \langle A, B, C, B, D, A, B \rangle$, then 
* $X^{4} = \langle A,B,CB \rangle$ 
* And $X^{0}$ is the empty sequence
* Also, when $k=m$, the prefix corresponds to the whole sequence.

In general $X = \langle x_{1},x_{2}, \ldots, x_{m} \rangle$ has $m+1$ prefixes, and by reducing the $LCS$ problem to
the $LCS$ problem on prefixes the complexity goes down to $\mathcal{O}(mn)$ sub-problems.
* Where $X = \langle x_{1},x_{2}, \ldots, x_{m} \rangle$ and $Y = \langle y_{1}, y_{2}, \ldots, y_{n} \rangle$

### Theorem 15.1: Optimal Substructure of an LCS

![Theroem 15.1](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/optimalstrLCS.png?raw=TRUE)

Let's rewrite it for analysis purposes

Let $X = \langle x_{1},x_{2}, \ldots, x_{m} \rangle \wedge Y = \langle y_{1},y_{2}, \ldots, y_{n} \rangle$ be two sequences
and $W = \langle w_{1}, w_{2}, \ldots, w_{k} \rangle \in LCS(X,Y)$ be one of the possible $LCS$

We consider $LCS$ as the optimal solution of the problem, if it does
not apply to the main problem, it could still be valid for a smaller one. Then:
1. If $x_{m} = y_{n}$, the last characters of LCS coincide, 
   1. The last characters of LCS coincide, $w_{k} = x_{m} = y_{n}$
   2. The prefix of this common sequence is the LCS of the prefixes of $X$ and $Y$, $W^{k-1} \in LCS(X^{m-1}, Y^{n-1})$
2. If $x_{m} \neq y_{n}$, Then:
   1. If $w_{k} \neq x_{m}$, then $W^{k} \in LCS(X^{m-1}, Y)$
   2. If $w_{k} \neq y_{n}$, then $W^{k} \in LCS(X, Y^{n-1})$
   

#### Demonstration 

Demonstration Ad-Absurdum:
* Part 1.1: $w_{k} = x_{m} = y_{n}$, 
  * Ad-absurdum, if this was not true we could build a sequence by chaining $x_{m}$ to $W$, resulting in 
  $W_{x_{m}}$ which is still a subsequence of $X$ and $Y$. 
  * But, this means there should be a subsequence longer than $W$, which is **absurd** because $W \in LCS(X,Y)$, 
  so it is already an optimal solution.
  * Then, $w_{k} = x_{m} = y_{n}$ is true.
* Part 1.2: $W^{k-1} \in LCS(X^{m-1}, Y^{n-1})$
  * Ad-absurdum, if this was not true we could have some $W' \in LCS(X^{m-1}, Y^{n-1})$ and $|W'| > |W^{k-1}| = k-1$
  * Since we know, $w_{k} = x_{m} = y_{n}$, If we concat the sequences with $w_{k}$ we would 
  get $| W^{k-1}_{w_{k}} | < | W^{'}_{w_{k}} |$ (which are both $LCS$).
  * But, $W^{k-1}_{w_{k}} = W$ as it is the string concatenated with the last character.
  * We reach an absurd as $|W| < |W^{'}_{w_{k}}|$, and $W$ would not be an optimal solution anymore.
* Part 2.1: $x_{m} \neq y_{n} \wedge w_{k} \neq x_{m} \Rightarrow W^{k} \in LCS(X^{m-1}, Y)$
  * Ad-absurdum, we suppose there exists some $W' \in LCS(X^{m-1}, Y) \wedge |W'| > |W|$, it is not possible as $W$ is
  by definition an optimal solution of maximum length
* Part 2.2: $x_{m} \neq y_{n} \wedge w_{k} \neq y_{n} \Rightarrow W^{k} \in LCS(X, Y^{n-1})$
  * Ad-absurdum, we suppose there exists some $W' \in LCS(X, Y^{n-1}) \wedge |W'| > |W|$, it is not possible as $W$ is
  by definition an optimal solution of maximum length


#### Conclusion 

To sum up:
1. Thanks to this we managed to express the $LCS(X,Y)$ in terms of sub-problems, now we have 
a polynomial way to construct our solution. 
2. The way that Theorem 15.1 characterizes the longest common subsequences tells
us that an LCS of two sequences contains within it an LCS of prefixes of the two sequences. 
3. This means we can start from prefixes of length i=1, and then proceed towards i=m (m as the last index)
4. Thus, the LCS problem has an optimal-substructure property. A recursive solution also has 
the overlapping sub-problems property, as we shall see in a moment.

---

## Step 2 - Recursive Solution
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

---

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

![LCS movement on matrix B](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/lcsmovement.png?raw=TRUE)

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

![example lcs](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exlcs.png?raw=TRUE)

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

![example lcs td](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exlcstd.png?raw=TRUE)

