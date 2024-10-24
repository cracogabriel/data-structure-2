#include <stdio.h>
#include <iostream>
using namespace std;


int find_max_pos(int* vet, int start, int end){
    int max_pos = start;
    for (int i = start; i < end; i++){
        if (vet[max_pos] < vet[i]) {
            max_pos = i;
        }
    }

    return max_pos;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printVector(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(){
    int n = 6;
    int arr[] = {64, 25, 12, 22, 11, 68};

    cout << "Before sort: ";
    printVector(arr, n);
    
    for (int i = 0; i < n - 1; i++) {
        int max_pos = find_max_pos(arr, 0, n - i);
        swap(arr, max_pos, n - i - 1);
    }
    
    cout << "After sort: ";
    printVector(arr, n);
}

int main() {
    selectionSort();
    return 0;
}