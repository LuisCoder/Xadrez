#pragma once


#include <Math.h>
#include <Windows.h>

#include <io.h>
#include <fcntl.h>

#include <GL/freeglut.h>



#define PI 3.1415926535F

void material(int n, int flag, float x,float y,float z, float i);
void light(int n, int flag, float x,float y,float z, float i);

// conversões de angulos
float radian(float degrees);
float degrees(float radian);

// valor absoluto
float absf(float number);

unsigned char *LoadBMP(char *path,BITMAPINFOHEADER *header);
void FreeBMP(unsigned char *bitmap);


#define COS(X) ((float) cos(radian(X)))
#define SIN(X) ((float) sin(radian(X)))
#define ABSCOS(X) absf((float) cos(radian(X)))
#define ABSSIN(X) absf((float) sin(radian(X)))
#define ASIN(X) (degrees((float) asin(X)))
#define ACOS(X) (degrees((float) acos(X)))
#define TAN(X) (degrees((float) tan(X)))
#define ATAN(X) (degrees((float) atan(X)))




