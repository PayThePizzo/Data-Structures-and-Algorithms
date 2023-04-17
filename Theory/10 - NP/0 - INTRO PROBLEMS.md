# NP-Completeness Theory

Almost all the algorithms we have studied thus far have been
polynomial-time algorithms: on inputs of size $n$, their worst-case
running time is $\mathcal{O}(n^{k})$ for some constant $k$. 

You might wonder whether all problems can be solved in polynomial time. The answer is no.

However, there is an interesting class of problems, called
the *NP-complete* problems, whose status is unknown.
1. No polynomial-time algorithm has yet been discovered for an NP-complete problem, 
2. Nor has anyone yet been able to prove that no polynomial-time algorithm can exist for any one of them.

Several NP-complete problems are particularly tantalizing because they seem
on the surface to be similar to problems that we know how to solve in polynomial
time. In each of the following pairs of problems, one is solvable in polynomial
time and the other is NP-complete. 

This is the case for the [greedy clique](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Theory/9%20-%20Greedy%20Algorithms/1.1%20-%20GREEDY%20CLIQUE.md).

We will focus here on the **complexity of PROBLEMS** (classes of complexity), which is not the complexity of algorithms
(computational complexity).

---

## Problems
We want to categorize the complexity of a problem. But first, let's define a "problem".

> A problem $P$ is a **binary relation between two sets** $I, S$ (typically large).

```math
P \subseteq I \times S \text{, where} \left\{\begin{matrix}
I & \text{set of problem's instances} \\
S & \text{set of problem's solutions}  \\
\end{matrix}\right.
```

There are many ways to classify problems, such as
* Hierarchy based on decidability
* Types of problem

---

## Classes of Problems - Decidability :
* _Decidable_, **for which it is possible to write an algorithm that solves them in a finite time-span**
  * Treatable: algorithms that have polynomial time $\mathcal{O}(n^{k})$
  * Untreatable: algorithms that have exponential $\mathcal{O}(k^{n})$ o super-exponential time $\mathcal{O}(n!)$, and are not usable
  in real life. They cannot be reduced to polynomial time.
* _Undecidable_, for which **it is not possible to write algorithms** that **solve them in a finite time-span**
  * We have no clue whether it is possible to find an algorithm that will converge, like the *alt problem*

### Example of Undecidable Problem: The Alt Problem.
Given a program and some data, we want to write an algorithm to that returns:
* `TRUE`, if the program stops at some point, given with the input.
* `FALSE`, else.

We cannot construct an algorithm capable of evaluating this as it would need to mimic the input program, namely never
returning an answer if it does not stop. It is a paradox.

We cannot reduce the hardness of a problem on the presence of a solution at a certain time in history!
We need some classification!

---

## Classes of Problems - Types:
Given the definition given above, we can initially identify three classes of problems:
* Search Problems
  * Spanning Trees, Walks between nodes, ...
* Optimization Problems
  * Max Clique
  * MST
* Decision Problems

### Search Problems
These problems, given an instance $x$, require to find a solution $s$, such that $(x,s) \in P$ 

### Optimization Problems
These problems, given an instance $x$, require finding **the best** solution $s$ (within all possible solutions), 
such that $(x,s) \in P$

Many problems of interest are optimization problems, in which each feasible (i.e.,
“legal”) solution has an associated value, and we wish to find a feasible solution
with the best value.

### Decision Problems
These problems, expect a binary answer, (i.e. either yes or no). They usually require to verify some condition.

```math
P_{decision} \subseteq I \times S \text{, where} \left\{\begin{matrix}
I  \\
S = S_{yes} \cup S_{no} \\
\end{matrix}\right.
```
  
Examples:
* Given an x and a set A, does x belong to A?
* Given a graph G, is there a _cycle that connects all the vertices in G_ (also called a **Hamiltonian Cycle**)?

---

## From an optimization problem to a decision problem
Two useful facts about these two classes of problems, are the following ones:

> FACT 1: It is, usually, possible to **transform** a given **optimization problem to a related decision problem** by imposing a
bound on the value to be optimized, and vice-versa.

> FACT 2: **The optimization problem and its decision problem version, belong to the same complexity class**.

It, is easier to demonstrate the class to which a decision problem belongs than an optimization one.
* A decision problem is untreatable, the optimization version is untreatable too.
* For the same principle, if there is a polynomial-time solution for a decision problem, there must exist a polynomial
solution for the optimization problem too, and vice-versa.

### Example: Max-Clique
The max clique problem (optimization) is related to the clique problem (decision).

Clique:
* Instances: undirected graphs, integer $k$
* Is there a clique with at least, $k$ vertices? (Y/N).

If there is a polynomial-time solution for _Clique_, there must exist a polynomial
solution for _Max Clique_ too, and vice-versa.




