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
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/NodeMCUv3.jpg" width="550" title="hover text">
  </p>
<br>

Poco que añadir a esta placa. [info de la placa](http://nodemcu.com/index_en.html). Basada en el ESP8266.

Tiene un puerto micro USB

Conversor Serie-USB, el CH340G

un LED conectado al pin 2 o D4 y dos botones, uno para reinicio y otro para flasheo.

Se alimenta a 3,3V.

3 salidas de 3,3V

1 de 5 (Solo da 5V si en las otras no hay nada conectado, **_no lo he probado_**)

La v3 que yo tengo, solo se puede usar a 9600 bps. Al establecer conexión mediante el puerto serie, Serial.begin (9600);

<p align="center">
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/NodeMCU-pines.png" width="550" title="hover text">
  </p>
<br>

Necesiataremos 2 placas, una la llamo servidor y la otra cliente.

Ahora los sensores. Os detallo los que actualmente están operativos.

  ### **BME280**

<p align="center">
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/BMP280.jpg" width="550" title="hover text">
  </p>
<br>
- Temperatura (rango de -40 a + 85 °C, precisión ±1 °C y resolución 0,01 °C)

- Humedad (a 100%, con una precisión de ±3% Pa y una resolución de 0.008%)

- Presión (300-1100 hPa, precisión de ±1 Pa, y resolución de 0,18 Pa)

- Current consumption -1.8 μA a 1Hz - Humedad y temperatura

    - 2.8 μA a 1Hz - Presión y temperatura

    - 3.6 μA a 1Hz - Humedad, presión y temperatura

    - 0.1 μA in sleep mode

    - V 3,3V

Necestaremos 2 sensores.

  ### **ML8511**

<p align="center">
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ML8511.jpg" width="550" title="hover text">
  </p>
<br>
- Longitud de onda: 280-390nm

- Current consumption 300 μA standby current 0.1 μA

El sensor UV ML8511 necesita dos pines analógicos y el NodeMCU dispone de 1, necesitamos un multiplexor/desmultiplexor, como el ADS1115.

<p align="center">
    <img src= "https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ADS1115_ADC_pines.png"> width="550" title="hover text">
    </p>
    <br>
Según el ejemplo de Sparkfun, las conversiones analógicas a digitales dependen completamente del voltaje. Si alimentamos el sensor mediante la placa y esta a través de un USB, el voltaje puede variar de 5,25V a 4,75V. Por eso utilizaremos los 3,3V del NodeMCU. El pin marcado con 3,3V del sensor irá conectado a 3,3V y al pin A1 del ADS1115. El pin Out irá al pin analógico A0 del ADS1115. El EN ira a 3,3V también. Si eres como yo, con una imagen lo entenderás mejor.


<p align="center">
  <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ADS1115_ADC.png" width="550" title="hover text">
  </p>
<br>

  ### **BH1750**

  Las características del sensor BH1750 son las siguientes:

- Interfaz I2C con dos posibles direcciones. 0x5C y 0x23 (por defecto).
- Representación del espectro apróximadamente a la del ojo humano.
- Alta resolución, (1 - 65535 lx)
- Baja dependencia al tipo de luz. (Incandescente, fluorescente, halógena, LED, sol)
- Resultado de medición ajustable teniendo en cuenta el "cascarón" que cubre el sensor. (Es posible detectar un mínimo de 0,11 lx, un máximo de 100000 lx utilizando esta función.)
- Baja influencia de luz infrarroja.

- Especificaciones:

    - Voltaje
        * mín 2,4V
        * max 3,6V
        * Resolución 4lux, 1lux, 0,5lux. Usando la resolución de 1lux permite distinguir iluminaciones por debajo de los 10lux (luz crepúscular) Para 1 lux y 4 lux se usan los 16bits de datos, llegando a los 65535 lux (día soleado sin luz directa) En el modo 0,5 lux usa 15 bits y puede representar un valor máximo de 32767 lux (exterior sin luz directa) Fuente
    - Consumo
        * mín 0,01 μA
        * max 190 μA

Necestaremos 1 sensor.

  ### **ARGENT DATA SYSTEMS**
  
Con los sensores anteriores ya tenía una estación más o menos adecuada, pero me faltaba dos mediciones muy importantes, la lluvia y el viento. Con el combo de Argent Data Systems podía medir la precipitación gracias al pluviómetro y mediante programación la lluvia acumulada en 1h y en 24h. Una veleta, para saber la dirección del viento, mediante código desde que punto cardinal y desde que grado, y un anemómetro, para saber la velocidad del mismo. 

Ya tenía el hardware, ¿y ahora qué?

Con todos estos datos pensé en hacer una web para poder mostrarlos. Estaba aprendiendo a programar con Arduino, a desembolverme con la electrónica, a entender mínimamente la meteorología y sobre todo, recorrer lo que llamamos el camino de la vida con lo que ello conlleva, así que añadir HTML, CSS y yo que se más, me iba a llevar mucho tiempo si quería dar el 100% de mi capacidad. Pensé que seguramente habría algo ya realizado por alquien y podría adaptarlo a mis necesidades. Por supuesto si que lo hay.

Elegí la plataforma de Thinger.io porque me pareció visualmente atractiva.

<p align="center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/Dashboard_Thinger1.JPG" width="650" title="hola amigo">
    </p>
    <br>

Este es mi panel de pruebas, como podéis ver se puede añadir alguna imagen a los paneles, poner un mapa y por supuesto, gráficas.

<p aligh= "center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/Dashboard_Thinger2.JPG" width="550" title="what's up">
    </p>
    <br>

Y un detalle que me gustó fue el de poner una cuenta con retroceso para saber cuando se va a actualizar el panel.

<p aligh="center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/Dashboard_Thinger3.JPG" width="550" title="hola">
    </p>
    <br>


