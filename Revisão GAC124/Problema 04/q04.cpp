//Revisão - Questão 4
#include <iostream>

using namespace std;

void SelectionSort(int *numeros, unsigned int tam, int num) {
    for (unsigned int indice = 0; indice < tam; indice++) {
        unsigned int iMin = indice;




    }


    return;
}

int main() {
    const unsigned int tam = 8;
    int *numeros = new int[tam];
    int num, aux;


    //primeiro for é pro input dos elementos
    for (unsigned int i = 0; i < tam; i++) {
        cin >> num;
        //segundo for é para começar a ordenação

        SelectionSort(numeros, tam, num);




        for (unsigned int j = 0; j < i; j++) {
            cout << numeros[j] << " ";
        }
    }
    delete [] numeros;

    return 0;
}
 