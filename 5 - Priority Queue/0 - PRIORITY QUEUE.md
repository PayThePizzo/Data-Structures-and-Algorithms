

Descrizione e Proprietà
Una coda con priorità viene definita come un insieme di elementi, le cui chiavi associate
sono legate da una relazione di ordine totale. Sono spesso implementate usando degli
Heap, in quanto l’accesso all’elemento massimo (o minimo) è estremamente efficiente.
Operazioni sulle code con priorità
● findMax(A):
○ PRECONDIZIONI: A è una coda con priorità.
○ POSTCONDIZIONI: Viene restituito il massimo elemento della coda.
● insert(A,x,k):
○ PRECONDIZIONI: A è una coda con priorità.
○ POSTCONDIZIONI: Viene inserito l’elemento x con chiave k nella coda.
● delete(A,k):
○ PRECONDIZIONI: A è una coda con priorità.
○ POSTCONDIZIONI: Viene eliminato l’elemento di A con chiave k.
● increaseKey(A,x,d):
○ PRECONDIZIONI: A è una coda con priorità.
○ POSTCONDIZIONI: Viene incrementato di d la chiave dell’elemento x.
● decreaseKey(A,x,d):
○ PRECONDIZIONI: A è una coda con priorità.
○ POSTCONDIZIONI: Viene decrementato di d la chiave dell’elemento x.

