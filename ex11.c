/* ************************************************************************ *
 *    IMPRIMINDO VETORES, 2018 VERSION                                      *
 *    Este programa mostrará vetores aleatórios não ordenados e em ordem    *
 *    crescente                                                             *
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


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAXSORT     100 /*O máximo que um numero aleatorio poderá ser escolhido*/
#define TOTAL 20 /*total do vetor*/

int main(void)
{
    int i,j;
    int alea[TOTAL];
    int aux;

    printf("Bem-vindo! Este programa mostrara o valor de vetores aleatorios nao ordenados e em ordem crescente:\n\n"); /*boas-vindas*/
    
    srand(time(NULL) + getpid());
    
    printf("Vetor nao ordenado:\n\n");

    for(i = 0; i < TOTAL; i++)
    {   
        alea[i]=rand()%MAXSORT;
        printf(" Vetor[%02d] = %02d\n", i, alea[i]);
    }/*End for1*/
    for(i=0; i < TOTAL; i++) /*Esta parte do código se dedica a ordenar o vetor em ordem crescente*/
    {
        for(j=i+1; j < TOTAL; j++)
        {
            if(alea[i]>alea[j])
            {
                aux = alea[i];
                alea[i] = alea[j];
                alea[j] = aux;
            
            }/*End if*/
        }/*End for3*/
    }/*End for2*/

    printf("\nVetor em ordem crescente:\n\n");/*Imprime na tela que o proximo vetor esta ordenado*/ 
    
    for(i=0;i<TOTAL; i++) /*Para imprimir na tela o resultado ordenado*/
    {
        printf(" Vetor[%02d} = %02d\n", i, alea[i]);
    }/*End for4*/

    return EXIT_SUCCESS;
}/*End main*/
