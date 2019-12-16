#include "inc/libmx.h"
#include <stdio.h>

static int index_point(t_path *p, char *point, int count) {
	int index_point = -1;
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(p[i].name, point) == 0) {
			index_point = p[i].index_name;
		}
	}
	return index_point;
}

static bool new_island(char *str, t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(str, p[i].name) == 0)
			return false;
	}
	return true;
}

static void connect_count(t_path *p, char *fl, char **WordsA, int count) {
	for (int j = 0; j < count; j++) {
		int k = 0;
		p[j].count_distance = mx_count_substr(fl, p[j].name);
		p[j].d = (t_dist *)malloc(sizeof(t_dist) * p[j].count_distance);
		for (int i = 1; WordsA[i]; i++) {
			char **str1 = mx_strsplit(WordsA[i], '-');
			char **str2 = mx_strsplit(str1[1], ',');
			if (mx_strcmp(p[j].name, str1[0]) == 0) {
				p[j].d[k].point = mx_strdup(str2[0]);
				p[j].d[k].index_point = index_point(p, p[j].d[k].point, count);
				p[j].d[k++].dist = mx_atoi(str2[1]);
			}
			if (mx_strcmp(p[j].name, str2[0]) == 0) {
				p[j].d[k].point = mx_strdup(str1[0]);
				p[j].d[k].index_point = index_point(p, p[j].d[k].point, count);
				p[j].d[k++].dist = mx_atoi(str2[1]);
			}
			double_del_arr(str1, str2);
		}
	}
}

// static void mx_islands(char **WordsA, int count) {
// 	char **str1;
// 	char **str2;
// 	int j = 0;
// 	t_path *p;

// 	for(int i = 1; WordsA[i]; i++) {
// 		str1 = mx_strsplit(WordsA[i], '-');
// 		str2 = mx_strsplit(str1[1], ',');
// 		printf("-------------------------\n");
// 		if (new_island(str1[0], p, j)) {
// 			p = realloc(p, sizeof(p) * (j + 2));
// 			p[j].index_name = j;
// 			p[j++].name = mx_strdup(str1[0]);
// 		}
// 		if (new_island(str2[0], p, j)) {
// 			p = realloc(p, sizeof(p) * (j + 2));
// 			p[j].index_name = j;
// 			p[j++].name = mx_strdup(str2[0]);
// 		}
// 		double_del_arr(str1, str2);
// 	}
// 	// free(p);
// 	if (j != count)
// 	{
// 		printf("PREKL");
// 		exit(0);
// 	}
// }

static void mx_islands(t_path *p, char *fl, char **WordsA, int count) {
	char **str1;
	char **str2;
	int j = 0;

	for(int i = 1; WordsA[i]; i++) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		if (new_island(str1[0], p, j)) {
			p[j].index_name = j;
			p[j++].name = mx_strdup(str1[0]);
		}
		if (new_island(str2[0], p, j)) {
			p[j].index_name = j;
			p[j++].name = mx_strdup(str2[0]);
		}
		double_del_arr(str1, str2);
	}
}

static void print_island_struct(t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		printf("\n");
		printf("$******PRINT NEW ISLAND********$\n");
		printf("Name = %s ||| Index = %d ||| Count_distance = %d\n", 
			p[i].name, p[i].index_name, p[i].count_distance);
		for (int j = 0; j < p[i].count_distance; j++) {
			printf("point name = %s ||| index point = %d ||| distance = %d\n", 
				p[i].d[j].point, p[i].d[j].index_point, p[i].d[j].dist);
		}
		printf("$*********END ISLAND***********$\n\n");
	}
}

int main(int ac, char **av) {
	t_path *p;
	char *fl = mx_file_to_str(av[1]);
	char **WordsA = mx_strsplit(fl, '\n');
	int count = mx_atoi(fl);
	p = (t_path *)malloc(sizeof(t_path) * count);
	mx_islands(p, fl, WordsA, count);
	// mx_islands(WordsA, count);
	connect_count(p, fl, WordsA, count);
	print_island_struct(p, count);
	free(fl);
	mx_del_strarr(&WordsA);
	
	system("leaks -q a.out");
	return 0;
}
