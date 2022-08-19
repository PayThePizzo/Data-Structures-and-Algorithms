# Clique ∈ NPC
The problem: Is there a clique in G with k vertices?

Demonstration:
1. **CLIQUE ∈ NP**
  * Easy to write a polynomial verification algorithm, like we saw before.
2. ∃P' ∈ NPC : P' <=p CLIQUE ?
  * It can be demonstrated that **SAT-3-CNF <= p CLIQUE**
  
### Example of demonstration that SAT-3-CNF <= p CLIQUE
We need an Instance-Yes of SAT-3-CNF `i(S)`, and create CLIQUE Instance-Yes `i(C)` such that i(C) is **equivalent** to i(S).
Therefore we are applying the very concept of polynomial reducibility!

![excliqueis](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/excliqueis.png?raw=True)

The resulting graph would have:
* |V| = #literals
* Groups of vertices = #clauses
  * Only edges between **compatible** literals in **different groups**
    * No edges in the same group
    * No edge if one is the negation of the other

![excliqueic](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/excliqueic.png?raw=True)



# Planal Graphs