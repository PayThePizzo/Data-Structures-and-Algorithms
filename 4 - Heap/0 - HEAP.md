
Utilizza una struttura dati chiamata heap, un albero binario quasi completo. In un heap tutti i livelli
sono riempiti ad eccezione dell’ultimo, in cui le foglie sono addossate a sinsitra. Grazie a questa sua
proprietà è facile da salvare in un array A, con attributi .length (numero degli elementi dell’array) e
.heap_size (numero degli elementi dell’heap).
La radice è salvata all’inizio di A, e se i è l’indice di un nodo, allora il figlio sinistro si trova a 2 ∗ i,
mentre il figlio destro a 2 ∗ i + 1. Di conseguenza il genitore è la parte intera di i/2. In base alle
proprietà soddisfatte dai nodi, esistono due tipi di heap: maxheap, dove per ogni nodo i diverso dalla
radice, il padre di i è maggiore o uguale al figlio, e minheap, per cui vale la proprietà contraria. In
un maxheap quindi la radice è l’elemento maggiore (e il contrario vale per minheap).
L’altezza di un heap di n elementi è sempre log n, le foglie si trovano agli indici strettamente
maggiori della parte intera di n/2, per cui metà dei nodi sono foglie, e il numero massimo di nodi ad
altezza h è n/2
h+1

Descrizione e Proprietà
Un Heap è un albero binario quasi completo, rappresentabile come un array, con le seguenti
proprietà:
● data la sua altezza ℎ, l’albero è completo fino all’altezza ℎ − 1;
● l’array 𝐴 che descrive l’Heap soddisfa la proprietà di ordinamento parziale degli heap,
ovvero ogni nodo ha valore al più uguale a quello del padre.
Operazioni sugli heap
● Heapify(A,i):
○ PRECONDIZIONI: dato i, indice dell’array A, si assume che i figli di A[i] siano
degli Heap, ma che A[i] sia minore di almeno uno dei suoi figli.
○ POSTCONDIZIONI: A[i] viene spostato in una posizione più bassa dell’albero
rappresentato da A, in maniera che che l’albero sia un Heap.
● Build-Heap(A):
○ PRECONDIZIONI:A è un array, non ordinato.
○ POSTCONDIZIONI: Viene restituito un Heap costruito a partire dagli elementi
di A.
● Heapsort(A):
○ PRECONDIZIONI:A è un array non ordinato.
○ POSTCONDIZIONI: A viene ordinato secondo l’algoritmo Heapsort.
● Max(A):
○ PRECONDIZIONI: A è un Heap.
○ POSTCONDIZIONI: Viene restituito il massimo elemento dell’Heap (la
radice).
● Insert(A,x):
○ PRECONDIZIONI:A è un Heap.
○ POSTCONDIZIONI: L’elemento x viene inserito nell’Heap, in maniera tale che
venga rispettata la proprietà dell’Heap.


