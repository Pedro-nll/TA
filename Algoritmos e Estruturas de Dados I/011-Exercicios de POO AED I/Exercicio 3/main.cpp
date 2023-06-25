#include <iostream>
#include <string>

using namespace std;

#define NUMERODEOBJETOS 3

/*Escreva um código em C/C++ que apresente a classe Moto, com atributos marca, modelo,
cor e marcha e, o método imprimir. O método imprimir deve mostrar na tela os valores de
todos os atributos. O atributo marcha indica em que a marcha a Moto se encontra no
momento, sendo representado de forma inteira, onde 0 - neutro, 1 – primeira, 2 – segunda,
etc. Adicionar um método construtor que permita a definição de todos os atributos no
momento da instanciação do objeto.*/

class Moto{
private:
    string marca;
    string modelo;
    string cor;
    int marcha;
public:
    Moto(string marc, string mod, string c, int march){
        marca = marc;
        modelo = mod;
        cor = c;
        marcha = march;
    }

    void imprimirMoto(){
        cout << "Marca: " << marca << " - Modelo: " << modelo << " - Cor: " << cor << " - Marcha atual: " << marcha << endl;
    }
};

int main()
{
    Moto a = Moto("Honda", "CG 160 Start", "Azul", 0);
    Moto b = Moto("Honda", "Pop 110i", "Vermelha e branca", 1);
    Moto c = Moto("Honda", "PCX", "Preta", 2);

    Moto listaDeMotos[NUMERODEOBJETOS] = {a,b,c};

    for(int i = 0; i<NUMERODEOBJETOS; i++) listaDeMotos[i].imprimirMoto();

    return 0;
}
