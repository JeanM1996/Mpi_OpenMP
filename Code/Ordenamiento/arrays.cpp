#include  "arrays.h"

void CargarVectorDesordenado(ty_vec&v)
//void CargarVectorDesordenado()
{
    cout<<"\nCargando vector desordenado...\n";
    int f;
    int n;
    vector <int> vNotas;
    float cal = 0;
    ifstream fNotas ("datos100000.txt"); //Apertura del archivo en modo lectura
    if(fNotas.is_open())
    {
        for(f=0; f<TOPEF; f++)
        {
            //n= rand() %TOPEF+1;
            while (fNotas >> cal)
        {
            vNotas.push_back(cal);

           // cout << cal << endl;
           n=cal;
            v[f]=n;
            //cout <<n<< endl;
        }

        }

    }
    cout<<"Fin!\n";

    fNotas.close();
}

void Burbujeo(ty_vec v2)
{
    int i;
    int iAux;
    int iPaso=1;
    bool bOrd;
    clock_t t;
    t = clock();
    int tim=0;
    int hour=0;
    int minuts=0;
    int seconds=0;


    cout<<"Realizando Ordenamineto de burbuja de forma secuencial\n";
    do
    {
        bOrd=TRUE;
        for(i=0; i<TOPEF-iPaso; i++)
        {
            if(v2[i]>v2[i+1])
            {
                iAux	= v2[i];
                v2[i]	= v2[i+1];
                v2[i+1]	= iAux;
                bOrd=FALSE;
            }
        }
        iPaso++;
    }
    while(!bOrd);
    t = clock() - t;
    tim = ((float)t)/CLOCKS_PER_SEC;
    hour = tim / 3600;
    tim = tim % 3600;
    minuts= tim / 60;
    seconds= tim % 60;
    cout<<"Ordenamiento realizado.\n";
    cout<<"Tardo "<<t<<" ticks del reloj. ( "<< ((float)t)/CLOCKS_PER_SEC<<" segundos)\n";
    cout<< "Horas: " << hour<<"\n" ;
    cout<< "Minutos: " << minuts<<"\n" ;
    cout<< "Segundos: " << seconds<<"\n" ;
    cout<< "Tiempo Transcurrido: " << hour<<":"<<minuts<<":"<<seconds<<"\n" ;
}

void BurbujeoParalelo(ty_vec v2)
{
    int i;
    int fase;
    int tmp;
    int iPos;
    clock_t t;
    t = clock();
    int tim=0;
    int hour=0;
    int minuts=0;
    int seconds=0;

    cout<<"\n Realizando ordenamiento de burbuja Paralelizado con OpenMP...\n";
    #pragma omp parallel default(none) shared(v2) private(i, tmp, fase)//Usando default fuerzo a decidir el scope de TODAS las variables
    {

        for (fase=0; fase<TOPEF; fase++)
        {
            if(fase % 2 == 0)

                for (i=1; i<TOPEF; i+=2)
                {
                    if(v2[i-1]>v2[i])
                    {
                        tmp = v2[i-1];
                        v2[i-1] = v2[i];
                        v2[i] = tmp;
                    }
                }
            else

                for(i=1; i<TOPEF-1; i+=2)
                {
                    if(v2[i]>v2[i+1])
                    {
                        tmp=v2[i+1];
                        v2[i+1] = v2[i];
                        v2[i]= tmp;
                    }
                }
        }

    }
    t = clock() - t;
    tim = ((float)t)/CLOCKS_PER_SEC;
    hour = tim / 3600;
    tim = tim % 3600;
    minuts= tim / 60;
    seconds= tim % 60;
    cout<<"Ordenamiento realizado.\n";
    cout<<"Tardo "<<t<<" ticks del reloj. ( "<< ((float)t)/CLOCKS_PER_SEC<<" segundos)\n";
    cout<< "Horas: " << hour<<"\n" ;
    cout<< "Minutos: " << minuts<<"\n" ;
    cout<< "Segundos: " << seconds<<"\n" ;
    cout<< "Tiempo Transcurrido: " << hour<<":"<<minuts<<":"<<seconds<<"\n" ;
    cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
    while(!(cin>>iPos))
    {
        LimpiarCin();
        cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
    }
    while(iPos!=-1)
    {
        cout<<"En la posicion "<<iPos<<" se encuentra el nro "<<v2[iPos]<<endl;
        cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
        while(!(cin>>iPos))
        {
            LimpiarCin();
            cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
        }
    }
}

