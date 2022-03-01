# Red and Black Trees

Gli alberi rosso-neri sono degli alberi binari di ricerca che memorizzano all’interno del nodo
anche l’informazione sul colore dello stesso. Sono verificate le seguenti proprietà:
● Ogni nodo ha colore rosso o nero.
● Il nodo root inizialmente è nero.
● Ogni foglia è nera e contiene elemento null;
● Entrambi i figli di ciascun nodo rosso sono neri;
● Ogni cammino da un nodo a una foglia nel suo sottoalbero contiene lo stesso
numero di nodi neri.
E’ valida l’invariante 𝐿(𝑐𝑎𝑚𝑚𝑖𝑛𝑜_𝑚𝑎𝑠𝑠𝑖𝑚𝑜) ≤ 2 · 𝐿(𝑐𝑎𝑚𝑚𝑖𝑛𝑜_𝑚𝑖𝑛𝑖𝑚𝑜).

Proprietà
● Numero di foglie di un albero k-ario completo ad altezza ℎ = 𝑘
ℎ
● Numero di nodi interni di un albero k-ario completo di altezza h:
𝑖 = 0
ℎ − 1
∑ 𝑘
𝑖 =
𝑘
ℎ − 1
𝑘 − 1
● Altezza di un albero k-ario completo con n foglie:
# 𝑓𝑜𝑔𝑙𝑖𝑒(ℎ) = 𝑘
ℎ = 𝑛 ⇔ ℎ = 𝑙𝑜𝑔
𝑘
(𝑛)