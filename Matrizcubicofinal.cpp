#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

int main(){
    int n;
    int m;
    int o;

    scanf("%d %d %d",&n,&m,&o); //%d escaneo entero
     
    long long dato1; //datos para matriz 1
    long long dato2; //datos para matriz 2
    long long resultado[n][o]; //almacenará la matriz resultado

    //Definiendo Matriz 1 y 2
    long long** matriz1 = new long long*[n];
    long long** matriz2 = new long long*[m];
    for(long long i = 0; i < n; i++) matriz1[i] =new long long[m];
    for(long long i = 0; i < m; i++) matriz2[i] =new long long[o];
    
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            dato1 = i+j;
            matriz1[i][j] = dato1;
        }
    }
    
    for(long long i = 0; i < m; i++){
        for(long long j = 0; j < o; j++){
            dato2 = i+j;
            matriz2[i][j] = dato2;
        }
    }
 
    //Midiendo tiempo de ejecución
    double t0, t1;

    t0=clock();
    
    //Generando matriz resultado con triple "for"
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < o; j++){
            resultado[i][j] = 0;
            for(long long k = 0; k <m; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    
    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
    return 0;
}

