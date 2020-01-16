#include "pathfinder.h"

static bool new_island(char *str, t_path *p, int count);
static void add_island(char *str, t_path *p, int *j);

void mx_islands(t_path *p, char **WordsA, int count) {
	char **str1;
	char **str2;
	int j = 0;

	for(int i = 1; WordsA[i]; i++) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		if (j == count && new_island(str1[0], p, j))
			mx_invalid_apex();
		if (new_island(str1[0], p, j))
			add_island(str1[0], &p[j], &j);
		if(j == count && new_island(str2[0], p, j))
			mx_invalid_apex();
		if (new_island(str2[0], p, j))
			add_island(str2[0], &p[j], &j);
		double_del_arr(str1, str2);
	}
	if (count != j)
		mx_invalid_apex();
}

static bool new_island(char *str, t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(str, p[i].name) == 0)
			return false;
	}
	return true;
}

static void add_island(char *str, t_path *p, int *j) {
	p->index_name = *j;
	p->name = mx_strdup(str);
	(*j)++;
}
