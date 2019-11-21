#include "inc/libmx.h"
#include "stdio.h"

int main(int ac, char **av) {
    char *file = NULL; // file contain
    char **islands; 
	int PointIslands = 0; // apex
    char **range;
    int k = 0;

    file = mx_file_to_str(av[1]);
    PointIslands = mx_atoi(&file[0]);
    char **islands = mx_strsplit(file, '\n');
    if (ac > 0) {
        
        range = mx_strnew(mx_strlen(mx_isdigit(*islands)));
        for (int i = 1; *islands[i]; i++) {
            for (int j = 0; *islands[j]; j++) {
                if (mx_isdigit(*islands))
                    range[i][k] = *islands[j++];
            }
            printf("%s\n", range);
        }
            
     

        //printf("point = %d", PointIslands);
    // error case
    // if (ac > 2)
    //     mx_printerr("usage: ./pathfinder [filename]");

    }
}


