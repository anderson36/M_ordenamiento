/*Autor: Jhon Anderson Sanchez
Funcion del programa: Metodos de ordenamiento
Fecha:11/10/2016*/

#include<iostream>
#include <conio.h>
#define d 4
#define largo 100

using namespace std;

//declaracionde las funciones de metodos de ordenamiento
void burbuja();
void insercion();
void seleccion();
void shell();
void quicksort(int A[],int izq, int der );
void leeCadena(int cant,int n[]);
void muestraCadena(int cant,int n[]);
void Pausa ();

int main()

{

    int x;
    cout<<"**************Menu*****************";
    cout<<endl;
    cout<<endl;
    cout<<"1.-Ordenamiento por Metodo Burbuja";
    cout<<endl;
    cout<<"2.-Ordenamiento por Metodo Insercion";
    cout<<endl;
    cout<<"3.-Ordenamiento por Metodo Seleccion";
    cout<<endl;
    cout<<"4.-Ordenamiento por Metodo Shell";
    cout << endl;
    cout << "5.-Ordenamiento por Metodo QuickSort";
    cout<<endl;
    cout<<endl;
    cout<<"ELIGE UNA OPCION:";
    // variable donde se guarda el datos del menu
    cin>>x;
    cout<<endl;
    cout<<endl;


switch (x)
{
        case 1: cout << "ha selecionado el metodo de Burbuja"<<"\n"<< endl;
                cout << "por favor siga las instruciones"<<"\n"<< endl;
                Pausa ();
                burbuja();
        break;
        case 2: cout << "ha selecionado el metodo de Insercion"<<"\n"<< endl;
                cout << "por favor siga las instruciones"<<"\n"<< endl;
                Pausa ();
                insercion();
        break;
        case 3: cout << "ha selecionado el metodo de Selecion"<<"\n"<< endl;
                cout << "por favor siga las instruciones"<<"\n"<< endl;
                Pausa ();seleccion();
        break;
        case 4: cout << "ha selecionado el metodo de Shell"<<"\n"<< endl;
                cout << "por favor siga las instruciones"<<"\n"<< endl;
                Pausa ();shell();
        break;
        case 5: cout << "ha selecionado el metodo de QuickSort"<<"\n"<< endl;
                cout << "por favor siga las instruciones"<<"\n"<< endl;
                Pausa ();
        int A[largo],n;
        do{
            cout<<"Cantidad de numeros a ingresar: ";
            cin>>n;

            if(n<=0||n>largo)

                cout<<"Debe ingresar un valor > a 0 y < a "<<largo<<endl;
            }
            while(n<=0||n>largo);
                leeCadena(n,A);
                quicksort(A,0,n-1);
                muestraCadena(n,A);
        break;
        default: cout<<"ERROR EN LA SECCION";
}
    return 0;
}



void burbuja()
{
        char salir;
        int N,Aux,J,opcion;
        int V[10];
        int I;


        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }
        for (I=0; I<N-1; I++)
            for (J=0; J<(N-1)-I; J++)
                if (V[J]>V[J+1]){
                    Aux=V[J];
                    V[J]=V[J+1];
                    V[J+1]=Aux ;
                }

        cout<<"Los numeros de forma ordenada son:";
        for(I=0; I<N; I++)
            cout<<endl<<V[I];
            getch();

}

void insercion()
{
        int N,Aux,J,SW;
        int V[10];
        int I;

        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }
        for (I=1; I<N;I++){
            Aux=V[I];
            J=I-1;
            SW=1;
        while (SW&&J>=0){
            if (Aux<V[J]){
                V[J+1]=V[J];
                J--;
            }
            else{
                SW=0;
                }
            }
            V[J+1]=Aux;
        }


        cout<<"Los numeros de forma ordenada son:";
        for(I=0; I<N; I++)
            cout<<endl<<V[I];

        getch();
}




void seleccion()
{
        int J,I,N,K;
        int V[10];
        int Sw;
        int Aux;

        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }

        for(I=0; I<N-1; I++){
            K=I;
        for (J=I+1; J<N; J++)
            if (V[J]<V[K])
                K=J;
                Aux=V[I];
                V[I]=V[K];
                V[K]=Aux;
        }


        cout<<"Los numeros de forma decrecciente son:";
        for(I=N-1; I>=0; I--)
            cout<<endl<<V[I];
            getch();
}



void shell()
{
        int J,I,N,K,INC,TMP;
        int V[10];
        int Sw;
        int Aux;

        cout<<"¿Cuantos numeros va a ingresar al vector?, maximo 10:";
        cin>>N;
        for(I=0; I<N; I++){
            cout<<"Ingrese dato "<<I+1<<":";
            cin>>V[I];
        }

        INC=N/2;
        do{
            for(I=INC; I<N; I++){
                TMP=V[I];
                J=I-INC;
                while ((J>=0)&&(TMP<V[J])){
                    V[J+INC]=V[J];
                    J-=INC;
                }
                V[J+INC]=TMP;
            }
                INC/=2;
        }
        while(INC!=0);

        cout<<"Los numeros de forma decrecciente son:";
        for(I=0; I<N; I++)
            cout<<endl<<V[I];
            getch();
}



void quicksort(int A[],int izq, int der )
{
        int i, j, x , aux;
        i = izq;
        j = der;
        x = A[ (izq + der) /2 ];
            do{
                while( (A[i] < x) && (j <= der) ){
                    i++;
                }

                while( (x < A[j]) && (j > izq) ){
                    j--;
                }

                if( i <= j ){
                    aux = A[i]; A[i] = A[j]; A[j] = aux;
                    i++;  j--;
                }

            }
            while( i <= j );

            if( izq < j )
                quicksort( A, izq, j );
            if( i < der )
                quicksort( A, i, der );
        }


void leeCadena(int cant,int n[])
{
        int i;
        for(i=0;i<cant;i++){
            cout<<"Ingresa numero "<<i+1<<": ";
            cin>>n[i];
        }
}
void muestraCadena(int cant,int n[])
{
        int i;
        for(i=0;i<cant;i++){
            cout<<n[i]<<endl;
        }
}
void Pausa ()
{
        cout << "Pulse una tecla para continuar...";
        if (!getch ())
            getch ();
        cout << endl;
}
