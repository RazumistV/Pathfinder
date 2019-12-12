#include "inc/libmx.h"
#include <stdio.h>

static void double_del_arr(char **str1, char **str2) {
	mx_del_strarr(&str1);
	mx_del_strarr(&str2);
}

static bool new_island(char *str, t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(str, p[i].name) == 0)
			return false;
	}
	return true;
}


void mx_islands(t_path *p, char *fl, int count) {
	char **WordsA = mx_strsplit(fl, '\n');
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
	mx_del_strarr(&WordsA);
}

static void routes_count(t_path *p, char *fl, int count) {
	char **WordsA = mx_strsplit(fl, '\n');
	char **str1;
	char **str2;

	for(int i = 1; WordsA[i]; i++) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		for(int j = 0; j < 7; j++) {
			p[i].d[j].distance = mx_atoi(str2[1]);
		}
	}
}

// static int mx_str_count(char *file) {
// 	char *str = mx_file_to_str(file);
// 	int j = 0;

// 	for (int i = 0; str[i]; i++) {
// 		if (str[i] == '\n')
// 			j++;
// 	}
// 	free(str);
// 	return j;
// }


void print_island_struct(t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		printf("\n");
		printf("$******PRINT NEW ISLAND********$\n");
		printf("Name = %s\nIndex = %d\n", p[i].name, p[i].index_name);
		// for (int j = 0; j < 10; j++) {
		// 	printf("distance = %d\n", p[i].d[j].distance);
		// }
		//****************************************
		// for (int j = 0; j < p[i].routes_count; j++) {
		// 	printf("point name = %s, index point = %d, distance = %d\n", p[i].d[j].point, p[i].d[j].index_point, p[i].d[j].dist);
		// }
		printf("$*********END ISLAND***********$\n\n");
	}
}

int main(int ac, char **av) {
	t_path *p;
	char *fl = mx_file_to_str(av[1]);
	int count = mx_atoi(fl);
	p = (t_path *)malloc(sizeof(t_path) * count);
	printf("struct count \\n = %d\n", count);
	mx_islands(p, fl, count);
	print_island_struct(p, count);
	free(fl);
	
	system("leaks -q a.out");
	return 0;
}
