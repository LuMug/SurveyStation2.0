# PROGETTO | Diario di lavoro - 04.05.2018

### Canobbio, 04.05.2018


## Lavori svolti


##### Alessandro Colugnat e  Luca Ristagno
| **Orario**     | **Lavori svolti** |
| :------------- | :---------------- |
| 8:20 - 16:30  |  `Alessandro` era assente  |
| 8:20 - 16:30  | `Luca` ha cercato tutto il giorno di mettere a posto il database    |







##  Problemi riscontrati e soluzioni adottate
  Nel Database ho riscontrato il problema seguente: la tabella shake non si aggiorna piu. l'unica cosa che avevo fatto al database era aggiungere il trigger che ho creato il database di prova a parte e cancellare i dati della tabella `sismografo` e `shake` con il comando delete
  anche se era tardi ho fatto una copia del database con il comando mysqldump <db> > nomefile.sql e poi ho tentato di mettere a posto ricreando il database dal file database.sql che era gia presente sulla macchina,... in piu mentre controllavo la struttura dell'attuale database con i comandi `desc` e `show create`... il raspberry P3 è riuscito a crashare..
  verso le 16:04 ho provato a fare un `call` della procedura e sembra andare anche se non sono sicuro che l'event funzioni siccome ci vogliono 4 parametri
  riprovato a fare il `call` (sempre con 4 parametri) e mi da questa risposta `Query OK, 0 rows affected, 1 warning` non funzionando....
  alla fine la procedura ha funzionato per un attimo e adesso non funziona più


##  Punto della situazione rispetto alla pianificazione
  Siamo indietro ai tempi del nostro Gantt.

## Programma di massima per la prossima giornata di lavoro
  Ancora sistemare il database e la grafica del sito
