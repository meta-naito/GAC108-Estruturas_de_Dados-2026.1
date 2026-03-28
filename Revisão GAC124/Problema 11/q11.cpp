//Revisão - Questão 11
#include <iostream>

using namespace std;

struct anosDeVida {
    unsigned int idade; 
};

struct familia {
    string sobrenome;
    anosDeVida iPai;
    anosDeVida iMae;
    anosDeVida iFilho;
};

int main() {
    int tam = 3, qFamilia = 0;
    familia *vetor = new familia[tam];


    for (int i = 0; i < tam; i++) {
        cin >> vetor[i].sobrenome;
        
        while (vetor[i].sobrenome != "FIM") {
            cin >> vetor[i].iPai.idade
            >> vetor[i].iMae.idade >> vetor[i].iFilho.idade;
            qFamilia++;
        }

            
    }


    delete [] vetor;
    
    return 0;
}
