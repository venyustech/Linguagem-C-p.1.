/* *
 * *********************************************************************** *
 *    ASCENDING ORDER,2019  VERSION                                         *
 *    This program will show the ascending order of three numbers           *
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
    /*Boas-vindas*/
    printf("Bem-vindo ao programa que informa a ordem crescente de tres numeros.\n");
    /*Dados:*/
    float a, b, c;

    printf("Digite o primeiro numero:\n");
    scanf("%f",&a);
    printf("Digite o segundo numero:\n");
    scanf("%f",&b);
    printf("Digite o terceiro numero:\n");
    scanf("%f",&c);
    if(a>b)
    {
        if (b>c) /*a>b>c)*/
        printf("A ordem crescente eh: %0.2f, %0.2f, %0.2f \n", c, b, a);
        else /*a>b, b<c*/
        {
            if(a<c) /*c>a>b*/
                printf("A ordem crescente eh: %0.2f, %0.2f, %0.2f \n", b, a, c);
            else /*a>b,b<c, a>c ---> a>c>b*/
                printf("A ondem crescente eh: %0.2f, %0.2f, %0.2f\n", b, c, a);
        }
    }   
    else /*b>a*/
    {    
        if (c>b)/*c>b>a*/
        printf("A ordem crescente eh: %0.2f, %0.2f, %0.2f\n", a, b, c);
        else/*b>a, b>c*/
        {    
            if(a>c)/*b>a,b>c,a>c -----> b>a>c*/
            printf("A ordem crescente eh: %0.2f, %0.2f, %0.2f,\n", c, a, b);
            else /*b>a,b>c,a<c -----> b>c>a*/
            printf("A ordem crescente eh: %0.2f, %0.2f, %0.2f, n", a, c, b);
        }
    } 
    return EXIT_SUCCESS;
}
