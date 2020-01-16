#include "pathfinder.h"

static void main_start(char *fl, char **WordsA, int count);

void mx_parse_apex_dist(t_path *p, char **WordsA, char *fl, int count) {
	mx_islands(p, WordsA, count);
	mx_connect_count(p, fl, WordsA, count);
	mx_del_strarr(&WordsA);
	free(fl);
}

int main(int ac, char **av) {
	if (mx_print_errors2(ac, av[1])) {
		char *fl = mx_file_to_str(av[1]);
		char **WordsA = mx_strsplit(fl, '\n');
		int count = mx_atoi(fl);

		main_start(fl, WordsA, count);
	system("leaks -q pathfinder");
	}
	return 0;
}

static void main_start(char *fl, char **WordsA, int count) {
	mx_print_errors(fl, WordsA);
	if (count == 0)
		mx_invalid_apex();
	t_lst_res **l = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
	t_lst_res **res = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
	t_path *p = (t_path *)malloc(sizeof(t_path) * count);

	mx_parse_apex_dist(p, WordsA, fl, count);
	mx_vivod_sort_lst(l, res, p, count);
	free(res);
	free(l);
	free(p);
}
