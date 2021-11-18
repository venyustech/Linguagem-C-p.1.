/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <math.h>
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h>

int main(int argc, char *argv[])
{
    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    int f;
    t_game g; /* the game */
    const char *sready = "Se voce tiver pronto para embarcar nessa aventura(comilanca) pressione a tecla: 's', do contrario pressione:'n' para sair"; /* ready string */
    const char *quit = " Para sair do game pressione a tecla: ESC "; /* ready string */
    int kin; /* keyboard input */

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
    {
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");
        
    g = upecman_init();
        
    printlab(g);
    
    mvprintw(10, 26, "%s", sready);
    mvchgat(10,25,-1,A_BOLD,1,NULL);
   
    for(f= blinky; f <= clyde; f++)
    g.ghost[f].inittime = time(NULL);

    mvprintw(11, 25,"%s",quit);
    mvchgat(11, 25,-1, A_BOLD,1,NULL);
    
    refresh();

    g.pacman.score = 0;

    /* Laco que envolve as teclas para o usuario decidir entrar ou nao no jogo */
    refresh();
    do
    {
        kin=getch();
        if(kin == 's')
        {
            g = mov_pac(g, kin);
            /*g = ghostmove(g);*/
            refresh();
        }
        if(kin == 'n')
            break;

        usleep(16667); /* wait 16667 microseconds to avoid frying the processor (1/60 s) *1/ */
        
    }while(!end_game(g));
    
    endwin();
    
    return EXIT_SUCCESS;
}


/*******************************************************************************
 * Esta funcao esta diretamente relacionada a todos movimentos e restricoes esta-
 * belecidas ao pacman
 */
t_game mov_pac(t_game g, int kin) 
 {
    int move=0, pm=0;

    while(kin != 27)
    {
        kin = getch(); 

        if(kin == 27 || ((g.pacman.score >= 2040) && (end_game(g) == 1)) || g.pacman.life < 1)
        {
            endwin();
            exit(1);
        }

        if(kin==KEY_LEFT || kin == KEY_RIGHT || kin== KEY_DOWN || kin == KEY_UP || kin == 'a' || kin == 'w' || kin == 's' || kin == 'd') 
            pm = kin; 
        if((pm == KEY_LEFT || pm == 'a') && g.lab[g.pacman.pos.y][g.pacman.pos.x-1] != '#') 
            move = pm; 
        else if((pm == KEY_RIGHT || pm == 'd') && g.lab[g.pacman.pos.y][g.pacman.pos.x+1] != '#') 
            move = pm;  
        else if((pm == KEY_UP || pm == 'w') && g.lab[g.pacman.pos.y-1][g.pacman.pos.x] != '#') 
            move = pm; 
        else if((pm == KEY_DOWN || pm == 's') && g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '-') 
            move = pm; 

        switch(move) 
        { 
            case 'd': 
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x+1] != '#' )
                {
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.x = g.pacman.pos.x+1;
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 20))
                        g.pacman.pos.x = 0;
                }
                break;

            case KEY_RIGHT: 
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x+1] != '#' ) 
                { 
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' '; 
                    g.pacman.pos.x = g.pacman.pos.x+1; 
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 20)) 
                        g.pacman.pos.x = 0; 
                } 
                break; 

            case 'a':
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x-1] != '#')
                {   
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.x = g.pacman.pos.x-1;
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 0)) 
                        g.pacman.pos.x = 19; 
                }
                break;

            case KEY_LEFT: 
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x-1] != '#') 
                {   
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' '; 
                    g.pacman.pos.x = g.pacman.pos.x-1; 
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 0)) 
                        g.pacman.pos.x = 19; 
                } 
                break; 

            case 'w':
                if(g.lab[g.pacman.pos.y-1][g.pacman.pos.x] != '#')
                {
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.y = g.pacman.pos.y-1;
                }
                break;

            case KEY_UP: 
                if(g.lab[g.pacman.pos.y-1][g.pacman.pos.x] != '#') 
                { 
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' '; 
                    g.pacman.pos.y = g.pacman.pos.y-1; 
                } 
                break; 

            case 's':
                if(g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '#')
                {
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.y = g.pacman.pos.y+1;
                }
                break;

            case KEY_DOWN: 
                if(g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '#') 
                { 
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' '; 
                    g.pacman.pos.y = g.pacman.pos.y+1; 
                } 
                break; 
         } 
        g=criacereja(g); 
        g = pontos(g); 
        g.ghost[0].target.y=g.pacman.pos.y; 
        g.ghost[0].target.x=g.pacman.pos.x;
        g = inkychase(g);
        g = ghostm(g,0);
        g = ghostm(g,2);
        g = pinkychase(g);
        g = clydechase(g);
        g = ghostm(g,1);
        g = ghostm(g,3);
        g = colisao(g);
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = '@';
        g.pacman.anteripos = g.pacman.pos;
        printlab(g); 
        refresh(); 
        usleep(170000); 
      } 
     return g; 
}  


