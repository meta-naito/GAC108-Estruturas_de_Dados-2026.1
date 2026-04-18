//Atividade Prática de Pilhas
#include <iostream>

using namespace std;

class Pilha {
    private:
        unsigned int topo;
        int *vetor;

        //funcao auxiliar do MaiorValor()
        int CalculaMaior(int num1, int num2) {
            if (num1 > num2) {
                return num1;
            }
            //desnecessario o else aqui, e compilador reclama
            return num2;
        }
        
        //funcao auxiliar para poder imprimir mensagem de VAZIA no terminal quando for pedido
        bool TaVazia() {
            //se topo é igual a zero, implica que nao tem numero dentro da pilha
            if (topo <= 0) {
                return true;
            }

            return false;
        }

    public:
        //construtor (cria a classe pilha)
        Pilha(const unsigned int tam = 10) {
            topo = 0;
            vetor = new int[tam]; //tamanho da pilha já é dado kk
        }

        //destrutor (mata a classe pilha)
        ~Pilha() {
            delete [] vetor;
        }

        //insere elemento
        void Push(int elemento) {
            //entao, nao sei se eu to fazendo a definicao de topo corretamente
            //nao me deu problema agora, mas pilha por ponteiro parece mais divertido de qlqr maneira
            topo++;
            vetor[topo] = elemento;

            return;
        }

        //"remove" o elemento (ele ainda ta la, mas nn tem como acessar/se inserir elem. novo ele só morre)
        void Pop() {
            //checa se a pilha ta vazia
            if (TaVazia() == true) {
                cout << "VAZIA" << endl;
            }

            else {
                cout << vetor[topo] << endl;
                topo--;
            }

            return;
        }

        int MaiorValor() {
            int maior = this->vetor[topo];

            if (TaVazia() == true) {
                return -1;
            }
            
            else {
                Pilha pAux;
                int aux;

                //desemplihar a pilha original, e enquanto passa pra pAux checa se o valor é o maior
                //dps de terminar isso, aí empilha a pilha original dnv yayy
                while (TaVazia() != true) {
                    aux = this->vetor[topo];
                    //mata o elemento que ta agr armazenado em aux
                    topo--;
                    pAux.Push(aux);
                    maior = CalculaMaior(aux, maior);
                }

                while (pAux.TaVazia() != true) {
                    aux = pAux.vetor[pAux.topo];
                    pAux.topo--;
                    this->Push(aux);
                }
            }
            
            return maior;
        }

        void Imprimir() {
            //so pra dar um aviso kk
            if (TaVazia() == true) {
                cout << "PILHA SEM ELEMENTOS!" << endl;
            }
            //desempilha o trem todo, e enquanto desempilha vai dando cout
            for (unsigned int i = topo; i > 0; i--) {
                cout << vetor[i] << endl;
            }
        }
};

int main() {
    Pilha myPilha;
    //qNum existe para contar qntos elementos foram inseridos para não colocar coisa em espaço de memória que não tem alocação
    int num, qNum = 0;

    char opcao;
    cin >> opcao;

    while (opcao) {
        switch (opcao) {
            case 'e': {
                try {
                    if (qNum < 10) {
                        cin >> num;
                        myPilha.Push(num);
                        qNum++;
                    }

                    else {
                        throw(qNum);
                    }
                } 

                catch(int qNum) {
                    cin >> num;
                    cout << "Não é possível inserir mais elementos." << endl;
                }
                break;
            }
            case 'd': {
                myPilha.Pop();
                qNum--;

                break;
            }
            case 'm': {
                if (myPilha.MaiorValor() == -1) {
                    cout << "VAZIA" << endl;
                }
                else {
                    cout << myPilha.MaiorValor() << endl;
                }
                break;
            }
            case 's': {
                myPilha.Imprimir();
                exit(0);

                break;
            }
            default: {
                cout << "Não é uma opção! Tente novamente :)" << endl;

                break;
            }
        }
        cin >> opcao;    
    }
    
    return 0;
}
