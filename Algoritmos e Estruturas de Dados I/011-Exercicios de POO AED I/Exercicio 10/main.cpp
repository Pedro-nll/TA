#include <iostream>
#include <string>

#define NUMERODEOBJETOS 3

using namespace std;

//Enunciado:
/*Baseando-se no exerc�cio 6 adicione os m�todos volumeAcima e volumeAbaixo, sendo que
o m�todo volumeAcima deve modificar o volume para o pr�ximo n�vel de volume poss�vel,
onde ao chegar ao volumeMaximo n�o poder� possibilitar que o volume seja alterado. O
m�todo volumeAbaixo deve modificar o volume para o n�vel imediatamente inferior de
volume em rela��o ao volume atual, n�o podendo ser menor do que 0, simulando desta forma
o funcionamento de um televisor.*/

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

    void canalAcima(){
        if(canal+1 > numCanais) canal = 1;
        else canal++;
    }

    void canalAbaixo(){
        if(canal-1<1)canal = numCanais;
        else canal--;
    }

    void volumeAcima(){
        if(volume == volumeMax) cout << "Volume maximo ja alcancado" << endl;
        else volume++;
    }

    void volumeAbaixo(){
        if(volume == 0) cout << "Volume minimo ja alcancado" << endl;
        else volume--;
    }

    void imprimeTelevisor(){
        if(ligado) cout << "O televisor esta ligado no canal " << canal << " com o volume no " << volume
            << " || O volume maximo eh: " << volumeMax << " e esse televisor tem " << numCanais <<" canais." << endl;
        else cout << "O televisor esta desligado." << endl;
    }
};

int main()
{
    Televisor a = Televisor(1,1,60,400,100);
    Televisor b = Televisor(false,69,10,500,11);
    Televisor c = Televisor(true,420,1,421,100);

    Televisor *listaDeTelevisores[NUMERODEOBJETOS] = {&a,&b,&c};

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;

    a.canalAbaixo();
    c.canalAcima();
    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;
    a.canalAcima();
    c.canalAcima();

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;

    a.ligarOuDesligar();
    b.ligarOuDesligar();
    c.ligarOuDesligar();

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;

    c.ligarOuDesligar();
    c.volumeAbaixo();
    b.volumeAcima();

    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    cout << "---- Apertando alguns botoes... " << endl;
    c.volumeAbaixo();
    b.volumeAcima();
    for(int i = 0; i<NUMERODEOBJETOS; i++)listaDeTelevisores[i]->imprimeTelevisor();

    return 0;
}