/*******************************************************************************
 * Esta funcao esta relacionada ao fim do jogo, ela fecha a janela do game, se
 * todas as condicoes pre-estabelecidas a morte do pacman estiverem de acordo
 */
int end_game(t_game g)
{
    int i, y;
    for(i=0;i<LABL;i++)
        for(y=0;y<LABC;y++)
        {
            if(g.lab[i][y]=='.')
                return 0;
            else
                continue;
        }

    return 1;
} 


/*******************************************************************************
 * Esta funcao gera um contador que esta relacionado diretamente a pontuacao do 
 * jogador
 */
t_game pontos(t_game g) 
{
    int f;
    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '.') 
        g.pacman.score += 10; 
    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == 'o')
    {
        g.pacman.score += 50;
        for(f= blinky; f<= clyde; f++)
        {
            g.ghost[f].mode = afraid;
            g.ghost[f].inittime = time(NULL);
        }
    }
    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%')
    {
        g.pacman.score += 500;
        g.pacman.cereja++;
    }
    return g;
} 


/*******************************************************************************
 * Esta funcao cria a cereja do jogo, esta cereja obedece uma condicao que corres-
 * ponde ao momento em que o usuario alcanca o valor de 1000 pontos 
 */
t_game criacereja(t_game g)
{
    if(g.pacman.score >= 1000 && g.pacman.cereja == 1)
        g.lab[13][10]='%';

    return g;
}


/*******************************************************************************
 * Esta funcao retorna como o fantasma inky ira se comportar no modo de caca ao
 * pacman(chase)
 */
t_game inkychase(t_game g)
{
    t_pos posref;
    posref = intermed(g);
    g = alvoinky(posref,g);

    return g;
}


/*******************************************************************************
 * Esta funcao calcula o valor intermediario entre os fantasmas e o pacman
 */
t_pos intermed(t_game g)
 {
    t_pos intermed;

    intermed.y = g.pacman.pos.y;
    intermed.x = g.pacman.pos.x;

    switch(g.pacman.dir)
    {
        case up:
            intermed.y -=2;
            break;
        case left:
            intermed.x -=2;
            break;
        case down:
            intermed.y +=2;
        case right:
            intermed.x +=2;
            break;
        default:
            break;
    }
    return intermed;
}

/*******************************************************************************
 * Esta funcao faz com que o fantasma inky fique rondando o pacman na posicao
 * calculada abaixo, correspondendo a sua caracteristica
 */
t_game alvoinky(t_pos intermed, t_game g)
{
    g.ghost[inky].target.y = 2 * intermed.y - g.ghost[blinky].pos.y;
    g.ghost[inky].target.x = 2 * intermed.x - g.ghost[blinky].pos.x;

    return g;
}


/*******************************************************************************
 * Esta funcao aplica a caracteristica do fantasma pinky, no momento que ele esta
 * em modo chase(caca ao pacman)
 */
t_game pinkychase(t_game g)
{
    switch(g.pacman.dir)
    {
        case up:
            g.ghost[pinky].target.y = g.pacman.pos.y-4;
            g.ghost[pinky].target.x = g.pacman.pos.x;
            break;
        case left:
            g.ghost[pinky].target.y = g.pacman.pos.y;
            g.ghost[pinky].target.x = g.pacman.pos.x-4;
            break;
        case down:
            g.ghost[pinky].target.y = g.pacman.pos.y+4;
            g.ghost[pinky].target.x = g.pacman.pos.x;
            break;
        case right:
            g.ghost[pinky].target.y = g.pacman.pos.y;
            g.ghost[pinky].target.x = g.pacman.pos.x+4;
        default:
            break;
    }
    return g;
}

