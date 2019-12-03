#include "inc/libmx.h"
#include <stdio.h>

void mx_islands(t_path *p, char *file) {
	char *fl = mx_file_to_str(file);
	char **WordsA = mx_strsplit(fl, '\n');
	char **str1;
	char **str2;
	int i;

	free(fl);
	for(i = 0; WordsA[++i];) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		p[i - 1].a = mx_strdup(str1[0]);
		p[i - 1].b = mx_strdup(str2[0]);
		p[i - 1].distance = mx_atoi(str2[1]);
		mx_del_strarr(&str1);
		mx_del_strarr(&str2);
	}

	mx_del_strarr(&WordsA);
}

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
	t_path *p;
	int count = 6;

	p = (t_path *)malloc(sizeof(t_path) * count);
	mx_islands(p, av[1]);
	printf("----------------\n");
	for (int k = 0; k < count; k++) {
		printf("---Apex = %s\n---Apex = %s\n-distance = %d\n----------------\n", p[k].a, p[k].b, p[k].distance);
	}

	// mx_strdel(&p->a);
	// mx_strdel(&p->b);
	system("leaks -q a.out");
	return 0;
}
