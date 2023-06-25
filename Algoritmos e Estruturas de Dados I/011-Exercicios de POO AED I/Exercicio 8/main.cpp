#include <iostream>
#include <string>

#define NUMERODEOBJETOS 3

using namespace std;

//Enunciado:
/*Baseando-se no exercício 6 adicione os atributos numeroCanais e, volumeMaximo, onde
numeroCanais indica o número máximo de canais que o televisor pode sintonizar e
volumeMaximo indica qual o maior nível de volume possível. O método imprimir deve ser
modificado de forma a mostrar na tela os valores de todos os atributos.*/

class Televisor{
private:
    bool ligado;
    int canal;
    int volume;
    int numCanais;
    int volumeMax;
public:
    Televisor(bool l, int c, int v, int nCanais, int volMax){
        ligado = l;
        canal = c;
        volume = v;
        numCanais = nCanais;
        volumeMax = volMax;
    }

    void ligarOuDesligar(){
        ligado = !(ligado);
    }

    void imprimeTelevisor(){
        if(ligado) cout << "O televisor esta ligado no canal " << canal << " com o volume no " << volume
            << " || O volume maximo eh: " << volumeMax << " e esse televisor tem " << numCanais <<" canais." << endl;
        else cout << "O televisor esta desligado. Porem ele tem " << numCanais << " canais e seu volume maximo eh " << volumeMax << endl;
    }
};

int main()
{
    Televisor a = Televisor(1,12,60,400,100);
    Televisor b = Televisor(false,69,10,500,100);
    Televisor c = Televisor(true,420,1,600,100);

    Televisor *listaDeTelevisores[NUMERODEOBJETOS] = {&a,&b,&c};

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;

    a.ligarOuDesligar();
    b.ligarOuDesligar();
    c.ligarOuDesligar();

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    return 0;
}
