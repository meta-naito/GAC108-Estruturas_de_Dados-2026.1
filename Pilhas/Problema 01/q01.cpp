//Pilhas - Questão 01
#include <iostream>

using namespace std;
typedef int Dado;

class Pilha {
    private:
        unsigned int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;

    public:
        // caso vc queira fazer com que o construtor tenha um valor default e use implementação externa,
        // NÃO precisa de fazer com que a declaração tenha o valor default!!! só declara isso qndo for escrever a função <3 
        Pilha(unsigned int cap);
        ~Pilha();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e posição do topo)

};

Pilha::Pilha(unsigned int cap = 20) {
    dados = new Dado[cap];
    capacidade = cap;
    tamanho = 0;
    posTopo = -1;
}
Pilha::~Pilha() {
    delete [] dados;
}
void Pilha::empilha(Dado valor) {
    tamanho++;
    posTopo++;

    dados[posTopo] = valor;

    return;
}
Dado Pilha::desempilha() {
    Dado valor = dados[posTopo];
    tamanho--;
    posTopo--;
    
    return valor;
}
Dado Pilha::espia() {
    Dado valor = dados[posTopo];

    return valor;
}
// APENAS PARA FINS DE DEPURAÇÃO!!! NÃO SE FAZ ASSIM NUMA PILHA NORMAL
void Pilha::depura() {
    for (int i = 0; i < this->tamanho; i++) {
        cout << dados[i] << " ";
    }

    cout << endl;

    return;
}
void Pilha::info() {
    cout << this->tamanho << " " << this->posTopo << endl;

    return;
}

void InsereValores(Pilha &myPilha, unsigned int qValores) {
    Dado valor;

    for (unsigned int i = 0; i < qValores; i++) {
        cin >> valor;
        myPilha.empilha(valor);
    }

    return;
}

void RetiraValores(Pilha &myPilha, unsigned int qDesempilha) {
    for (unsigned int i = 0; i < qDesempilha; i++) {
        cout << myPilha.desempilha() << " ";
    }
    cout << endl;
    
    return;
}

int main() {
    Pilha myPilha;
    // valores iniciais pra questão, depois mudam
    unsigned int qValores = 5, qDesempilha = 3;

    InsereValores(myPilha, qValores);
    RetiraValores(myPilha, qDesempilha);

    qValores = 4;
    InsereValores(myPilha, qValores);
    RetiraValores(myPilha, qDesempilha);

    cout << myPilha.espia() << endl;
    myPilha.depura();
    myPilha.info();

    return 0;
}
