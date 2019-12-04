#include "inc/libmx.h"
#include "stdio.h"


int **matrix(const char *file, t_path) {
    int **range;
    char *str = mx_file_to_str(file);
    int PointIslands = mx_atoi(str);
    
    printf("matrix = %d\n", PointIslands);
    range = (int **)malloc(sizeof(int *) * PointIslands + 1);
    for (int i = 0; i < PointIslands ; i++) {
        range[i] = (int *)malloc(sizeof(int *) * PointIslands);
        for (int j = 0; j < PointIslands; j++) {
            range[i][j] = -1;
        }
    }
    free(str);
    return range;
}

int mx_min_elem_inarr(int *arr, int size) {
    int min = arr[0];
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            break ;
        }
    }
    return i;
}

char *mx_dejksta(int **matrix, int size_m, t_path *p, int size_p) {
    int k = 0;
    int min = 0;

    for (int i = 0; i < size_m; i++) {
        matrix[i][0] = min;
        for (int j = 1; j < size_m;) {
            for (; k < size_p; k++) {
                if (p[k].index_a == matrix[i][0]);
                    break ; 
            }
            if (p[k].index_b == j)
                matrix[i][j] = p[k].distance;
            j++;
        }
        min = mx_min_elem_inarr(matrix[i], size_m);
    }
}

int main(int ac, char **av) {
    int **range;
    int **res = matrix(av[1]);
    for (int i, j = 0; res[i]; i++) {
        for (int j = 0; res[j]; j++)
            printf("  %d", res[i][j]);
        printf("\n");
    }
    system("leaks -q a.out");
}       
    //printf("point = %d", PointIslands);
    // error case
    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