/**********************************************************************************/

t_game clydechase(t_game g)
{
    if((g.ghost[clyde].pos.x >= g.pacman.pos.x+8) && (g.ghost[clyde].pos.y == g.pacman.pos.y))
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x == g.pacman.pos.x) && g.ghost[clyde].pos.y >= g.pacman.pos.y+8)
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x >= g.pacman.pos.x-8) && g.ghost[clyde].pos.y == g.pacman.pos.y)
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x == g.pacman.pos.x) && g.ghost[clyde].pos.y >= g.pacman.pos.y-8)
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    else
    {
        g.ghost[clyde].target.x = 22;
        g.ghost[clyde].target.y = 0;
    }
    return g;

}

/*******************************************************************************
 * Funcao que serve como ponte(ligacao) para outras duas funcoes, fazendo uma 
 * chamada das mesmas
 */
t_game ghostm(t_game g, int fant)
{
    g = oneghost(g, fant);
    g = movernadirecao(g,fant);

    return g;
}


/*******************************************************************************
 * Esta funcao recebe um fantasma e devolve o movimento do mesmo conforme sua
 * caracteristica especifica
 */
t_game oneghost(t_game g, int fant)
{
    t_pos adj[4];
    t_pos alvo; 
    t_direction contm,contd, mdirecao;

    float dist[4]; 
    float mdistancia;
    mdirecao = up;
    
    alvo.x = g.ghost[fant].target.x;
    alvo.y = g.ghost[fant].target.y;
    
    /* Adjacente cima */
    adj[up].x = g.ghost[fant].pos.x;
    adj[up].y = g.ghost[fant].pos.y-1;
    /* Adjacente baixo */
    adj[down].x = g.ghost[fant].pos.x;
    adj[down].y = g.ghost[fant].pos.y+1;
    /* Adjacente direita */
    adj[right].x = g.ghost[fant].pos.x+1;
    adj[right].y = g.ghost[fant].pos.y;
    /* Adjacente esquerda*/ 
    adj[left].x = g.ghost[fant].pos.x-1;
    adj[left].y = g.ghost[fant].pos.y;
    
    for(contd = 0;contd <= 3;contd++)
    {
        if((g.lab[adj[contd].y][adj[contd].x] == '#')||(adj[contd].x == g.ghost[fant].anteriorpos.x && adj[contd].y == g.ghost[contd].anteriorpos.y))
            dist[contd] = 5001.0;
        else if(adj[contd].x > 7 && adj[contd].x < 12 && adj[contd].y > 7 && adj[contd].y < 12)       
            dist[contd] = (adj[contd].y - 4) * 1000;
        else
            dist[contd] = sqrt(((adj[contd].x -  alvo.x)*(adj[contd].x -  alvo.x)) + ((adj[contd].y -  alvo.y)*(adj[contd].y -  alvo.y)));
    }
    
    mdistancia = dist[up];

    for(contm = 0; contm <= 3; contm++)
    {
        if(dist[contm]< mdistancia)
        {
            mdistancia = dist[contm];
            mdirecao = contm;

        }

    }
    g.ghost[fant].dir = mdirecao;
    
    return g;
}


/*******************************************************************************
 * Esta funcao tera como objetivo principal apagar os rastros dos fantasmas,
 * aplicando as condicoes necessarias para eles passarem pelos pellets e os 
 * powerpills, sem deixa-los serem apagados
 */
