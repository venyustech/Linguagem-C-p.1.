/* **
 * ********************************************************************** *
 *    BIGGERST BETWEEN, 2018 VERSION                                        *
 *    This program will show you the biggest number between five values.    *
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

int main(void)
{
     float a,b,c,d,e,max;

     printf("Digite o primeiro numero:\n");
     scanf("%f",&a);
     printf("Digite o segundo numero:\n");
     scanf("%f",&b);
     printf("Digite o terceiro numero:\n");
     scanf("%f",&c);
     printf("Digite o quarto numero:\n");
     scanf("%f",&d);
     printf("Digite o quinto numero:\n");
     scanf("%f",&e);

     max=a;

     if(max<b)
     max=b;
     if(max<c) 
     max=c; 
     if(max<d)
     max=d;
     if(max<e)
     max=e;
     printf("O maior valor eh:%0.2f.\n",max);
     
     return EXIT_SUCCESS;
}
