#include <stdio.h>
#include <stdlib.h>

//Enunciado:
/*Crie um programa que leia a quantidade de ve�culos que uma locadora de ve�culos possui e
o valor que ela cobra por cada aluguel, mostrando as informa��es pedidas a seguir:
� Sabendo-se que um ter�o dos ve�culos s�o alugados por m�s, exiba o faturamento anual
da locadora
� Quando o cliente atrasa a entrega, � cobrada uma multa de 20% sobre o valor do aluguel.
Sabendo que um d�cimo dos ve�culos alugados no m�s � devolvido com atraso, calcule
o valor ganho com multas no m�s
� Sabe-se ainda que 2% dos ve�culos precisam de manuten��o ao longo do ano. Calcule o
valor gasto com a manuten��o anual, sabendo que o valor gasto em m�dia com a
manuten��o � de R$ 600,00.
Al�m de mostrar os resultados na tela, grave em um arquivo chamado resultado.txt. Cada
valor dever� ser armazenado em uma linha.*/

int main()
{
    FILE *entrada = fopen("locadora.txt", "r");
    FILE *saida = fopen("resultado.txt", "w");
    if(entrada == NULL){
        printf("Nao foi possivel abrir o arquivo de entrada.\n");
        return 1;
    }
    if(saida == NULL){
        printf("Nao foi possivel criar o arquivo de saida");
        return 1;
    }

    int qntVeiculos, valorAluguel;
    fscanf(entrada, "Quantidade de veiculos %d\n", &qntVeiculos);
    fscanf(entrada, "Valor do aluguel %d\n", &valorAluguel);

    double faturamento = ((qntVeiculos/3) * valorAluguel) * 12;
    double multas = (((qntVeiculos/3)/10) * 0.2)*12;
    double manutencao = (qntVeiculos*0.02)*600;

    double lucro = faturamento + multas - manutencao;

    printf("O faturamento anual com o aluguel foi de $%.2lf.\nAlem disso, foram faturados %.2lf reais com multas.\n", faturamento,multas);
    printf("Porem a manutencao custou %.2lf reais.\nCom isso o lucro foi de R$%.2lf\n",manutencao,lucro);

    fprintf(saida, "O faturamento anual com o aluguel foi de $%.2lf.\nAlem disso, foram faturados %.2lf reais com multas.\n", faturamento,multas);
    fprintf(saida, "Porem a manutencao custou %.2lf reais.\nCom isso o lucro foi de R$%.2lf\n",manutencao,lucro);

    fclose(entrada);
    fclose(saida);
    return 0;
}
