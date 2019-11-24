#include "inc/libmx.h"
#include "stdio.h"

int main(int ac, char **av) {
    char *file = NULL; // file contain
    // char **islands; 
	int PointIslands = 0; // apex
    char **range;
    int n = 0;

    file = mx_file_to_str(av[1]);
    PointIslands = mx_atoi(&file[0]);
    // char **islands = mx_strsplit(file, '\n');
    if (ac > 0) {
        range = (char**)malloc(sizeof(char *) * PointIslands);
        for (int i = 0; i < PointIslands ; i++) {
            range[i] = (char *)malloc(sizeof(char *) * PointIslands);
            for (int j = 0; j < PointIslands; j++) {
                range[i][j] = '1';
            }
        }
        int d = 0;
        printf("matrix =\n");
        while (range[d])
            printf("        %s\n", range[d++]);
    }
}
            
     

        //printf("point = %d", PointIslands);
    // error case
    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

