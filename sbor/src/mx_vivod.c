#include "pathfinder.h"

static void print_routes(t_lst_res *lst, t_path *p);
static void print_routes_distance(t_lst_res *lst);

void mx_vivod(t_lst_res *lst, t_path *p) {
	char *tmp;

	while (lst) {
		mx_printstr(RAVNO);
		mx_printstr("Path: ");
		mx_printstr(p[lst->road[0]].name);
		mx_printstr(" -> ");
		mx_printstr(p[lst->road[lst->len - 1]].name);
		mx_printchar('\n');
		print_routes(lst, p);
		// mx_printchar('\n');
		print_routes_distance(lst);
		tmp = mx_itoa(lst->sum_dist);
		mx_printstr(tmp);
		free(tmp);
		mx_printchar('\n');
		mx_printstr(RAVNO);
		lst = lst->next;
	}
}

void mx_vivod_sort_lst(t_lst_res **l, t_lst_res **res, t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		l[i] = first_itter(p, i);
		res[i] = mx_al(p, l[i], count, i);
		mx_sort_res2(res[i]);
		mx_sort_res1(res[i]);
		mx_sort_res3(res[i]);
		mx_vivod(res[i], p);
	}
}

static void print_routes(t_lst_res *lst, t_path *p) {
	mx_printstr("Route: ");
		for (int i = 0; i < lst->len; i++) {
			mx_printstr(p[lst->road[i]].name);
			if (i != lst->len - 1)
				mx_printstr(" -> ");
		}
		mx_printchar('\n');
}

static void print_routes_distance(t_lst_res *lst) {
	mx_printstr("Distance: ");	
	char *tmp;
	
	if (lst->len - 1 != 1) {
		for (int i = 0; i < lst->len - 1; i++) {
			tmp = mx_itoa(lst->road_dist[i]);
			mx_printstr(tmp);
			free(tmp);
			if (i != lst->len - 2)
				mx_printstr(" + ");
		}
		mx_printstr(" = ");
	}
}
