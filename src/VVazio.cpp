#include "VVazio.h"


VVazio::VVazio(void)
{
	cor=-1;
}

VVazio::~VVazio(void)
{
}

void VVazio::Draw()
{
}

void VVazio::Init ()
{
}
void VVazio::Destroy ()
{
}

bool VVazio::estaVazio(){
	return true;
}

int VVazio::getAltura(){
	return 0;
}