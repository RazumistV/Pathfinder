#include "inc/libmx.h"
#include <stdio.h>

void freearray(char **arr) {
	int i = -1;

	if (arr == NULL)
		return ;
	while (arr[++i]) {
		if (arr[i] != NULL)
			free(arr[i]);
	}
}

// static void mx_points(t_path *p, char *str) {
// 	char **apex;
// 	char **apex2;
// 	int i = 0;
	
// 	apex = mx_strsplit(str, '\n');
	
// 	while (apex[++i]) {
// 		apex2 = mx_strsplit(apex[i], '-');
// 		p[i - 1].a = mx_strdup(apex2[0]);
// 		apex2 = mx_strsplit(apex2[1], ',');
// 		p[i - 1].b = mx_strdup(apex2[0]);
// 		freearray(apex2);
// 		free(apex[i]);
// 	}
// 	free(apex);

//}

void mx_islands(t_path *p, char *file) {
	char *str = mx_file_to_str(file);
	char **apex = mx_strsplit(str, '\n');
	char **apex2;
	int i = 1;

	while(apex[++i]) {
		apex2 = mx_strsplit(apex[i], '-');
		p[i - 1].a = mx_strdup(apex2[0]);
		apex2 = mx_strsplit(apex2[1], ',');
		p[i - 1].b = mx_strdup(apex2[0]);
		p[i - 1].distance = mx_atoi(apex2[1]);
		//printf("%d", p[i].distance);
	}
	free(apex);
	free(apex2);

}

// void mx_islands(t_path *p, char *file) {
// 	char *str = mx_file_to_str(file);
// 	char **split = mx_strsplit(str, '\n');
// 	int i = 1;
// 	while (split[i]) {
// 		p[i - 1].distance = mx_atoi(split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	mx_points(p, str);
// 	free(str);

// }

int main(int ac, char **av) {
	t_path *p;
	int count = 10;


	p = (t_path *)malloc(sizeof(t_path) * count);
	mx_islands(p, av[1]);
	for (int k = 0; k < count; k++) {
		printf("---Apex = %s\n---Apex = %s\ndistance = %d\n", p[k].a, p[k].b, p[k].distance);
	}
	system("leaks -q a.out");
	return (0);
}







