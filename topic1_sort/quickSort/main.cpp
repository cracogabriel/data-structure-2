#include <stdio.h>
#include <iostream>
using namespace std;


int partition(int* v, int p, int r) {
    int x = v[r]; // pivô
    int i = p-1; 

    for (int j = p; j < r; j++){ 
        if (v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    return i+1;
}

void quickSort(int *v, int n){
    quickSort(v, 0, n-1);
}

void quickSort(int* v, int p, int r) {
    if(p < r) {
        int q = partition(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }
}


int* vetor_aleatorio(int n){
    int* v = new int[n];
    srand(99);
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n*100);
    }
    return v;
}


int main(int argc, char** argv){
    using namespace std;

    int n = atoi(argv[1]);

    int* v = vetor_aleatorio(n);

    quickSort(v, n);

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;        

    return 0;
}
