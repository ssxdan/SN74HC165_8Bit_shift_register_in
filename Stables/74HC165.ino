/*
 * Shift Register de entrada
 * Lee los valores de sus 8 entradas en paralelo y las carga en su memoria, tras esto permite mandarlas de manera serie usando una señal de reloj
 * http://picrobot.blogspot.com.es/2008/11/shift-register-que-son-y-como-se-usan.html
 * 
 * SSXDan 25/11/2016
 */

const int clk = 12;    // Reloj que marta el ritmo de la salida de datos.
const int load = 13;   // Cuando se pone a 0 se cargan los valores de las patas en memoria.
const int out = 11;    // Salida de los registros.



void setup() {
  // Inicar puertos:
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(out, INPUT);

  Serial.begin(9600);


}

void loop() {
  Serial.println("Modo 1");
  Serial.println(leeRegistro());
  delay(1000);
  Serial.println();
  Serial.println("Modo2");
  Serial.println(leeRegistro2());
  

}

int leeRegistro2(){
  //Load a 0 para cargar los valores en los registros internos.
  digitalWrite(load, LOW);
  delayMicroseconds(500);
  //Load a 1 ya se han cargado los valores.
  digitalWrite(load, HIGH);

  return shiftIn(out, clk, MSBFIRST);
  
}

int leeRegistro(){
  //Variables auxiliares.
  int numRegistros = 8;
  int posicion = 0;
  int valores = 0;

  //Load a 0 para cargar los valores en los registros internos.
  digitalWrite(load, LOW);
  delayMicroseconds(500);
  //Load a 1 ya se han cargado los valores.
  digitalWrite(load, HIGH);

  //Leer las posiciones y muestre el valor de cada una.
  for( posicion=0; posicion<=7; ++posicion ){ 
     
      //Cargamos el valor que hay en el puerto de entrada.
      valores <<= 1;
      valores += digitalRead(out);
      delay(20);
      Serial.println("Puerto " + (String)posicion + ": " + digitalRead(out));

      //Generamos un ciclo de reloj para que el 74HC65, nos muestre el valor del siguiente registro.
      digitalWrite(clk, LOW);
      delay(20);
      digitalWrite(clk, HIGH);
  }
  
}

