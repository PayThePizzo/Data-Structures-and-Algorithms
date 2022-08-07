# NP-Complete Problems
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

The **class P** consists of those problems that are solvable in polynomial time. They
are problems that can be solved in time O(n^k) for some
constant k, where n is the size of the input to the problem.
* However, it can contain untreatable problems (since the algorithm might take
too long, and it is not usable in real life)

The **class NP** consists of those problems that are “verifiable” in
polynomial time.

NPC—and we refer to it as being **NP-complete**, if it is in NP and is as
“hard” as any problem in NP.

### Problem
We want to categorize the <mark> the complexity of a problem</mark>. 
But first let's define a "problem".

A problem is a binary relation between two sets (typically large).
> P ⊆ I x S 
* I, the instances' set 
* S, the solutions' set

Problems have two subcategories:
* _Undecidable_, for which it is not possible to write an algorithm
  * The alt problem: Given a program and some data, we want to know if that 
  particular program will stop (exit loop and stop) at some point.
    * We cannot construct an algorithm capable of evaluating this as it would
    need to mimic the input program. It is a paradox.
* _Decidable_, for which it is possible to write an algorithm
  * Treatable: algorithms that have polynomial time **O(n^k)**, **Class P algorithm**
  * Untreatable: algorithms which might take too long **O(k^n)**, and are not usable
  in real life.