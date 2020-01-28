#include "libs.h"
#include "dtp.h"

#define		TOPEF 100000

#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED
typedef int ty_vec[TOPEF];
//vector <float> vNotas;
void CargarVectorDesordenado(ty_vec &v);
void Burbujeo(ty_vec v2);
void BurbujeoParalelo(ty_vec v2);
void InsertSort(ty_vec v2);
void InsertionSort(ty_vec v2);
void InsertionSortParalelo(ty_vec v2);
void Menu();
#endif // ARRAYS_H_INCLUDED
