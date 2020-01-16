#include "pathfinder.h"

static void mx_check(t_lst_res *lst);

t_lst_res *mx_sort_list_res(t_lst_res *lst) {
	bool sort = true;
	t_lst_res *head = lst;

	if (!lst)
		return NULL;
	while (sort == true) {
		sort = false;
		while (lst->next) {
			if (lst->sum_dist > lst->next->sum_dist) {
				mx_swap_res(lst);
				sort = true;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return lst;
}

t_lst_res *mx_sort_res1(t_lst_res *lst) {
	bool sort = false;
	t_lst_res *head = lst;

	if (!lst)
		return NULL;
	while (sort == false) {
		sort = true;
		while (lst->next) {
			if (lst->road[lst->len - 1] 
				> lst->next->road[lst->next->len - 1]) {
			mx_swap_res(lst);
				sort = false;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return lst;
}

t_lst_res *mx_sort_res2(t_lst_res *lst) {
	bool sort = false;
	t_lst_res *head = lst;

	if (!lst)
		return NULL;
	while (sort == false) {
		sort = true;
		while (lst->next) {
			if (lst->len - 1 > lst->next->len - 1) {
				mx_swap_res(lst);
				sort = 1;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return lst;
}


void mx_sort_res3(t_lst_res *lst) {
	int i = 0;
	int size = list_size_res(lst);
	t_lst_res *new = lst;

	if (i != size - 1)
		while (i < size) {
			mx_check(lst);
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}
}

static void mx_check(t_lst_res *lst) {
	int j = 0;

	if (lst->road[lst->len - 1]
		== lst->next->road[lst->next->len - 1]) {
		while (lst->road[j] == lst->next->road[j]) 
			j++;
		if (lst->road[j] > lst->next->road[j]) 
			mx_swap_res(lst);
	}
}

