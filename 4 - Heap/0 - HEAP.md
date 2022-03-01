
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