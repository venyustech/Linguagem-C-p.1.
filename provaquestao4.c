/* ************************************************************************ *
 *    Questao_Recursao, 2018 VERSION                                        *
 *    Escreva as funcoes recursivas f1(...) e f2(...), onde f1 fica en-     *
 *    carregada das colunas(printf("%d..",i) e f2 fica encarregada das      *
 *    linhas ( printf("%d" \n",i)                                           *
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

int f1(int i);
int f2(int i);

int main(void)
{
    f2(6);
    return 0;
}

int f1(int i)
{
    int aux = i;

    for(aux = i; aux > 0; aux--)
        printf("%d, ",aux); /* Para imprimir linhas. Eh impresso de aux(naquele momento) ateh 1 */
    printf("\n"); /*Apenas como quebra linha*/
    f2(i-1); /* Retorno para funcao f2, sendo que com i -= 1 */
    return 0;
}

int f2(int i)
{
    if(i == 0) /* Criterio de parada */
        return 0;
    printf("%d: ", i);  /* Imprime as colunas. Eh impresso de 6 ateh 1 */
    f1(i); /* Chama da da funcao f1, para imprimir a linha equivalente a sua devida coluna */
    return 0;
}
