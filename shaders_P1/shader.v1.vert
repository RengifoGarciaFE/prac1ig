#version 330 core

in vec3 inPos;		
#define M_PI 3.1419265
void main()
{
	mat4 modelView = mat4(1.0); //matriz identidad
	modelView[3].z=-3;
	mat4 proj= mat4(1.0); //matriz de proyeccion
	float f=1.0/tan(M_PI/60); //FOO, apertura de la camara
	float far = 20.0; //plano lejano
	float near = 0.1; //plano cercano

	proj[0].x=f;//metemos parametros a la proyecction
	proj[1].y=f;
	proj[2].z=(far + near)/(near-far);
	proj[2].w=-1.0;
	proj[3].z=(2.0*far*near)/(near-far);
	proj[3].w=0.0;

	gl_Position =  proj*modelView*vec4(inPos,1);

}
