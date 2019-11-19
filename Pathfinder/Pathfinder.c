#include "inc/libmx.h"

int main(int ac, char **av) {
    char *file;
	char **str;
    int i = 0;
    int j = 0;
    
    if (ac > 1) {
        mx_printerr("usage: ./pathfinder [filename]");
        exit(0);
    }
    if (ac == 1) {
        file = mx_file_to_str(av[1]);
        *str = mx_str_split(file, '\n');

    }
}
