# Exercises on Hash Tables

---

## 1 - Confronto tra complessita' 

Completare la seguente tabella indicando la complessità delle operazioni che si riferiscono a un dizionario
di $n$ elementi. Per l’operazione Predecessore e Successore si assuma di essere sull’elemento $x$ a cui si applica 
l’operazione. La tabelle Hash hanno dimensione $m$ e il fattore di carico è $\alpha$.

| _Struttura Dati_                                    	| **Ricerca**                 	| **Minimo**       	| **Massimo**      	| **Predecessore** 	| **Successore**     	| **Costruzione**             	  |
|-----------------------------------------------------	|-----------------------------	|------------------	|------------------	|------------------	|--------------------	|--------------------------------|
| Tabella Hash con liste di collisione (caso medio)   	| $\Theta(1+\alpha)$          	|                  	| $\Theta(m+n)$    	|                  	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	  |
| Tabella Hash con liste di collisione (caso pessimo) 	| $\mathcal{O}(n)$            	|                  	| $\Theta(m+n)$    	|                  	| $\mathcal{O}(m+n)$ 	| $\Theta(n)$                 	  |
| Tabella Hash a indirizzamento aperto (caso medio)   	| $\mathcal{O}(1/(1-\alpha))$ 	|                  	| $\Theta(m)$      	|                  	| $\mathcal{O}(m)$   	| $\mathcal{O}(n/(1-\alpha))$ 	  |
| Tabella Hash a indirizzamento aperto (caso pessimo) 	| $\mathcal{O}(n)$            	|                  	| $\Theta(m)$      	|                  	| $\mathcal{O}(m)$   	| $\mathcal{O}(n^{2})$        	  |
| Array ordinato in senso crescente                   	|                             	|                  	|                  	|                  	|                    	| 	                              |
| Array ordinato in senso decrescente                 	|                             	|                  	|                  	|                  	|                    	| 	                              |
| Binary Search Tree                                  	| $\mathcal{O}(h)$            	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$ 	| $\mathcal{O}(h)$   	| $\Theta(nlog(n))$      	       |
| Max-Heap                                            	| $\mathcal{O}(n)$            	|                  	| $\Theta(1)$      	|                  	| $\mathcal{O}(n)$   	| $\mathcal{O}(n)$            	  |
| Min-Heap                                            	| $\mathcal{O}(n)$            	| $\Theta(1)$      	|                  	| $\mathcal{O}(n)$ 	|                    	| $\mathcal{O}(n)$            	  |

---
