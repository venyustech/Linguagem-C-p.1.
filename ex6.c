/* ************************************************************************ *
 *    Jogo da Vaquinha,2018 VERSION                                         *
 *    Esse programa irá mostrar quem ganhou uma vaquinha                    *
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
    /*Boas-vindas*/
    printf("Bem-vindo ao jogo da vaquinha. Aqui voce saberah se ganhou ou nao.\n");
    /*Dados*/
    float a, b, c;

    printf("Digite o primeiro numero da sorte:\n");
    scanf("%f",&a);
    printf("Digite o segundo numero da sorte:\n");
    scanf("%f",&b);
    printf("Digite o terceiro numero da sorte:\n");
    scanf("%f",&c);
    if((a<10&&(b>9&&b<21)&&c<12)||(a>28&&b>25&&(c>21&&c<42)))
    printf("Parabens, voce ganhou uma vaquinha\n");
    else
    printf("Infelizmente voce nao ganhou uma vaquinha\n");

    return EXIT_SUCCESS;
}
