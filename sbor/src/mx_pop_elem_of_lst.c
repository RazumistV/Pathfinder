#include "pathfinder.h"

int find_itter(t_lst_res *lst) {
	int i = 0;

	if (!lst)
		return -1;
	for (t_lst_res *tmp = lst; tmp ; tmp = tmp->next) {
		i = 0;
		for (t_lst_res *tmp2 = lst; tmp2; tmp2 = tmp2->next) {
			if (tmp2->sum_dist > tmp->sum_dist &&
				tmp->road[tmp->len - 1] == tmp2->road[tmp2->len - 1])
				return i;
			i++;
		}
	}
	return -1;
}

void mx_pop_back_res(t_lst_res **lst) {
	t_lst_res *tmp = NULL;
	t_lst_res *last = NULL;

	if ((*lst)->next == NULL) {
		free((*lst)->road);
		free((*lst)->road_dist);
		free(*lst);
		(*lst) = NULL;
	}
	else {
		tmp = (*lst);
		last = (*lst)->next;
		while (last->next != NULL) {
			tmp = last;
			last = last->next; 
		}
		free(last->road);
		free(last->road_dist);
		free(last);
		tmp->next = NULL;
	}
}

void del_el_list(t_lst_res *tmp) {
	free(tmp->road);
	free(tmp->road_dist);
	free(tmp);
}

void mx_pop_elem_of_lst(t_lst_res *lst) {
	if (lst) {
		t_lst_res *tmp = lst;
		t_lst_res *current;

		while (find_itter(lst) != -1) {
			tmp = lst;
			if (find_itter(lst) == 0)
				mx_pop_front_res(&lst);
			else if (find_itter(lst) == list_size_res(lst) - 1)
				mx_pop_back_res(&lst);
			else {
				for (int i = 0; i < find_itter(lst); i++) {
					current = tmp;
					tmp = tmp->next;
				}
				current->next = tmp->next;
				del_el_list(tmp);
			}
		}
	}
}
