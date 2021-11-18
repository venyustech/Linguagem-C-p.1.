/* ************************************************************************ *
 *    NUMERO_PRIMO, 2018 VERSION                                            *
 *    Programa responde se um numero dado eh ou nao primo.                  *
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
#include <stdlib.h>

#define MAX 100

int testa_primo(int x);

int main(void)
{
    int i, k = 2, x, vet[MAX];

    printf("Bem-vindo ao programa que descobre se um numero eh primo.\nDigite um numero desejado:\n");
    scanf("%d",&x);

    while(i < MAX)
    {
        if(testa_primo(k)) /* Se o k for prime, ele éh adicinado dentro do devido vetor */
        {
            vet[i] = testa_primo(k);
            i++;
        } /* End if */
        k++;
    } /* End while */
    if( x <= vet[MAX - 1])
    {
        for(i = 0; i< MAX; i++)
        {
            if(x == vet[i])
            {
                printf("%d eh primo!\n",x);
                return 1;
            } /* End if aninhado */
            else if(x% vet[i] == 0)
            {
                printf("%d nao eh primo\n",x);
                return 0;
            } /* End elseif*/
        } /* End for */
    } /* End if */
    else
    {
        for(i = 0; i < MAX; i++)
            if(x%vet[i] == 0)
            {
                printf("%d nao eh primo!\n",x);
                return 0;
            } /* End if */
        i = vet[MAX -1];

        while(x%i != 0) /* Quando o resto não eh 0 */
        {
            i +=2;
        }
        if(x == i)
        {
            printf("%d eh primo!\n",x);
            return 1;
        }
        else
        {
            printf("%d nao eh primo\n",x);
            return 0;
        }
    }/*End else*/

    return EXIT_SUCCESS;
}
int testa_primo(int x)
{
    int aux = 1, i;
    
    for(i = 2; i <= x; i++)
        if(x%i == 0) /* Quando o x dividido por i seja 0, auxiliar ++.*/
            aux++;
    if(aux == 2)  /* Primo so eh dividido por um 1 ele mesmo, portanto, quando aux>2, o numero nao eh primo. */
        return x;
    else
        return 0;  
} /* End testa_primo*/
