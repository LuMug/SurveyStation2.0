# Survey station
1. [Introduzione](#introduzione)

  - [Informazioni sul progetto](#informazioni-sul-progetto)

  - [Abstract](#abstract)

  - [Scopo](#scopo)

2. [Analisi](#analisi)

  - [Analisi del dominio](#analisi-del-dominio)

  - [Analisi dei mezzi](#analisi-dei-mezzi)

  - [Analisi e specifica dei requisiti](#analisi-e-specifica-dei-requisiti)

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
