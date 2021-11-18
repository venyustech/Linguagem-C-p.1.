/* ************************************************************************ *
 *    MONTA_PERSONAGEM, 2018 VERSION                                        *
 *    Ajuda o usuario a escolher habilidades                                *
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
#include <math.h> 

void imprime_cabecalho(void);
void modifica(void);
void pontos_moedas(void);
void habilidades(void);
void personagem(void);


int pontos = 0;
int forca = 8;
int destreza= 8;
int constituicao = 8;
int inteligencia = 8;
int sabedoria = 8;
int carisma = 8;
int moeda = 27;
int coin[6];
int mod[6];
int habilidade[6] = {8,8,8,8,8,8};
int i;
int habil;
int aux;
float vetor[6];

int main(void)
{
    imprime_cabecalho();

    for(i = 0; i < 100; i++)
    {
        if(moeda == 0) /* Quando nao tem mais moedas termina a contagem */
        {
            printf("\n Voce jah usou todas as suas moedas\n");
            break;
        } /* End if */

        printf("\n Digite o numero da habilidade/numero de pontos que voce deseja atribuir a essa habilidade: ");
        scanf("%d/%d", &habil,&pontos);

        switch(habil)
        {
            case 1: 
                {
                    forca = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }
            case 2:
                {
                    destreza = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }
            case 3:
                {
                    constituicao = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }
            case 4:
                {
                    inteligencia = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }
            case 5:
                {
                    sabedoria = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }
            case 6:
                {
                    carisma = pontos;
                    pontos_moedas();
                    imprime_cabecalho();
                    break;
                }

        } /* End switch*/
    } /* End for */
    personagem();
 
    return EXIT_SUCCESS;

} /* End main*/

void imprime_cabecalho(void)
{
    modifica();
    
    printf("\n Selecione quantos pontos tera em cada habilidade.");
    printf("\n A tabela abaixo mostra o custos que voce pagara de acordo com a quantidade de pontos que deseja: \n ");
    printf("\n     PONTOS     |     PRECO\n   8 pontos     |     0 moedas\n   9 pontos     |     1 moedas\n  10 pontos     |     2 moedas\n  11 pontos     |     3 moedas\n  12 pontos     |     4 moedas\n  13 pontos     |     5 moedas\n  14 pontos     |     7 moedas\n  15 pontos     |     8 moedas(max)");

    printf("\n\nObserve como estah o seu quadro de pontos de acordo com as habilidades. Lembre que o minimo eh 8 pontos para cada:\n");
    printf("\n     Habilidades     |     PONTOS    |     MOD\n");
    printf("\n  1. forca           |      %2d       |     %2d      (%2d moedas usadas)", habilidade[0],mod[0],coin[0]);
    printf("\n  2. destreza        |      %2d       |     %2d      (%2d moedas usadas)", habilidade[1],mod[1],coin[1]);
    printf("\n  3. constituicao    |      %2d       |     %2d      (%2d moedas usadas)", habilidade[2],mod[2],coin[2]);
    printf("\n  4. inteligencia    |      %2d       |     %2d      (%2d moedas usadas)", habilidade[3],mod[3],coin[3]);
    printf("\n  5. sabedoria       |      %2d       |     %2d      (%2d moedas usadas)", habilidade[4],mod[4],coin[4]);
    printf("\n  6. carisma         |      %2d       |     %2d      (%2d moedas usadas)\n", habilidade[5],mod[5],coin[5]);
    printf("\n \n        Voce ainda possui:    %d moedas \n",moeda);
} /* End imprime_cabecalho */

void modifica(void)
{
    for(i = 0; i < 6; i++)
    {
        vetor[i] = (habilidade[i] - 10)/2;
        mod[i] = vetor[i];
    }
} /* End modifica */

void pontos_moedas(void)
{
    printf("%d pontos", pontos);
    
    for(i = habil - 1;habil<=6; i++)
    {
        if(pontos == 8)
        {
            aux = 0;
            moeda -= aux;
        }
        else if( pontos == 9)
        {
            aux = 1;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += aux;
        }
        else if(pontos == 10)
        {
            aux = 2;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += aux;
        }
        else if(pontos == 11)
        {
            aux = 3;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += aux;
        }
        else if(pontos == 12)
        {
            aux = 4;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += aux;
        }
        else if(pontos == 13)
        {
            aux = 5;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += aux;
        }
        else if(pontos == 14)
        {
            aux = 7;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += (aux-1);
        }
        else if(pontos == 15)
        {
            aux = 8;
            habilidades();
            coin[i] = aux;
            moeda -= aux;
            habilidade[i] += (aux-1);
        }
        break;
    } /* End for*/

} /* End pontos_moedas */

void habilidades(void)
{
    while(habilidade[i] >= 9)
    {
        habilidade[i] = 8;
        moeda += coin[i];
        break;
    }
} /* End habilidades */
void personagem(void)
{
    int maior[2] = {0, 0};
    
    printf("De acordo com seu perfil, o melhor para voce é: ");

    for(i=0;i<6;i++)
    {
        if(habilidade[i] == maior[0])
            maior[1] = habilidade[i];
        if(habilidade[i] > maior[0])
            maior[0] = habilidade[i];
    }/* End for */

    if(habilidade[0] == maior[1] || habilidade[0] == maior[0]) /* preferivel Barbaro ou Guerreiro*/
        printf("\n *Barbaro\n *Guerreiro");
    if(habilidade[5] == maior[1] || habilidade[5] == maior[0]) /* Preferivel Bardo, Bruxo ou Feiticeiro*/
        printf("\n *Bardo\n *Bruxo\n *Feiticeiro");
    if(habilidade[4] == maior[1] || habilidade[4] == maior[0]) /* Preferivel Clerigo ou Druida*/
        printf("\n *Clerigo\n *Druida");
    if(habilidade[1] == maior[1] || habilidade[1] == maior[0]) /* Preferivel Ladino*/
        printf("\n *Ladino");
    if(habilidade[3] == maior[1] || habilidade[3] == maior[0]) /* Preferivel Mago*/
        printf("\n *Mago");
    if((habilidade[1] == maior[1] || habilidade[1] == maior[0]) && (habilidade[4] == maior[1] || habilidade[4] == maior[0])) /* Preferivel Monge */
        printf("\n *Monge");
    if((habilidade[0] == maior[1] || habilidade[0] == maior[0]) && (habilidade[5] == maior[1] || habilidade[5] == maior[0])) /* Preferivel Paladino*/
        printf("\n *Paladino");
    if((habilidade[1] == maior[1] || habilidade[1] == maior[0]) && (habilidade[4] == maior[1] || habilidade[4] == maior[0])) /* Preferivel Patrulheiro */
        printf("\n *Patrulheiro");
    printf("\n");

} /* End personagem*/
