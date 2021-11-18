/* ************************************************************************ *
 *    Labirinto, 2018 VERSION                                               *
 *    Esse programa demonstra uma possivel resposta para um labirinto qual- *
 *    quer em 2D.                                                           *
 *    Objetivo: -Aprender a usar funcao recursiva.                          *
 *              -Desafio pessoal de aprender a ler um arquivo no programa   *
 *    Novos conhecimentos adquiridos: - FILE *fopen(char *filename, "r")    *
 *                                    - int getc(FILE *stream)              *
 *                                    - void *malloc(size_t size)           *
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

void get_labirinto(char* file_name); /* analizando o arquivo */
void alloc_labirinto(); /* para alocar espaco para o labirinto1 */
void print_labirinto();
void get_visitado(); /* necessario para melhor codificacao de como sera o percurco do caminho percorrido no labirinto */
void alloc_visitado(); /* para alocar espaco para o labirinto preenchido com o caminho formado */
int put_sementes(int linha, int coluna); /* funcao recursiva para colocar o caminho("sementes") na matriz labirinto2(visitado) recebendo a linha de comeco e coluna do comeco */
int put_sementes(int linha, int coluna); /* funcao recursiva para colocar o caminho("sementes") na matriz labirinto2(visitado) recebendo a linha de comeco e coluna do comeco */
void add_sementes(); /* funcao para adicionar um caractere sugerido pelo orientador para representar o caminho percorrido */

char **labirinto;
int **visitado;
int linhas;
int colunas;
int start_linha;
int start_coluna;

enum terreno{vazio, parede, final, semente};

int main(void)
{
    get_labirinto("ex20-README.txt"); /* enviara o arquivo.txt para leitura do labirinto */

    printf("\n Este programa mostra uma solucao para um labirinto 2D de sua preferencia.\n\n OBS: Para editar e colocar um novo labirinto, edite\n      seguindo as instrucoes no arquivo ex20-README.txt\n\n");
    printf("O labirinto localizado foi:\n");
    print_labirinto();

    get_visitado(); /* Mapeara para o labirinto 2 */
    put_sementes(start_linha,start_coluna);
    add_sementes();
    printf("Uma possivel solucao eh:\n");
    print_labirinto();

    return 0;
}

void get_labirinto(char* file_name)/* analizando o arquivo */
{
    char c; /* usado para armazenar o arquivo nessa variavel */
    char linhas_s[3] = { '\0' }; /* linhas a serem preenchidas(comeca vazio)*/
    char colunas_s[3] = { '\0' };
    int linhas_i = 0; /* para saber em que digito estamos ao ler a string*/
    int colunas_i = 0;
    int pula = 0;
    FILE* file; /* declarando um ponteiro do tipo FILE(para que um programa possa manipular um arquivo eh necessario associa-lo a uma variavel do tipo FILE) */

    file = fopen(file_name, "r"); /* FILE *fopen(char *filename, "r"): abre o arquivo.txt para leitura e será usado como argumento para funcao getc() */

    if(file) /* Aqui leremos o arquivo para armazenar as fronteiras, ou seja, quantidade de linhas e colunas */
    {
        while((c = getc(file))!= EOF) /* getc(file): get character --- EOF End Of File ---- armazena em c até o fim da funcao */
        {
            if(c == '\n') /* acaba o laço, pois ja foi lido os caracteres de quantidade de linha e coluna */
                break;
            else 
                if (c == ',') /* na primeira linha do arquivo, ignoramos o caractere',', pois nao faz parte de qtd de linha e coluna, serve apenas para separar */
                    pula = 1;
                else 
                    if(pula==0)
                    {
                        linhas_s[linhas_i] = c; /* armazena quantidade de linhas */
                        linhas_i++; /* move para a proxima parte do digito */
                    }
                    else
                        if(pula==1)
                        {
                            colunas_s[colunas_i] = c; /* armazena quantidade de colunas, ou seja, proximos caracteres depois de',' e antes de '\n'*/
                            colunas_i++;
                        }
        }
    }

    linhas = atoi(linhas_s); /* para transformar os caracteres em linhas_s em inteiro */
    colunas = atoi(colunas_s); /* para transformar os caracteres em colunas_s em inteiro */

    alloc_labirinto(); /* necesario pois antes nao temos um espaco alocado para chamar **labirinto */
    /* laço a segui para criacao da matriz com o labirinto preenchido, de acordo com o que foi informado no arquivo.txt: */    
    for(int i = 0; i< linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            c = getc(file);

            if(c == '\n') /* quando bater num caractere newline, então temos que pula-lo */
                c = getc(file);

            labirinto[i][j] = c; /* preenchemos a matriz*/

            if(c == 'i') /* onde comeca o labirinto */
            {
                start_linha = i; 
                start_coluna = j;
            }
        }
    }

    fclose(file); /* Depois de usado o arquivo fclose() foi usado para fecha-lo */
}
void alloc_labirinto() /* para alocar espaco para o labirinto1 */
{
    labirinto = malloc(linhas * sizeof(char*)); /* void* malloc(size_t size): Aloca bloco de memoria no tamanho dado e retorna um ponteiro para o comeco do bloco. Necessario por nao foi alocado um tamanho para o labirinto, sera determinado de acordo com o tamanho dado no arquivo.txt */

    for(int i = 0; i < linhas; i++)
        labirinto[i] = malloc(colunas * sizeof(char*));
}
void print_labirinto()
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
            printf("%c ", labirinto[i][j]);
        printf("\n");
    }
    printf("\n");
}

void get_visitado() /* necessario para melhor codificacao de como sera o percurco do caminho percorrido no labirinto */
{
    alloc_visitado();

    for(int i = 0; i< linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(labirinto[i][j] == '#')
                visitado[i][j] = parede; /* fixado em enum() */
            else 
                if(labirinto[i][j] == 'f')
                    visitado[i][j] = final; /* fixado em enum() */
                else
                    visitado[i][j] = vazio;
        }
    }
}
void alloc_visitado() /* para alocar espaco para o labirinto preenchido com o caminho formado */
{
    visitado =  malloc(linhas * sizeof(char*));

    for(int i = 0; i < linhas; i++)
        visitado[i] =  malloc(colunas * sizeof(char*));
}

int put_sementes(int linha, int coluna) /* funcao recursiva para colocar o caminho("sementes") na matriz labirinto2(visitado) recebendo a linha de comeco e coluna do comeco */
{
    int* current = &visitado[linha][coluna]; /* ponteiro para a matriz visitado, para colocarmos um inteiro diferente ao caminho percorrido, necessario para imprimir o caminho depois */
        if(*current == final)
            return 1;

    if(*current == vazio)
    {
        *current = parede;

        if(put_sementes(linha,coluna - 1))
        { 
            *current = semente;
            return 1;
        }
        if(put_sementes(linha,coluna + 1))
        {
            *current = semente;
            return 1;
        }
        if(put_sementes(linha + 1,coluna))
        {
            *current = semente;
            return 1;
        }
        if(put_sementes(linha - 1,coluna))
        {
            *current = semente;
            return 1;
        }
    }

    return 0;
}

void add_sementes() /* funcao para adicionar um caractere sugerido pelo orientador para representar o caminho percorrido */
{
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            if(labirinto[i][j] != 's')
                if(visitado[i][j] == semente)
                    labirinto[i][j] = 'x';
}

