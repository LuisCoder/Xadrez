// Funções uteis para manipulação de elementos em OpenGL

#include "libGL.h"


// define a cor do material a trabalhar
void material(int n, int flag, float x,float y,float z, float i)
{
	float v[4];
	v[0]=x;
	v[1]=y;
	v[2]=z;
	v[3]=i;
	glMaterialfv(n,flag,v);
}

void light(int n, int flag, float x,float y,float z, float i)
{
	float v[4];
	v[0]=x;
	v[1]=y;
	v[2]=z;
	v[3]=1.0F;
	v[3]=i;
	glLightfv(GL_LIGHT0+n,flag,v);
}



float absf(float number)
{
  if(number < 0)
    return -number;
  return number;
}

float radian(float degrees)
{
  return (degrees*PI)/180.0F;
}

float degrees(float radian)
{
	return (radian*180.0F)/PI;
}




unsigned char *LoadBMP(char *path,BITMAPINFOHEADER *header){
  	int fd=-1;
	BITMAPFILEHEADER bmfHeader;
	unsigned char * hDIB;
    unsigned char tmp;
	long nFileLen = 0, curLen = 0, i =0;
	
	header->biHeight = header->biWidth = header->biSize = header->biSizeImage = 0;

	if( (fd = _open(path,_O_RDWR)) < 0)
      return NULL;
	if(_read(fd,&bmfHeader,sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
	  return NULL;
	
	nFileLen = _lseek(fd,0,SEEK_END) - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);
	_lseek(fd,sizeof(BITMAPFILEHEADER),SEEK_SET);

    if(_read(fd,header,sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
	  return NULL;

	hDIB = (unsigned char *) ::GlobalAlloc(GMEM_FIXED, nFileLen + sizeof(BITMAPINFOHEADER));

    if(hDIB == 0)
     return NULL; 

    curLen=0;
	while(curLen < nFileLen){
	  if(!_read(fd,&(hDIB[curLen]),1)){
	    hDIB[curLen] = 0x0010;
        _lseek(fd,sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)+ curLen + 1,SEEK_SET);
	  }
	  curLen++;
	}
	_close(fd);

	for( i = 0 ; i < header->biWidth * header->biHeight * 3 ; i+=3){
	  tmp  = hDIB[i];
	  hDIB[i]  = hDIB[i+2];
      hDIB[i+2] = tmp;
	}
	return (unsigned char *) (hDIB);
}

void FreeBMP(unsigned char *bitmap){
  ::GlobalFree(bitmap);
}
