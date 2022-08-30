# Ex 1

![Exercise 1](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex1.png?raw=TRUE)

What we know:
1) By definition of polynomial reduction, if P1, P2 are two problems such that:
   * P2 ∈ NP & P1 <=p P2 stands true --> P1 ∈ NP.
   * Mind that, we must have a POLYNOMIAL algorithm that maps ALL the instances of P1 to equivalent instances of P2
2) P ⊆ NP, trivially
3) **NEG_CYCLE ∈ P, NEG_CYCLE ∈ NP**.
    1) In polynomial time we can tell where there exists a negative-weight cycle inside a given graph, thanks to Bellman-Ford.
       1) BF checks and returns FALSE when negative cycles are present, namely when after RELAX() on every edge
          there are still estimates larger than the real distances.
4) **CLIQUE ∈ NP, CLIQUE ∈ NPC***
   1) By Cook's Theorem and Cook's property, it was proven that CIRCUIT_SAT ∈ NPC and CIRCUIT_SAT <=p SAT <=p SAT-3-CNF.
   2) Clique ∈ NP, we can easily write a polynomial algorithm that checks whether an instance-yes is a clique, given a certificate.
   3) To demonstrate SAT-3-CNF <=p CLIQUE (and CLIQUE <=p SAT-3-CNF)
      1) We can create a graph that satisfies the following condition from a SAT-3-CNF statement:
         * The count of literals is equal to |V|
         * For each clause (3), we can create a group of vertices.
         * We trace edges between vertices in different groups, only if they are not the negation of each other.
      2) It can be demonstrated that the entry statement ϕ = C1^ C2 ^ C3 is satisfiable i.f.f. inside the graph there 
      exists a clique with 3 vertices, which is trivial to demonstrate.
      3) Now, for those vertices belonging to one of the cliques, we must find a configuration of values (X1, X2, X3) 
      such that ϕ is satisfiable.
5) **ISOM_GRAPH ∈ NP, ISOM_GRAPH ∈ NPI**


## Solution

Let's try and resolve the problem through the F.T. of NPC:

F.T. of NPC tells us: **P** ∩ NPC != Ø : **P** = NP, then we need to demonstrate it.
* Hypothesis: ∃P' ∈ **P** ∩ NPC, if there exists at least one instance of a problem for which this stands true.
* Thesis: **P** = NP, then they coincide.
   1) CASE 1: **P** ⊆ NP, trivially
   2) CASE 2: If ∀Q ∈ NP : Q ∈ **P**, then NP⊆P
      * Q ∈ NP, trivially
      * P' ∈ NPC, trivially
      * ∀Q ∈ NP : Q <=p P', by definition of NPC
      * Q <=p P' ∈ **P**, by hypothesis
      * Q ∈ **P**, by transitivity


### If NEG_CYCLE <=p CLIQUE --> P = NP [FALSE]

If we found out that NEG_CYCLE <=p CLIQUE, we would obtain 
that all P problems (which are also in NP) are reducible to NPC problems. 

For the F.T. of NPC, we just need to verify that NEG_CYCLE <=p CLIQUE ∈ **P**:
* _NEG_CYCLE <=p CLIQUE is trivially true_, by definition NPC;
* But _CLIQUE ∈ P is false_, there is no polynomial solving algorithm as of today for CLIQUE.

The fact that any problem in P, is polynomially reducible to any problem in NPC, tells us nothing regarding the nature of the set P∩NPC,
which keeps being empty by hypothesis. Therefore `If NEG_CYCLE <=p CLIQUE` is not sufficient to imply `P = NP`.


### If ISOM_GRAPH <=p CLIQUE --> P = NP [FALSE]

If we found out that ISOM_GRAPH <=p CLIQUE, we would obtain that all NPI problems are
reducible to NPC problems. 

For the F.T. of NPC, we just need to verify that ISOM_GRAPH <=p CLIQUE ∈ **P**:
* ISOM_GRAPH <=p CLIQUE is trivially true, by definition NPC;
* But _CLIQUE ∈ P has not been demonstrated yet_, so there is no polynomial solving algorithm as of today for CLIQUE.

The fact that any problem in NPI, is polynomially reducible to any problem in NPC, tells us nothing regarding the nature of the set P∩NPC,
which keeps being empty by hypothesis. Therefore `If ISOM_GRAPH <=p CLIQUE` is not sufficient to imply `P = NP`.

### If CLIQUE <=p ISOM_GRAPH --> P = NP [FALSE]

If we found out that CLIQUE <=p ISOM_GRAPH, we would obtain that all NPC problems are reducible to NPI problem.  

For the F.T. of NPC, we just need to verify that CLIQUE <=p ISOM_GRAPH ∈ **P**:
* ISOM_GRAPH ∈ NPC is unknown for the time being, trivially since ISOM_GRAPH ∈ NPI;
* CLIQUE <=p ISOM_GRAPH has not been demonstrated yet. It has not been demonstrated yet that an NPC
problem can be polynomially reduced to a NP problem.
* ISOM_GRAPH ∈ **P** is false, trivially there is no polynomial solving algorithm as of today for ISOM_GRAPH.

The fact that any problem in NPC, is polynomially reducible to any problem in NPI, tells us nothing regarding the nature 
of the set P∩NPC, which keeps being empty by hypothesis. Therefore `If CLIQUE <=p ISOM_GRAPH` is not sufficient to imply `P = NP`.


### If CLIQUE <=p NEG_CYCLE --> P = NP [TRUE]

If we found out CLIQUE <=p NEG_CYCLE, we would obtain that all NPC problems are reducible to P problems. 
Knowing all NPC problems are NP, we would have a way to make P and NP coincide.