void InsertionSort(ty_vec v2)
{
    int i, j, index;
    clock_t t;
    t = clock();
    int tim=0;
    int hour=0;
    int minuts=0;
    int seconds=0;
    cout<<"Realizando ordenamiento utilizando InsertionSort LINEAL...";
    for (i=1; i<TOPEF; i++)
    {
        index = v2[i];
        j = i;
        while ((j>0) && (v2[j-1] > index))
        {
            v2[j] = v2[j-1];
            j = j - 1;
        }
        v2[j] = index;
    }
    t = clock() - t;
    tim = ((float)t)/CLOCKS_PER_SEC;
    hour = tim / 3600;
    tim = tim % 3600;
    minuts= tim / 60;
    seconds= tim % 60;
    cout<<"Ordenamiento realizado.\n";
    cout<<"Tardo "<<t<<" ticks del reloj. ( "<< ((float)t)/CLOCKS_PER_SEC<<" segundos)\n";
    cout<< "Horas: " << hour<<"\n" ;
    cout<< "Minutos: " << minuts<<"\n" ;
    cout<< "Segundos: " << seconds<<"\n" ;
    cout<< "Tiempo Transcurrido: " << hour<<":"<<minuts<<":"<<seconds<<"\n" ;
}

void InsertionSortParalelo(ty_vec v2)
{
    int i, j, index;
    long iPos;
    clock_t t;
    t = clock();
    int tim=0;
    int hour=0;
    int minuts=0;
    int seconds=0;

    cout<<"Realizando ordenamiento utilizando InsertionSort PARALELO...";
    #pragma omp parallel for default(none) shared(v2) private(i, j, index)
    for (i=1; i<TOPEF; i++)
    {
        index = v2[i];
        j = i;
        while ((j>0) && (v2[j-1] > index))
        {
            v2[j] = v2[j-1];
            j = j - 1;
        }
        v2[j] = index;
    }
    t = clock() - t;
    tim = ((float)t)/CLOCKS_PER_SEC;
    hour = tim / 3600;
    tim = tim % 3600;
    minuts= tim / 60;
    seconds= tim % 60;
    cout<<"Ordenamiento realizado.\n";
    cout<<"Tardo "<<t<<" ticks del reloj. ( "<< ((float)t)/CLOCKS_PER_SEC<<" segundos)\n";
    cout<< "Horas: " << hour<<"\n" ;
    cout<< "Minutos: " << minuts<<"\n" ;
    cout<< "Segundos: " << seconds<<"\n" ;
    cout<< "Tiempo Transcurrido: " << hour<<":"<<minuts<<":"<<seconds<<"\n" ;
    cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
    while(!(cin>>iPos))
    {
        LimpiarCin();
        cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
    }
    while(iPos!=-1)
    {
        cout<<"En la posicion "<<iPos<<" se encuentra el nro "<<v2[iPos]<<endl;
        cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
        while(!(cin>>iPos))
        {
            LimpiarCin();
            cout<<"Ingrese la posicion que desea ver (-1 para volver al menu principal):";
        }
    }
}
void Menu()
{
    cout<<"Presione:\n";
    cout<<"0 para salir.\n";
    cout<<"1 para Comparativa programación secuencial vs programación paralela (BubbleShort).\n";
    cout<<"2 para Comparativa programación secuencial vs programación paralela (InsertShort).\n";

}
