#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int aux;
    
    // Se ingresan los tamaños a considerar del arreglo
    scanf("%d",&n);
    
    int vector[n];
    
    for(int i = 0; i < n; i++){
        vector[i] = i+1;
    }
    
    random_shuffle(vector, vector+n);
    
    float t0, t1; //Para calcular tiempo de ejecución
    t0=clock();
    
    for(int i = 0; i < n;i++){
        for(int j =0; j < n;j++){
            if(vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    
     t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    (void)std::cout.precision(7);
    cout << "Execution Time: " << time << endl;
    
    return 0;
}
