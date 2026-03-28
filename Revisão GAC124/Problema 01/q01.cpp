//Revisão - Questão 1
#include <iostream>

using namespace std;

bool CalculaPrimo (unsigned int primo) {
    bool ePrimo = true;
    unsigned int fatorPrimo = 2;

    //exceção pro número sendo 0 ou 1, pq aí não passa no while embaixo (0 e 1 NÃO SÃO PRIMOS!!)
    if (primo == 1 or primo == 0) {
        ePrimo = false;
    }

    while (fatorPrimo <= (primo/2)) {
        if ((primo % fatorPrimo == 0) or (primo == 1)) {
            ePrimo = false;
        }

        fatorPrimo++;
    }
    
    return ePrimo;
}

int main() {
    const unsigned int tam = 9;
    unsigned int *numeros = new unsigned int[tam];

    for (unsigned int i = 0; i < tam; i++) {
        cin >> numeros[i];
    }

    //teste pra ver se é primo o número yay yahooo
    unsigned int pos = 0;

    while (pos < tam) {
        
        if (CalculaPrimo(numeros[pos]) == true) {
            cout << numeros[pos] << " " << pos << endl;
        }

        pos++;
    }

    delete [] numeros;
    
    return 0;
}