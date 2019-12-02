#include "inc/libmx.h"
#include "stdio.h"


void point(t_path *p) {
    char *file = NULL;
    char **perenos = NULL; 
    // char **minus = NULL;
    // char **zap = NULL;

    file = mx_file_to_str(p);
    perenos = mx_strsplit(file, '\n');
    //minus = mx_strsplit(file, '-');
    // zap = mx_strsplit(file, ',');

    p->a = mx_strsplit(perenos, '-');
    p->b = mx_strsplit(perenos, ',');
}

//void islands(t_path *p) {
//   p->distance = 5;
//   point(p);

//}



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
    // int **range;
    // int **res = matrix(av[1]);
    t_path *p;
    int count = 10;

    p = (t_path *)malloc(sizeof(t_path)* count);
    //p[0].distance = 3;
    //p[1].distance = 2;
    islands(&p);
    printf("distance = %d a = %s b = %s\n",  p[1].distance, p[1].a, p[1].b);

    
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++)
    //         printf("  %d", res[i][j]);
    //     printf("\n");
    // }
}       
    //printf("point = %d", PointIslands);
    // error case
    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

