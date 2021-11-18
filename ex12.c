/* ************************************************************************ *
 *    Multiplicação de Matriz, 2018 VERSION                                 *
 *    Dadas as matriz X e matriz Y, teremos a matriz C = X*Y.               *
 *    Mostraremos a matriz X, matriz Y  e matriz C na tela.                 *
 *                                                                          *
 *    Copyright (C) 2018 by Gardenia Georgia Barbosa de Siqueira            *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Gardenia Georgia Barbosa de Siqueira <gardenia.georgia.b.s@gmail.com> *
 *    Webpage: http://www.upe.com                                           *
 *    Phone: +55 (81) 99785-0393                                            *
 * ************************************************************************ *
 * 
 */

/*Diretivas ao pré-processador*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


/*Defines*/
#define LA 10   /*Quantidade de Linhas de A */
#define CA 10   /*Quantidade de Colunas de A */
#define CB 10   /*Quantidade de Colunas de B */
#define LB CA   /*Quantidade de Linhas de B tem que ser igual a quantidades de Colunas de A*/
#define LC LA   /*Quantidade de Linhas de C tem que ser igual a quantidade de Linhas de A*/
#define CC CB   /*Quantidade de Colunas de C tem que ser igual a quandidade de Colunas de B*/


/*Funções*/
int sorteado (void); /*Escolhe aleatorio na faixa [ ... 93] ou [101 ... 144]*/

int main(void)
{
    int i,j,k; /*Variáveis de controle de laços*/
    int MatrizA[LA][CA], MatrizB[LB][CB], MatrizC[LC][CC];

    srand(time(NULL) + getpid()); /*Semente*/

    for(i = 0;i < LA; i++)   /*Laço para atribuir valores a MatrizA*/
        for(j = 0;j < CA; j++)
            MatrizA[i][j] = sorteado(); /*Chama função sorteado()*/

    if (LA != CA) /*Caso quantidade de Linha de A seja diferente  da quantidade de Linha de B, ou seja  LA!=CA*/
        printf("Nao existe o produto de matriz AxB");

    else /*Caso LA=CA podemos continuar a atribuir valores e multiplicar a matriz*/
    {   
        for(i = 0; i<LB; i++) /*Laço para atribuir valor a MatrizB*/
            for(j = 0; j < CB; j++)
                MatrizB[i][j] = sorteado();

        for(i = 0; i < LA; i++) /*Laço para forma a MatrizC  = MatrizA x MatrizB*/
            for(j=0;j<CB;j++)
            {
                MatrizC[i][j]=0;
                for(k=0;k<CA;k++)
                    MatrizC[i][j] = MatrizC[i][j] + MatrizA[i][k] * MatrizB[k][j];
            }

        printf("\nMatriz A:\n \n");/*Para imprimir na tela Matriz A:*/

        for(i=0;i<LA;i++)
        {
            for(j=0;j<CA;j++)
                printf("|%03d", MatrizA[i][j]);
            printf("\n");
        }

        printf("\nMatriz B:\n \n"); /*Para imprimir na tela Matriz B*/
        for(i=0;i<LB;i++)
        {
            for(j=0;j<CB;j++)
                printf("|%03d", MatrizB[i][j]);
            printf("\n");
        }

        printf("\nMatriz C = Matriz A x Matriz B: \n"); /*Para imprimir na tela MatrizC = MatrizA x MatrizB:*/
        for(i=0;i<LB;i++)
        {
            for(j=0;j<CB;j++)
                printf("|%d", MatrizC[i][j]);
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}

int sorteado(void) /*Aleatório na faixa [5...93] ou [101...141]*/
{
    int s;
    
    s=rand()%((93-5)+(141-101)); /*faixa 0 a 127*/

    s+=5; /*Para faixa [5...93]*/

    if(s>93)
        s += 7; /*Para faixa [101...141]*/
    
    return s;
}
