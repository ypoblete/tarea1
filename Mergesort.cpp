#include <iostream>

using namespace std;

void mezcla(int a[], int izquierda, int medio, int derecha); //Función para mezclar mergesort
void mergeSort(int a[], int primero, int ultimo); //Función mergesort recursiva

int main(){
    int n; //Con esto se ingresan los tamaños del arreglo a considerar
    scanf("%d", &n);
    int vector[n];
    
    for(int i=0; i<n;i++){
        vector[i] = i+1;
    }
    
    random_shuffle(vector,vector+n);
    
    float t0, t1; //Con esto se calcula el tiempo del algoritmo mergesort
    t0=clock();
    mergeSort(vector,0,n-1);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    (void)std::cout.precision(7);
    cout << "Execution Time: " << time << endl;
    
    cout << endl;
    return 0;
}

void mezcla(int a[], int izquierda, int medio, int derecha){
    
    int* aux;
    int i,k,z;
    aux = new int[derecha - izquierda + 1];
    i = izquierda;
    k = medio + 1;
    z = 0;
    
    //Se ordenan los elementos en arreglo aux[]
    while(i<=medio && k<=derecha){
        if(a[i] <= a[k]){
            aux[z++] = a[i++];
        }
        else{
            aux[z++] = a[k++];
        }
    }

    //Se copian elementos de la lista que no quedo vacía
    while(i<=medio){
        aux[z++] = a[i++];
    }
    
    while(k<=derecha){
        aux[z++] = a[k++];
    }
    
    //Copiando los elementos del arreglo auxiliar al arreglo a
    for(int i = izquierda;i<=derecha;i++){
        a[i] = aux[i-izquierda];
    }
    delete aux;
}

void mergeSort(int a[], int primero, int ultimo){
    int central;
    

    if(primero < ultimo){
        central = (primero+ultimo)/2;
        mergeSort(a, primero,central); //Se ordena la sublista izquierda
        mergeSort(a, central+1, ultimo); //Se ordena la sublista derecha
        mezcla(a,primero,central,ultimo); //Mezclar elementos ordenados
    }
    
}
