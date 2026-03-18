//Revisão - Questão 2
//OBS: usei snake_case mais pelo fato de conjuntoA ser meio confuso de ler pra mim kk
#include <iostream>

using namespace std;

void LeituraVetor(int *vetor, unsigned int tam) {
    for (unsigned int i = 0; i < tam; i++) {
        cin >> vetor[i];
    }

    return;
}

void ImprimirUniao(int *A, unsigned int tam_A, int *B, unsigned int tam_B, bool *repete_B) {
    //impressao dos elementos no terminal, meio desnecessário criar um vetor novo pra isso (já que nao importa se ta ordenado ou não bleh)
    for (unsigned int i = 0; i < tam_A; i++) {
        cout << A[i] << " ";
    }

    for (unsigned int i = 0; i < tam_B; i++) {
        if (!repete_B[i]) {
            cout << B[i] << " ";
        }
    }

    return;
}

int main() {
    unsigned int tam_A, tam_B;
    
    //criação dos vetores e inserção de dados
    cin >> tam_A;
    int *conjunto_A = new int[tam_A];
    LeituraVetor(conjunto_A, tam_A);

    cin >> tam_B;
    int *conjunto_B = new int[tam_B];
    LeituraVetor(conjunto_B, tam_B);

    //cria um vetor booleano pra "marcar" os numeros que tao repetidos no vetor B
    //tem jeito mais facil de fazer isso (usando modularizacao), mas queria fazer a solução do meu jeito e não copiar eu do passado
    bool *repete_B = new bool[tam_B];
    
    for (unsigned int i = 0; i < tam_B; i++) {
        repete_B[i] = false;
    }

    for (unsigned int i = 0; i < tam_A; i++) {
        for (unsigned int j = 0; j < tam_B; j++) {
            //ta dando certo aqui kk
            if (conjunto_A[i] == conjunto_B[j]) {
                repete_B[j] = true;
            }
        }
    }

    ImprimirUniao(conjunto_A, tam_A, conjunto_B, tam_B, repete_B);

    delete [] conjunto_A;
    delete [] conjunto_B;
    delete [] repete_B;

    return 0;
}