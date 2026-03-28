//Revisão - Questão 10
#include <iostream>

using namespace std;

int main() {
    int linha, coluna;
    cin >> linha >> coluna;

    int **matriz = new int*[linha];
    for (int i = 0; i < linha; i++) {
        matriz[i] = new int[coluna];
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < coluna; i++) {
        for (int j = 0; j < linha; j++) {
            cout << matriz[j][i] << " ";    
        }
        cout << endl;
    }

    for (int i = 0; i < linha; i++) {
        delete [] matriz[i];
    }
    delete [] matriz;
    
    return 0;
}
