#include <iostream>
#include <string>

#define NUMERODEOBJETOS 3

using namespace std;

//Enunciado:
/*Baseando-se no exercício 6 adicione os métodos ligar e desligar que deverão mudar o
conteúdo do atributo ligado conforme o caso*/

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

    void ligarOuDesligar(){
        ligado = !(ligado);
    }

    void imprimeTelevisor(){
        if(ligado) cout << "O televisor esta ligado no canal " << canal << " com o volume no " << volume << endl;
        else cout << "O televisor esta desligado." << endl;
    }
};

int main()
{
    Televisor a = Televisor(1,12,60);
    Televisor b = Televisor(false,69,10);
    Televisor c = Televisor(true,420,1);

    Televisor *listaDeTelevisores[NUMERODEOBJETOS] = {&a,&b,&c};

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;

    a.ligarOuDesligar();
    b.ligarOuDesligar();
    c.ligarOuDesligar();

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    return 0;
}
