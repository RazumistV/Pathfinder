#include "inc/libmx.h"
#include "stdio.h"

int main(int ac, char **av) {
    char *file = NULL;
    //char *islands = NULL;
	int PointIslands = 0;


    file = mx_file_to_str(av[1]);
    PointIslands = mx_atoi(&file[0]);
    //islands = *mx_strsplit(file, '\n');

    if (ac > 0) {
        
        printf("point = %d", PointIslands);

    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

    }
}
