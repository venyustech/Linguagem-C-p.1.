/* ************************************************************************ *
 *    Akernaak game,2018 VERSION                                            *
 *    Este programa mostrará 4 frases de forma aleatória cujas quais        *
 *    apenas a quarta frase poderá ser lida mais de uma vez, caso seja      *
 *    sorteada novamente.                                                   *
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
#include<time.h>

int main(void)
{
    int L1=1, L2=2, L3=4, jalidos=0, r, opcao;
    srand(time(NULL));
    printf("Deseja abrir um livro? 1-Sim \n");
    scanf("%d",&opcao);
    if(opcao==1)
    {
inicio:
        r= rand() % 4 + 1;
        switch(r)
        {
            case 1:
                if(!((jalidos & L1) == L1))
                {
                    jalidos= jalidos | L1;
                    printf("...Akon eh a palavra das direcoes \n");
                }
                break;
            case 2:
                if(!((jalidos & L2) == L2))
                {
                    jalidos= jalidos | L2;
                    printf("...o numero magico eh 15\n");
                }
                break;
            case 3:
                if(!((jalidos & L3) == L3))
                {
                    jalidos= jalidos | L3;
                    printf("...porque os magos detestam vinho\n");
                }
                break;
            case 4:
                printf("...o pergaminho que estah dentro do diamante tem o segredo.\n");
                break;
        }//end_switch-1
meio:
        printf("Deseja abrir um livro? 1-Sim 2-Nao \n");
        scanf("%d",&opcao);
        switch (opcao)
        { 
            case 1: 
                goto inicio;
                break;
            case 2:
                goto fim;
                break;
            default:
                printf("opcao invalida\n");
                goto meio;
        }//end_switch-2
    }//end_if-1

fim:

    return EXIT_SUCCESS;
}
