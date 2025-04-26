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

    //DECLARAÇAO DA MATRIZ 5X5 QUE REPRESENTARÁ O TABULEIRO E INICIALIZADO COM ZERA PARA REPRESENTAR AGUA
    int tabuleiro[5][5] = {
        {0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0 }
    };


    //DECLARADO E INICIALIZADO DOIS VETORES QUE REPRESENTARAR OS NAVIOS COM O VALOR 3 DE CADA POSIÇÃO DO VETOR
    int navio_1[3]={3, 3, 3};
    int navio_2[3]={3, 3, 3};

    //COORDENADAS       X  Y
    int coordenada1[2]={1, 1};
    int coordenada2[2]={5, 4};
 //      0  1  2  3  4  -->POSIÇOES NA MATRIZ
 //   | --------->  Y
 // 0 | {0, 0, 0, 0, 0 },
 // 1 | {0, 0, 0, 0, 0 },
 // 2 | {0, 0, 0, 0, 0 },
 // 3 X {0, 0, 0, 0, 0 },
 // 4   {0, 0, 0, 0, 0 }
 
// CONDIÇÃO QUE VALIDA SE AS COORDENADAS SETADAS ESTAO DENTRO DO LIMITE DO TABULEIRO.
    if(coordenada1[0] < 5 && coordenada1[1] < 5 && coordenada2[0] < 5 && coordenada2[1] < 5)
    {

        // VARRE O TABULEIRO (MATRIZ ) HORIZONTALMENTE DE ACORDO COM A COORDENADA SETADA NAS VARIAVEIS E COPIA O VALOR DA POSICAO DO VETOR 
        for (int y = coordenada1[1]; y < (3 + coordenada1[1]); y++)
        {
            tabuleiro[coordenada1[0]][y] = navio_1[(y - coordenada1[1])];
        }
    
        // VARRE O TABULEIRO (MATRIZ )VERTICALMENTE DE ACORDO COM A COORDENADA SETADAS NAS VARIAVEIS E COPIA O VALOR DA POSICAO DO VETOR PARA A POSICAO DA MATRIZ
        for (int x = coordenada2[0]; x < (3 + coordenada2[0]); x++)
        {
            tabuleiro[x][coordenada2[1]]= navio_1[(x - coordenada2[0])];
            
        }

        printf("\nTABULEIRO - BATALHA NAVAL\n\n");
        //LOOP PARA MOSTRAR NA TELA OS VALORES DAS POSICOES DO TABULEIRO
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                printf("%d ",tabuleiro[x][y]);
            }
            printf("\n");
            
        }

    }//QUANDO A CONDIÇAO É FALSA -- VERIFICA QUAL COORDENADA PASSOU DO LIMITE E PASSA A MESAGEM PARA CORRIGIR
    else{
            if(coordenada1[0] >= 5 || coordenada1[1] >=5) // CODIÇÃO QUE VALIDA SE UMA DAS DUAS POSIÇOES DA COORDENADA PASSOU DO LIMITE DO TABULEIRO
            {
                printf("\n\nCoordenada 1 [x][y] PASSOU DO LIMITE DO TABULEIRO!!\n Necessario Corrigir\n\n");
                
            }
            if(coordenada2[0] >=5 || coordenada2[1] >=5)// CODIÇÃO QUE VALIDA SE UMA DAS DUAS POSIÇOES DA COORDENADA PASSOU DO LIMITE DO TABULEIRO
            {
                printf("\n\nCoordenada 2 [x][y] PASSOU DO LIMITE DO TABULEIRO!!\n Necessario Corrigir\n\n");
                    
             }
        }


    return 0;
}
