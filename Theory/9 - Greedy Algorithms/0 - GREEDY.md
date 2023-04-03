# Greedy Algorithms
A greedy algorithm always makes the choice that looks best at
the moment. That is, it makes a **locally optimal choice** in the hope that this choice
will lead to a globally optimal solution.

### Let's ask ChatSonic

Greedy Algorithms are a problem-solving approach that selects the best available option at each step to solve a 
problem. It works in a top-down approach and makes locally optimal choices at each stage, without worrying 
about the overall optimal result. This algorithm can be used if the problem has greedy choice and optimal 
substructure properties. 

However, this algorithm may not always produce the optimal solution and can be characterized as being "short-sighted" 
and "non-recoverable".

References:
* [Greedy Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/greedy-algorithms/)
* [Greedy Algorithms - Programiz](https://www.programiz.com/dsa/greedy-algorithm)
* [Greedy Algorithms - Wikipedia](https://en.wikipedia.org/wiki/Greedy_algorithm)

---

## Greedy Algorithms vs Dynamic Programming

|                     	| **Greedy**                                                                                      	| **Dynamic Programming**                                                            	|
|---------------------	|-------------------------------------------------------------------------------------------------	|------------------------------------------------------------------------------------	|
| _Technique_         	| Usually **Top-Down**                                                                            	| Usually **Bottom-Up**                                                              	|
| _Problems solved_   	| Does **not** need to solve **all** the sub-problems                                             	| Solves **all** the sub-problems                                                    	|
| _Choices_           	| We make whatever choice seems **best at the moment** and then solve the subproblem that remains 	| At each step we make a choice, it usually depends on the solutions to subproblems  	|
| _Choices depend on_ 	| **Previous choices, choices made so far**, no future problems or other solutions                	| **Future choices or on the solutions of the subproblems**                          	|
| _Solution_          	| Locally Optimal Solution                                                                        	| Optimal Solution                                                                   	|


Greedy:
* What if we could choose an activity to add to our optimal solution without having 
to first solve all the sub-problems? That could save us from having to consider all 
the choices inherent in recurrence. In fact, for the activity-selection problem, 
we need consider only one choice: the greedy choice. 
* All we really need to do is argue that an optimal solution to 
the subproblem, combined with the greedy choice already made, yields an optimal 
solution to the original problem. This scheme implicitly uses induction on the 
subproblems to prove that making the greedy choice at every step produces an optimal solution.

---

## An activity-selection problem - Introductory Example

Our first example is the problem of scheduling several competing activities that 
**require exclusive use of a common resource**, with a goal of selecting a maximum-size
set of mutually compatible activities.
* $V$, a set of mutually compatible activities, $V = \lbrace 1, 2, \ldots, n \rbrace$, with $i = 1 \ldots n$.
  * Each activity tracks a starting time $s(i)$ and end time $f(i)$, with $\forall i = 1 \ldots n$.
  * We can interpret an activity as interval $i = [s(i), f(i)[$
* Two activities $i, j$ are said to be **compatible if** they do not overlap!
  * $[s(i), f(i)) \cap [s(j), f(j)) = \emptyset$
  * $f(i) \geq s(j) \vee f(j) \geq s(i)$

Example with Gantt diagram:

![ex act](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exact.png?raw=TRUE)

Let's try and study an algorithm that extracts activities in a greedy way:
1) Sort activities by end time
2) Create a set $A$ to regroup the maximum number of compatible activities
3) Initialize it with the longest activity
4) For each remaining activity, choose the one which finishes first
   1) if the current activity $i$ has a starting time, bigger than the first activity $j$,
   add it to the group $A$.
   2) Set current activity for next comparison
5) Return $A$

```python
Greedy_Activity_Selector(Double[] s, Double[] f): #Arrays of times
    n = s.lenght(); 
    sort_activities(predicate = f) 
    A = {1}; 
    j = 1;
    for(i=2 to n):
        if(s[i] >= f[j]):
            A = A.union(i);
            j = i;
    return A;
```
**Final Time Complexity**: $T(n) = \mathcal{O}(nlog(n))$

This algorithm is very similar to Kruskal, that is because they share a common structure. 

---

## Greedy Common Structure
The following structure is a very common structure between certain types of greedy algorithm.
The algorithm we just saw, and Kruskal share this same "skeleton", but they are not the only ones.
1) **Sorting** on some _criteria_
2) **Initialization** of a _data structure_ 
3) **For each element** (extracted following the sorting _criteria_)
   1) **If** $A \cup \lbrace x \rbrace$ is OK (compatibility condition) 
      1) **Add it**  to _data structure_
4) **Return** the _data structure_

### Ambiguous points
The predicate used to sort the elements and the condition of compatibility are yet to be defined and can change for 
each problem we face.

---

#### Credits

We deeply suggest reading through the chapter 16 of the "Introduction to Algorithms" (CLRS).
