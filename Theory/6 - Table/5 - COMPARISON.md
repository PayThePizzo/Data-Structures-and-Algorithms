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

| _Data Structure_                         	| **Search**                  	| **Minimum**      	| **Maximum**      	| **Predecessor**  	| **Successor**      	| **Construction**            	|
|------------------------------------------	|-----------------------------	|------------------	|------------------	|------------------	|--------------------	|-----------------------------	|
| Closed Address Hashtables (average case) 	| $\Theta(1+\alpha)$          	|                  	| $\Theta(m+n)$    	|                  	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	|
| Closed Address Hashtables (worst case)   	| $\mathcal{O}(n)$            	|                  	| $\Theta(m+n)$    	|                  	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	|
| Open Address Hashtables (average case)   	| $\mathcal{O}(1/(1-\alpha))$ 	|                  	| $\Theta(m)$      	|                  	| $\mathcal{O}(m)$   	| $\mathcal{O}(n/(1-\alpha))$ 	|
| Open Address Hashtables (worst case)     	| $\mathcal{O}(n)$            	|                  	| $\Theta(m)$      	|                  	| $\mathcal{O}(m)$   	| $\mathcal{O}(n^{2})$        	|
| Non-decreasing Sorted Array              	|                             	|                  	|                  	|                  	|                    	|                             	|
| Non-Increasing Sorted Array              	|                             	|                  	|                  	|                  	|                    	|                             	|
| Binary Search Tree                       	| $\mathcal{O}(h)$            	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$   	| $\Theta(nlog(n))$           	|
| Max-Heap                                 	| $\mathcal{O}(n)$            	|                  	| $\Theta(1)$      	|                  	| $\mathcal{O}(n)$   	| $\mathcal{O}(n)$            	|
| Min-Heap                                 	| $\mathcal{O}(n)$            	| $\Theta(1)$      	|                  	| $\mathcal{O}(n)$ 	|                    	| $\mathcal{O}(n)$            	|