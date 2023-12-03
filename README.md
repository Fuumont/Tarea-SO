# Tarea 2: Procesamiento paralelo de im´agenes utilizando hebras.

Integrantes:
- Andrés Azuaje
- Sebastián Vásquez

# Instrucciones

Antes de ejecutar los programas es necesarios tener un par de cosas instaladas, para esto se deben ingresar los siguientes comandos en la terminal de linux:
- sudo apt install opencv-data
- sudo apt install python3-opencv

Con esto se instalara el compilador GNU g++, la libreria OpenCV y las dependencias de esta librería, todo esto es necesario para que el programa funcione correctamente

También se puede instalar esta librería si el programa aun no funciona con las anteriores
- sudo apt install libopencv-dev

Para comprobar que la librería funciona correctamente hay que utilizar PKG, para instalarlo hay que ingresar el comando
- sudo apt install pkg-config

Ya instalado PKG hay que ingresar el comando 
- pkg-config --cflags --libs opencv4

Si este comando genera un error significa que no se está encontrando la ubicación de la librería, esta se puede obtener con
- dpkg -L libopencv-dev | grep pkgconfig

Este comando debería desplegar dos rutas, de las cuales solo nos interesa la que diga "openvc4". Lo siguiente es ingresar este comando para exportar pkg a la ruta de opencv
- export PKG_CONFIG_PATH=(ruta obtenida anteriormente):$PKG_CONFIG_PATH

Ejecutar nuevamente pkg-config --cflags --libs opencv4 para comprobar si funciona, si aún no lo hace volver a ingresar en anterior comando pero de la siguiente forma
- export PKG_CONFIG_PATH=(ruta obtenida anteriormente)

Con todo esto ya realizado, se debe ingresar a la carpeta del programa que se desea ejecutar usando cd en la terminal, y escribiendo "make" en cualquiera de los 3 se compilará el programa, si no lo hace, lo más probable es que sea porque el archivo Makefile no encontró la librería OpenCV, asegúrese de tenerla instalada.

Para ejecutar cualquiera de los programas hay que escribir el siguiente comando
- ./(nombre programa) (nombre de la imagen.jpg) (nombre de la imagen de salida)

Reemplazando (nombre programa) con el nombre del programa de dicha carpeta; (nombre de la imagen.jpg) con la imagen que se desea transformar a escala de grises, dentro de las carpetas hay imágenes de prueba para ejecutar el programa, pero también puede usarse cualquier otra que se añada a la carpeta, siempre y cuando sea esta sea un archivo .jpg o .png; por ultimo (nombre de la imagen de salida) se reemplaza con el nombre de la imagen que saldrá en escala de grises, la única restricción es que esta debe ser el mismo tipo de archivo de la imagen de entrada (jpg o png). Para los casos de Hebras y OpenMP además hay que añadir un número al final del todo, el cual representa la cantidad de hebras que se quiere utilizar para ejecutar el programa, que por defecto son 4.

Aquí un ejemplo de los comandos de los programas usando las respectivas imágenes de las carpetas:

Secuencial:
- make
- ./gris esponja.jpg esponjasincolor.jpg

Hebras:
- make
- ./hebras fraudkuna.jpg grayfraudkuna.jpg 6

OpenMP:
- make
- ./mp jogoat.jpg jogoatGris.jpg 4

Por último, se puede ingresar el comando "make clean" para eliminar el archivo compilado de su respectiva carpeta.
