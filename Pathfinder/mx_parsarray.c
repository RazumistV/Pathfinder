#include "inc/libmx.h"

// char **mx_parsarray(char *str) {


// 	return islands;
// }

int main(int ac, char **av) {
	char **anyway = NULL;
	char *file = NULL; 
	char **dist = NULL;
	char **point = NULL;
	file = mx_file_to_str(av[1]);
	dist = mx_strsplit(file, '\n');

	for (int i = 1; dist[i]; i++) 
    	printf(" dist = %s\n", dist[i]);
    printf("********************************\n");

	point = mx_strsplit(file, '-');
    for (int i = 1; point[i]; i++) 
    	printf(" point = %s\n", point[i]);
    printf("********************************\n");

    anyway = mx_strsplit(file, ',');
    for (int i = 1; anyway[i]; i++) 
    	printf(" point = %s\n", point[i]);
}
