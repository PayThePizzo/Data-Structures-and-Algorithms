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

## Solution

Let's try and resolve the problem: Demonstrate the F.T. of NPC:

F.T. of NPC tells us: **P** ∩ NPC != Ø : **P** = NP, then we need to demonstrate it.
* Hypothesis: ∃P' ∈ **P** ∩ NPC
* Thesis: **P** = NP
    1) CASE 1: **P** ⊆ NP, trivially
    2) CASE 2: If ∀Q ∈ NP : Q ∈ **P**, then NP⊆P
        * Q ∈ NP, trivially
        * P' ∈ NPC, trivially
        * ∀Q ∈ NP : Q <=p P', by definition of NPC
        * Q <=p P' ∈ **P**, by hypothesis
        * Q ∈ **P**, by transitivity

> If NEG_CYCLE <=p CLIQUE --> P = NP, FALSE

We just need to verify that NEG_CYCLE <=p CLIQUE ∈ **P**:
* _NEG_CYCLE <=p CLIQUE is true_, by definition NPC;
* But _CLIQUE ∈ P is false_, there is no polynomial solving algorithm as of today for CLIQUE. It is not sufficient for
NEG_CYCLE to be polynomially reducible to CLIQUE, CLIQUE must belong to P too!

> If ISOM_GRAPH <=p CLIQUE --> P = NP, FALSE

We just need to verify that ISOM_GRAPH <=p CLIQUE ∈ **P**:
* ISOM_GRAPH <=p CLIQUE is true_, by definition NPC;
* But _CLIQUE ∈ P is false_, there is no polynomial solving algorithm as of today for CLIQUE. It is not sufficient for
ISOM_GRAPH to be polynomially reducible to CLIQUE, CLIQUE must belong to P too!
* Moreover, ISOM_GRAPH is in NPI and no polynomial solving algorithm has be found for it.

> If CLIQUE <=p ISOM_GRAPH --> P = NP, FALSE

We just need to verify that:
1) ISOM_GRAPH ∈ NPC
   * ISOM_GRAPH ∈ NPC is unknown for the time being, ISOM_GRAPH ∈ NPI;
2) CLIQUE <=p ISOM_GRAPH ∈ **P**:
   * CLIQUE <=p ISOM_GRAPH is false, it has not been demonstrated yet that an NPC
     problem can be polynomially reduced to a NP problem. 
   * ISOM_GRAPH ∈ **P** is false, there is no polynomial solving algorithm as of today for ISOM_GRAPH.

> If CLIQUE <=p NEG_CYCLE --> P = NP, TRUE

We just need to verify that:
1) NEG_CYCLE ∈ NPC is true_, by definition NPC;
2) CLIQUE <=p NEG_CYCLE ∈ **P**:
   * CLIQUE <=p ISOM_GRAPH is false it has not been demonstrated yet that an NPC
     problem can be polynomially reduced to a NP problem;
   * NEG_CYCLE ∈ **P** is true, trivially.

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