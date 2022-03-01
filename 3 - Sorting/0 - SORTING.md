Problema dell’ordinamento
Limite inferiore di complessità
Il limite inferiore della complessità dei problemi di ordinamento è .
Ciò è dovuto alla rappresentazione del problema in forma generica: costruendo un albero di
decisione, in cui ogni nodo interno rappresenta i possibili confronti effettuabili e le foglie
rappresentano le possibili permutazioni dell’array.
Dimostrazione
● E’ chiaro che le foglie sono 𝑛!, in quanto rappresentano le possibili permutazioni di
un array di dimensione 𝑛.
● L’altezza minima dell’albero di decisione è Ω(𝑙𝑜𝑔 𝑘), con 𝑘 il numero di foglie.
● Nel caso migliore, il numero di confronti effettuati è pari all’altezza minima dell’albero.
● Di conseguenza, il numero di confronti effettuati è
Ω(𝑙𝑜𝑔 𝑘) = Ω(𝑙𝑜𝑔 𝑛!) = Ω(𝑛 · 𝑙𝑜𝑔 𝑛).
