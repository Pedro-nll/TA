#include <iostream>
#include <string>

#define NUMERODEOBJETOS 3

using namespace std;

//Enunciado:
/*Escreva um c�digo em C/C++ que apresente a classe Televisor, com atributos ligado, canal
e volume e, o m�todo imprimir. O m�todo imprimir deve mostrar na tela os valores de todos
os atributos. O atributo ligado ser� booleano e dever� indicar o estado atual do televisor, se
ligado ou desligado. O atributo canal dever� indicar o canal atual em que o televisor est�
sintonizado. O atributo volume dever� indicar o volume atual do televisor. Adicionar um
m�todo construtor que permita a defini��o de todos os atributos no momento da instancia��o
do objeto.*/

class Televisor{
private:
    bool ligado;
    int canal;
    int volume;
public:
    Televisor(bool l, int c, int v){
        ligado = l;
        canal = c;
        volume = v;
    }
    void imprimeTelevisor(){
        if(ligado) cout << "O televisor esta ligado no canal " << canal << " com o volume no " << volume << endl;
        else cout << "O televisor esta desligado no canal " << canal << " com o volume no " << volume << endl;
    }
};

int main()
{
    Televisor a = Televisor(1,12,60);
    Televisor b = Televisor(false,69,10);
    Televisor c = Televisor(true,420,1);

    Televisor listaDeTelevisores[NUMERODEOBJETOS] = {a,b,c};

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i].imprimeTelevisor();

    return 0;
}
