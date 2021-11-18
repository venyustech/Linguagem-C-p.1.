/* ************************************************************************ *
 *    GRAVITY, VERSION                                                      *
 *    Calcula a gravidade en 10 pontos e depois a media total.              *
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
    float a[10],t[10],g[10],mtotal=0; /*"a" pega a altura, "t" o tempo, "g" a gravidade, e "mtotal" será para fazer a media da gravidade. */
    int i; /* variavel e iteração */
    for(i=0;i<10;i++)
    {
        printf("Digite a altura %d/tempo%d\n",i+1,i+1);
        scanf("%f/%f",&a[i],&t[i]);
    }   
    for(i=0;i<10;i++)
    {
        g[i]=(2*a[i])/(t[i]*t[i]);
        printf("Gravidade no predio%02d eh: %f\n",i+1,g[i]);
    }
    for(i=0;i<10;i++)
        mtotal=mtotal+g[i];
    mtotal=mtotal/10;
    printf("Media total eh: %f\n",mtotal);

    return EXIT_SUCCESS;
}
