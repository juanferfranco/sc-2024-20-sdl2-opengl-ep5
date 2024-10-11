# OpenGL SDL2

Proyecto para realizar experimentos con el curso de Mike Sha sobre openGL

Para adicionar soporte de opengl moderno y poder cargar dinámicamente las funciones de opengl que traen los drivers de las GPU se usa GLAD. En este sitio se pueden generar los archivos 
.h y .c necesarios para poder hacer la carga de opengl: [glad site](https://glad.dav1d.de/).

Para la configuración en el API GL seleccionar 4.6. En Windows hay soporte sin problema hasta esa versión de OPENGL, creo que en macOS solo llegó hasta la 4.1. El API actual de macOS es Metal.  
Profile: core. Esta opción elimina las funcionalidades antiguas de versiones 1 y 2 de opengl y solo deja las funciones modernas.

Luego, se adicionan todas las funciones: ADD ALL

En las opciones se puede dejar seleccionado solo Generate a loader. Presionar generate. En este sitio se baja el .zip y luego se adiciona el archivo .c al proyecto y en la propiedades se incluye el directorio includes (que puede guardarse en la misma carpeta del proyecto). Este directorio contienen los archivos de cabezera de glad. Finalmente, es importante no olvidar incluir en las dependencias del enlazador la biblioteca openGL32.lib que viene con el Windows Kit. Esta bibliteca contienen las entradas para las funciones básicas de openGL en Windows, pero no contiende las funciones modernas de openGL que vienen con los dirvers de la GPU. Estas funciones se deben cargar, precisamente con glad, al programa en tiempo de ejecución 

## Archivos por episodio

* En el episodio 5 simplemente se configuró opengl y se cargó en tiempo de ejecución las funciones modernas de opengl que provee el driver de la GPU. El archivo es ep5FinalVersion.txt
* 




