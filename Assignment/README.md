# Esercitazioni
Questo e' quello che viene scritto su tutte le esercitazioni.

Normalmente alcune di queste queste sono fatte su Hackerrank, dove vi sono gia' test case da provare ed e' 
possibile non dover fare run in locale del codice.

## Utilizzo IDE
Utilizzate qualsiasi IDE che vi risulti comodo e familiare, soprattutto se siete in grado di sfruttare il debugger. 
Per i nostri scopi, è anche possibile utilizzare editor di testo come gedit, notepad++ o sublime text.

>[!TIP] Usate VSCode che e' piu' facile da impostare

---

## Correzione
La correzione sarà svolta su una macchina con sistema Linux e il compilatore g++: è pertanto suggerito che utilizziate 
anche voi il medesimo ambiente di sviluppo.

>[!TIP] Su MacOs e' possibile scaricare g++ in modo diretto, senno' e' possibile usare WSL per Linux. In ogni caso
> i tutorial si trovano per delle macchine virtuali linux (ma sono relativamente poco utili).

---

## Compilazione
Compilate da linea di comando specificando le flag `-std=c++14`, `--pedantic` e `-Wall`.

Queste flag servono per compilare il sorgente secondo lo standard c++14 (`-std=c++14`) e mostrano vari warning 
(`--pedantic -Wall`) che possono essere causa di malfunzionamenti del vostro codice. 

### Esempio

Ad esempio, usate il comando:

```bash
g++ -std=c++14 --pedantic -Wall -o es1 main_es1.cpp
```

per compilare il sorgente main_es1.cpp e creare il file eseguibile es1.

>[!NOTE] Successivamente dovete runnare l'eseguibile che su MacOs e Linux si fa con `./es1`

---

