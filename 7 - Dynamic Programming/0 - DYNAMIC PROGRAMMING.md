# Dynamic Programming
It is an <mark>algorithm design technique</mark> used to recursively divide a 
problem in smaller sub-problems.

Dynamic programming, like the divide-and-conquer method, solves problems by
combining the solutions to subproblems. 

As we saw, divide-and-conquer algorithms partition the problem into disjoint subproblems, 
solve the subproblems recursively, and then combine their solutions to solve the original problem. 

In contrast, dynamic programming applies when the subproblems overlap—that is, when subproblems share subsubproblems. In this context,
a divide-and-conquer algorithm **does more work than necessary**, repeatedly solving the common subsubproblems

We typically apply dynamic programming to <mark>optimization problems.</mark> 

Such problems can have many possible solutions. Each solution has a value, and we wish to
find a solution with the optimal (minimum or maximum) value. 

We call such a solution an optimal solution to the problem, as opposed to the optimal solution,
since **there may be several solutions that achieve the optimal value**.

### Dynamic Programming

When developing a dynamic-programming algorithm, we follow a sequence of
four steps:
1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information


### Property of Optimal Substructure
Optimal solutions to a problem incorporate optimal solutions to related sub-problems, 
which we may solve independently.

In general, we adopt two main strategies (which have the same complexity) to achieve this: 
* Top-down
  * Saves the solved problems inside a vector
* Bottom-up.
  * Starts from simpler problems and goes towards the solution
  