t_game movernadirecao(t_game g, int nomeDoFantasma)
{
    g.ghost[nomeDoFantasma].anteriorpos = g.ghost[nomeDoFantasma].pos;

    usleep(40000);
    if(g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] == '@' || g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] == 'B' || g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] == 'C' || g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] == 'P' || g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] == 'I')
        g.ghost[nomeDoFantasma].iten_anterior = ' ';

    if(g.pacman.primeira_pallet == 1)
    {
        g.ghost[blinky].iten_anterior = '.';
        g.pacman.primeira_pallet--;
    }

    switch(g.ghost[nomeDoFantasma].dir) /*switch que altera o fantasma, dependendo da sua direcao atual*/
    {
           
        case up:
                g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] =g.ghost[nomeDoFantasma].iten_anterior;
                g.ghost[nomeDoFantasma].iten_anterior =g.lab[g.ghost[nomeDoFantasma].pos.y-1][g.ghost[nomeDoFantasma].pos.x];
                g.ghost[nomeDoFantasma].pos.y =g.ghost[nomeDoFantasma].pos.y-1;
            break;
            
        case left:
            if(g.ghost[nomeDoFantasma].pos.x ==0)
            {
                g.ghost[nomeDoFantasma].pos.x =19;
                g.lab[10][0]=' ';
            }
                g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] =g.ghost[nomeDoFantasma].iten_anterior;
                g.ghost[nomeDoFantasma].iten_anterior =g.lab[g.ghost[nomeDoFantasma].pos.y][g.ghost[nomeDoFantasma].pos.x-1];
                g.ghost[nomeDoFantasma].pos.x =g.ghost[nomeDoFantasma].pos.x-1;
            break;

        case down:
                g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] = g.ghost[nomeDoFantasma].iten_anterior;
                g.ghost[nomeDoFantasma].iten_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y+1][g.ghost[nomeDoFantasma].pos.x];
                g.ghost[nomeDoFantasma].pos.y = g.ghost[nomeDoFantasma].pos.y+1;
            break;

        case right:
            if(g.ghost[nomeDoFantasma].pos.x == 19)
            {
                g.ghost[nomeDoFantasma].pos.x = 0;
                g.lab[10][19]= ' ';
            }
                g.lab[g.ghost[nomeDoFantasma].anteriorpos.y][g.ghost[nomeDoFantasma].anteriorpos.x] = g.ghost[nomeDoFantasma].iten_anterior;
                g.ghost[nomeDoFantasma].iten_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y][g.ghost[nomeDoFantasma].pos.x+1];
                g.ghost[nomeDoFantasma].pos.x = g.ghost[nomeDoFantasma].pos.x+1;
        default:
            break;
    }
    g.lab[10][10] = ' ';
    g.lab[11][10] = ' ';
    return g;
} 


/*******************************************************************************
 * Esta funcao tera como principal objetivo fazer que no momento em que algum
 * fantasma colidir com o pacman ele morrer ou ter uma vida a menos
 */
t_game colisao(t_game g)
{
    int f;

    for(f = blinky; f <= clyde; f++) /*blinky, pinky, inky e clyde*/
    {
        if((g.ghost[f].mode != afraid) && (g.ghost[f].mode != dead))
        {
            if(((g.ghost[f].pos.x == g.pacman.pos.x) && (g.ghost[f].pos.y == g.pacman.pos.y)) || ((g.pacman.pos.x == g.ghost[f].anteriorpos.x && g.pacman.pos.y == g.ghost[f].anteriorpos.y) && (g.ghost[f].pos.x == g.pacman.anteripos.x && g.ghost[f].pos.y == g.pacman.anteripos.y)))
            {
                usleep(16000);
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = ' ';
                g.ghost[f].iten_anterior = ' ';
                
                //posicao start blinky
                g.ghost[blinky].pos.y =7; //linha
                g.ghost[blinky].pos.x =9; //coluna
                //start pinky
                g.ghost[pinky].pos.y= 9;  //linha
                g.ghost[pinky].pos.x= 10; //coluna
                //start inky
                g.ghost[inky].pos.y= 10; //linha
                g.ghost[inky].pos.x=10; //coluna
                //start clyde
                g.ghost[clyde].pos.y= 11; //linha
                g.ghost[clyde].pos.x= 10; //coluna
            }
        }
            else if(g.ghost[f].mode == afraid) //condicao
            {
                if((g.pacman.pos.x == g.ghost[f].pos.x) && (g.pacman.pos.y == g.ghost[f].pos.y))
                {
                    g.ghost[f].mode= dead;
                    g.pacman.score= g.pacman.score + 200;
                }
            } 
    } 

    return g;
}
t_game afraidmode(t_game g)
{
     int f; 
     
     for(f = 0; f <= clyde; f++)
        if(g.lab[g.pacman.pos.x][g.pacman.pos.y] == 'o')
        {
            srand((unsigned)time(NULL));
            g.ghost[f].target.x = rand()%18; /* Numero de colunas */
            g.ghost[f].target.y = rand()%21; /* Numero de linha */
        }
     
     return g;
}
/* ****************************************************************************
 * Modo de acordo com as situacoes e com o tempo 
 * */
