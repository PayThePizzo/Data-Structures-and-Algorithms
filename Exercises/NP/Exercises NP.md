# Ex 1

![Exercise 1](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex1.png?raw=TRUE)

What we know:

1) **NEG_CYCLE ∈ P**, similarly to Bellman-Ford.
    1) In polynomial time we can tell where there exists a negative-weight cycle inside a given graph.
    2) BF checks and returns FALSE when negative cycles are present, namely when after RELAX() on every edge
       there are still estimates larger than the real distances.
    3) Therefore, **NEG_CYCLE ∈ NP** and it is polynomially reducible to any problem in NPC.
2) **CLIQUE ∈ NPC**
   1) By Cook's Theorem and Cook's property, it was proven that CIRCUIT_SAT ∈ NPC and CIRCUIT_SAT <=p SAT <=p SAT-3-CNF.
   2) Clique ∈ NP, we can easily write an exponential algorithm that checks whether an instance-yes is a clique, given a certificate.
   3) To demonstrate SAT-3-CNF <=p CLIQUE (and CLIQUE <=p SAT-3-CNF)
      1) We can create a graph that satisfies the following condition from a SAT-3-CNF statement:
         * The count of literals is equal to |V|
         * For each clause (3), we can create a group of vertices.
         * We trace edges between vertices in different groups, only if they are not the negation of each other.
      2) It can be demonstrated that the entry statement ϕ = C1^ C2 ^ C3 is satisfiable i.f.f. inside the graph there 
      exists a clique with 3 vertices, which is trivial to demonstrate.
      3) Now, for those vertices belonging to one of the cliques, we must find a configuration of values (X1, X2, X3) 
      such that ϕ is satisfiable.
3) **ISOM_GRAPH ∈ NPI**
4) If P1, P2 are two problems and P1 <=p P2 stands true, then P1 belongs to the same class of P2.

## Solution

Let's try and resolve the problem: If X <=p Y,  then P = NP is true?

> If NEG_CYCLE <=p CLIQUE --> P = NP, FALSE

If we found an instance of NEG_CYCLE that is polynomially reducible to CLIQUE we would obtain that all P problems 
(which are also in NP) are reducible to NPC problem.  However, this is not sufficient because CLIQUE would have to be 
solvable in polynomial time which is not the case for now.

> If ISOM_GRAPH <=p CLIQUE --> P = NP, FALSE

If we found an instance of ISOM_GRAPH that is polynomially reducible to CLIQUE we would obtain that all NPI problems are
reducible to NPC problem. However, this is not sufficient because CLIQUE would have to be solvable in polynomial time
which is not the case for now.

> If CLIQUE <=p ISOM_GRAPH --> P = NP, FALSE

If we found an instance of CLIQUE that is polynomially reducible to ISOM_GRAPH, we would obtain that all NPC problems are
reducible to NPI problem, which is trivial since CLIQUE and ISOM_GRAPH are in NP and can be polynomially reduced 
symmetrically between them. However, this is not sufficient because ISOM_GRAPH would have to be solvable in polynomial time
which is not the case for now.

> If CLIQUE <=p NEG_CYCLE --> P = NP, TRUE

If we found an instance of CLIQUE that is polynomially reducible to NEG_CYCLE, then CLIQUE ∈ **P** and we would have found
a way to reduce all NPC problems to the class P. Knowing all NPC problems are NP, we found a way to make P and NP coincide.


---

# Ex 2

![Exercise 2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex2.png?raw=TRUE)

## Solution




---

# Ex 3

![Exercise 3](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex3.png?raw=TRUE)

## Solution




---

# Ex 4

![Exercise 4](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex4.png?raw=TRUE)

## Solution