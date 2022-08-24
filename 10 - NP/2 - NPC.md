### Intro
We need to study some notation before getting to the point!

## Polynomial Reducibility (between problems) - <=p
A **binary relation between two decision problems** (it can be extended to non-decision problems).

Given P(1) and P(2), we can say that P(1) is polynomially reducible to P(2) `P(1) <=p P(2)` i.f.f 
1. There exists a **polynomial** algorithm A (such that T(A)=O(n^k)) 
2. A **"maps"**/transforms the Instances of P(1) in **equivalent** Instances of P(2).

![poly red](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/polyred.png?raw=True)

By applying A, we obtain a result that preserves the positivity/negativity of the instances!

![poly red2](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/polyred2.png?raw=True)

### Properties
Since it is a binary relation, we want to know if certain mathematical properties can be found here too.

Is <=p reflexive? If it is then every object is in relation with itself.
It is! The mapping algorithm would be the identity function.

> <=p is REFLEXIVE!

Is <=p transitive? If given three objects (p1, p2, p3) if there is a relation between (p1,p2) and one between (p2,p3)
there must be one between (p1,p3).

Correspondingly, if `p1 <=p p2`, and `p2 <=p p3` then `p1 <=p p3`?

Let's say we have:
* `A(1,2): I(1)->I(2)`, which is polynomial.
* `A(2,3): I(2)->I(3)`, which is polynomial.

![trans red](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/transred.png?raw=True)

There must exist`A(1,3): I(1)->I(3)`, which is polynomial, by _concatenation_!
* Obviously polynomial (sum of two polynomial algorithms)
* It is like applying A(2,3) to the result of A(1,2)!

![trans 13](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/a13.png?raw=True)

> <=p is TRANSITIVE!

Is <=p symmetric? If given `P(1) <=p P(2)`, is it true that `P(2) <= P(1)? **NO**
* Only for NPC problems.

If it was, then we would have **P=NP** which is yet to be proved.

> <=p is NOT SYMMETRIC

---

# Class NPC or NP-Complete
A problem P belongs to NPC class if:
1) `P∈NP`, **verifiable in polynomial time**
   1) NPC ⊆ NP
2) `∀P'∈NP : P' <=p P`(polynomial), closed to the polynomial reducibility
   1) We need to **verify** that **all the problems in NP, are polynomially reducible to the problem P**.
   2) This means that all NPC problems can be reduced between them, by _point 2_. If we solve just one in polynomial time, then
      all of them must have a polynomial time solution.
   3) As of today, no NPC problem was found to be reducible in polynomial time.
   
## Fundamental Theorem of NP-Completeness
> P∩NPC != Ø : P = NP

They are very hard problems, not solvable in polynomial time. However, we do not know if they are untreatable!

### Demonstration
Hypothesis: ∃P' ∈ P∩NPC, At least one problem for which this is true.
* Implies P' ∈ P
* Implies P' ∈ NPC --> ∀P''∈NP : P'' <=p P`

Thesis: We want to demonstrate P = NP:
1) Case 1: **P⊆NP**, trivially true!
   * The verification algorithm mimics that solving algorithm.
2) Case 2: NP⊆P? Only if we demonstrate that **∀Q ∈ NP : Q ∈ P**, for every problem Q, Q belongs to P too!
   * **Q ∈ NP**, Let Q be a generic problem of NP
   * **P' ∈ NPC**, by _hypothesis_
   * **∀Q∈NP : Q <=p P'**, by _point 2 of NPC_, Q can be reduced to P'
   * **Q <=p P' ∈ P**, by _hypothesis_
   * **Q ∈ P**, by _transitivity_
     * There is a polynomial algorithm that maps Q to P.
     * There is another polynomial algorithm that solves P.
     * There must be a polynomial algorithm that solves Q ∈ P
     
---

# NPI or NP-Intermediate
A class of problems for which no NPC demonstration was formulated, nor a polynomial algorithm has been found for them.

Ex: Isomorphism of Graphs

![NPC](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/npc.png?raw=True)

![NPC Topology](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/npctopology.png?raw=True)

### Isomorphism of Graphs - NPI
Given G1 and G2, is G2 an isomorphism of G2?

#### Demonstration that Isom. of G. is in NP
TBD

---

# Is NPC = Ø?
The notion of NP-completeness was proposed in 1971 by Cook, who gave
the first NP-completeness proofs for formula satisfiability and 3-CNF satisfiability.

By defining a set, we suppose that it is not empty!
When it was first formulated, it was not clear whether it was empty or not, Cook identified the first NPC
problem which implied NPC != Ø.






