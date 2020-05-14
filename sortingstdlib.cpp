#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <list>

using namespace std;

int main(){
    
    int n;
    //Se ingresa la cantidad de elementos que queremos en el arreglo
    scanf("%d", &n);

    int numeros[n];
    
    for(int i = 0; i < n; i++){
        numeros[i] = i + 1;
    }
    
    random_shuffle(numeros,numeros+n);
    
    //Creamos un vector y le pasamos los valores del arreglo que se creará dependiendo la cantidad de elementos
    vector<int> vector (numeros,numeros+n);

    float t0, t1; //Para medir el tiempo de ejecución del algoritmo.
    
       t0=clock();
    sort(vector.begin(),vector.end()); //Así se define la función sort en la STDLIB
    
    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    (void)std::cout.precision(7);
    cout << "Execution Time: " << time << endl;
    
    return 0;
}
