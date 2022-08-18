# Class NPC or NP-Complete
The **class NPC** consists of those **decision problems** that are in **NP** and is as
“hard” as any problem in NP.

P belongs to NPC class if:
* P∈NP
* ∀P'∈NP : P'⊆P(polynomial)


∀u,v∈𝐶 -> ∃(u,v)


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