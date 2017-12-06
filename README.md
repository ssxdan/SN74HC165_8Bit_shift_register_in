# 74HC165 Expandir entradas digitales arduino.

Con el proyecto del terrario automatizado, me he quedado sin puertos en el ESP8266, mirando un poco por internet, he encontrado el 74HC595, el cual permite añadir 8 salidas digitales al ESP8266, para este hay tutoriales de sobra.

Para expandir puertos de entrada se utiliza el 74HC165, para este no hay tanta documentación (en Español), así que dejo por aquí mi aportación.

Antes de seguir, lo bueno de estos registros de desplazamiento es que se pueden unir tantos como se quiera y no hacen falta más conexiones, usando 3 cables puedes tener 64 puertos de entrada.

## Funcionamiento del 74HC165.
<div style="text-align:center"><img src ="https://github.com/ssxdan/SN74HC165_8Bit_shift_register_in/blob/master/Documentacion/882194.gif" /></div>

El 74HC165 es un registro de almacenamiento, que permite leer los valores de sus patas de manera paralela y mandarlos secuencialmente.

Poniendo su pata 1(Load) a LOW, los valores que hay en las patas [3-6] y [11-14] se almacenan en los registros internos del 74HC165, para poder acceder a ellos hay que poner de nuevo la pata  1(Load) a HIGH.

Los valores de los registros se van mostrando por su pata 9(out), y para pasar al siguiente hay que mandar una señal de reloj.

Si se quieren unir dos registros solo hay que unir la pata 9 el primero con la 10 del último y que compartan tanto la señal de reloj como la señal de Load.

## Esquema de conexiones:
![conexiones](https://github.com/ssxdan/SN74HC165_8Bit_shift_register_in/blob/master/Documentacion/74HC165_bb.png)
