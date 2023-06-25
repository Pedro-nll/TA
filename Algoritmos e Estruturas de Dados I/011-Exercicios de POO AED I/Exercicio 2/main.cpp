#include <iostream>
#include <string>

using namespace std;

#define NUMERODEOBJETOS 3

//Enunciado:
/*Escreva um código em C/C++ que apresente a classe Retangulo, com atributos
comprimento, largura, area e perimetro e, os métodos calcularArea, calcularPerimetro
e imprimir. Os métodos calcularArea e calcularPerimetro devem efetuar seus respectivos
cálculos e atribuir os respectivos valores nos atributos area e perimetro. O método imprimir
deve mostrar na tela os valores de todos os atributos. Adicionar um método construtor que
permita a definição de todos os atributos no momento da instanciação do objeto.*/

class Retangulo{
private:
    int comprimento, largura, area, perimetro;
public:
    Retangulo(int c, int l){
        comprimento = c;
        largura = l;
        calcularArea();
        calcularPerimetro();
    }
    void calcularArea(){
        area = comprimento * largura;
    }
    void calcularPerimetro(){
        perimetro = (comprimento * 2) + (largura * 2);
    }
    void imprimirRetangulo(){
        cout << "Comprimento: " << comprimento << " - Largura: " << largura << " - Area: " << area << " - Perimetro: "<< perimetro << endl;
    }
};

int main()
{
    Retangulo a = Retangulo(10, 5);
    Retangulo b = Retangulo(20,10);
    Retangulo c = Retangulo(40,20);

    Retangulo listaDeRetangulos[NUMERODEOBJETOS] = {a,b,c};

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeRetangulos[i].imprimirRetangulo();
    return 0;
}
