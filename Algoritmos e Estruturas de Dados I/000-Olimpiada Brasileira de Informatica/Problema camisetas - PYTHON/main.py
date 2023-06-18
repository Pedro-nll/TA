Pq = 0
Mq=0
#armazena a quantidade de premiados
N = int(input())
#armazena os tamanhos desejados por cada premiado
T = []
for i in range(N):
  tamanho = int(input())
  T.append(tamanho)
#itera o array de tamanhos desejados e armazena a quantidade necessaria de cada tamanho
for i in range(N):
  if (T[i] == 1):
    Pq += 1
  else:
    Mq += 1
#Recebe a quantidade de camisas P produzidas
P = int(input())
#Recebe a quantidade de camisas M produzidas
M = int(input())
#Saída
if(Pq <= P and Mq <= M):
  print('s')
else:
  print('n')