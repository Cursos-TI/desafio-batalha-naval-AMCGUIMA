#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //DECLARAÇAO DA MATRIZ 10x10 QUE REPRESENTARÁ O TABULEIRO  
    int tabuleiro[10][10];

    int Cone[3][5]=
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    
    int Octaedro[3][5]=
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int Cruz[3][5]=
    {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0 ,0, 1, 0, 0}

    };

    //INICIALIZA COM ZERO A MATRIZ PARA REPRESENTAR AGUA
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            tabuleiro[x][y] = 0;
        }
        
    }

    


    //DECLARADO E INICIALIZADO DOIS VETORES QUE REPRESENTARAR OS NAVIOS COM O VALOR 3 DE CADA POSIÇÃO DO VETOR
    int navio_1[3]={3, 3, 3};
    int navio_2[3]={3, 3, 3};
    int navio_3[3]={3, 3, 3};
    int navio_4[3]={3, 3, 3};

    //COORDENADAS       X  Y   DOS NAVIOS
    int coordenada1[2]={0, 2}; // horizontal
    int coordenada2[2]={2, 0}; // vertical
    int coordenada3[2]={5, 8}; // diagonal 1 para baixo esquerda
    int coordenada4[2]={2, 4}; // diagonal 2 para baixo direita

    //COORDENADAS INICIAIS DAS HABILIDADES
    int coordCone[2]={1, 7};
    int coordOctaedro[2]={8, 2};
    int coordCruz[2]={5, 3};


 //      0  1  2  3  4  5  6  7  8  9-->POSIÇOES NA MATRIZ
 //   | --------->  Y
 // 0 | {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
 // 1 | {0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
 // 2 | {0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
 // 3 V {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 4   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 5 X {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 6   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 7   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 8   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 // 9   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
 
