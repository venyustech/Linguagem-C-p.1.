/* ************************************************************************ *
 *    SECONDS OF LIFE, 2018 VERSION                                         *
 *    Esse programa perguntará que horas e em que data o usuário nasceu e   *
 *    calculará os segundos de vida que o usuário já viveu.                 *
 *    Foi usado novas funções de conhecimentos prévios:                     *   
 *    difftime(time_t,time_t beginning) para calcular a diferença em segun- *
 *    dos; mktime(struct tm * timeptr) para guardar a data que o usuario di-*
 *    gitar; ctime(const time_t * timer) para imprimir na tela as datas.    *
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
    int horacomeco,diacomeco,mescomeco,anocomeco,minutocomeco;
    int segundos;
    time_t dataAtual; /*(time_t *time) retorna data e horado sistema,e como parâmetro, pode passar o ponteiro para a variavel, quando passado o */
    time_t dataInicial;/*armazenar o tempo no inteiro dataInicial*/
    struct tm data; /*mantém a data e hora divididos em elementos*/
    
    printf("Digite a data do seu nascimento  para comecar a calcular: Formato DD/MM/AAAA.\nEx: 30/12/1998 \n"); /*Da linha 14 a 17 são dados para receber numero do usuario*/
    scanf("%d/%d/%d",&diacomeco,&mescomeco,&anocomeco);
    printf("Digite a hora do seu nascimento para comecar a calcular: Formato HORA:MINUTO.\nEx: 23:55 \n");
    scanf("%d:%d",&horacomeco,&minutocomeco);

    data.tm_year = anocomeco - 1900;    /*the number of years since 1900*/ /*Uso a biblioteca time.h para criar a data de aniversario do usuario usando  mktime()*/
    data.tm_mon  = mescomeco - 1;       /*range 0 to 11*/
    data.tm_mday = diacomeco;           /*range 1 to 31*/
    data.tm_hour = horacomeco;          /*hour, range 0 to 13*/
    data.tm_min  = minutocomeco;        /*range 0 to 59*/
    data.tm_sec  = 0;                   /*range 0 to 59*/
    
    dataInicial = mktime(&data);

    printf("Voce nasceu em:    \t");   
    printf(ctime(&dataInicial));        /*Imprime na tela a data de nascimento*/
    
    dataAtual = time(NULL);             /*Registra a data atual*/
    
    printf("A data de hoje eh: \t");   
    printf(ctime(&dataAtual));         /*Imprime na tela a data atual*/
    
    segundos = difftime(dataAtual,dataInicial);  /*Uso a difftime() para calcular a diferença em segundos de duas datas*/
    printf("\n\n%d segundos desde a sua data de nascimento.\n\n",segundos); /*Imprime na tela a quantidade de segundos de vida do usuario*/
    
    return EXIT_SUCCESS;

}
