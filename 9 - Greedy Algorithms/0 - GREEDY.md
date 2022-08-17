# Greedy Algorithms
A greedy algorithm always makes the choice that looks best at
the moment. 

That is, it makes a **locally optimal choice** in the hope that this choice
will lead to a globally optimal solution.

## An activity-selection problem
Our first example is the problem of scheduling several competing activities that 
**require exclusive use of a common resource**, with a goal of selecting a maximum-size
set of mutually compatible activities.
* V, a set of mutually compatible activities, V={1, 2, ..., n}, with i=1 to n.
  * Each activity tracks a starting time **s(i)** and end time **f(i)**, with i=1 to n.
  * We can interpret an activity as interval **i = [s(i), f(i)[**
* Two activities i, j are said to be **compatible if**
**[s(i), f(i)[ ∩ [s(j), f(j)[ = ∅**
  * f(i)<= s(j) OR f(j)<= s(i)
  * They do not overlap!

Example with Gantt diagram:

![ex act](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/exact.png?raw=TRUE)

Let's try and study an algorithm that extracts activities in a greedy way:
1) Sort activities by end time
2) Create a set A to regroup the maximum number of compatible activities
3) Initialize it with the longest activity
4) For each remaining activity
   1) if the current activity i has a starting time, bigger than the first activity j,
   add it to the group A.
   2) Set current activity for next comparison
5) Return A

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
**Final Time Complexity**: T(n) = **O(n * log(n))**

This algorithm is very similar to Kruskal, that is because they
share a common structure. 

## Greedy Common Structure
The following structure is a very common structure between certain types of greedy algorithm.
The algorithm we just saw, and Kruskal share this same "skeleton", but they are not the only ones.
1) **Sorting** on some criteria
2) **Initialization** of a _data structure_
3) **For each element** (one at a time, in order from step 1)
   1) **If** A U {x} is ok (compatibility condition) 
      1) **Add it**  to _data structure_
4) **Return** the _data structure_

#### Ambiguous points
The predicate used to sort the elements and the condition of compatibility are yet
to be defined and can change for each problem we face.
 




