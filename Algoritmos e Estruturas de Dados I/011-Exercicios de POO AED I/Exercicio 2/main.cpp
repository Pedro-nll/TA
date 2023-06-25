#include <iostream>
#include <string>

using namespace std;

#define NUMERODEOBJETOS 3

//Enunciado:
/*Escreva um c�digo em C/C++ que apresente a classe Retangulo, com atributos
comprimento, largura, area e perimetro e, os m�todos calcularArea, calcularPerimetro
e imprimir. Os m�todos calcularArea e calcularPerimetro devem efetuar seus respectivos
c�lculos e atribuir os respectivos valores nos atributos area e perimetro. O m�todo imprimir
deve mostrar na tela os valores de todos os atributos. Adicionar um m�todo construtor que
permita a defini��o de todos os atributos no momento da instancia��o do objeto.*/

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
