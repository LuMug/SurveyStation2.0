# PROGETTO | Diario di lavoro - 20.04.2018

### Canobbio, 20.04.2018


## Lavori svolti


##### Alessandro Colugnat e  Luca Ristagno
| **Orario**     | **Lavori svolti** |
| :------------- | :---------------- |
| 8:20 - 11:35  |   Abbiamo lavorato assieme cercando una soluzione al problema del grafico che non si aggiorna in tempo reale. abbiamo deciso di creare un trigger che in base ai valori li limitiamo a 50 ad esempio al 51esimo valore rimuove il primo. Ci siamo divisi il compito: `Luca` si è messo a creare il trigger e alessandro a cercare di capire perchè il grafico del sismografo si blocca dopo circa 15 secondi |
| 13:15 - 16:30   | `Luca` ha risolto il problema riquardante l'id cambiando parte del'unica condizione (al posto di < <=) e mettendo l'INSERT INTO `testsismografo`.`shake` (`id`,`nome`) VALUES (new.id-1,new.nome) |
| 13:15 - 16:30   | `Alessandro` ha velocizzato il grafico del sismografo e sistemato il problema citato  |






##  Problemi riscontrati e soluzioni adottate
  Nella creazione del trigger (su un database di prova) causa questo errore:`Error Code: 1442. Can't update table 'shake' in stored function/trigger because it is already used by statement which invoked this stored function/trigger.` questo è causato dall'uso della stessa tabella, per risolverlo ho creato una tabella copia (siccome per fortuna nel sismografo utilizziamo 2 tabelle uguali)
  dopo aver risolto il problema ne è sorto un altro... che sarebbe nella tabella, l'id lo cambia ma il nuovo dato che viene messo resta con l'id sbagliato


##  Punto della situazione rispetto alla pianificazione
  Siamo dentro i tempi del nostro Gantt.

## Programma di massima per la prossima giornata di lavoro
  Sistemare il calcolo delle forze del sismografo e mettere e adattare il codice per limitare la tabella.
