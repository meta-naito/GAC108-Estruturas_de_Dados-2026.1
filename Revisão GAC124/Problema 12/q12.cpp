//Revisão - Questão 12
#include <iostream>
#include <cmath>

using namespace std;

struct circulo {
    char figura;
    float raio;
};

struct retangulo {
    char figura;
    float base, altura;
};

struct triangulo {
    char figura;
    float ladoA, ladoB, ladoC;
};

int main() {
    const unsigned int qFiguras = 5;
    char figura;

    for (unsigned int i = 0; i < qFiguras; i++) {
        cin >> figura;
        tolower(figura);

        if (figura == 'c') {


        }


    }




    return 0;
}