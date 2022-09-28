#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


//Idenficadores de los objetos de la escena
int objId =-1;//id del objeto de la escena a pintar

//Declaración de CB, es decir funciones call back, funcion de llamada que va ejecutarse siempre que ocurra un evento
void resizeFunc(int width, int height);//cambio de tamaño de pantalla
void idleFunc();//iddle, hace que hagan cosas los elementos de la escena
void keyboardFunc(unsigned char key, int x, int y);//funciones de teclado
void mouseFunc(int button, int state, int x, int y);//funciones de raton
void mouseMotionFunc(int x, int y);//mas funciones de raton


int main(int argc, char** argv)
{   //declaracion de vartiables locales
	std::locale::global(std::locale("spanish"));// acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v1.vert", "../shaders_P1/shader.v1.frag"))//llamada al shader de fragmentos y de vertices
		return -1;
   
	//Se ajusta la cámara
	//Si no se da valor se cojen valores por defecto
	//IGlib::setProjMat(const glm::mat4 &projMat);
	//IGlib::setViewMat(const glm::mat4 &viewMat);

	//Creamos el objeto que vamos a visualizar en funcion de los parametros que pasamos
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, //lamada a la libreria
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);
	
	glm::mat4 modelMat = glm::mat4(1.0f);//hay que configurar la model matrix (matriz de transformacion)
	IGlib::setModelMat(objId, modelMat);//con esta llamada, la establecemos como matriz modelo del objeto
	//Incluir texturas aquí.
	


  //CBs, call bakcs, lo hace la libreria
  IGlib::setResizeCB(resizeFunc);
  IGlib::setIdleCB(idleFunc);
  IGlib::setKeyboardCB(keyboardFunc);
  IGlib::setMouseCB(mouseFunc);
  IGlib::setMouseMoveCB(mouseMotionFunc);

	
	//Mainloop, la libreria se encarga del bucle del dibujado
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{
	//Ajusta el aspect ratio al tamaño de la venta
}

void idleFunc()
{
}

void keyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el botón ";
	else
		std::cout << "Se ha soltado el botón ";
	
	if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	if (button == 1) std::cout << "central del ratón " << std::endl;
	if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
}
