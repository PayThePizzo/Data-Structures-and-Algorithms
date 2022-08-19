# How to approach a NPC Problem
What to do when we face an untreatable problem that looks like an NPC Problem?

## 1) Develop an approximation algorithm - Suboptimal Solution
Sometimes algorithms that go close to a solution, based on a tolerance parameter, are acceptable. It can be
demonstrated that an approximation of the solution (following an arbitrary tolerance parameter) can be found.


Ex: Travelling Salesman Problem

However, there exists problems like the Clique problem, are NPC even if approximated.

## 2) Particular cases
Are we facing some particular cases? Some instances can be tackled in polynomial time!

NPC theory considers T(worst) which focuses on the worst possible cases, 
but T(average) is what we usually find in the real world!

Ex: Planar Graph

### Planar Graph
A graph is planar if it can be drawn in 2D without an intersection of its edges.

Is a clique, a planar graph? It can be since we can draw it as we want!

![planar](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/planar.png?raw=True)

It can be demonstrated that a **graph is planar i.f.f. the maximum clique has max 4 vertices**. This means 
**we can find in polynomial time the maximum clique!**
* **Kuratowski's theorem**
  * It states that a finite graph is planar if and only if it does not contain a subgraph that is a subdivision of 
  K_{5} (the complete graph on five vertices) or of K_{3,3} (a complete bipartite graph on six vertices, 
  three of which connect to each of the other three, also known as the utility graph).

## 3) Randomized Algorithms
Algorithms that return different outputs everytime we execute them

## 4) Heuristics
Algorithms that have no formal demonstration but works based on experimental empiricism. Basically, an algorithm is "good enough"
when it works well for many instances.

We might have some hopes for convergence but no absolutes on the truth of the result! From the results on the instances
we consider how much we can trust it before we put it at work.
