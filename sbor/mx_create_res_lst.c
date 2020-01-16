#include "inc/libmx.h"


t_lst_res *mx_create_list_res(int *road, int *road_dist, int sum_dist, int len) {
	t_lst_res *node = malloc(sizeof(t_lst_res));

	if (!node)
		return NULL;
	node->road = (int *)malloc(sizeof(int) * len);
	node->road_dist = (int *)malloc(sizeof(int) * len - 1);
	node->road = mx_memcpy(node->road, road, sizeof(int) * len);
	node->road_dist = mx_memcpy(node->road_dist, road_dist, sizeof(int) * (len - 1));
	node->sum_dist = sum_dist;
	node->len = len;
	node->next = NULL;
	return node;
}

void mx_push_back_res(t_lst_res **list, int *road, int count
	, int *road_dist, int dist) {
	if (list) {
		t_lst_res *new = mx_create_list_res(road, road_dist, dist, count);

		if (*list) { 
			t_lst_res *current = *list;

			while(current->next != NULL) {
				current = current->next;
			}
			current->next = new;
		}
		else 
			*list = new;
	}
}

void mx_pop_front_res(t_lst_res **lst) {
	t_lst_res *current = NULL;

	if (lst && *lst) {
		current = (*lst)->next;
		free((*lst)->road);
		free((*lst)->road_dist);
		free(*lst);
		*lst = current;
	}
}

int list_size_res(t_lst_res *list) {
	int c = 0;
	t_lst_res *temp = list;

	if (!list) 
		return 0;

	while (temp) {
		c++;
		temp = temp->next;
	}
    return c;
}
