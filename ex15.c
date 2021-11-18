/* ************************************************************************ *
 *    Determinante de matriz 2x2, 2018  VERSION                             *
 *    Esse programa calcula uma matriz 3x3 com uma função 2x2 como parte    *
 *    para achar a determinante da matriz 3x3                               *
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


#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAXSORT 20
#define linA 3 /*Quantidade de linhas de A*/
#define colA 3 /*Quantidade de linhas de b*/

int det2X2(int a00, int a11, int a10, int a01);

int main(void)
{
    int A[linA][colA];
    int DeterminanteP1,DeterminanteP2,DeterminanteP3; /*Partes para o calculo da determinante 3x3*/
    int ValTotalDeterminante; /*Valortotal da determinante 3x3 = DeterminanteP1 - Determinante P2 + DeterminanteP3*/
    int i,j;

    srand(time(NULL)+getpid());

    printf("Seja a matriz A : \n");

    for(i = 0; i < linA; i++)  /*preenchendo a matrizA*/
        for(j = 0; j < colA; j++)
            A[i][j] = rand()%MAXSORT;

    for(i = 0; i < linA;i++) /*imprimindo na tela a matrizA*/
    {
        for(j = 0; j < colA; j++)
            printf("| %03d", A[i][j]);
        printf("|\n");
    }
    DeterminanteP1 = (A[0][0])*(det2x2(A[1][1], A[2][2], A[2][1], A[1][2])); /*de linha 64 ate 67 calculando a determinante da matriz e imprimindo na tela */
    DeterminanteP2 = (A[0][1])*(det2x2(A[1][0], A[2][2], A[2][0], A[1][2]));
    DeterminanteP3 = (A[0][2])*(det2x2(A[1][0], A[2][1], A[2][0], A[1][1]));
    ValTotalDeterminante = DeterminanteP1 - DeterminanteP2 + DeterminanteP3;

    printf("\n\nO valor de sua determinante eh: %5d\n",ValTotalDeterminante);
    
    return EXIT_SUCCESS;
}
int det2x2(int a00, int a11, int a10, int a01) /*retorna a determinante de matriz2x2*/
{
    int d2x2 = 0;
    d2x2 = (a00*a11) - (a10*a01);
    return d2x2;
}
