#include "inc/libmx.h"

struct s_island {
	char **points;
	int count;
};

// static void *mx_glist(char **str, int count) {
// 	t_list *pl = *str;
//  	t_list *node = mx_create_node(str);
 
//     if (pl == NULL) {
//     	*str = node;
//         return ;
//     }
//     while (pl->next != NULL) {
//         pl = pl->next;
//     }
//     pl->next = node;
// }

char **mx_parsarray(char *str) {
	char *file = NULL;
	char **perenos = NULL; 
	char **minus = NULL;
	char **zap = NULL;

	file = mx_file_to_str(str);
	perenos = mx_strsplit(file, '\n');
	// minus = mx_strsplit(file, '-');
	// zap = mx_strsplit(file, ',');

	return perenos;
}

int main(int ac, char **av) {
	char **dist = mx_parsarray(av[1]);

	for (int i = 1; dist[i]; i++) 
    	printf("%\n", dist[i]);

    printf("********************************\n");

	char **point = mx_parsarray(av[1]);
    for (int i = 1; point[i]; i++) 
    	printf("%s\n", point[i]);
//     printf("********************************\n");

//     anyway = mx_strsplit(file, ',');
//     for (int i = 1; anyway[i]; i++) 
//     	printf(" point = %s\n", point[i]);
}
