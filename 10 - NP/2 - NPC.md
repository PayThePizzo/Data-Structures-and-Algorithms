# Class NPC or NP-Complete
The **class NPC** consists of those **decision problems** that are in **NP** and is as
“hard” as any problem in NP.

P belongs to NPC class if:
* P∈NP
* ∀P'∈NP : P'⊆P(polynomial)


∀u,v∈𝐶 -> ∃(u,v)


## Polynomial Reducibility (between problems)
A binary relation between two decision problems (it can be extended to non-decision problems).

Given P(1) and P(2), we can say that P(1) is polynomially reducible to P(2) `P(1)<=P(2)` i.f.f there exists
a polynomial algorithm A (such that T(A)=O(n^k)) which "maps"/transforms the Instances of P(1) in equivalent Instances of P(2).

![poly red](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/polyred.png?raw=True)