// CONDIÇÃO QUE VALIDA SE AS COORDENADAS SETADAS ESTAO DENTRO DO LIMITE DO TABULEIRO.
    if(coordenada1[0] < 10 && coordenada1[1] < 10 && coordenada2[0] < 10 && coordenada2[1] < 10)
    {

        //LOOP NAVIO 1 VARRE O TABULEIRO (MATRIZ ) HORIZONTALMENTE DE ACORDO COM A COORDENADA SETADA NAS VARIAVEIS E COPIA O VALOR DA POSICAO DO VETOR 
        for (int y = coordenada1[1]; y < (3 + coordenada1[1]); y++)
        {
            if(tabuleiro[coordenada1[0]][y] == 0) //CONDIÇAO QUE VALIDA SE HOUVE SOBREPOSIÇAO DOS NAVIOS NO TABULEIRO
            {
                tabuleiro[coordenada1[0]][y] = navio_1[(y - coordenada1[1])];
            }else{
                    printf("\n\nCordenadas do Navio 1 estao sobrepondo outro navio !! \nEscolha outra coordenada.\n\n");
                    return 0;
                 }
        }
    
        // LOOP NAVIO 2 VARRE O TABULEIRO (MATRIZ )VERTICALMENTE DE ACORDO COM A COORDENADA SETADAS NAS VARIAVEIS E COPIA O VALOR DA POSICAO DO VETOR PARA A POSICAO DA MATRIZ
        for (int x = coordenada2[0]; x < (3 + coordenada2[0]); x++)
        {   
            if(tabuleiro[x][coordenada2[1]] == 0) //CONDIÇAO QUE VALIDA SE HOUVE SOBREPOSIÇAO DOS NAVIOS NO TABULEIRO
            {
                tabuleiro[x][coordenada2[1]]= navio_2[(x - coordenada2[0])];
            }else{
                    printf("\n\nCordenadas do Navio 2 estao sobrepondo outro navio !! \nEscolha outra coordenada.\n\n");
                    return 0;
                 }
        }

        // LOOP DO NAVIO 3 DIAGONAL PARA BAIXO ESQUERDA
        for (int i = coordenada3[0]; i < (3 + coordenada3[0]); i++)
        {
            if( tabuleiro[i][(coordenada3[1] - (i - coordenada3[0]))] == 0) //CONDIÇAO QUE VALIDA SE HOUVE SOBREPOSIÇAO DOS NAVIOS NO TABULEIRO
            {
                tabuleiro[i][(coordenada3[1] - (i - coordenada3[0]))] = navio_3[i - coordenada3[0]];
            }else{
                    printf("\n\nCordenadas do Navio 3 estao sobrepondo outro navio !! \nEscolha outra coordenada.\n\n");
                    return 0;
                 }
        }
        
        //LOOP DO NAVIO 4 DIAGONAL PARA BAIXO DIREITA
        for (int i = coordenada4[0]; i < (3 + coordenada4[0]); i++)
        {
            if(tabuleiro[i][(coordenada4[1] + (i - coordenada4[0]))] == 0) //CONDIÇAO QUE VALIDA SE HOUVE SOBREPOSIÇAO DOS NAVIOS NO TABULEIRO
            {
                tabuleiro[i][(coordenada4[1] + (i - coordenada4[0]))] = navio_4[i - coordenada4[0]];
            }else{
                    printf("\n\nCordenadas do Navio 4 estao sobrepondo outro navio !! \nEscolha outra coordenada.\n\n");
                    return 0;
                } 
        }
                                        

 //HABILIDADE CONE--
        for (int x = (coordCone[0] - 1); x < (coordCone[0] + 2); x++) //LOOP FOR ANINHADAS COM O VETOR coordCone[2]={x, y} comoCOORDENADAS para CONDIÇÃO PARA SOBRE-POR A MATRIX DO TABULEIRO
        {                                
            for (int y = (coordCone[1] - 2); y < (coordCone[1] + 3); y++) // PARA CENTRALIZAR O EFEITO DA HABILIDADE, FOI NECESSARIO EQUAÇÕES NAS CONDIÇOES DOS LOOPS PARA
            {                                                             // ALINHAR COM POSIÇÃO INICIAL DA MATRIZ DA HABILIDADE DE 3X5 DE ACORDO COM A COORDENADA .
                tabuleiro[x][y] = Cone[x - (coordCone[0] - 1)][y - (coordCone[1] - 2)];
            }
            
        }

        /*EXPLICACÃO DO LOOP - PARA COORDENADAS no vetor coordCone[]={1, 7}, se refere ao tabuleiro
        considerando que as habilidades tem um tamanho padrao de matriz[3][5],
      y
     --> 0  1  2  3  4
    | 0 {0, 0, 1, 0, 0},
   X| 1 {0, 1, 1, 1, 0},
    v 2 {1, 1, 1, 1, 1}

    Para centralizar na posiçao X foi necessario subtrair -1 da coordCone[0] referente ao eixo X para que comece a sobrePor na Matrix do Tabuleiro a partir do indice [0] da
    matrix da habilidade Cone. A mesma coisa foi feita para coordCone[1] referente ao eixo y, mas foi subtraido -2 devido ser 5 colunas na matrix da habilidade para partir do
    indice [0] do vetor coordCone no eixo Y.
    Dessa forma tanto no eixo x e no Y foi necessario compenssar no incremento para sobrepor o tamanho correto da matrix da habilidade de modo centralizado de acordo com a coordenada
    na matrix do tabuleiro.

       0  1  2  3  4  5  6  7  8  9-->POSIÇOES NA MATRIZ
    | --------->  Y
  0 | {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  1 | {0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
  2 | {0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
  3 V {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  4   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  5 X {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  6   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  7   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  8   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  9   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }


  Para o eixo X - coordCone X= 1 ---> x - 1 == 0 inicia em Zero no eixo X a sobrepor na matriz tabuleiro
  Para o eixo Y -- coordCone Y= 7 ---> Y - 2 === 5 inicia na posiçao 5 no eixo Y a sobrepor na matriz tabuleiro

       0  1  2  3  4 -- POSIÇAO INDICE EIXO Y MATRIX HABILIDADE

       5  6  7  8  9-->POSIÇOES NA MATRIZ TABULEIRO
    | --------->  Y
  0 | {0, 0, 1, 0, 0 },
  1 V {0, 1, 1, 1, 0 },
  2 X {1, 1, 1, 1, 1 },
  3   {0, 0, 0, 0, 0 },

  depois de ajustar a coordenada para começar na posicao zero da matriz, foi necessario tambem compensar o indice da matriz de habilidade na hora de sobrePor a matriz
  do Tabuleiro :

  x = 0 de acordo com a equaçao na codicao dos for
  y = 5

--->  tabuleiro[x][y] = Cone[x - (coordCone[0] - 1)][y - (coordCone[1] - 2)];

      tabuleiro[0][5] = Cone[0 - (1 - 1)][5 - (7 - 2)];
      tebuleiro[0][5] = Cone[0][0]; --- valor da posicao 0,0 da matriz de habilidate vai para posicao 0,5 da matriz do tabuleiro.


      --> No incremento de cada For possui uma compensaçao de acordo com eixo: 
        -EIXO X:

            for (int x = (coordCone[0] - 1); x < (coordCone[0] + 2); x++) 
            for ( x = ( 1 - 1); x < ( 1 + 2); x++)
            for ( x = 0; x < 3; x++) ---> o loop vai rodar de 0 á 2 pecorrendo entao 3 posições do eixo X da matrix de habilidade

      --> Mesma coisa para o eixo Y possui uma compensaçao para tamanho
        - EIXO Y: 

            for (int y = (coordCone[1] - 2); y < (coordCone[1] + 3); y++)
            for( y = (7 - 2); y < ( 7 + 3); Y++)
            for( y = 5; y < 10; y++) --->  o loop vai rodar de 5 até 9 percorrendo 5 posições do eixo Y da matrix de habilidade


      --> AGORA COM O INCREMNWTO DOS LAÇOS DE REPETIÇÃO, PERCORRE TODO EIXO Y NA POSIÇÃO 0 DO EIXO X
      E DEPOIS INCREMENTA PRA POSICAO 1 DO EIXO X E PERCORRE NOVAMENTE TODO EIXO Y
      E ASSIM VAI ATE PERCORRER TODA A MATRIZ DE HABILIDADE E SOBREpor a HABILIDADE NA MATRIZ DO tabuleiro

      OBS: ESSE MESMO TRECHO DE CODIGO FOI APLICADO NAS OUTRAS HABILIDADES MUDANDO SOMENTE O NOME DA VARIAVEIS COORDENADAS, MAS O CONCEITO É O MESMO
      LEVANDO EM CONTA QUE O TAMANHO DA MATRIX É PADRAO 3X5 .Cone

      MELHORIAS: PODERIA CRIAR UMA FUNÇAO PARA CODIGO E CHAMAR APLICANDO OS VALORES DAS COORDENADAS DE CADA HABILIDADE.






*/

//HABILIDADE OCTAEDRO

        for (int x = (coordOctaedro[0] - 1); x < (coordOctaedro[0] + 2); x++)
        {                                
            for (int y = (coordOctaedro[1] - 2); y < (coordOctaedro[1] + 3); y++)
            {
                tabuleiro[x][y] = Octaedro[x - (coordOctaedro[0] - 1)][y - (coordOctaedro[1] - 2)];
            }
            
        }

//HABILIDADE CRUZ

        for (int x = (coordCruz[0] - 1); x < (coordCruz[0] + 2); x++)
        {                                
            for (int y = (coordCruz[1] - 2); y < (coordCruz[1] + 3); y++)
            {
                tabuleiro[x][y] = Cruz[x - (coordCruz[0] - 1)][y - (coordCruz[1] - 2)];
            }
            
        }

        
        

        printf("\nTABULEIRO - BATALHA NAVAL\n\n");
        //LOOP PARA MOSTRAR NA TELA OS VALORES DAS POSICOES DO TABULEIRO   
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                printf("%d  ",tabuleiro[x][y]);
            }
            printf("\n");
            
        }

    }//QUANDO A CONDIÇAO É FALSA -- VERIFICA QUAL COORDENADA PASSOU DO LIMITE E PASSA A MESAGEM PARA CORRIGIR
    else{
            if(coordenada1[0] >= 10 || coordenada1[1] >= 10) // CODIÇÃO QUE VALIDA SE UMA DAS DUAS POSIÇOES DA COORDENADA PASSOU DO LIMITE DO TABULEIRO
            {
                printf("\n\nCoordenada 1 [x][y] PASSOU DO LIMITE DO TABULEIRO!!\n Necessario Corrigir\n\n");
                
            }
            if(coordenada2[0] >= 10 || coordenada2[1] >= 10)// CODIÇÃO QUE VALIDA SE UMA DAS DUAS POSIÇOES DA COORDENADA PASSOU DO LIMITE DO TABULEIRO
            {
                printf("\n\nCoordenada 2 [x][y] PASSOU DO LIMITE DO TABULEIRO!!\n Necessario Corrigir\n\n");
                    
             }
        }


    return 0;
}