t_game changemode(t_game g, int fant)
{
    int mode = g.ghost[fant].mode;
    
    if((g.ghost[fant].pos.x > 7 && g.ghost[fant].pos.x < 12) && (g.ghost[fant].pos.y >= 8 && g.ghost[fant].pos.y < 12))
            {
                g.ghost[fant].target.x = 9;
                g.ghost[fant].target.y = 7;
            }    
    else
    {
        switch(mode)
            {
                case chase:

                    if(calculatempo(g,fant) <=20)
                    {
                       g.ghost[fant].mode = chase;
                    }
                    else if(calculatempo(g,fant) > 20)
                    {
                        g.ghost[fant].mode = scatter;
                        g.ghost[fant].inittime = time(NULL);
                    }
               case scatter:

                    if(calculatempo(g,fant)<7)
                    {
                        g.ghost[fant].mode = scatter;
                    }
                    else
                    {
                        g.ghost[fant].mode = chase;
                        g.ghost[fant].inittime = time(NULL);
                    }

               case afraid:

                    if(calculatempo(g,fant) < 7)
                    {
                        if((g.ghost[fant].pos.x == g.pacman.pos.x) && (g.ghost[fant].pos.y == g.pacman.pos.y))
                        {
                            g.ghost[fant].mode = dead;
                            g.ghost[fant].inittime = time(NULL);
                        }
                        else
                            g.ghost[fant].mode = afraid;
                    }
                    else
                    {
                        g.ghost[fant].mode = chase;
                        g.ghost[fant].inittime = time(NULL);
                    }
                case dead:
                    if(calculatempo(g,fant)<7)
                    {
                        g.ghost[fant].target.y = 10;
                        g.ghost[fant].target.y = 10;
                    }
                    else
                    {
                        g.ghost[fant].mode = chase;
                        g.ghost[fant].inittime = time(NULL);
                    }
        }
    }
    return g;
}
/*******************************************************************************
 * Calcula diferenca de tempo 
 * */
double calculatempo(t_game g, int fant)
{
    g.ghost[fant].endtime = time(NULL);
    g.ghost[fant].time = difftime(g.ghost[fant].endtime,g.ghost[fant].inittime);
    return g.ghost[fant].time;
}

/* ---------------------------------------------------------------------- */
/* *
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
} 
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game upecman_init(void)
{ 
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */
    g.pacman.cereja = 1;
    g.pacman.primeira_pallet = 1;

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f)
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
        g.ghost[f].iten_anterior = ' ';
    }

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK);  /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK);  /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */

    return g;
} 

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */ 
void printlab(t_game g)
{ 
    IFDEBUG("printlab()");

    int y, i, f;

    clear(); /* clear the screen */
    //curs_set(0);
    /* for(y=0; y<LABL; y++)
       {
       mvprintw(y,0,"%s\n", g.lab[y]);
       mvchgat(y,0,-1,A_BOLD,5,NULL);
       }*/

    for(i=0;i<LABL;i++) 
    {
        for(y=0;y<LABC;y++) 
        {
            mvprintw(i,y,"%c",g.lab[i][y]);  
            if((g.lab[i][y]=='#')||(g.lab[i][y]=='-'))  
                mvchgat(i,y,-1,A_BOLD,5,NULL);  
            if(g.lab[i][y]=='.')  
                mvchgat(i,y,-1,A_BOLD,6,NULL);  
            if(g.lab[i][y]=='o')  
                mvchgat(i,y,-1,A_BOLD,6,NULL);                          
            if(g.lab[i][y]=='%')
            mvchgat(i,y,-1,A_BOLD,1,NULL);
         }
     }

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);
    }

    for(f=blinky; f<=clyde; f++)
    {
        if(f == blinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "B");

        if(f == pinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "P");
        
        if(f == inky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "I");

        if(f == clyde)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "C");

        if((g.ghost[f].mode != afraid) && (g.ghost[f].mode != dead))
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f+1, NULL);
        else
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
    }

    mvprintw(g.pacman.pos.y, g.pacman.pos.x,"@");
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
    mvprintw(0, 25, "Score: %d", g.pacman.score); 
    mvprintw(8, 25, "life: %d", g.pacman.life);
    mvchgat(0, 25, -1, A_BOLD, 4, NULL); 

    refresh();
 }


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

