#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int** suma(int** mat1, int** mat2, int);
int** resta(int** mat1, int** mat2, int);
int** strassen(int** mat10, int** mat20, int);

int main(){
    int n, m, p, o;
    scanf("%d %d %d", &n, &m, &p);  //Introducir el orden de las matrices
    
    //Definiendo matriz 1 y 2
    int** matriz1=new int*[n];
    for(int i = 0; i < n;i++) matriz1[i]=new int[m];
    int** matriz2=new int*[m];
    for(int i = 0; i < m;i++) matriz2[i]=new int[p];
    int dato1;
    int dato2;

    
    //Llenando matriz 1
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            dato1= i+j;
            matriz1[i][j] = dato1;
        }
    }
    
    //LLenando matriz 2
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            dato2 = i+j;
            matriz2[i][j] = dato2;
        }
    }
    
    //Buscando el orden de la matriz cuadrada que contiene las matrices 1 y 2
    
    if(n>=m && n>=p){
        o = n;
    }
    else if(m>=n && m>=p){
        o =m;
    }
    else{
        o = p;
    }
    
    // Generando matriz potencia de 2^n que contiene matrices 1 y 2
    
    int pot = 1;
    while(pot < o){
        pot = pot*2;
    }
    
    int** m10 = new int*[pot];
    int** m20 = new int*[pot];
    for(int i = 0; i< pot; i++) m10[i]=new int[pot];
    for(int i = 0; i< pot; i++) m20[i]=new int[pot];
    
    
    for(int i = 0; i< pot; i++){
        for(int j = 0; j < pot; j++){
            m10[i][j] = 0; //Genera matriz encontrada 2^n con 0
            m20[i][j] = 0; //Genera matriz encontrada 2^n con 0
        }
    }
    
    //Completando matriz cuadrada 1 con 0 hasta tamaño de 2^n
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            m10[i][j] = matriz1[i][j];
        }
    }
    
    //Completando matriz cuadrada 2 con 0 hasta tamaño de 2^n
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            m20[i][j] = matriz2[i][j];
        }
    }
    
    //Repuesta llamando strassen
    
    float t0, t1;
    t0=clock(); //Tiempo inicial del reloj
    
    strassen(m10,m20,pot);
    t1 = clock(); //Tiempo final del reloj
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
    
    delete* m10;
    delete* m20;
    
    return 0;
}
//Definiendo función para la suma de submatrices
int** suma(int** mat1, int** mat2, int m){
    int** Sum = new int*[m];
    for(int i = 0; i < m; i++) Sum[i] = new int[m];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            Sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return Sum;
}
//Definiendo función para la resta de submatrices
int** resta(int** mat1, int** mat2, int m){
    int** Res = new int*[m];
    for(int i = 0; i < m; i++) Res[i]=new int[m];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            Res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return Res;
}
//Definiendo función de Strassen
int** strassen(int** mat10, int** mat20, int n){
    int** C;
    if(n == 1){
        // CASO BASE: Matrices cuadradas de 1 x 1
        // crear matriz de 1x1 poner dentro la mult a x b y retornar
        int** base = new int*[1];
        base[0] = new int[1];
        base[0][0] = mat10[0][0] * mat20[0][0];
        return base;
    }
    else{
    //Tomando submatrices de las matrices A y B de tamaño 2^n
        
        int** A1 = new int*[n/2];
        int** B1 = new int*[n/2];
        int** C1 = new int*[n/2];
        int** D1 = new int*[n/2];
        int** A2 = new int*[n/2];
        int** B2 = new int*[n/2];
        int** C2 = new int*[n/2];
        int** D2 = new int*[n/2];
        for(int i = 0; i < n/2; i++) A1[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) B1[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) C1[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) D1[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) A2[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) B2[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) C2[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) D2[i] = new int[n/2];
            
        //Generando submatrices de A y B
        for(int i = 0; i<n/2; i++){
            for(int j = 0; j < n/2;j++){
                A1[i][j] = mat10[i][j];
                B1[i][j] = mat10[i][j+n/2];
                C1[i][j] = mat10[i+n/2][j];
                D1[i][j] = mat10[i+n/2][j+n/2];
                A2[i][j] = mat20[i][j];
                B2[i][j] = mat20[i][j+n/2];
                C2[i][j] = mat20[i+n/2][j];
                D2[i][j] = mat20[i+n/2][j+n/2];
                
            }
        }
            
    //Obteniendo sumas y restas para armar desde M1 a M7:
        
        //sumando A11 + A22
        int** S1 = suma(A1, D1, n/2);
        //Sumando B11 + B22
        int** S2 = suma(A2, D2, n/2);
        //Sumando A21 + A22
        int** S3 = suma(C1, D1, n/2);
        //Sumando A11 + A12
        int** S4 = suma(A1, B1, n/2);
        //Sumando B11 + B12
        int** S5 = suma(A2, B2, n/2);
        //Sumando B21 + B22
        int** S6 = suma(C2, D2, n/2);
        //Restando B12 - B22
        int** R1 = resta(B2, D2, n/2);
        //Restando B21 - B11
        int** R2 = resta(C2, A2, n/2);
        //Restando A21 - A1
        int** R3 = resta(C1, A1, n/2);
        //Restando A12 - A22
        int** R4 = resta(B1, D1, n/2);
        
    //Obteniendo desde M1 a M7:
        

        //Definiendo M1 a M7
        int** M1 = new int*[n/2];
        int** M2 = new int*[n/2];
        int** M3 = new int*[n/2];
        int** M4 = new int*[n/2];
        int** M5 = new int*[n/2];
        int** M6 = new int*[n/2];
        int** M7 = new int*[n/2];
        for(int i = 0; i < n/2; i++) M1[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M2[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M3[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M4[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M5[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M6[i] = new int[n/2];
        for(int i = 0; i < n/2; i++) M7[i] = new int[n/2];
    
       
        
        //Obteniendo M1 a M7
         
        M1 = strassen(S1, S2, n/2);
        M2 = strassen(S3, A2, n/2);
        M3 = strassen(A1, R1, n/2);
        M4 = strassen(D1, R2, n/2);
        M5 = strassen(S4, D2, n/2);
        M6 = strassen(R3, S5, n/2);
        M7 = strassen(R4, S6, n/2);
        

        delete* S1;
        delete* S2;
        delete* S3;
        delete* S4;
        delete* S5;
        delete* S6;
        delete* R1;
        delete* R2;
        delete* R3;
        delete* R4;
        
        //Calculando C11 C12 C21 C22
        
        int** C11 = new int*[n/2];
        int** C12 = new int*[n/2];
        int** C21 = new int*[n/2];
        int** C22 = new int*[n/2];
        for(int i = 0; i < n/2; i++) C11[i]=new int[n/2];
        for(int i = 0; i < n/2; i++) C12[i]=new int[n/2];
        for(int i = 0; i < n/2; i++) C21[i]=new int[n/2];
        for(int i = 0; i < n/2; i++) C22[i]=new int[n/2];
        
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
                C12[i][j] = M3[i][j] + M5[i][j];
                C21[i][j] = M2[i][j] + M4[i][j];
                C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
            }
        }
      
        delete* M1;
        delete* M2;
        delete* M3;
        delete* M4;
        delete* M5;
        delete* M6;
        delete* M7;
        
        //Definiendo matriz resultado
        
        C = new int*[n];
        for(int i = 0; i < n;i++) C[i] =new int[n];
        
        //Armando matriz de suma de submatrices
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                C[i][j] = C11[i][j];
                C[i][j+n/2] = C12[i][j];
                C[i+n/2][j] = C21[i][j];
                C[i+n/2][j+n/2] = C22[i][j];
            }
        }
        
        delete* A1;
        delete* B1;
        delete* C1;
        delete* D1;
        delete* A2;
        delete* B2;
        delete* C2;
        delete* D2;
        delete* C11;
        delete* C12;
        delete* C21;
        delete* C22;
    }
    

    return C;
}

