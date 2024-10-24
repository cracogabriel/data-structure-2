#include <iostream>
#include <cstdlib>
#define DEBUG 0

void merge(int *v, int p, int q, int r){
    int *e, *d;
    int k;
    int n1 = q - p + 1;
    int n2 = r - q;
    e = new int[n1];
    d = new int[n2];
    for(k = 0; k < n1; k++)
        e[k] = v[p + k];
    for(k = 0; k < n2; k++)
        d[k] = v[q + 1 + k];
    int i = 0, j = 0;
    k = p;
    while(i < n1 && j < n2){
        if(e[i] <= d[j]){
            v[k] = e[i];
            i++;
        }
        else{
            v[k] = d[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = e[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = d[j];
        j++;
        k++;
    }
    delete[] e;
    delete[] d;
}

void MergeSort(int* v, int e, int d){
    if(e < d){
        int m = (e + d) / 2;
        MergeSort(v, e, m);
        MergeSort(v, m + 1, d);
        merge(v, e, m, d);
    }
}

//wrapper p/ MergeSort
void MergeSort(int* v, int n){
    MergeSort(v, 0, n - 1);
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

    MergeSort(v, n);
 
    #if DEBUG
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;        
    #endif

    return 0;
}

