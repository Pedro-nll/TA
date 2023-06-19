#include <stdio.h>
#include <stdlib.h>

void menuInicial(){
    int vooSelecionado;
    do{
        printf("---------- EMPRESA AEREA QUEDA LIVRE ----------\n");
        printf("    MENU DE VOOS    \n");
        printf("[1]BH-RIO\n[2]BH-SP\n[3]BH-BRASILIA\n\n[9]Para fechar o programa.");
        printf("\n\nDigite a opcao referente ao voo desejado: ");
        scanf("%d", &vooSelecionado);
        switch(vooSelecionado){
            case 1:{
                menuVoos(1);
                break;
            }
            case 2:{
                menuVoos(2);
                break;
            }
            case 3:{
                menuVoos(3);
                break;
            }
            case 9:{
                return 9;
            }
            default:{
                printf("Voo invalido.\n\n");
            }
        }
    }while(vooSelecionado != 1 && vooSelecionado != 2 && vooSelecionado != 3);
}

void menuVoos(int vooSelecionado){
    char voos[][20] = {"VOO BH-RIO", "VOO BH-SP", "VOO BH-BRASILIA"};
    int opcaoMenu;
    printf("---------- EMPRESA AEREA QUEDA LIVRE - %s ----------\n", voos[vooSelecionado-1]);
    printf("  MENU DE OPCOES  \n");
    printf("[1]Mostrar lista de passageiros\n[2]Pesquisar passageiro por CPF\n[3]Pesquisar passageiro por nome\n");
    printf("[4]Cadastrar passageiro\n[5]Excluir passageiro da lista\n[6]Mostrar lista de espera\n");
    printf("\n[9]Sair\n");
    printf("\nDigite sua opcao: ");
    scanf("%d", &opcaoMenu);
    switch(opcaoMenu){
        case 9:{
            menuInicial();
        }
        default:{
            printf("Opcao invalida.\n\n");
            menuVoos(vooSelecionado);
        }
    }
}

int main()
{
    menuInicial();
    return 0;
}
