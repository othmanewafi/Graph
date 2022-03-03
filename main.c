#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void ft_graph(int **tab, int n) {

    int check;
    int i, j;
    for(i = 0; i < n; i++)
    {
        check = 0;
        for (j = 0; j < n ; j++)
        {
            if(tab[i][j])
            {
                check = 1;
                j = n;
            }
        }

        if (!check){
            printf("Non\n");
            return;
        }
    }
    printf("Oui\n");
}

void ft_main_programe(FILE *fd,int sommet, int nbr_arcs)
{
    char *buffer = 0;
    int len;
    int x, y;
    int **graph;
    int i, j;
    int a = 1;
    int read;
    graph = (int **)malloc(sommet * sizeof(int *));
    for(i = 0; i < sommet; i++)
    {
        graph[i] = (int *)malloc(sommet * sizeof(int));
        for (j = 0; j < sommet; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(i = 0; i < nbr_arcs; i++)
    {
        read = getline(&buffer, &len, fd);

        x = atoi(buffer);
        y = atoi(buffer + 1);

        graph[x - 1][y - 1] = 1;
        graph[y - 1][x - 1] = 1;
    }
    
    ft_graph(graph, sommet);
}

int main() {

    char *ptr;
    char *buffer = 0;
    int len;
    int read;
    FILE *fd;
    int i = 1;
    int test;
    int sommet, arcs;

    fd = fopen("test.txt", "r");
    read = getline(&buffer, &len, fd);
    test = atoi(buffer);
    while (test && read) {
        read = getline(&buffer, &len, fd);
        sommet = atoi(buffer);
        arcs = atoi(buffer + 1);
        ft_main_programe(fd,sommet, arcs);
        test--;
    }

    return 0;
}