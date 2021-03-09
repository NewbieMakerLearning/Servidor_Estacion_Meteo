## No me cabrían todos los problemas que tuve...así que pongo algunos.

### El firewall.

Al intentar actualizar vía OTA tuve que romperme un poco la cabeza hasta dar con el problema de porque no lo conseguía.

Por muchos ejemplos que veía y ponía en práctica, no conseguía conectar a mi placa.

<p align="center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ERROR_IDE.JPG" width="650" title="hola amigo">
    </p>
    <br>

No se como pensé en que tal vez el maravillo firewall estaría bloqueando la conexión, y así era.

Uso NOD32 y para solucionar este problema hice lo siguiente.

<p align="center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ESET1.JPG" width="550" title="hola amigo">
    </p>
    <br>

Fui hasta _Configuración/protección de la red_, le di al engranaje de la derecha y elegí _configurar_

<p align="center">
    <img src="https://github.com/NewbieMakerLearning/Servidor_Estacion_Meteo/blob/master/pictures/ESET1.JPG" width="550" title="hola amigo">
    </p>
    <br>

En la parte _Básico/modo de filtrado_ le di a _modo interactivo_ y tras aceptar volví al IDE y probé la conexción. Inmediatamente me salto un aviso del firewall avisándome de la conexión. Aceptar y poner otra vez en modo automático porque si no hacemos esto, a cada rato tendremos avisos de estos que al final a mi me molestan.

### El IDE no encuentra mi placa

Has de decirle a cualquier IDE que placa vas a usar. En el IDE de Arduino has de ir a **_Archivo/Preferencias** En **_Gestor de URLs..._** ponemos la siguiente dirección:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json,https://dl.espressif.com/dl/package_esp32_index.json
```
