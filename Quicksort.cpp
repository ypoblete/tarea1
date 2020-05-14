#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

void cambio(int &x, int &y);
void qSort(int a[], int ini, int fin);

int main(){
    int n;
    scanf("%d", &n);
    
    int vector[n];
    
    for(int i = 0; i < n; i++){
        vector[i] = i+1;
    }
    
    random_shuffle(vector, vector+n);

    float t0, t1; //Con esto se mide el tiempo del algoritmo
    t0=clock();
    //Le entrego el vector, pos inicial y pos final
    qSort(vector,0,n-1);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    (void)std::cout.precision(7);
    cout << "Execution Time: " << time << endl;
    
    return 0;
}

void cambio(int &x, int &y){ //Función que permite cambiar los elementos cuando se cumpla la condición
    int aux;
    
    aux = x;
    x = y;
    y = aux;
}

void qSort(int a[], int ini, int fin){
    int i; //recorre izquierda
    int j; //recorre derecha
    int c; //posicion centro del arreglo
    int p; //pivot
    
    c = (ini + fin)/2;
    p = a[c];
    i = ini;
    j = fin;
    
    //Condiciones para realizar el cambio
    do{
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        
        if(i<=j){
            cambio(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    
    if(ini < j){
        qSort(a,ini,j); //Con esto se ordena la parte izquierda
    }
    if(i < fin){
        qSort(a,i,fin); //Con esto se ordena la parte derecha
    }
}
