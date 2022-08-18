# Decision Problem Classes

## Class P
The **class P** consists of those decision problems that are **solvable in polynomial time O(n^k)**. 
* for some constant k,
* n is the size of the input to the problem.

* However, it can contain untreatable problems (since the algorithm might take
  too long, and it is not usable in real life)

---

## Class NP
The **class NP** consists of those decision problems that are **“verifiable” in polynomial time O(n^k)**.

## A verifiable problem
Given an "Instance-Yes" `i` and a Certificate `c` of a solution, If we can **verify through the certificate that `i` is an Instance-Yes**, 
then the problem is verifiable in polynomial time O(n^k).

When it is not verifiable in polynomial time:
* If verification algorithm we plan, returns `No` for a certain tuple (Instance-Yes i, Certificate c)
  * The certificate is not sufficient or not correct
* If the verification algorithm is not polynomial, trivially.

Ex: It is like verifying a demonstration of an algorithm.

### Hamiltonian Graph
The problem: Is the graph a hamiltonian graph? Is there a cycle capable of touching all the vertices and go back
to the starting point?

_Does this problem belong to NP?_
We need to plan a **verification algorithm**:
* Input: Graph G, Certificate c
* Output: 
  * `Yes`
  * `No`, **means that the given certificate is not sufficient or not correct**

![Hamiltonian Graph]()

In this case, as a certificate we can use a sorted sequence of vertices (permutation of n = |V| vertices).
This permutation identifies the path along the graph G, which should represent the hamiltonian cycle.
The **problem now is REDUCED to the verification of existence of edges connecting the path/cycle**!
* p = <2,4,3,1> -> if (2,4),(4,3),(3,1),(1,2) belong to G.E, then it's verified
* But we still need to consider the complexity!

### Clique
The problem: Is there a clique in G with k vertices?

_Does this problem belong to NP?_
We need to plan a **verification algorithm**:
* Input: Graph G, Integer k
* Output:
  * `Yes`
  * `No`, **means that the given certificate is not sufficient or not correct**


---

## Class NPC or NP-Complete
The **class NPC** consists of those decision problems that are in NP and is as
“hard” as any problem in NP.

P belongs to NPC class if:
* P∈NP
* ∀P'∈NP : P'⊆P(polinomial)


∀u,v∈𝐶 -> ∃(u,v)
