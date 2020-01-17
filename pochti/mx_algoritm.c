#include "pathfinder.h"

static void init(bool *active, int count, int itter);

t_lst_res *first_itter(t_path *p , int count ) {
	t_lst_res *l;
	int road[2];
	int road_dist[1];
	int sum_dist;

	for (int k = 0; k < p[count].count_distance; k++) {
		road[0] = p[count].index_name;
		road[1] = p[count].d[k].index_point;
		road_dist[0] = p[count].d[k].dist;
		sum_dist = p[count].d[k].dist;
		if (k == 0) {
			l = mx_create_list_res(road, road_dist, sum_dist, 2);
		}
		else
			mx_push_back_res(&l, road, 2, road_dist, sum_dist);
	}
	return l;
}

void mx_create_active_list(t_lst_res *l, t_path p, bool *ative) {
	for (int k = 0; k < p.count_distance; k++) {
		if (active[p.d[k].index_point]) {
			int road = (int *)malloc(sizeof(int) * (l->len + 1));
			int road_dist = (int *)malloc(sizeof(int) * (l->len));
			int sum_dist = p.d[k].dist + l->sum_dist;
			
			road = mx_memcpy(road, l->road, sizeof(int) * (l->len));
			road[l->len] = p.d[k].index_point;
			road_dist = mx_memcpy(road_dist, l->road_dist
				, sizeof(int) * (l->len - 1));
			road_dist[l->len - 1] = p.d[k].dist;
			mx_push_back_res(&l, road, l->len + 1, road_dist, sum_dist);
			free(road);
			free(road_dist);
		}
	}
}

t_lst_res *mx_al(t_path *p, t_lst_res *l, int count, int itter) {
	bool active[count];
	int i;
	t_lst_res *res = NULL;
	
	init(acive, count, itter);
	for (int n = 0, l, n++) {
		l = mx_sort_list_res(l);
		i = l->road[l->len - 1];
		mx_create_active_list(l, p[i], active);
		if (l->len == 2 && n == 0 && l->road[l->len - 1] > l->road[0])
			res = mx_create_list_res(l->road, l->road_dist, l->sum_dist, l->len);
		else if (l->road[l->len - 1] > l->road[0])
			mx_push_back_res(&res, l->road, l->len, l->road_dist, l->sum_dist);
		mx_pop_elem_of_lst(l);
		mx_pop_front_res(&l);
		active[i] = false;
	}
	if (res == NULL)
		mx_memset(res, 0, sizeof(t_lst_res));
	return res;
}

static void init(bool *active, int count, int itter) {
	for (int j = 0; j < count; j++)
		active[j] = true;
	active[itter] = false;
}