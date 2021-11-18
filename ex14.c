/* ************************************************************************ *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
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

#define MAX 1000000
#define MIN 2

long int CollatzConjectureTest (long int n); /*funçao que foi usada uma estrutura recursiva para testar a conjectura de Collatz*/

int main(void)
{
    long int i,resultado; 
    
    for(i=MIN;i<=MAX ;i++)
    {
        printf("i=%ld!\n",i);
    
        resultado  = CollatzConjectureTest(i);
        
        printf("i=%ld RESULTAD0=%ld!\n",i,resultado);

        if(i==MAX)
        {
            if(resultado == 1)
                printf("Este programa testou todos os numeros interios de 2 ate %ld, a conjectura de Collatz eh valida de 2 ate %ld\n", i, i);
        }
        if(resultado != 1)
                printf("A conjectura de Collataz falhou em %ld", i);
        printf("i no fim do laço=%ld RESULTADO=%ld!\n",i,resultado);
    }
    
    return EXIT_SUCCESS;
}

long int CollatzConjectureTest(long int n)
{
    if(n == 1)
        return 1;
    else
        if(n % 2)
            return CollatzConjectureTest(((3*n)+1)/2);
        else 
            return CollatzConjectureTest(n/2);
}
