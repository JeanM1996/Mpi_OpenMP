#include "dtp.h"

void LimpiarCin()
{
	cin.clear();//arreglo el stream
	cin.ignore(200,'\n');//ignora el ingreso de hasta 200 caracteres
}
