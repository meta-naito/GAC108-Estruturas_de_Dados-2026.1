//Revisão - Questão 3
#include <iostream>

using namespace std;
 
void LeituraTermos(string *vetor, unsigned int tam) {
    for (unsigned int i = 0; i < tam; i++) {
        cin >> vetor[i];
    }

    return;
}

bool TemRepeticao(string *lista, unsigned int tam, string palavra) {
    for (unsigned int i = 0; i < tam; i++) {
        if (palavra == lista[i]) {
            return true;
        }
    }

    return false;
}

void ImprimeRepeticao(string *listaA, unsigned int tamA, string *listaB, unsigned int tamB, string *listaC, unsigned int tamC) {
    //cria um vetor pra armazenar a quantidade de vezes que o elemento aparece 
    //tem como fazer isso no cout, provavelmente KKKK
    unsigned int *qVezes = new unsigned int[tamC];

    //inicializando os numeros como zero pra nn ter problema dps
    for (unsigned int i = 0; i < tamC; i++) {
        qVezes[i] = 0;
    }

    for (unsigned int i = 0; i < tamC; i++) {
        if (TemRepeticao(listaA, tamA, listaC[i])) {
            qVezes[i]++;
        }

        //nao coloquei as duas junto pq pode ser que tenha nas DUAS listas
        if (TemRepeticao(listaB, tamB, listaC[i])) {
            qVezes[i]++;
        }
    }

    for (unsigned int i = 0; i < tamC; i++) {
        cout << qVezes[i] << " ";
    }

    return;
}

int main() {
    unsigned int qTermosA, qTermosB, qTermosC;

    cin >> qTermosA;
    string *termosA = new string[qTermosA];
    LeituraTermos(termosA, qTermosA);

    cin >> qTermosB;
    string *termosB = new string[qTermosB];
    LeituraTermos(termosB, qTermosB);

    cin >> qTermosC;
    string *termosC = new string[qTermosC];
    LeituraTermos(termosC, qTermosC);

    ImprimeRepeticao(termosA, qTermosA, termosB, qTermosB, termosC, qTermosC);

    return 0;
}