#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void switchVariable(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    
    // ! Aula dia 10/10/2024
    
    // * Switching variable positions with a generic type function params
    int a = 5, b = 10;
    cout << "Antes da troca: " << "a: " << a << " b: " << b << endl;
    switchVariable(a, b);
    cout << "Depois da troca usando switchVar: " << "a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "Depois da troca usando swap: " << "a: " << a << " b: " << b << endl;

    // * STL vector
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(7);
    v.pop_back();

    cout << "Vector: ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
    


    return 0;
}