#include <stdio.h>
#include <string.h>

int main(void) {
  int N;
  printf("Digite o numero da questao: ");
  scanf("%d", &N);
  switch(N){
    //Leia um conjunto indeterminado de palavras e ao final (estipule você um flag) informe qual foi a maior palavra e a menor palavra digitada, em tamanho
    case 1:{
      char palavras[100] = "a";
      int maior = 0, menor = 101;
      scanf("%[^\n]", palavras);
      getchar();
      maior = strlen(palavras);
      menor = strlen(palavras);
    while (strcmp(palavras, "fim") != 0){
      scanf("%[^\n]", palavras);
      getchar();
      //printf("%d\n",(int) strlen(palavras));
      if (strcmp(palavras, "fim") != 0){
        if (strlen(palavras)>maior) maior = strlen(palavras);
        if (strlen(palavras)<menor) menor = strlen(palavras);
      };
    };
      printf("a menor palavra tem %d letras, e a maior tem %d", menor, maior);
      return 0;
    }
    //Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere aparece na string lida e quantas vezes ele apareceu.
    case 2:{
      char string[51];
      char c;
      int contador = 0;

      getchar();
      printf("digite sua frase: \n");
      scanf("%[^\n]", string);
      getchar();
      printf("digite um caracter: \n");
      scanf("%c", &c);
      getchar();
      for (int i = 0; i<50; i++){
        if (string[i]==c){
          contador++;
          printf("posição: %d\n", i);
        }
      }
      printf("O caracter %c aparece %d vezes", c, contador);
      break;
    }
    //Ler uma string de no máximo 50 caracteres e mostrar quantas letras possui, quantos caracteres são números e quantos não são nem números nem letras
    case 3:{
      char string[51] = "";
      int numeros = 0, letras = 0, simbolos = 0;
      getchar();
      scanf("%[^\n]", string);
      getchar();
      for(int i = 0; i < strlen(string); i++){
        if((int) string[i] >= 48 && (int) string[i] <= 57) numeros++;
        else if((int) string[i] >= 65 && (int) string[i] <= 90 || (int) string[i] >= 97 && (int) string[i] <= 122) letras++;
      }
      simbolos = strlen(string) - numeros - letras;
      printf("A string tem %d letras, %d numeros e %d simbolos", letras, numeros, simbolos);
      break;
    }
    //Ler uma string de no máximo 50 caracteres e criar uma nova string com seu inverso, isso é a última letra da primeira string será a primeira na nova string e assim sucessivamente
    case 4:{
      char string[51];
      getchar();
      scanf("%[^\n]", string);
      getchar();
      for(int i = strlen(string); i >= 0; i--) printf("%c", string[i]);
      break;
    }
    //Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco
    case 5:{
      char string[51], stringSemEspaco[51] ="";
      int contador = 0;
      getchar();
      scanf("%[^\n]", string);
      getchar();
      for(int i = 0; i<strlen(string); i++){
        if (string[i] != ' ' ){
          stringSemEspaco[contador] = string[i];
          contador++;
        }
      }
      for(int i = 0; i < strlen(stringSemEspaco); i++) {
        printf("%c", stringSemEspaco[i]);
      };
      printf("\n");
      break;
    }
    //Ler uma string de no máximo 50 caracteres em seguida, leia outra string de no máximo 3 caracteres, informe quantas vezes a segunda string aparece na primeira string, e diga as posições iniciais em que ela aparece
    case 6:{
      char string[51], string2[4];//declaracao de strings
      int contador = 0; //contador de quantas vezes a string 2 aparece na string 1
      getchar(); //limpar o buffer
      scanf("%[^\n]", string);//string a ser definida pelo usuario
      getchar(); //limpar o buffer
      scanf("%[^\n]", string2); //String de 3 letras definidas pelo usuarios para encontrar na string 1
      getchar(); //limpar o buffer
      //loop percorrendo todos os caracteres da string 1
      for(int i = 0; i<strlen(string); i++){
         
        if(strncmp(string + i, string2, strlen(string2)) == 0){
          printf("A string 2 aparece na posicao: %d\n", i); 
          contador++;
        }
      }
      printf("A string aparece %d vezes", contador);
      break;
    }
    default:{
      printf("questão invalida.");
    }
  }
}