For the F.T. of NPC, we just need to verify that CLIQUE <=p NEG_CYCLE ∈ **P**:
* NEG_CYCLE ∈ **P** is true, trivially.
* CLIQUE <=p NEG_CYCLE, it has not been demonstrated yet that an NPC
problem can be polynomially reduced to a P problem, but it would be more than enough to make P = NP;

The fact that any problem in NPC, is polynomially reducible to any problem in P, tells us exactly what we needed regarding the nature
of the set P∩NPC, which would not be empty. Therefore `If  CLIQUE <=p NEG_CYCLE` is sufficient to imply `P = NP`.


---

# Ex 2

![Exercise 2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex5.jpg?raw=TRUE)


## Solution - Part 1
Polynomial Reducibility: a binary relation between two decision problems P(1), P(2).
Given P(1) and P(2), we can say that P(1) is polynomially reducible to P(2), `P(1) <=p P(2)` i.f.f:
1. There exists a polynomial algorithm A (such that T(A)=O(n^k))
2. A "maps"/transforms the Instances of P(1) in equivalent Instances of P(2).

NPC & "<=p" Properites:
* Reflective property is valid between NPC problems? 
  * _If every problem in NPC is in relation with itself_
  * We can trivially use the identity function as our mapping algorithm!
* Transitive property is valid between NPC problems?
  * _Given three problems in NPC (p1, p2, p3), if there is a relation between (p1,p2) and one between (p2,p3) there must be one between (p1,p3)._
  * We know, by definition of NPC, that all of them are in NP and all problems in NP must be polynomially reducible to each one of them.
  * Then, if we have p1 <=p p2 and p2 <= p3, we surely have p1 <= p3.
  * The transitive property is valid.
* Symmetric property is valid between NPC problems 
  * _If given two problems in NPC such that P(1) <=p P(2), it is true that P(2) <=p P(1)_
  * We know, by Cook's property, that a problem P' is in NPC if it is in NP and there exist another problem P'' in NPC such that P''<=P'.
  * We can transform an instance of SAT_3_CNF in an instance of CLIQUE (with some constraints) and viceversa.


## Solution - Part 2
We know P' and Q are in NP, and P <=p Q:
1. They are verifiable in polynomial time O(n^k)
2. P is polynomially reducible to Q
   * There exists a mapping algorithm A:P'--> Q that maps all P instances to Q instances 
   in polynomial time O(n^k).

### If Q is solvable in O(n^2) --> P' is solvable in O(n^2)? - FALSE + COUNTEREXAMPLE
It is not sufficient to know that Q is solvable in O(n^2) for P' to be solvable in O(n^2).
* We have no clue whether the mapping algorithm A:P'-->Q has time complexity equal to O(n^k), with k<=2.

If k>2 this statement loses its validity: We could construct an algorithm A for P'

Counterexample:
If the


### If Q is solvable in O(k^n) --> P' is solvable in O(k^n)? - TRUE + DEMONSTRATION
We know that we can create an algorithm A for P' that is composed of:
* The mapping algorithm in from P to Q, which is in O(n^k) by definition of polynomial reducibility;
* The solving algorithm for Q's instances, which is in O(j^n) by hypothesis;

The algorithm A would have T(A) = O(n^k) + O(j^n). However, asymptotically this equals to T(A) = O(j^n) 
since it can be demonstrated that (j^n) grows more rapidly than (n^k)!



### If Q is in NPC --> P' is in NPC? - FALSE + COUNTEREXAMPLE
By definition of NPC, we know that a problem Q is in NPC if it is in NP and all problems in NP are polynomially
reducible to Q.

This means that given:
* P' in NP
* P' <=p Q
* Q in NPC

We can just confirm that Q is NPC, yet another problem P in NP is polynomially reducible to Q. However, the premise
of the implication is not sufficient to demonstrate that P' is in NPC.

Ad-Absurdum, By saying t


### If P1 is in NPC --> Q is in NPC ? - TRUE + DEMONSTRATION
The implication is true.

**Demonstration: We need to prove that P1 <=q Q ∈ NPC, for this to be true!**

By hypothesis and premise the following statements are true:
* **Q is in NP**
* **P1 is in NPC**, therefore by definition of NPC:
    * P1 ∈ NP
    * ∀ P2 ∈ NP : P2 <=p P1
* **P1 <=q Q**;

By **Applying the definition of NPC**:
1. We need to show that Q is verifiable in polynomial time: **true by hypothesis**
2. We need to demonstrated that all problems in NP are polynomially reducible to Q.
  * Since this is a _tedious process_, Cook's property helps us!

By Cook's property, Q ∈ NPC iff:
1. Q ∈ NP, true by hypothesis!
2. ∃P1 ∈ NPC : P1 <=p Q, yet to be demonstrated!

We need to find a way to **polynomially reduce a known NPC problem, in this case P1, to Q**. This
will prove that Q is an NPC problem by transitivity!

To demonstrate point number 2 of Cook's property:
* ∀P2 ∈ NP : P2 <=p Q, by definition of NPC (if we imply Q is in NPC)
* **P1 ∈ NPC**, by hypothesis
  * **P1 ∈ NP**, by hypothesis & definition of NPC
  * ∀ P2 ∈ NP : P2 <=p P1, by definition of NPC
* **P1 <=p Q**, by hypothesis, if asked for an example demonstrate CLIQUE (P2=CIRCUIT_SAT <=p P1=SAT-3-CNF <=p Q=CLIQUE)
* P2 <=p P1 <=p Q --> **P2 <=p Q**, by transitivity Q is in NPC

---

# Ex 3

![Exercise 3](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex3.png?raw=TRUE)

## Solution




---

# Ex 4

![Exercise 4](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/NP/Ex4.png?raw=TRUE)

## Solution

