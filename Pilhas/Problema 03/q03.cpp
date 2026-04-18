// Pilhas - Questão 03
#include <iostream>
#include <string>

typedef char dado;

class Noh {
    friend class Pilha;
    private:
        dado chara;
        Noh *proximoDado;
    public:
        Noh() {
            proximoDado = nullptr;
        }
};

class Pilha {
    private:
        Noh *topo; // topo possui chara (vazio) e proximoDado (pro elem. do topo)
        int tamanho;
    public:
        Pilha() {
            topo = nullptr;
            tamanho = 0;
        }
        ~Pilha() {

        }
        void empilhar(dado novo){
            Noh *valor =  new Noh;
            valor->chara = novo;
            valor->proximoDado = topo;
            topo = valor;
            tamanho++;
        }
        dado desempilhar() {
            Noh *aux;
            dado valor;

            aux = topo;
            valor = aux->chara;
            topo = aux->proximoDado;
            tamanho--;

            return valor;
        }
        bool taVazia() {
            return tamanho <= 0;
        }
};

int main() {
    std::string linha;
    getline(std::cin, linha);
    Pilha myPilha;

    dado chara;
    int posLinha = 0;
    unsigned posAnterior = 0, posParentese = 0; // posAnterior existe para, qndo desempilhar, a posicao do parentese ser atualizada pra anterior

    // so pra nao reclamar de comparacao com tipos diferentes, aí o (unsigned)
    while (((unsigned)posLinha < linha.size()) and (posLinha != -1)) {
        chara = linha[posLinha];

        if (chara == '(') {
            myPilha.empilhar(chara);

            posAnterior = posParentese;
            posParentese = posLinha;
        }
        else if (chara == ')') {
            // se a pilha ta vazia mas encontrar um parentese fechado, nn tem correspondencia
            if (myPilha.taVazia() == true) {
                posParentese = posLinha;
                std::cout << posParentese << std::endl;

                // pra sair do while (tem que ser -2 pq posLinha incrementa em um a cada while)
                posLinha = -2;
            }
            // se nao estiver vazia, só desempilha e posParentese recebe a posicao do parentese aberto anterior
            else {
                myPilha.desempilhar();
                posParentese = posAnterior;
            }
        }

        posLinha++;
    }

    // se a pilha estiver com parentese aberto ainda, nn teve correspondencia
    if (myPilha.taVazia() == false) {
        std::cout << posParentese << std::endl;
    }
    // checa se nao deu já cout em parentese fechado sem correspondencia
    else if (posLinha != -1) {
        std::cout << "correto" << std::endl;
    }

    return 0;
}