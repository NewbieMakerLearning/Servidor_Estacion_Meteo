# Servidor_Estacion_Meteo
 Servidor operativo 2021_01_19

Por fin ha llegado el momento de poder compartir un proyecto con la comunidad Open Source. Antes de continuar he de aclarar que no soy experto en ningún ámbito que este proyecto pueda abarcar. Es por ello que lo que compatiré aquí es mejorable, habrá fallos de una persona novata, pero también encontraréis mi satisfacción de poder contribuir al código libre y a la cultura de compatir es evolucionar y avanzar.

He intentado poner enlaces y agradecer a todas esas personas que me ayudaron desinteresadamente a resolver mis dudas, algunos respondiendo directamente a mis preguntas y otros compartiendo sus estupendos trabajos. A todos aquellos que dan información por el motivo que sea, resumiendo, he intentado ser meticuloso en este tema pero seguramente, me habré dejado algunos, **mil disculpas**.

Después de esta breve explicación, continuemos.

Al principio iba a poner un solo sensor, el BME280 que mide temperatura, humedad y presión. Como era y soy bastante novato fui viendo posibilidades, al igual que con la parte
del [cliente](https://github.com/NewbieMakerLearning/Cliente_Estacion_Meteo). Informándome sobre meteorología vi que es un tema en el que se puede profundizar bastante. Aprendí que con unas ["simples fórmulas"](https://es.wikipedia.org/wiki/Punto_de_roc%C3%ADo), que la comunidad Arduino [compartió](https://forum.arduino.cc/index.php?topic=552050.0), podía añadir una medida más y hayar el punto de rocío y la sensación térmica. Este último valor no está puesto porque leí que no es muy fiable en el ámbito de
la meteorología.

Fui descubriendo una gran variedad de sensores que servirían para tener una información más amplia así que los añadí. Antes de pasar a los sensores, breve introducción a la placa usada.

  ### **NodeMCU**

<p align="center">
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/NodeMCUv3.jpg" width="450" title="hover text">
  </p>
<br>

Poco que añadir a esta placa. [iNFO PLACA](http://nodemcu.com/index_en.html). Basada en el ESP8266.

Tiene un puerto micro USB

Conversor Serie-USB, el CH340G

un LED conectado al pin 2 o D4 y dos botones, uno para reinicio y otro para flasheo.

Se alimenta a 3,3V.

3 salidas de 3,3V

1 de 5 (Solo da 5V si en las otras no hay nada conectado, **_no lo he probado_**)

La v3 que yo tengo, solo se puede usar a 9600 bps. Al establecer conexión mediante el puerto serie, Serial.begin (9600);

Necesataremos 2 placas.

Os detallo los que actualmente están operativos.

  ### **BME280**


  ### **ML8511**
  ### **BH1750**
  ### **ARGENT DATA SYSTEMS**
  
