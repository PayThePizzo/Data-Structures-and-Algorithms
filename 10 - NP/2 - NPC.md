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
* Implies P' ∈ NPC
  * Implies ∀P''∈NP : P'' <=p P`

We want to demonstrate P = NP:
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

# NPI or NP-Indeterminate
A class of problems which do not belong to NPC (no NPC demonstration was formulated), nor a polynomial algorithm has been found for them.

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

---

## Cook's Theorem - CIRCUIT_SAT ∈ NPC
The satisfiability problem concerns circuit logic. In fact, CIRCUIT_SAT is the case where a circuit produces `1` for a configuration.

> CIRCUIT_SAT ∈ NPC

This is the resulting theorem from Cook's findings. But let's start with some notions of circuit logic.

Imagine having a circuit with n entry lines (2^n possible configurations), and just one output `1` or `0`.
Given a boolean circuit, with n entries and just one output, can we determine all the possible permutations of 
**entry values** such that the output equals `1`?
* An approach could be the TRY-THEM-ALL, but this would bring us to T(CIRCUIT_SAT): Ω(2^n).
* Furthermore, as soon as the circuit changes, we have lost our progresses!
* If we could find a way to reduce the problem to NP, we would be done. However, we will see later that 
it is not our means that limit us, the **problem itself is intrinsically hard** and requires an exponential solution!

Cook starts with the general approach for when we face a new problem: try and understand if this problem 
belongs to NPC class.
1. Step one: `P' ∈ NP`?
2. Step two, the hardest: `∀P''∈NP : P'' <=p P`?, is there another problem reducible to the starting problem?

#### Step 1 - Trivial
> P∈NP

Let's take CIRCUIT_SAT problem, at the beginning it looks like an NP Problems since a trivial algorithm would be made of:
* As Instance-Yes, we could use a circuit with n entry lines and one output.
* And as certificate, the permutation of entry values to obtain `1`

#### Step 2 
> ∀P'∈NP : P' <=p CIRCUIT_SAT

Cook had to demonstrate that **any problem in NP is polynomially reducible to CIRCUIT_SAT**!
We will not cover his demonstration here, but the focus idea is useful.

Let's suppose we have P'' a new problem NP, how do we find out if it is NPC too? Applying Cook's demonstration to show
`∀P''∈NP : P'' <=p CIRCUIT_SAT`, would be too long.

Alternatively there is another way:

## Cook's Property
**P' ∈ NPC** i.f.f.:
1. **P' ∈ NP**
2. **∃P'' ∈ NPC : P'' <=p P'**

### Demonstration
To demonstrate P' ∈ NPC by demonstrating the **definition of NPC**:
1. We need to demonstrate that **P' ∈ NP**
   * Trivially true by _hypothesis_
2. We need to demonstrate that **∀Q ∈ NP : Q <=p P'**, for any problem Q in NP, Q is polynomially reducible to P'
   * `P'' <=p P'`, since we know by _hypothesis_ that any problem in NP is polynomially reducible to P' an NPC problem!
   * **Q <=p P'' <=p P'** --> **Q <=p P'**, Q too is reducible to P by _transitivity_

![Dem notation](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/Demnotat.png?raw=True)


### Example: SAT ∈ NPC
Logical problem concerning the satisfiability of a boolean statement. If we demonstrate, 
like we did before that SAT <=p P', we are done!

![Sat](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/sat.png?raw=True)

Between the possible configuration is there one that makes this statement true (SAT)?
We could find, each time, a configuration. Alternatively we can find a NPC problem reducible to SAT

**SAT ∈ NPC**, Since:
* SAT ∈ NP, trivially
* CIRCUIT_SAT <=p SAT, true
  * It can be demonstrated that for any instance of CIRCUIT_SAT, we can transform it 
  into a SAT instance (but we are not showing it here).

### Example: CNF ∈ NPC
A variant of this problem is the Conjunctive Normal Form, where the boolean statements
are composed of clauses 'C': `ϕ = C1 ^ C2 ^ C3 ^ ... ^ Ck`

Each clause Ci is represented by a disjunction of literals: `Ci = (X1 v NOT(X2) v NOT(X4))`.
They all have different combination of AND/OR/NOT etc...

This kind of statements help us with the problem of finding an Instance-Yes, the result is true i.f.f all the
clauses are true!

So given a statement like the one we saw in SAT, is it possible to transform it into CNF? Yes!!!
Therefore, the verification of SAT for statements in CNF also is an NPC problem.

### Example: 3-CNF ∈ NPC
Each clause Ci in a CNF statement is represented by a disjunction of exactly 3 literals.

It can be demonstrated that any boolean statement can be transformed into 3-CNF! This means:
* SAT <=p SAT-3-CNF
* SAT-3-CNF ∈ NPC

#### K-CNF
We know that 2-CNF ∈ P, but 3-CNF ∈ NPC! 
This is a common event among algorithm a parameter such as k in k-CNF, dictates the complexity of the problem!
* ∀k >= 3, SAT-k-CNF ∈ NPC

---







