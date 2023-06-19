#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * arq = fopen("file.txt", "r");
    int n;
    scanf("%d",&n);
    int vetor[20];
    for(int i = 0;i<n;i++) fscanf(arq,"%d ",vetor+i);
    for(int i = 0; i<n;i++) printf("%d", vetor[i]);
    fclose(arq);
    return 0;
}
