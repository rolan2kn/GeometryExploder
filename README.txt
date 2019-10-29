
DEPENDENCIAS

fuente: https://rizaldijs.wordpress.com/2017/10/28/setting-up-glfw-glad-with-clion-on-ubuntu/


Instalar dependencias en Ubuntu:

sudo apt install -y xorg-dev libgl1-mesa-dev libglu-dev libassimp-dev
###------------------------------------------------------------------------------------

glew: Biblioteca de extensiones OpenGL para trabajar con shaders.

web: http://glew.sourceforge.net

Ubuntu Instalación:
sudo apt-get install libglew-dev

Recuerde enlazar el proyecto en el Makelist con glew32.lib, glu32.lib, y opengl32.lib en Windows
y libGLEW.so, libGLU.so, y libGL.so on Unix (-lGLEW -lGLU -lGL).**

###------------------------------------------------------------------------------------

glm: OpenGL Mathematics, un archivo cabecera basado en GLSL.
 Provee fyunciones y clases para lidiar con vectores, matrices, quaterniones, etc.

web: http://glm.g-truc.net/0.9.8/api/index.html

Ubuntu Instalación:
-paquete:

sudo apt install libglm-dev

####------------------------------------------------------------------------------------

Open Asset Import Library (nombre corto: Assimp)
Es una libreria Open Source para importar varios formatos de modelos 3D conocidos de manera uniforme.

web: http://www.assimp.org/

Ubuntu Instalación:
-paquete:
sudo apt-get install libassimp-dev assimp-utils
sudo apt-get install libxmu-dev libxi-dev

####------------------------------------------------------------------------------------

GLFW es una biblioteca Multiplataforma, Open Source, para el desarrollo en OpenGL, OpenGL ES y Vulkan.
Provee un API simple para crear Ventanas, contextos y superficies que reciben eventos y entradas del usuario.

Ubuntu Instalación:
- paquete:
sudo apt-get install libglfw3-dev libglfw3

- github:

git clone https://github.com/glfw/glfw.git
cd glfw
cmake ./
make
sudo make install


####------------------------------------------------------------------------------------

glad:  es una biblioteca Multiplataforma, Open Source, para el desarrollo en OpenGL, OpenGL ES y Vulkan.
Provee un API simple para crear Ventanas, contextos y superficies que reciben eventos y entradas del usuario.

Ubuntu Instalación:

github:

git clone https://github.com/Dav1dde/glad.git
cd glad
cmake ./
make
sudo cp -a include /usr/local/

####------------------------------------------------------------------------------------

stb: Biblioteca simple para trabajo con imagenes en opengl soporta pocos formatos.
repositorio publico en https://github.com/nothings/stb


Instalación en Ubuntu:

github:
git clone https://github.com/nothings/stb.git
cd stb
cp -a stb* /usr/local/include/

 ####------------------------------------------------------------------------------------

 SOIL: Simple OpenGL Image Library

 Es una mini-biblioteca hecha en c, utilizada fundamentalmente para cargar texturas en OpenGL.
 Está basada en tsb_image version 1.6, fundamentalmente le añade soporte a archivos TGA y DDS,
 y ademas encapsula funciones necesarias para cargar texturas OpenGL. Ademas puede usarse para cargar y salvar
 imagenes en una variedad de formatos. mas info en: https://www.lonesock.net/soil.html

 Instalación en Ubuntu:

- paquete:

Promero descargue el fichero SOIL.h desde su sitio web http://www.lonesock.net/soil.html

Ponlo en el proyecto e incluyelo en el makelist. Instala el paquete

    sudo apt-get install libsoil-dev

para linkear (makelist) use -lSOIL

- codigo:

 Para usar SOIL, se descargó en un .zip (desde https://www.lonesock.net/soil.html) y luego en la terminal, ir a la carpeta projects/makefile y teclear:

$make
$make install

Entonces se puede usar la libreria incluyendo SOIL.h en tu archivo C++.

