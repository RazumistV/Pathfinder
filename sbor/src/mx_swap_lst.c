#include "pathfinder.h"

void swap_int(int *lst1, int *lst2) {
	int tmp;

	tmp = *lst1;
	*lst1 = *lst2;
	*lst2 = tmp;
}
void swap_intarr(int **lst1, int **lst2) {
	int *tmp;

	tmp = *lst1;
	*lst1 = *lst2;
	*lst2 = tmp;
}

void mx_swap_res(t_lst_res *lst) {
	swap_int(&(lst->sum_dist), &(lst->next->sum_dist));
	swap_int(&(lst->len), &(lst->next->len));
	swap_intarr(&(lst->road_dist), &(lst->next->road_dist));
	swap_intarr(&(lst->road), &(lst->next->road));
}
