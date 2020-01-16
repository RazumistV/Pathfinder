#include "pathfinder.h"

static int index_point(t_path *p, char *point, int count);

void mx_connect_count(t_path *p, char *fl, char **WordsA, int count) {
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

static int index_point(t_path *p, char *point, int count) {
	int index_point = -1;
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(p[i].name, point) == 0) {
			index_point = p[i].index_name;
		}
	}
	return index_point;
}
