#include "arrays.h"
#include "dtp.h"

using namespace std;

#include "arrays.h"
#include "dtp.h"

int main()
{
	int			iOpcion = -1;
	int			f=0;
	ty_vec		vec_desord;
	//omp_set_num_threads(4);

		srand(2);//Siempre usar la semilla antes de llamar la funcion CargarVectorDesordenado, para generar siempre los mismos numeros
		system("cls");
		CargarVectorDesordenado(vec_desord);//Cargo en vector los numeros desordenados
		Menu();
		if(!(cin>>iOpcion))
		{
			LimpiarCin();
		}
		while(iOpcion!=0)
		{
			switch(iOpcion)
			{
				case 1:
					Burbujeo(vec_desord);
					srand(2);
					CargarVectorDesordenado(vec_desord);// cargar el vector desordenado
					BurbujeoParalelo(vec_desord);
					srand(2);
					CargarVectorDesordenado(vec_desord);// cargar el vector desordenado
				break;
				case 2:
					InsertionSort(vec_desord);
					srand(2);
					CargarVectorDesordenado(vec_desord);//Se vuelve a cargar el vector desordenado
					InsertionSortParalelo(vec_desord);
					srand(2);
					CargarVectorDesordenado(vec_desord);//Se vuelve a cargar el vector desordenado
				break;
				case 4:

				break;
				default:
				cout<<"Debe ingresar un numero entre 0 y 4";
			}
			Menu();
			if(!(cin>>iOpcion))
			{
				LimpiarCin();
			}
		}
}
