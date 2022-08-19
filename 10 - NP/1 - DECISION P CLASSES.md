# Decision Problem Classes

## Class P
The **class P** consists of those decision problems that are **solvable in polynomial time O(n^k)**. 
* for some constant k,
* n is the size of the input to the problem.

Ex: MST, SP, Sorting...

However, it can contain untreatable problems (since the algorithm might take too long, and it is not usable in real life)

**If a problem is solvable in polynomial time, it is also verifiable in polynomial time! P⊆NP**
* Like the alt problem, the verification algorithm mimics that solving algorithm.
* The solving algorithm has polynomial time
* Trivially, the verification algorithm must have polynomial time too.

**If a problem is solvable in polynomial time, its complement is also verifiable in polynomial time! P⊆CO-NP**

![P NP CONP](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/pnpconp.png?raw=True)

---

## Class NP
The **class NP** consists of those decision problems that are **“verifiable” in polynomial time O(n^k)**.

## A verifiable problem
Given an "Instance-Yes" `i` and a Certificate `c` of a solution, If we can **verify through the Certificate c that `i` is an Instance-Yes**.

Ex: It is like verifying a demonstration of an algorithm for a theorem.

When it is not verifiable in polynomial time:
* If verification algorithm we plan, returns `No` for a certain tuple (Instance-Yes i, Certificate c)
  * The **certificate is not sufficient or not correct**
  * It does not imply that the theorem is not correct! Only the demonstration is not correct.
* If the verification algorithm is not polynomial, trivially.

### Hamiltonian Graph - NPC
The problem: Is the graph a hamiltonian graph? Is there a cycle capable of touching all the vertices and go back
to the starting point?

_Does this problem belong to NP?_ YES
We need to plan a **verification algorithm**: Basic verification of a cycle!
* Input: `Graph G`, `Certificate c`
* Output: 
  * `Yes`
  * `No`, **means that the given certificate is not sufficient or not correct**

![Ex Hamiltonian Graph](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exhamiltongraph.png?raw=True)

In this case, as a certificate we can use a sorted sequence of vertices (permutation of n = |V| vertices).
This permutation identifies the path along the graph G, which should represent the hamiltonian cycle.

Verification Steps:
* The **problem now is REDUCED to the verification of existence of edges connecting the path/cycle**!
* p = <2,4,3,1> -> if (2,4),(4,3),(3,1),(1,2) belong to G.E, then it's verified

The following algorithm is an attempt of mine for an algorithm, it is not verified to work.
```python
HAMILTONIAN_GRAPH(Graph G, Permutation A):
    if(|G.V| = |A.V| AND (A[0],A[|G.V|-1])∈G.E):
        for i=1 to |G.V|-1:
            if(A[i-1]==A[i] OR (A[i-1],A[i])∉G.E):
                return False
        return True
    return False
```

We will later see why this is an NPC problem.

### Clique - NPC
The problem: Is there a clique in G with k vertices?

_Does this problem belong to NP?_ YES
We need to plan a **verification algorithm**: Basic verification of a Clique!
* Input: `((Graph G, Integer k), (Clique C))` representing the Certificate c
* Output: `Yes` or `No`

Verification Steps:
1. |C| = k 
2. Verify that for every u,v (such that u!=v) in C there exist an edge (u,v) in E. 

Complexity: T(Clique) = O(|C|^2)

The following algorithm is an attempt of mine for an algorithm, it is not verified to work.
```python
CLIQUE(Graph G, Int k, Clique C)
    if(|C| == k):
        for u,v ∈ C:
            if(u==v OR (u,v)∉G.E):
                return False
        return True      
    return False
```

Mind that the algorithm of verification for the clique problem IS NOT the GREEDY_CLIQUE() algorithm!
The latter is a solution algorithm.

The Greedy algorithms do not allow for any error backtracking, so we cannot correct our errors! It would fail with
a graph like the following one:

![exfailclique](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exfailclique.png?raw=True)

We will later see why this is an NPC problem.

--

## Class CO-NP
The **class NP** consists of those decision problems **whose complements** that are **“verifiable” in polynomial time O(n^k)**.

### Complement of a (Decision) Problem
P^n (or P negate), is the complement of a problem P (We cannot show the proper symbol in a markdown). It is basically
**the negation of a decision problem**, where the **goal is to obtain an Instance-No of a problem**.

This impacts on the complexity!

#### Complement of Hamiltonian Graph
The problem: Is the graph a NON-hamiltonian graph?
* `Yes`
* `No`, it is a Hamiltonian graph.

![ex Non Hamiltonian Graph](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exnonhamgraph.png?raw=True)

_Does this problem belong to NP?_ **NO**
A possible Certificate could be represented by **all the possible cycles**, so the all the possible permutations of vertices.
The algorithm shall verify each one of them!
Therefore, an algorithm exists! But the T(best): Ω(n!), which is super-exponential!