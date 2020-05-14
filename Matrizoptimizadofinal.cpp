#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

int main(){
    int n,m,o;
    scanf("%d %d %d",&n,&m,&o);

    int dato1; //Se crearán los elementos para matriz 1
    int dato2; //Elementos para matriz 2
    int resultado[n][o]; //Se definirá matriz resultado.
    
    //Creando matriz 1, 2 y 3
    int** matriz1 = new int*[n];
    int** matriz2 = new int*[m];
    int** matriz3 = new int*[o];
    for(int i = 0; i < n; i++) matriz1[i] = new int[m];
    for(int i = 0; i < m; i++) matriz2[i] = new int[o];
    for(int i = 0; i < o; i++) matriz3[i] = new int[m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            dato1 = i+j;
            matriz1[i][j] = dato1;
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < o; j++){
        dato2 = i+j;
        matriz2[i][j] = dato2;
        }
    }
    
    //Generando matriz traspuesta
    
    for(int j =0; j < o; j++){
        for(int i = 0; i < m; i++){
            matriz3[j][i] = matriz2[i][j];
        }
    }

    //Generando matriz resultado y midiendo tiempo ejecución
    
    double t0, t1;

    t0=clock();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < o; j++){
            for(int k = 0; k < m; k++){
                resultado[i][j] = 0;
                resultado[i][j] += matriz1[i][k] * matriz3[j][k];
            }
        }
    }
    
    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
    
    delete* matriz1;
    delete* matriz2;
    delete* matriz3;
    
    return 0;
    
}
    
