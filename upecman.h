/***************************************************************************
 *   upecman.h                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
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
/* definitions */

#ifndef VERSION
#define VERSION "20160529.013231" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define LABL 23 /**< Number of lines in labyrinth */
#define LABC 21 /**< Number of columns in labyrinth */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

const char labmodel[LABL][LABC] =
{
    /*01234567890123456789*/
    {"####################"},    /* 0*/
    {"#........##........#"},    /* 1*/
    {"#o##.###.##.###.##o#"},    /* 2*/
    {"#..................#"},    /* 3*/
    {"#.##.#.######.#.##.#"},    /* 4*/
    {"#....#...##...#....#"},    /* 5*/
    {"####.###.##.###.####"},    /* 6*/
    {"   #.#...B....#.#   "},    /* 7*/
    {"   #.#.##--##.#.#   "},    /* 8*/
    {"####.#.#  P #.#.####"},    /* 9*/
    {"    ...#  I #...    "},    /*10*/
    {"####.#.#  C #.#.####"},    /*11*/
    {"   #.#.######.#.#   "},    /*12*/
    {"   #.#........#.#   "},    /*13*/
    {"####.#.######.#.####"},    /*14*/
    {"#........##........#"},    /*15*/
    {"#o##.###.##.###.##o#"},    /*16*/
    {"#..#.....@......#..#"},    /*17*/
    {"##.#.#.######.#.#.##"},    /*18*/
    {"#....#...##...#....#"},    /*19*/
    {"#.######.##.######.#"},    /*20*/
    {"#..................#"},    /*21*/
    {"####################"}     /*22*/
};


typedef enum e_ghostmode {chase, scatter, afraid, dead} t_ghostmode;
typedef enum e_direction {up, left, down, right} t_direction;
typedef enum e_ghosts {blinky, pinky, inky, clyde} t_ghosts;

typedef struct st_position
{
    int y; /* line */
    int x; /* column */
} t_pos;

typedef struct st_pacman
{
    t_pos pos; /* current pacman position */
    t_direction dir; /* direction */
    t_pos anteripos;
    int life; /* how many lifes pacman has */
    int score; /* dot = 10 point; pill = 50 points; ghost = 750 points; cherry = 500 */
    int cereja;
    int primeira_pallet;

} t_pacman;

typedef struct st_ghost
{
    t_pos pos; /* ghost position */
    t_direction dir; /* ghost current direction */
    t_pos starget; /* ghost scatter preferred corner */
    t_pos target; /* ghost target */
    t_pos anteriorpos; /*ghost last position*/
    t_ghostmode mode; /* chase, scatter, afraid or dead */
    char iten_anterior;
    time_t inittime;
    time_t endtime;
    time_t time;
} t_ghost;

typedef struct st_pacdata
{
    char lab[LABL][LABC]; /* the labyrinth map */
    t_pacman pacman; /* pacman data */
    t_ghost ghost[4]; /* ghost[blinky], ghost[pinky], ghost[inky], ghost[clyde] */
} t_game;


/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
t_game upecman_init(void); /* initialize game variables */
void printlab(t_game g); /* print the labyrinth */
int end_game(t_game g);
t_game modeafraid(t_game g, int fant);
t_game mov_pac(t_game g, int kin);
t_game pontos(t_game g);    
t_game criacereja(t_game g);
/*t_game ghostmove(t_game g);*/
t_game fanmovi(t_game g);
/* Inky funcoes */
t_game inkychase(t_game g);
t_pos intermed(t_game g);
t_game alvoinky(t_pos intermed, t_game g);  
/* Pinky funcoes  */
t_game pinkychase(t_game g);
t_game pinkychase(t_game g);
/* Clyde funcoes*/
t_game clydechase(t_game g);
/* Modo dos fantasmas */
t_game changemode(t_game g, int fant);
double calculatempo(t_game g, int fant);
/* Movimento do ghost */
t_game mapa(t_game g, int nomeDoFantasma);
t_game ghostmove(t_game g);
t_game oneghost(t_game g, int fant);
t_game ghostm(t_game g, int fant);
t_game movernadirecao(t_game g, int nomeDoFantasma);
t_game colisao(t_game g);/*caso de colisao fantasma pacman*/
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

