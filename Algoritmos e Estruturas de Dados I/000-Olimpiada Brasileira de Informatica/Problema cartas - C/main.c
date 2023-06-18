#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cartas[5];
    char resposta = 'N';
    for(int i = 0; i<5; i++){
        scanf("%d", cartas + i);
    }
    if(cartas[0]>cartas[1]){
        for(int i=0; i<4;i++){
            if(cartas[i]<cartas[i+1]){
                resposta = 'N';
                break;
            }else{
                resposta = 'D';
            }
        }
    }else{
        for(int i=0; i<4;i++){
            if(cartas[i]>cartas[i+1]){
                resposta = 'N';
                break;
            }else{
                resposta = 'C';
            }
        }
    }
    printf("%c", resposta);
    return 0;
}
