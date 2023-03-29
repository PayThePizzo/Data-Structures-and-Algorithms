# Closed Addressing vs Open Addressing

![comparisonhash](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/comparisonhash.png?raw=TRUE)

What to prefer
* Closed Addressing for efficiency 
* Open Addressing for local memory management 

---

## Dictionary Performances
Here listed below we compare some data structures we saw in this course, and we compare their times of executions for 
some dictionary-related operations, as dictionaries are indeed a kind of dynamic set. 

Just to clarify:
* $x$ is the element to which the operations `Predecessor` and `Successor` is applied to.
* $n$ is the input size of the problems
* $m$ is the table size for hash-tables and $\alpha$ is their load factor
* $h$ is the height of the tree for the Binary Search Tree

| _Data Structure_                                        	| **Search**                  	| **Minimum**      	| **Maximum**      	| **Predecessor**    	| **Successor**      	| **Construction**            	| **Delete**       	|
|---------------------------------------------------------	|-----------------------------	|------------------	|------------------	|--------------------	|--------------------	|-----------------------------	|------------------	|
| Closed Address Hashtables (average case)                	| $\Theta(1+\alpha)$          	| $\Theta(m+n)$    	| $\Theta(m+n)$    	| $\mathcal{O}(m+n)$ 	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	|                  	|
| Closed Address Hashtables (worst case)                  	| $\mathcal{O}(n)$            	| $\Theta(m+n)$    	| $\Theta(m+n)$    	| $\mathcal{O}(m+n)$ 	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	|                  	|
| Open Address Hashtables (average case)                  	| $\mathcal{O}(1/(1-\alpha))$ 	| $\Theta(m)$      	| $\Theta(m)$      	| $\mathcal{O}(m)$   	| $\mathcal{O}(m)$   	| $\mathcal{O}(n/(1-\alpha))$ 	|                  	|
| Open Address Hashtables (worst case)                    	| $\mathcal{O}(n)$            	| $\Theta(m)$      	| $\Theta(m)$      	| $\mathcal{O}(m)$   	| $\mathcal{O}(m)$   	| $\mathcal{O}(n^{2})$        	|                  	|
| Non-decreasing Sorted Array                             	| $\mathcal{O}(log(n))$       	| $\Theta(1)$      	| $\Theta(n)$      	|                    	|                    	|                             	| $\mathcal{O}(n)$ 	|
| Non-Increasing Sorted Array                             	| $\mathcal{O}(log(n))$       	| $\Theta(n)$      	| $\Theta(1)$      	|                    	|                    	|                             	| $\mathcal{O}(n)$ 	|
| Non-decreasing Sorted Double-Linked List  with Sentinel 	| $\mathcal{O}(n)$            	|                  	|                  	|                    	|                    	|                             	| $\Theta(n)$      	|
| Non-decreasing Sorted Double-Linked List  with Sentinel 	| $\mathcal{O}(n)$            	|                  	|                  	|                    	|                    	|                             	| $\Theta(n)$      	|
| Binary Search Tree                                      	| $\mathcal{O}(h)$            	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$   	| $\mathcal{O}(h)$   	| $\Theta(nlog(n))$           	|                  	|
| Balanced Binary Search Tree                             	|                             	|                  	|                  	|                    	|                    	|                             	|                  	|
| Max-Heap                                                	| $\mathcal{O}(n)$            	|                  	| $\Theta(1)$      	|                    	| $\mathcal{O}(n)$   	| $\Theta(n)$                 	|                  	|
| Min-Heap                                                	| $\mathcal{O}(n)$            	| $\Theta(1)$      	|                  	| $\mathcal{O}(n)$   	|                    	| $\Theta(n)$                 	|                  	|

### Hashtables
As we know, hash-tables do not have any efficient primitive operation to find the `Successor` or `Predecessor`. This means:
* Closed Address hash-tables must traverse the $m$ cells and examine the $n$ keys in the lists.
* Open Address hash-tables must traverse the $m$ cells

In both case we might stop before, so we use a big O notation.

While for the `Minimum` and `Maximum` we need to check the whole content of the table, obtaining respectively the same
results with $\Theta$ notation instead.

For what regards the `Construction`
* For Closed Address hash-tables, this represents $n$ `Insertion`, which have constant time. 
  * We insert the elements on top of the list in both cases
* For Open Address hash-tables, this represents $n$ `Search`, which depend on the load factor
  * In the average case, it depends on the load factor (see the related theorems)
  * In the worst case, for $n$ keys we need to use the `Search` which has linear time.

Finally the `Search` depends
* For Closed Address hash-tables
  * In the average case, it depends on the load factor (see the related theorems)
  * In the worst case, it depends on the input size as one list contains all the elements.
* For Open Address hash-tables
  * In the average case, it depends on the load factor (see the related theorems)
  * In the worst case, all the $n$ inspections result in finding an occupied slot. Which means we need to iterate through
    the $n$ keys.