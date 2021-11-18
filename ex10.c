/***************************************************************************
 *   ex10.c                                    Version 20160908.182830     *
 *                                                                         *
 *   Guess the number with cards                                           *
 *   Copyright (C) 2018         by Gardenia Georgia B. De Siqueira         *
 *                                 Daniel Henrique de Freitas Macedo       *
 *                                 Israel Fonseca Neto                     *
 *                                 Lucas Decesares Cunha Lima              *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the authors, please write to:                              *
 ***************************************************************************
 *   Gardenia Georgia Barbosa De Siqueira                                  *
 *   Email: gardenia.georgia.b.s@gmail.com                                 *
 *   Webpage: http://www.poli.upe.br                                       *
 *   Phone: +55 (81) 9785-0393                                             *
 ***************************************************************************
 *   Daniel Henrique de Freitas Macedo                                     *                
 *   Email: macedorobotica@gmail.com                                       *
 *   Webpage: http://www.poli.upe.br                                       *
 *   Phone: +55 (81) 99345-8660                                            *
 ***************************************************************************
 *   Israel Fonsecas Neto                                                  *
 *   Email: israelfneto@gmail.com                                          *
 *   Webpage: http://www.poli.upe.br                                       *
 *   Phone: +55 (81) 99842-0176                                            *
 ***************************************************************************
 *   Lucas Decesares Cunha Lima                                            *
 *   Email: lucasdecesares21@gmail.com                                     *
 *   Webpage: http://www.poli.upe.br                                       *
 *   Phone: +55 (81) 98774-1227                                            *
 ***************************************************************************
*/

/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* definitions */

#define MAX 31
#define MIN 1

/* prototypes */

int MostraCabecalho(void);/*Mostrará os catões para as perguntas do jogo e as boas-vindas ao usuráio*/
int CalculandoAData(int N[5]);/*Função usada para calcular a data de aniversario de acordo com as respostas do usuráio*/
int ValidandoAData(int num);/*Função para que o resultado da data de aniversário não caia um número n<=0 ou n>31*/

int main(void)
{   int i;
    int op[5],DataAniversario=0;
    MostraCabecalho();
        
        for(i = 0; i < 5; i++)
        {
            printf("Sua data de aniversario estah no cartao %d?\n 1-sim\n0-nao\n",i+1);
            scanf("%d", &op[i]);
        }
    if(ValidandoAData(CalculandoAData(op)))
    {
        DataAniversario=CalculandoAData(op);
        printf("\n O dia do seu aniversario eh: %d\n",DataAniversario);
    }
    else
        printf("Voce digitou algum valor errado. Tente novamente.\n");

    return EXIT_SUCCESS;
}

int MostraCabecalho(void)
{
    int linha,cartao,coluna;
    int cards[5][4][4]=
    {   {  {16, 17, 18, 19},
           {20, 21, 22, 23},
           {24, 25, 26, 27},
           {28, 29, 30, 31}  },
        {  {8,9, 10, 11},
           {12, 13, 14, 15},
           {24, 25, 26, 27},
           {28, 29, 30, 31}, },
        {  {4, 5, 6, 7},
           {12, 13, 14, 15},
           {20, 21, 22, 23},
           {28, 29, 30, 31}, },
        {  {2, 3, 6, 7},
           {10, 11, 14, 15},
           {18, 19, 22, 23},
           {26, 27, 30, 31}, },
        {  {1, 3, 5, 7},
           {9, 11, 13, 15},
           {17, 19, 21, 23},
           {25, 27, 29, 31} } };

    printf("Bem-vindo ao Mundo Magico! Aqui iremos ler sua mente e adivinhar sua data de aniversario.\n");
    printf("Mas antes observe os seguintes cartoes e responda as perguntas abaixo:\n\n");
    
    for(cartao=0;cartao<5;cartao++)
        printf("Cartao %d\t",cartao+1);

    printf("\n");
    for(linha=0;linha<4;linha++)  
    {
         for(cartao=0;cartao<5;cartao++)
         {
             for(coluna=0;coluna<4;coluna++)
             {
                 printf("|%02d",cards[cartao][linha][coluna]);
             }
             printf("|\t");
         }
         printf("\n");
     }
    return 0;
}

int CalculandoAData(int N[5])
{
    int i, resultado = 0, v[5] = {16, 8, 4, 2, 1};
    for(i=0; i<5; i++)
        if(N[i] != 0)
            resultado = resultado | v[i];
    return resultado;
}/*end função CalculandoAData*/

int ValidandoAData(int num)
{
    return num>=MIN && num<=MAX;
}/*End função ValidandoAData*/

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */

/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */

