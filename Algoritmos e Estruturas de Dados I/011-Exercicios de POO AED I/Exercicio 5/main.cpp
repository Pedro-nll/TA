#include <iostream>
#include <string>

using namespace std;

#define NUMERODEOBJETOS 3

//Enunciado:
/*Baseando-se no exercício 4 adicione os atributos menorMarcha e maiorMarcha, onde o
atributo menorMarcha indica qual será a menor marcha possível para a moto e o atributo
maiorMarcha indica qual será a maior marcha possível. Desta forma os métodos
marchaAcima e marchaAbaixo devem ser reescritos de forma a não permitirem a troca de
marchas para valores abaixo da menorMarcha e acima da maiorMarcha. O método imprimir
deve ser modificado de forma a mostrar na tela os valores de todos os atributos. Corrigir o
construtor para que permitir a definição de todos os atributos no momento da instanciação
do objeto.*/


class Moto{
private:
    string marca;
    string modelo;
    string cor;
    int marcha;
    int menorMarcha;
    int maiorMarcha;
public:
    Moto(string marc, string mod, string c, int march, int menor, int maior){
        marca = marc;
        modelo = mod;
        cor = c;
        marcha = march;
        menorMarcha = menor;
        maiorMarcha = maior;
    }

    void marchaAcima(){
        if (marcha + 1 > maiorMarcha) cout << "A " << modelo << " ja alcancou a maior marcha" << endl;
        else marcha += 1;
    }
    void marchaAbaixo(){
        if (marcha - 1 < menorMarcha) cout << "A " << modelo << " ja alcancou a menor marcha" << endl;
        else marcha -= 1;
    }

    void imprimirMoto(){
        cout << "Marca: " << marca << " - Modelo: " << modelo << " - Cor: " << cor << " - Marcha atual: "
        << marcha << " - Menor marcha: "<<menorMarcha <<" - Maior marcha: " << maiorMarcha <<  endl;
    }
};

int main()
{
    Moto a = Moto("Honda", "CG 160 Start", "Azul", 0, 0, 5);
    Moto b = Moto("Honda", "Pop 110i", "Vermelha e branca", 3, 0, 6);
    Moto c = Moto("Honda", "PCX", "Preta", 2, 0, 2);

    Moto *listaDeMotos[NUMERODEOBJETOS] = {&a,&b,&c};

    for(int i = 0; i<NUMERODEOBJETOS; i++) listaDeMotos[i]->imprimirMoto();

    cout << "----- TROCA DE MARCHA -----" << endl;

    a.marchaAbaixo();
    b.marchaAcima();
    c.marchaAcima();

    for(int i = 0; i<NUMERODEOBJETOS; i++) (*listaDeMotos[i]).imprimirMoto();

    return 0;
}
