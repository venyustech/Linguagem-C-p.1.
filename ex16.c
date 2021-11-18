/* ************************************************************************ *
 *    VECTOR ORDER, 2018 VERSION                                            *
 *    Este programa receberá aleatóriamente numeros nos vetores e imprimirá *
 *    na tela todos eles em ondem crescente. Foi usado o método quick sort  *
 *    para colocar os numeros em ordem, ultilizando a função qsort disponí- *
 *    vel na biblioteca stdlib. Também é necessário um mínimo de conhecimen-*
 *    to de ponteiros para entende o código.                                *
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

#define MAX 20
int comparacrescente(const void* a, const void *b); /*Função que irá estabelecer os critérios de comparação*/

int main(void)
{
    int i;
    int vet[MAX];

    srand(time(NULL)+getpid());

    for(i = 0; i < 50; i++)
        vet[i] = rand()%100;
    qsort(vet,MAX,sizeof(int),comparacrescente); /*Função que ultiliza o método de comparação QuickSort e permite ordenar um vetor. funciona da seguinte forma: 1- passa-se o vetor(vet), 2- quantos elementos ele tem(MAX), 3- o tamanho de cada elemento (sizeof(int),4- a função de comparação(comparacrescente)*/ 
    for(i=0;i<MAX;i++)
        printf("Numero = %d\n",vet[i]);
    
    return EXIT_SUCCESS;
}/*End main*/

int comparacrescente(const void* a, const void *b)/*Definido dois valores que são dois parâmetros da função, de modo que eles vão ser comparados.*/
{
    if(*(int*)a == *(int*)b) /*recebe a que é void* e converte ele para int*para guardar num vetor de inteiros acessa o conteúdo. Faz o mesmo com void *b e depois verifica se a condição é válida*/
        return 0;/*iguais*/
    else 
        if(*(int*)a<*(int*)b)
            return -1;/*a vem antes*/
        else
            return 1;/*a vem depois*/
}/*End comparacrescente*/
