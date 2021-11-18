/* ************************************************************************ *
 *    HIGHER BETWEEN, 2018 VERSION                                          *
 *    This program will show you the higher between trhee numbers           *
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

int main(void)
{
    /*Boas-vindas:*/
     printf("Bem-vindo ao programa que identifica o maior entre tres valores.\n");
     /*Dados*/
     float a, b, c;

     printf("Digite o primeiro valor:\n");
     scanf("%f", &a); 
     printf("Digite o segundo valor:\n");
     scanf("%f", &b); 
     printf("Digite o terceiro valor:\n");
     scanf("%f", &c); 
     if(a>b)
     {
         if(a>c)
             printf("O maior valor eh:%0.2f",a);
         else
             printf("O maior valor eh:%0.2f",c);
     }
     else
     {
         if(b>c)
             printf("O maior valor eh:%0.2f",b);
         else
             printf("O maior número eh:%0.2f",c);
     }
     return EXIT_SUCCESS;
}
