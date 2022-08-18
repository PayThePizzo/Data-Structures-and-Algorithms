### Intro
Almost all the algorithms we have studied thus far have been
polynomial-time algorithms: on inputs of size n, their worst-case
running time is O(n^k) for some constant k. You might wonder whether all
problems can be solved in polynomial time. The answer is no.

However, there is an interesting class of problems, called
the “NP-complete” problems, whose status is unknown.
No polynomial-time algorithm has yet been discovered for an
NP-complete problem, nor has anyone yet been able to prove that no
polynomial-time algorithm can exist for any one of them.

Several NP-complete problems are particularly tantalizing because they seem
on the surface to be similar to problems that we know how to solve in polynomial
time. In each of the following pairs of problems, one is solvable in polynomial
time and the other is NP-complete. This is the case for the greedy clique.

---

# Problem
We will focus here on the **complexity of the PROBLEMS**, not the algorithms.

We want to categorize the <mark> the complexity of a problem</mark>. 
But first let's define a "problem".

A problem is a **binary relation between two sets** (typically large).
> P ⊆ I x S 
* I, the set of problem's instances
* S, the set of problem's solutions

Problems have two subcategories:
* _Decidable_, for which it is possible to write an algorithm that **solve them in a finite time-span**
  * Treatable: algorithms that have polynomial time **O(n^k)**, **Class P algorithm**
  * Untreatable: algorithms that have exponential time **O(k^n)**, and are not usable
    in real life. They cannot be reduced to polynomial time.
* _Undecidable_, for which **it is not possible to write algorithms** that **solve them in a finite time-span**
  * We have no clue whether it is possible to find an algorithm that will converge, like the *alt problem*

### Example of Undecidable Problem: The Alt Problem.
Given a program and some data, we want to write an algorithm to that returns:
* `TRUE`, if the program stops at some point, given with the input.
* `FALSE`, else.

We cannot construct an algorithm capable of evaluating this as it would need to mimic the input program. 
It is a paradox.

---

# Classes of Problems
* Optimization Problems
  * Max Clique
* Decision Problems

## Optimization Problems
Many problems of interest are optimization problems, in which each feasible (i.e.,
“legal”) solution has an associated value, and we wish to find a feasible solution
with the best value.

## Decision Problems
The expected answer is a binary, either yes or no for example.
* For a decision problem P, **|S| = 2**. S = S' U S'', such that:
  * S' = { Instances-Yes }
  * S'' = { Instances-No }
  
Examples:
* Given an x and a set A, does x belong to A?
* Given a graph G, is there a _cycle that connects all the vertices in G_ (also called a **Hamiltonian Cycle**)?

### From an optimization problem to a decision problem
Two useful facts about these two classes of problems, are the following ones:
* We usually can **transform** a given **optimization problem to a related decision problem** by imposing a
bound on the value to be optimized.
* **The optimization problem and its decision problem version, belong to the same complexity class**.
It, is easier to demonstrate the class to which a decision problem belongs than an optimization one.
  * A decision problem is untreatable, the optimization version is untreatable too.
  * For the same principle, if there is a polynomial-time solution for a decision problem, there must exist a polynomial
  solution for the optimization problem too, and vice-versa.

#### Example: Max-Clique
The max clique problem (optimization) is related to the clique problem (decision).

Clique:
* Instances: undirected graphs, integer k
* Is there a clique with at least, k vertices? (Y/N).

If there is a polynomial-time solution for _Clique_, there must exist a polynomial
solution for _Max Clique_ too, an.




