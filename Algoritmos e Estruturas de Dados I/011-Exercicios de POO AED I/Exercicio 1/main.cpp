#include <iostream>
#include <string>

//Enunciado:
/*Escreva um c�digo em C/C++ que apresente a classe Pessoa, com atributos nome, endereco
e telefone e, o m�todo imprimir. O m�todo imprimir deve mostrar na tela os valores de
todos os atributos. Adicionar um m�todo construtor que permita a defini��o de todos os
atributos no momento da instancia��o do objeto.*/

using namespace std;

class Pessoa{
private:
    string nome;
    string endereco;
    string telefone;
public:
    Pessoa(string n, string e, string t){
        nome = n;
        endereco = e;
        telefone = t;
    }
    void imprimePessoa(){
        cout << nome << " telefone: "<<telefone << " endereco: " << endereco << endl;
    }
};

int main()
{
    Pessoa a = Pessoa("Pedro", "Alameda a", "(31) 91234-1234");
    Pessoa b = Pessoa("Raquel", "Bairro b", "(31) 94321-4321");
    Pessoa c = Pessoa("Marcio", "Cidade c", "(31) 91234-4321");

    Pessoa listaDePessoas[3] = {a, b, c};

    for(int i = 0; i<3; i++)listaDePessoas[i].imprimePessoa();

    return 0;
}
