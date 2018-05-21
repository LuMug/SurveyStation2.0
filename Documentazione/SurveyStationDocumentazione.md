# Survey station
1. [Introduzione](#introduzione)

  - [Informazioni sul progetto](#informazioni-sul-progetto)

  - [Abstract](#abstract)

  - [Scopo](#scopo)

2. [Analisi](#analisi)

  - [Analisi del dominio](#analisi-del-dominio)

    - [Analisi e specifica dei requisiti](#analisi-e-specifica-dei-requisiti)

  - [Analisi dei mezzi](#analisi-dei-mezzi)

  - [Pianificazione](#pianificazione)

3. [Progettazione](#progettazione)

  - [Design dell’architettura del sistema](#design-dell’architettura-del-sistema)

  - [Design dei dati e database](#design-dei-dati-e-database)

  - [Arduino](#arduino)

4. [Implementazione](#implementazione)

5. [Test](#test)

  - [Protocollo di test](#protocollo-di-test)

  - [Risultati test](#risultati-test)

  - [Mancanze/limitazioni conosciute](#mancanze/limitazioni-conosciute)

5. [Consuntivo](#consuntivo)

6. [Conclusioni](#conclusioni)

  - [Sviluppi futuri](#sviluppi-futuri)

  - [Considerazioni personali](#considerazioni-personali)

7. [Sitografia](#sitografia)

8. [Allegati](#allegati)

## Introduzione

### Informazioni sul progetto
  - Allievi: Alessandro Colugnat, Luca Ristagno
  - Docente responsabile: Luca Muggiasca
  - Scuola Arti e Mestieri Trevano (SAMT)
  - Inizio: 16.03.2018
  - Consegna: 18.05.2018
### Abstract
>* The following document has the goal to illustrate the process of developement behind our creation: Survey Station.
This project it's gave to Alessandro Colugnat and Luca Ristagno for make better and faster the Survey Station, this project it's a continuity of a old project who is made by five guys in 2017
### Scopo
  Lo scopo del progetto è quello di velocizzare e migliorare il progetto fatto dai ragazzi dell'anno 2017 cercando di capire ciò che hanno fatto e migliorarlo per avere un sismografo velocè e migliore.
## Analisi

### Analisi del dominio
  Il prodotto dovrà lavorare in un contesto scolastico e 'artigianale', come forma di raccolta e visualizzazione dati più per curiosi che per professionisti. La pagina sarà dunque ovviamente limitata, l'intenzione non è quella di creare un centro geologico o metereologico, ma di avere una piccola stazione di rilevamento e misurazione. L'idea è dunque quella di costruire una 'miniatura' di siti professionali (p.es. sed.ch) in modo, come detto, artigianale e 'casalingo'.

  Per fare questo progetto si dovrà capire ciò che hanno fatto i ragazzi nel 2017 e cercare di capire quali sono le parti che rallentano il codice, si dovrà fare un lavoro di analisi e anche un lavoro di modifica.
### Analisi e specifica dei requisiti

|ID  |REQ-001                                         |
|----|------------------------------------------------|
|**Nome**    |Sismografo |
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**      | Costruzione di un sismografo in grado di rilevare le vibrazioni del terreno |
|**002**      | Lo stesso (tramite Arduino o simili) deve essere in grado di inviare i dati al server |


|ID  |REQ-002                                         |
|----|------------------------------------------------|
|**Nome**    |Altri sensori |
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**      | Sulla base del sismografo dev'essere possibile aggiungere altri strumenti di misura alla stazione (p.es. barometro o termometro) |
|**002**      | Di nuovo sulla base del sismografo la stazione deve poter inviare i dati al server |


|ID  |REQ-003                                         |
|----|------------------------------------------------|
|**Nome**    |Salvataggio dati|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**      | Non è necessario salvare a lungo termine tutti i dati ricevuti dalla stazione|
|**002**      | Quando i valori entrano in una soglia interessante i dati vengono raccolti e archiviati|


|ID  |REQ-004                                         |
|----|------------------------------------------------|
|**Nome**    | Allarmi e notifiche|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**      | Gli allarmi e le notifiche scattano al superamento di una soglia definita |
|**002**      | Gli utenti registrati, se hanno settato l'opzione, ricevono un e-mail di avviso |
|**003**      | Sulla pagina web viene mostrato l'allarme |
|**004**      | Le e-mail vengono inviate a intervalli regolari in caso di allarme (timespan configurabile), per evitare l'invio continuo all'utente |
|**005**      | Deve essere presente una notifica anche sulla stazione fisica (p.es un LED) |


|ID  |REQ-005                                         |
|----|------------------------------------------------|
|**Nome**    | Admin e utenti|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**     | Deve esserci un form di login e di registrazione |
|**002**     | L'admin ha accesso a una dashboard di gestione |
|**003**     | La registrazione richiede un indirizzo e-mail (univoco nel sistema) e una password |
|**004**     | Gli utenti devono avere la possibilità di cambiare la password |
|**005**     | L'admin può gestire le configurazioni (vedi REQ-006) |
|**006**     | L'admin può gestire gli utenti |


|ID  |REQ-006                                         |
|----|------------------------------------------------|
|**Nome**    | Configurabilità moduli |
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**     | Per ogni modulo devono essere configurabili le soglie di valori interessanti |
|**002**     | Per ogni modulo deve essere configurabile il tempo della durata di una misurazione (p.es. un terremoto che non ha picchi per X minuti è da considerarsi concluso) |
|**003**     | Dovranno poi essere configurabili altri parametri |


|ID  |REQ-007                                         |
|----|------------------------------------------------|
|**Nome**    | Raccolta e confronto dati professionali|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**     | È necessario confrontare i dati raccolti con quelli del SED (http://www.seismo.ethz.ch/) |
|**002**     | Questo confronto dev'essere visibile all'utente (sul grafico o tramite tabella) |
|**003**     | I dati vengono raccolti a intervalli regolari (non troppo frequenti a causa del traffico generato) |


|ID  |REQ-008                                         |
|----|------------------------------------------------|
|**Nome**    | Visualizzazione e rappresentazione dati|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**     | I dati raccolti per ogni modulo devono essere mostrati sulla pagina web tramite un grafico con il tempo in ascissa. |
|**002**     | I dati salvati devono essere consultabili |


|ID  |REQ-009                                         |
|----|------------------------------------------------|
|**Nome**    | Modulabilità|
|**Priorità**|1                     |
|**Versione**|1.0                   |
|**Note**    ||
|            |**Sotto requisiti** |
|**001**     | I moduli hanno delle configurazioni che possono essere definite dall'admin (vedi REQ-006) |
|**002**     | Ogni modulo dispone della sua sezione sul sito, con tabella nel DB per il salvataggio dei valori e grafico per la visualizzazione |

### Pianificazione
  In questo capitolo è esposto il Gantt preventivo per l'organizzazione del lavoro
  ![schema gantt](../SismografoGantt.png)

  Preventivo costi:

|Risorsa  |Prezzo                                         |
|----|------------------------------------------------|
|**Personale**| 50 CHF/h * 80 h lavoro * 2 = 8000 CHF              |

### Analisi dei mezzi

#### Hardware

|Tipo componente  |Utilizzo nel progetto|
|-----------------|--------------------------------|
|1x Accelerometro|Componente principale, viene utilizzato per ricevere i dati dell'accelerazione nel caso di un sisma|
|1x Led RGB|Utilizzato per creare un segnale fisico sulla scheda|
|1x Veroboard|Utilizzata per saldare i componenti su di essa|
|7x cavi arduino|Utilizzati per collegare i componenti saldati all'arduino|
|1x Arduino Ethernet|Utilizzato per trasmettere i valori dell'accelerometro al database e per controllare il led rgb|
|1x Raspberry pi 3|Utilizzato come webserver e database server|

#### Software

|Nome software|Versione|Utilizzo nel progetto|
|--------|---------|--------------------------------|
|Raspbian| April 2017|Utilizzato come sistema operativo di raspberry|
|Apache| 2.2|Webserver|
|PHP| 5.6|Gestione di php|
|Mysql| 5.5|Database|

## Progettazione

### Design dell'architettura del sistema



![schema generale](Immagini_doc/schemagenerale.PNG)

Il sistema si basa su 3 grossi passaggi di funzionamento.
In primo luogo c'é l'Arduino collegato a vari sensori, questo si occupa di inviare tramite la rete Ethernet i dati rilevati.
Il secondo punto è rappresentato da un (web)Server che implementa il database. Nel DB i dati vengono raccolti e vengono già parzialmente lavorati.
In questa fase è importante notare la presenza di Raspberry, è infatti quest'ultimo che funge da WebServer, questo è un dettaglio che è stato pensato solo in seguito, quando ci si è resi conto che il servizio che doveva ospitare il lavoro non era adatto alle nostre esigenze.
Nel Raspberry è implementato un semplice sistema LAMP su una scheda da 16 GB.
Infine c'é l'utente che chiama la pagina, questo livello è l'ultimo nel percorso dei dati.
Il codice PHP preleva i dati dal DB, li adatta alla visualizzazione sulla pagina e infine li invia alla stessa.
Questo schema ha il vantaggio di poter essere applicato facilmente a qualunque tipo di rilevamento (prendendo chiaramente coscienza di quello che si sta misurando).

<br>

Di seguito uno schema che rappresenta l'archietettura della pagina web, essa è costruita in base a pagine php che vengono utilizzate con 'require'. Questo facilita la comprensione, ottimizza i files utilizzati e facilita la modulabilità.

![schema sito](Immagini_doc/SchemaSito.png)
<br>
<br>

### Design dei dati e database

La parte di design dei dati ha la funzione di mostrare che tipi di dati sono stati assegnati ai vari attributi delle tabelle presenti nel database. L'immagine che segue mostra il design dei dati del database "surveyStation", usato per questo progetto.

<img src="Immagini_doc/Designdeidati.png" />
<br>
Nei campi "Amministratore" e "Email_Notification" ho usato il tipo di dato "tinyint" poiché è molto più conveniente che usare un altro tipo di flag. Si sarebbe potuto usare ad esempio un int e dire che se il campo equivale a 0 il valore è false, mentre se è 1 equivale a true. Sarebbe stata una soluzione che avrebbe portato allo stesso risultato, ma il tipo di dato int è indubbiamente più pesante rispetto al tinyint che assume solamente 2 valori. Per ottimizzare il database, le risorse e la memoria ho deciso di utilizzare questo tipo di dato. Nel nostro progetto la differenza potrebbe non sentirsi poiché le query non occupano tante linee di codice, ma in altri progetti l'ottimizzazione della memoria è cruciale ed è quindi meglio prevenire i disagi legati alle prestazioni.

Lo stesso discorso vale per la scelta effettuata sugli identificatori di ogni tabella. Ho utilizzato il tipo di dato int al posto di un dobule o di un float poiché le chiavi primarie sono sempre caratterizzate da numeri primi e quindi sarebbe stato inutile e dispendioso utilizzare dei tipi di dato che usano la virgola.

Nelle tabelle sismografo e shake, nei campi dove vanno inseriti i valori, ho preferito optare per un tipo di dato int piuttosto che altri poiché per la nostra analisi vanno benissimo i numeri senza virgola. Ciò comporta, come spiegato in precedenza, un miglioramente delle prestazioni e un risparmio di memoria.


### Schema E-R, schema logico e descrizione.

Lo schema E-R è fondamentale per la creazione di un database e quindi sono dovuto partire da qui per poi passare a scrivere il codice sql. Qui di seguito si può osservare come ho pensato di strutturare il database con le rispettive tabelle.

<img src="Immagini_doc/ER.png" />
<br>
Per creare questo schema ho pensato a come questo progetto verrà utilizzato. Ovviamente diverse persone vi accederanno con il proprio account e ciò mi ha fatto subito pensare ad una tabella che gestisca gli utenti che usufruiscono del servizio da noi messo in piedi.
<br>
L'arduino, al quale è attaccato un sensore, si occupa di percepire le vibrazioni terrestre che avvengono e quindi i dati da esso registrati devono essere registrati da qualche parte. Da qui è nata la tabella sismografo.
<br>
Ovviamente, e auspicabilmente, la maggior parte dei dati registrati dall'arduino ed inseriti nella tabella sismografo sono insignificanti poiché non permettono di osservare nulla. La parte "interessante", dal punto di vista d'analisi, si verifica quando vi è una scossa di ciò che secondo l'arduino è etichettabile come una scossa di terremoto. Ho creato la tabella Shake per poterci inserire i dati interessanti e in modo da facilitare il lavoro anche a coloro che si sono occupati della rappresentazione grafica dei dati in questione.
<br>
Salta subito all'occhio che le tabelle presenti nello schema non sono in nessun modo relazionate tra di loro. Non si tratta di un errore o di disattenzione, ma semplicemente per raggiungere il nostro obiettivo non c'era il bisogno di creare delle relazioni.
<br>
Nella tabelle "utente" l'identificatore primario è il campo "email". Abbiamo optato per questa soluzione poiché due o più utenti non possono avere lo stesso indirizzo email e ciò fa risparmiare anche memoria, oltre che a rendere più ordinata e pulita la tabella e il codice che la riguarda.  


### Arduino

#### Struttura

La struttura è stata progettata per contenere Raspberry, Arduino, Veroboard (con su saldati accelerometro e led) e Breadboard per eventuali lavori o aggiunte future.

![schema sito](Immagini_doc/struttura.jpg)

L'accelerometro è stato collegato ad un Arduino con il collegamento per il cavo Ethernet tramite i pins 'scl' e 'sda', poi per l'alimentazione del componente viene usato un voltaggio di 3,3V e infine viene collegato al gnd per andare a massa.
Il led RGB viene collegato al gnd, al pin 6 per il colore rosso e 5 per il colore verde, il pin blu del componente non viene utilizzato poichè al momento non serve il colore blu in quanto questo led viene utilizzato come segnale in caso di rilevamento di un sisma, in questo caso il led diventerà di colore rosso, nel secondo caso quando non viene rilevato niente, il led rimarrà di colore verde.

![schema sito](Immagini_doc/SchemaSismografo.png)


#### Codice
Lo scopo di Arduino e del suo codice è quello di prelevare i dati rilevati dall'accelerometro, contattare il server e la pagina PHP di riferimento, creare l'URL con i relativi valori e spedirli. Oltre a ciò si deve occupare di controllare i dati e, nel quale ci fosse un'anomalia o un terremoto, illuminare l'apposito led.
<br>
Il codice di Arduino importa tre librerie esterne:
- <b>Ethernet:</b> include tutte le funzioni per eseguire le connessioni e le richieste.
- <b>SPI:</b> serve da supporto alla libreria Ethernet.
- <b>SFE_MMA8452Q:</b> questa libreria implementa la completa gestione dell'accelerometro.

![schema sito](Immagini_doc/toPagePHP_UML.jpg)

<br>
<b>Attributi:</b>

- <b>redPin:</b> È il pin con cui alimentare il colore rosso del led. <br>
- <b>greePin:</b> È il pin con cui alimentare il colore verde del led. <br>
- <b>mac:</b> È il MAC Address della scheda Arduino. <br>
- <b>serverIp:</b> È l'indirizzo IP del server. <br>
- <b>arduinoIp:</b> È l'indirizzo IP di Arduino. <br>
- <b>client:</b> È il client ethernet. Serve a contattare il server e la pagina PHP. <br>
- <b>strURL:</b> È la stringa URL che si spedirà tramite client. All'interno di essa si formatterà un URL con la pagina da chiamare e i valori di X, Y e Z. <br>
- <b>accel:</b> È l'istanza dell'accelerometro.

<br>
<b>Funzioni:</b>

- <b>setup(): </b> Funzione di settaggi e istanze.<br>
- <b>loop(): </b> Innanzitutto richiama la funzione updateValues. Dopodichè controlla se il client è disponibile. Se non lo è stampa un messaggio d'errore.<br>
- <b>updateValues(): </b> Per prima cosa si connette al server, successivamente controlla se l'accelerometro è disponibile. Nel caso di un riscontro positivo si verificano le coordinate prelevate dal sensore. Infine si crea la stringa con i valori formattata con le regole di un URL.<br>

#### Pagina PHP
Il lavoro che deve fare la pagina PHP è quello di recuperare X, Y e Z dall'URL trasmesso da Arduino. Dopodichè deve connettersi al database "surveystation" e alla tabella "sismografo". La pagina si deve occupare di creare la query e di eseguirla correttamente.

## implementazione

#### Codice di Arduino
Nel codice di Arduino sono statie aggiunte modifica per quando si prendono i dati, inizialmente quando si posizionava il prodotto doveva essere messo orizzontale al piano per avere una situazione di calma da un terremoto è quando si inclinava risultava che c'era uno scossone, il problema si situava nell'if perchè prima veniva visto lo spostamento senza un confronto dei dati trovati prima. Il codice è stato ristrutturato in modo per far usare l'arduino anche in un piano inclinato:

(cxi < (accel.cx + margine) && cxi > (accel.cx - margine)) || (cyi < (accel.cy + margine) && cyi > (accel.cy - margine)) || (czi < (accel.cz + margine) && czi > (accel.cz - margine))

Questo serve per vedere quando il sismografo sia effetivamente in un caso di terremoto.
cxi, cyi, czi sono i dati precedentemente calcolati dal sismografo che vengono comparati con i dati trovati nell'istante con un margine per fare in modo che i dati abbiamo un differenziale.

Per esempio:

margine = 0.03;

cxi = 0.06;

accel.cx = 0.08;

In questo caso si entrerà nell'if perchè cxi è diverso da accel.cx più il margine di errore.
Nel codice di Arduino è stato tolto anche il delay perchè rallentava il programma.
Qunado il delay è stato tolto il grafico era più fluido perchè non aveva problemi nell'inviare dati, ci sono ancora dei problemi perchè quando arrivano dei dati alti il grafico si blocca per un paio di secondi ma puoi continua a far vedere gli altri dati.

#### Pagina PHP
Nel codice della pagina PHP sono state aggiunte delle modifiche per la parte delle mail anche se con insuccesso, avevamo installato il protocollo ssmpt per poter inviare delle mail in caso di un terremoto e abbiamo creato un if che controlla i valori x, y e z del sismografo e in caso di terremoto mandava una mail a chi aveva confermato l'opzione della notifica tramite mail
il metodo in php che abbiamo usato è questo: mail(to,subject,message,header)

### Database
Nel codice del database era stata applicata una modifica che però aveva danneggiato il database quindi non è stata applicata, il pezzo di codice che avevamo aggiunto era un trigger che serviva a limitare il carico di dati del database nella tabella sismografo, questo era il codice di test che era stato testato sulla macchina di luca in locale:
![test trigger](Immagini_doc/codice_test_trigger.png)


### Sito Web

## Test

### Protocollo di test

### Risultati test

### Mancanze/limitazioni conosciute

## Consuntivo
![gantt consuntivo](../GanttConsuntivo.gan)

## Conclusioni

### Sviluppi futuri
Per questo progetto ci sarebbe da correggere il sito siccome possiede alcuni bug (non del tutto responsive) e poi ci sarebbe da far funzionare la parte delle mail
### Considerazioni personali

## Bibliografia

### Sitografia
- https://www.w3schools.com/php/php_ref_mail.asp per il codice php delle mail
- https://www.w3schools.com/php/func_mysqli_query.asp per le query sql tramite php


## Allegati
