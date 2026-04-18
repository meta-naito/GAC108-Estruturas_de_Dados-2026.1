// Pilhas - Questão 04
// a questao já tinha um código pré-feito, só faltava implementar as funções!
#include <iostream>

using namespace std;
typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mPtProx;
};

class Pilha {
    public:
        // Constrói pilha vazia.
        Pilha();
        // Destrutor que desaloca memória.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se não for possível desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() {
            return mTamanho;
        }
        // Retorna o valor que está no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha está Vazia.
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};


Pilha::Pilha() {
    mPtTopo = nullptr;
    mTamanho = 0;
}

Pilha::~Pilha() {
    while (mPtTopo != nullptr) {
        this->Desempilhar();
    }
}

Dado Pilha::Desempilhar() {
    Noh *aux = new Noh;
    Dado valor;
    
    try {
        if (this->Vazia() == true) {
            throw 'a';
        }
        else {
            aux = mPtTopo;
            valor = aux->mDado;
            mPtTopo = aux->mPtProx;
            
            mTamanho--;
        }
    }
    
    catch (char e) {
        cout << "a pilha está vazia, não tem como desempilhar!\n";
        valor = -1;
    }

    return valor;
}

void Pilha::Empilhar(const Dado& d) {
    Noh *novoElem = new Noh;

    novoElem->mDado = d;
    novoElem->mPtProx = mPtTopo;
    mPtTopo = novoElem;
    this->mTamanho++;

    return;
}

void Pilha::LimparTudo() {
    while (mPtTopo != nullptr) {
        this->Desempilhar();
    }
    
    return;
}

Dado Pilha::Topo() const {
    return mPtTopo->mDado;
}

bool Pilha::Vazia() const {
    return mPtTopo == nullptr;
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando inválido!\n";
        }
    } while (comando != 'f'); // finalizar execução
    
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    
    return 0;
}
