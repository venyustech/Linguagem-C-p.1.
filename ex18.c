/***************************************************************************
 *   ex18.c                                   Version 20181017.120446      *
 *                                                                         *
 *   Tabuada                                                               *
 *   Copyright (C) 2018         by Gardenia Georgia Barbosa de Siqueira    *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
 *   Gardenia Georgia Barbosa de Siqueira                                  *
 *   Email: gardenia.georgia.b.s@gmail.com                                 *
 *   Webpage: http://www.upe.br                                            *
 *   Phone: +55 (81) 99785-0393                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file ex18.c
 * @ingroup GroupUnique
 * @brief Tabuada
 * @details This program really do a nice job as a table, and template only!
 * @version 20181017.120446
 * @date 2018-10-17
 * @author Gardenia Georgia Barbosa de Siqueira <<gardenia.georgia.b.s@gmail.com>>
 * @par Webpage
 * <<a href="http://www.upe.br">www.upe.br</a>>
 * @copyright (c) 2018 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <unistd.h>/* UNIX standard function */

/* ---------------------------------------------------------------------- */
/* definitions */

#define MIN 1   /* numero que irá começar a multiplicação */
#define MAX 10  /* numero que irá terminar a multiplicação */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181017.120446" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

int tab(int com, int fim); /* função que calcula a tabuada e imprime na tela */
void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void tabuada_init(void); /* global initialization function */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This program will do a math table
 * @details This program makes a multiplication table according to the command data
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex18 -h
 * @endcode
 *
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 * @author Gardenia Georgia Barbosa de Siqueira
 * @version 20181017.120446
 * @date 2018-10-17
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int inicio=0,fim=0;

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "i:f:vhV")) != EOF)
        switch(opt)
        {   
            case 'i':
                inicio=atoi(optarg);
                break;
            case 'f':
                fim=atoi(optarg);
                break;
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
                if(fim>20)
                    return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    tabuada_init(); /* initialization function */

    tab(inicio,fim);

    return EXIT_SUCCESS;
}

/* functions */

int tab(int Ninicio, int Nfim)
{
    int tabuada,linha;
    if(Nfim<Ninicio)
        printf("Voce digitou um fim menor que um inicio. Nao faz sentido.\nTente novamente com um valor onde inicio<fim.\n");
    else
    {
        if(Nfim>20)
            printf("Valores maiores que 20 nao sao permitidos.\n");
        else
        {
            for(linha=MIN;linha<=MAX;linha++)
            {
                for(tabuada=Ninicio;tabuada<=Nfim;tabuada++)
                    printf("%2d x %2d = %3d |\t",tabuada,linha,tabuada*linha);
                printf("\n");
            }
        }   
    }
    return 0;
}
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Gardenia Georgia Barbosa de Siqueira
 * @version 20181017.120446
 * @date 2018-10-17
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "tabuada", "Tabuada");
    printf("\nUsage: %s [-h|-v]\n", "tabuada");
    printf("\nOptions:\n");
    printf("\t-i(plus an integer),  --start:\n\t\tShow a math table beggining to a integer you put.\n");
    printf("\t-f(plus an integer,  --end\n\tShow a math table ending to a integer you put.\n\t\t you need put a integer end>start to work\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Gardenia Georgia Barbosa de Siqueira", "gardenia.georgia.b.s@gmail.com");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Gardenia Georgia Barbosa de Siqueira
 * @version 20181017.120446
 * @date 2018-10-17
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "tabuada", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2018, "Gardenia Georgia Barbosa de Siqueira", "gardenia.georgia.b.s@gmail.com");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 *
 * @author Gardenia Georgia Barbosa de Siqueira
 * @version 20181017.120446
 * @date 2018-10-17
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void tabuada_init(void)
{
    IFDEBUG("tabuada_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */

