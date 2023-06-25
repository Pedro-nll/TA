#include <iostream>
#include <string>

using namespace std;

#define NUMERODEOBJETOS 3

//Enunciado:
/*Baseando-se no exercício 3 adicione os métodos marchaAcima e marchaAbaixo que
deverão efetuar a troca de marchas, onde o método marchaAcima deverá subir uma marcha,
ou seja, se a moto estiver em primeira marcha, deverá ser trocada para segunda marcha e
assim por diante. O método marchaAbaixo deverá realizar o oposto, ou seja, descer a marcha.
O método imprimir deve ser modificado de forma a mostrar na tela os valores de todos os
atributos*/


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

    void marchaAcima(){
        marcha += 1;
    }
    void marchaAbaixo(){
        marcha -= 1;
    }

    void imprimirMoto(){
        cout << "Marca: " << marca << " - Modelo: " << modelo << " - Cor: " << cor << " - Marcha atual: " << marcha << endl;
    }
};

int main()
{
    Moto a = Moto("Honda", "CG 160 Start", "Azul", 1);
    Moto b = Moto("Honda", "Pop 110i", "Vermelha e branca", 2);
    Moto c = Moto("Honda", "PCX", "Preta", 3);

    Moto *listaDeMotos[NUMERODEOBJETOS] = {&a,&b,&c};

    for(int i = 0; i<NUMERODEOBJETOS; i++) listaDeMotos[i]->imprimirMoto();

    cout << "----- TROCA DE MARCHA -----" << endl;

    a.marchaAbaixo();
    b.marchaAcima();
    c.marchaAbaixo();

    for(int i = 0; i<NUMERODEOBJETOS; i++) (*listaDeMotos[i]).imprimirMoto();

    return 0;
}
