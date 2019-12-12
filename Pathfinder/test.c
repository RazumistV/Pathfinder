#include "inc/libmx.h"

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

int **matrix(const char *file, t_path *p) {
    int **range;
    char *str = mx_file_to_str(file);
    int PointIslands = mx_atoi(str);
    int k = 0;
    int b = 0;
	
	free(str);
    range = (int **)malloc(sizeof(int *) * PointIslands);
    for (int i = 0; i < PointIslands ; i++) {
        range[i] = (int *)malloc(sizeof(int *) * PointIslands);
        for (int j = 0; j < PointIslands; j++) {
			if (i == p[k].index_b && j == p[k].index_a) {
				range[i][j] = p[k].distance;
				range[j][i] = p[k].distance;
				k++;
				printf("%d\n", range[i][j]);
			}
			// else if (i == p[b].index_a && j == p[b].index_b) {
			// 	printf("index_b = %d, index_b = %d\n", p[b].index_a, p[b].index_a);
			// 	range[i][j] = p[b].distance;
			// 	b++;
			// }
			else
				range[i][j] = -1;
        }
    }
    return range;
}

static int mx_str_count(char *file) {
	char *str = mx_file_to_str(file);
	int j = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '\n')
			j++;
	}
	free(str);
	return j;
}

// int **dejkstra(t_path p) {

// 	int j = 0;
// 	for (int i = 0; p[i].)
// }

int main(int ac, char **av) {
	int count = mx_str_count(av[1]) - 1;
	t_path *p = (t_path *)malloc(sizeof(t_path) * count - 1);
	mx_islands(p, av[1]);
    char *fl = mx_file_to_str(av[1]);
    int counter1 = mx_atoi(fl);
    int **res = matrix(av[1], p);
	
    for (int i = 0; i < counter1; i++) {
        for (int j = 0; j < counter1; j++)
            printf("    %d", res[i][j]);
        printf("\n\n");
    }
   system("leaks -q a.out");
}
