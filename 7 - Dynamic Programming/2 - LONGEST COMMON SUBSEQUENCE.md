# LCS
A strand of DNA consists of a string of molecules called bases, 
where the possible bases are adenine, guanine, cytosine, and thymine.

Representing each of these bases by its initial letter, we can express a strand
of DNA as a string over the finite set {A, C, G, T}.

One reason to compare two strands of DNA is to determine how “similar” the two strands are, as some
measure of how closely related the two organisms are. For example, we can say that two DNA strands are
similar if one is a substring of the other.

### Formal definitions

Formally, given a sequence `X = [x1, x2, ..., xm]`, another sequence `Z = [z1, z2, ..., zk]` is
a <mark>subsequence</mark> of X if there exists a **strictly increasing** sequence [i1, i2, ..., ik] of indices
of X such that for all `j = 1,2,...,k`, we have xij = z(j);
* So it is not mandatory for them to be consecutive elements.

Formally, given a sequence `X = [x1, x2, ..., xm]` we define the i-th <mark>prefix</mark> of X,
(for i=0 to m) as `Xi = [x1, x2, ..., xi]`
* 

### Problem Statement
In the longest-common-subsequence problem
* Input
  * `X = [x1, x2, ..., xm]`
  * `Y = [y1, y2, ..., yn`
* Output: 
  * `W` 
    * A maximum length common subsequence of X and Y.

---
## Step 1
Characterizing the longest common subsequence

In a brute-force approach to solving the LCS problem, we would enumerate all
subsequences of X and check each subsequence to see whether it is also a subsequence of Y , 
keeping track of the longest subsequence we find. 

This has T(n) = O(2**m)
* Every character xi can be either included or not.

But this would bring us to another problem: there might be **multiple distinct 
subsequences of the same length**, even though they are the longest.

We can apply dynamic programming here, if we can express the solution in a polynomial count
of sub-problems.

So how shall we proceed?
The LCS problem has an optimal-substructure property. 

As we shall see, the natural classes of subproblems correspond to pairs of “prefixes” 
of the two input sequences.

![Optimal Struct. LCS](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/optimalstrLCS.png?raw=TRUE)
