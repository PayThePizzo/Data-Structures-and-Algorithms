# 1) AVL Trees
AVL trees are BST that are always balanced.

They have a structure such that a node has:
* A Key
* Balancing Factor (BF)
  * an integer indicating the difference between the height of the left-subtree and the height of the right-subtree.
  * `|BF| <= 1` for every node x.

This complicates the operations of insertion and extraction because
we need to maintain the BF.

---

# 2) B-Trees
B-Trees are balanced BST of degree t (with t>=2). They are not necessarily
binary trees. 

However, they must satisfy the following conditions: 
1. Every leaf has the same depth
2. Every node (except for the root) saves k(v) sorted keys.
   1. where `t-1 <= k(v) <= 2t-1`
3. The root saves `1 >= n <= 2t-1` ordered keys
4. Every internal node v, has `k(v)+1` children
5. The keys i(v) separates the intervals of keys saved in each subtree:
   1. If c(i) is a key in the i-ary subtree of a node v, then 
   `c(1) <= v.key(1) <= c(2) <= ... <= x.v(k)` with 1..k as the number of the children.


![BTrees](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/BTrees.png?raw=TRUE)

The keys being ordered reduced to a cost O(log(n)) the cost for
most operations.

--- 

# 3) Red and Black Trees
Red and black trees are BST *almost* balanced.

Their main feature is that their nodes contain one more piece 
of information about themselves: <mark>the color of the node.</mark>
* Black 
* Red

They must also respect the following conditions:
1. Every node is either black or red
2. The root node is **initially black**
3. Every leaf is **black** and contains **NULL**
4. Both children of a red node, are black
5. Every path from a node x to a leaf (contained in x's subtree) has the
same number of black nodes.

If all these conditions are to be found in a BST, then a RB Tree also 
guarantees the following invariant: `longest_path <= 2*(smallest_path)` 
* The longest path of the tree cannot be longer than double the smallest path.

Here again, most operations have a reduced cost equal to O(log(n)).
