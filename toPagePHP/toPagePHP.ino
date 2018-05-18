
/**
 * Classe toPagePHP
 * Classe che contatta una pagina PHP su un server e gli spedisce dei dati.
 */
#include <SPI.h>
#include <Ethernet.h>
#include <SFE_MMA8452Q.h>

/**
 * Pin per il notificatore multicolore
 */
int redPin = 5;
int greenPin = 6;

/**
 * Indirizzo MAC di Arduino
 */
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x26, 0x5E };

/**
 * Indirizzo IP del server
 */
IPAddress server(10, 20, 4, 238); 
 
/**
 * Indirizzo IP di Arduino
 */
IPAddress ip(10, 20, 4, 105);

/**
 * Client
 */
EthernetClient client;
 
String strURL = "";

/**
 * Istanza di acceleromeetro
 */
MMA8452Q accel;

void setup(){
  //Serial.begin(9600);

  /**
   * Metodo che setta all'accelerometro scala e frequenza
   */
  accel.init(SCALE_2G, ODR_400);
  
    Serial.println(Ethernet.begin(mac));
  if (Ethernet.begin(mac) != 0){
    Ethernet.begin(mac, ip);
  }else{
    Serial.println("Errore");
  }
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  

  /**
   * Connessione al server
   */

  //delay(100);
}
double cxi;
double cyi;
double czi;
void loop(){
  /**
   * Aggiorno i valori
   */
  client.connect(server, 80);
  UpdateValues();
  //while(client.available()){
  //  char c = client.read();
  //  Serial.print(c);
  //}
      cxi = accel.cx;
      cyi = accel.cy;
      czi = accel.cz;
  //delay(100);
}

void UpdateValues(){
 // Serial.println("Connessione...");

   // Serial.println("Connesso");
    /**
     * Controllo la disponi
     */
    if(accel.available() == 1){
      accel.read();
      /**
      * Notificatore fisico
      */
      /**
      * I range sono stati adattati alla posizione dell'accelerometro.
      */
      /*  
      if((accel.cx < -0.015 || accel.cx > 0.015) || (accel.cy < 0.04 || accel.cy > 0.7) || (accel.cz < 0.97 || accel.cx > 1)){
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
      }else{
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
      }
      */
      double margine = 0.01;
      if((cxi < (accel.cx + margine) && cxi > (accel.cx - margine)) || (cyi < (accel.cy + margine) && cyi > (accel.cy - margine)) || (czi < (accel.cz + margine) && czi > (accel.cz - margine)))
      {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
      }else{
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
      }
      /**
      * Creazione dell'URL
      */
      strURL = "GET /index.php?x=";
      strURL += accel.cx;
      strURL += "&y=";
      strURL += accel.cy;
      strURL += "&z=";
      strURL += accel.cz;
      strURL += " HTTP/1.1";
      Serial.println(strURL);
      //invio la richiesta al server
      client.println(strURL);
      client.println("Host: 10.20.4.202");
      client.println("Connection: close");
      client.println();
      //delay(10);
      //chiudo la connessione
      client.stop();
    }else{
      Serial.println("Accelerometro non disponibile.");
    }
}
