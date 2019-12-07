#include "inc/libmx.h"
#include <stdio.h>

int mx_islands_index(t_path *p, int current, int max_index) {
	int j = 0;

	if (current == 0) {
		p[current].index_a = 0;
		p[current].index_b = 1;
		max_index = 1;
	}
	while (j < current) {
		if(mx_strcmp(p[current].a, p[j].a) == 0)
			p[current].index_a = p[j].index_a;
		else if(mx_strcmp(p[current].a, p[j].b) == 0)
			p[current].index_a = p[j].index_b;
		else if (p[current].index_a == -1 && j == current - 1) {
			p[current].index_a = max_index + 1;
			max_index++;
		}
		if (mx_strcmp(p[current].b, p[j].a) == 0)
			p[current].index_b = p[j].index_a;
		else if (mx_strcmp(p[current].b, p[j].b) == 0)
			p[current].index_b = p[j].index_b;
		else if (p[current].index_b == -1 && j == current - 1) {
			p[current].index_b = max_index + 1;
			max_index++;
		}
		j++;
	}
	return max_index;
}

int mx_islands(t_path *p, char *file) {
	char *fl = mx_file_to_str(file);
	char **WordsA = mx_strsplit(fl, '\n');
	char **str1;
	char **str2;
	int i;
	int max_index = 0;

	free(fl);
	for(i = 0; WordsA[++i];) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		p[i - 1].a = mx_strdup(str1[0]);
		p[i - 1].b = mx_strdup(str2[0]);
		p[i - 1].distance = mx_atoi(str2[1]);
		p[i - 1].index_a = -1;
		p[i - 1].index_b = -1;
		max_index = mx_islands_index(p, i - 1, max_index);
		mx_del_strarr(&str1);
		mx_del_strarr(&str2);
	}
	mx_del_strarr(&WordsA);
	return --i;
}

static char **mx_perenos(char *file) {
	char *str = mx_file_to_str(file);
	char **split = mx_strsplit(str, '\n');

	free(str);
	return split;
}

int main(int ac, char **av) {
	t_path *p;
	char **a = mx_perenos(av[1]);
	int count = mx_arrlen(a);

	p = (t_path *)malloc(sizeof(t_path) * count - 1);
	mx_islands(p, av[1]);
	printf("----------------\n");
	for (int k = 0; k < count - 1; k++) {
		printf("---Apex = %s\n---Apex = %s\n-distance = %d\n index a = %d\n index b = %d\n----------------\n", 
			p[k].a, p[k].b, p[k].distance, p[k].index_a, p[k].index_b);
	}
	
	system("leaks -q a.out");
	return 0;
}
