# Dynamic Programming
It is an <mark>algorithm design technique</mark> used to recursively divide a 
problem in smaller sub-problems.

Dynamic programming, like the divide-and-conquer method, solves problems by
combining the solutions to subproblems. 

As we saw, divide-and-conquer algorithms partition the problem into disjoint subproblems, 
solve the subproblems recursively, and then combine their solutions to solve the original problem. 

In contrast, dynamic programming applies when the subproblems overlap that is, when subproblems share subsubproblems. 
In this context, a divide-and-conquer algorithm **does more work than necessary**, repeatedly solving the common subsubproblems

We typically apply dynamic programming to <mark>optimization problems.</mark> 

Such problems can have many possible solutions. Each solution has a value, and we wish to
find a solution with the optimal (minimum or maximum) value. 

We call such a solution an optimal solution to the problem, as opposed to the optimal solution,
since **there may be several solutions that achieve the optimal value**.

### Property of Optimal Substructure
Optimal solutions to a problem incorporate optimal solutions to related sub-problems,
which we may solve independently.

---
### Steps of Dynamic Programming

When developing a dynamic-programming algorithm, we follow a sequence of
four steps:
1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information

---
## Time-Memory Trade-Off

The dynamic-programming method works as follows. 
* Having observed that a naive recursive solution is inefficient because it solves the same subproblems 
repeatedly, we arrange for each subproblem to be solved only once, saving its solution. 
* If we need to refer to this subproblem’s solution again later, we can just look it 
up, rather than recompute it. Dynamic programming thus uses additional memory
to save computation time; it serves an example of a **time-memory trade-off**. 
* The savings may be dramatic: an exponential-time solution may be transformed into a
polynomial-time solution. A dynamic-programming approach runs in polynomial
time when the number of distinct subproblems involved is polynomial in the input
size and we can solve each such subproblem in polynomial time

### Top-Down with Memorization
In this approach, we write the procedure recursively in a natural manner, but modified to save the result of
each subproblem (usually in an array or hash table). 
1. The procedure now, first checks to see whether it has previously solved this subproblem. 
   1. If so, it returns the saved value, saving further computation at this level;
      1. We say that the recursive procedure has been **memorized**; it “remembers” what results it has computed previously.
   2. If not, the procedure computes the value in the usual manner. 

### Bottom-Up Method
This approach typically depends on some natural notion of the “size” of a subproblem, 
such that solving any particular subproblem depends only on solving “smaller” subproblems. 

We sort the subproblems by size and solve them in size order, **smallest first**. 
* When solving a particular subproblem, we have already solved all of the smaller subproblems its
solution depends upon, and we have saved their solutions. 
* We solve each subproblem only once, and when we first see it, we have already solved all of its
prerequisite subproblems

These two approaches yield algorithms with the same asymptotic running time, except in unusual circumstances 
where the top-down approach does not actually recurse to examine all possible subproblems. 
The bottom-up approach often has much better constant factors, since it has less overhead for procedure calls

---

### Extra Credits
* [1] Mainly take from Chapter 15 of Introduction to Algorithms (see main README.md)