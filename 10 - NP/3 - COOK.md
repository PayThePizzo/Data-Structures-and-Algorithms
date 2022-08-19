# Cook's Theorem - CIRCUIT_SAT ∈ NPC
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

### Step 1 - Trivial
> P∈NP

Let's take CIRCUIT_SAT problem, at the beginning it looks like an NP Problems since a trivial algorithm would be made of:
* As Instance-Yes, we could use a circuit with n entry lines and one output.
* And as certificate, the permutation of entry values to obtain `1`

### Step 2
> ∀P'∈NP : P' <=p CIRCUIT_SAT

Cook had to demonstrate that **any problem in NP is polynomially reducible to CIRCUIT_SAT**!
We will not cover his demonstration here, but the focus idea is useful.

Let's suppose we have P'' a new problem NP, how do we find out if it is NPC too? Applying Cook's demonstration to show
`∀P''∈NP : P'' <=p CIRCUIT_SAT`, would be too long.

Alternatively there is another way:

---

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

### K-CNF
We know that 2-CNF ∈ P, but 3-CNF ∈ NPC!
This is a common event among algorithm a parameter such as k in k-CNF, dictates the complexity of the problem!
* ∀k >= 3, SAT-k-CNF ∈ NPC

---
