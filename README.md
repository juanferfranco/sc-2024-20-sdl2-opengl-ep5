# OpenGL SDL2

Proyecto para realizar experimentos con el curso de Mike Sha sobre openGL

Para adicionar soporte de opengl moderno y poder cargar dinámicamente las funciones de opengl que traen los drivers de las GPU se usa GLAD. 
En este sitio se pueden generar los archivos .h y .c necesarios para poder hacer la carga de opengl: [glad site](https://glad.dav1d.de/).

Para la configuración en el API GL seleccionar 4.6. En Windows hay soporte sin problema hasta esa versión de OPENGL, creo que en macOS 
solo llegó hasta la 4.1. El API actual de macOS es Metal. Profile: core. Esta opción elimina las funcionalidades antiguas de 
versiones 1 y 2 de opengl y solo deja las funciones modernas.

Luego, se adicionan todas las funciones: ADD ALL

En las opciones se puede dejar seleccionado solo Generate a loader. Presionar generate. En este sitio se baja el .zip y luego se adiciona el 
archivo .c al proyecto y en la propiedades se incluye el directorio includes (que puede guardarse en la misma carpeta del proyecto). Este 
directorio contienen los archivos de cabezera de glad. Finalmente, es importante no olvidar incluir en las dependencias del enlazador la 
biblioteca openGL32.lib que viene con el Windows Kit. Esta bibliteca contienen las entradas para las funciones básicas de openGL en Windows, 
pero no contiende las funciones modernas de openGL que vienen con los dirvers de la GPU. Estas funciones se deben cargar, precisamente con 
glad, al programa en tiempo de ejecución 

## Archivos por episodio

* En el episodio 5 simplemente se configuró opengl y se cargó en tiempo de ejecución las funciones modernas de opengl que provee el driver
  de la GPU. El archivo es ep5FinalVersion.txt. Considerar que con esta versión se ejecutarán los primeros comandos de opengl, 



## Conceptos fundamentales de OpenGL

Concepto fundamental. Leer este material:

[Rendering Pipeline Overview - OpenGL Wiki](https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview)

[OpenGL Context - OpenGL Wiki](https://www.khronos.org/opengl/wiki/OpenGL_Context)

[Debugging Tools - OpenGL Wiki](https://www.khronos.org/opengl/wiki/Debugging_Tools)

En el episodio 6 se comienza a discturir sobre aquellos conceptos necesarios para poder renderizar el primer 
triángulo en pantalla usando opengl. En particular, se muestran tres elementos fundamentales: 
Vertex Array Object (VAO) y Vertex Buffer Object (VBO). Cada uno 
de estos objetos son fundamentales para poder renderizar un objeto en pantalla. Los VBO son realmente 
los datos que se van a renderizar en pantalla, mientras que los VAO son los objetos que contienen la 
configuración de los VBOs o cómo acceder a los datos de los VBOs.

![image](https://github.com/user-attachments/assets/8ba2c36c-6009-4c59-be87-e2ed3f7d8aa9)

En el episodio 7 se introduce el concept de shaders. Los shaders son programas que se ejecutan en la GPU. 
En particular, se muestran dos tipos de shaders: Vertex Shader y Fragment Shader. El Vertex Shader se 
ejecuta una vez por cada vértice que se renderiza en pantalla. El Fragment Shader se ejecuta una vez por 
cada pixel que se renderiza en pantalla.

![image](https://github.com/user-attachments/assets/24c7c7f3-9730-4dcb-97c2-8d042657954f)



