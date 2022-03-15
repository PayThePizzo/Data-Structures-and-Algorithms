# Dynamic Programming



È una tecnica di progettazione da applicare quando un problema si può dividere in sottoproblemi più
piccoli e non indipendenti, come i problemi di ottimizzazione. L’idea consiste nel risolvere ogni sottoproblema una volta sola, memoizzando la soluzione e non dovendola quindi ricalcolare. La definizione
di una soluzione si svolge in quattro fasi:
1. caratterizzazione della struttura di una soluzione ottima
2. definizione ricorsiva del valore di una soluzione ottima
3. calcolo di tale valore, con strategia top-down o bottom-up
4. individuazione della soluzione ottima
   La soluzione ottima, non per forza unica, si ottiene come combinazione di soluzioni ottime di sottoproblemi. Questa si chiama proprietà della sottostruttura ottima.
   In base al tipo di problema si possono adottare due strategie: top-down o bottom-up. Il primo
   memoizza i problemi già risolti in una tabella o un vettore, mentre il secondo parte dai problemi più
   piccoli fino a raggiungere la soluzione. La loro complessità è equivalente a meno di costanti, solitamente
   minori nel BU, anche se TD conviene quando non si calcolano tutti i sottoproblemi