#include "pathfinder.h"

void mx_parse_apex_dist(t_path *p, char **WordsA, char *fl, int count) {
	mx_islands(p, WordsA, count);
	mx_connect_count(p, fl, WordsA, count);
	free(fl);
	mx_del_strarr(&WordsA);
}

int main(int ac, char **av) {
	if (mx_print_errors2(ac, av[1])) {
		char *fl = mx_file_to_str(av[1]);
		char **WordsA = mx_strsplit(fl, '\n');
		int count = mx_atoi(fl);

		mx_print_errors(fl, WordsA);
		if (count == 0)
			mx_invalid_apex();
		t_lst_res **l = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
		t_lst_res **res = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
		t_path *p = (t_path *)malloc(sizeof(t_path) * count);

		mx_parse_apex_dist(p, WordsA, fl, count);
		for (int i = 0; i < count; i++) {
			l[i] = first_itter(p, i);
			res[i] = mx_al(p, l[i], count, i);
		}
		mx_vivod_sort_lst(res, p, count);
	}
	return 0;
}
