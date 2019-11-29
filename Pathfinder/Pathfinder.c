#include "inc/libmx.h"
#include "stdio.h"



int **matrix(const char *file) {
    int **range = NULL;

    int PointIslands = mx_atoi(mx_file_to_str(file));
    printf("matrix = %d\n", PointIslands);
    range = (int **)malloc(sizeof(int *) * PointIslands);
    for (int i = 0; i < PointIslands ; i++) {
        range[i] = (int *)malloc(sizeof(int *) * PointIslands);
        for (int j = 0; j < PointIslands; j++) {
            range[i][j] = -1;
        }
    }
    return range;
}

int main(int ac, char **av) {
    int **range;
    int **res = matrix(av[1]);

    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("  %d", res[i][j]);
        printf("\n");
    }
}       
    //printf("point = %d", PointIslands);
    // error case
    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

