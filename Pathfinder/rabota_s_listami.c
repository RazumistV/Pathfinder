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

void mx_push_back_res(t_lst_res **lst, int *road, int *road_dist, int sum_dist, int len) {
	t_lst_res *tmp = *lst;
	t_lst_res *node = mx_create_list_res(road, road_dist, sum_dist, len);

	if (tmp == NULL) {
		*lst = node;
		return ;
	}
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

void mx_pop_front_res(t_lst_res **lst) {
	if (lst == NULL || *lst == NULL)
		return ;
	t_lst_res *tmp = (*lst)->next;
	free((*lst)->road);
	free((*lst)->road_dist);
	free(*lst);
	*lst = tmp;
}

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



t_lst_res *mx_sort_list_res(t_lst_res *lst) {
	int sort = 1;
	t_lst_res *head = lst;

	if (!lst)
		return NULL;
	while (sort == 1) {
		sort = 0;
		while (lst->next) {
			if (lst->sum_dist > lst->next->sum_dist) {
				swap_intarr(&lst->road_dist, &lst->next->road_dist);
				swap_intarr(&lst->road, &lst->next->road);
				swap_int(&lst->sum_dist, &lst->next->sum_dist);
				swap_int(&lst->len, &lst->next->len);
				sort = 1;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return lst;
}

int find_itter(t_lst_res *lst) {
	t_lst_res *tmp = lst;
	t_lst_res *tmp2 = lst;

	for (int i = 0; tmp; tmp = tmp->next, i++)
		for (int j = 0; tmp2; tmp2 = tmp2->next, j++) {
			if (tmp->sum_dist > tmp2->sum_dist
				&& tmp->road[tmp->len - 1] == tmp2->road[tmp->len - 1])
				return i;
			if (tmp->sum_dist < tmp2->sum_dist
				&& tmp->road[tmp->len - 1] == tmp2->road[tmp->len - 1])
				return j;
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


void mx_pop_elem_of_lst(t_lst_res *lst) {
	t_lst_res *tmp = lst;
	int i = 0;
	t_lst_res *current;
	t_lst_res *next;

	while (find_itter(tmp) != -1) {
		if (find_itter(tmp) == 0)
			mx_pop_front_res(&tmp);
		if(find_itter(tmp) == tmp->len - 1)
			mx_pop_back_res(&tmp);
		else {
			while (i < find_itter(tmp) - 1) {
				tmp = tmp->next;
				i++;
			}
		
				printf("%d\n", tmp->sum_dist);
			current = tmp;
			next = tmp->next->next;
			free(tmp->next->road);
			free(tmp->next->road_dist);
			free(tmp->next);
			current->next = next;
		}
	}
}

t_lst_res *first_itter(t_path *p/* , int count*/) {
	t_lst_res *l;
	int road[2];
	int road_dist[1];
	int sum_dist;

	for (int k = 0; k < count_distance; k++) {
		road[0] = p[0].index_name;
		road[1] = p[0].d[k].index_point;
		road_dist[0] = p[0].d[k].dist;
		sum_dist = p[0].d[k].dist;
		if (k == 0)
			l = mx_create_list_res(*road, *road_dist, sum_dist, 2);
		else
			mx_push_back_res(&p[0], *road, *road_dist, sum_dist, 2);
	//road_dist = p[0].d.dist
	}
}


void mx_print_res(t_lst_res *res) {
	t_lst_res *tmp = res;

	while (tmp) {
	printf("*************************************\n");
		printf("ROAD = ");
		for (int i = 0; i < tmp->len; i++) {
			printf("%d, ", tmp->road[i]);
		}
		printf("\n");
		printf("ROAD_DIST = ");
		for (int i = 0; i < tmp->len - 1; i++) {
			printf("%d, ", tmp->road_dist[i]);
		}
		printf("\n");
		printf("DIST = %d\n", tmp->sum_dist);
		tmp = tmp->next;
	printf("*************************************\n");
	}
}

// int main() {
// 	int *road = (int *)malloc(sizeof(int) * 3);
// 	int *road_dist = (int *)malloc(sizeof(int) * 3);
// 	int k = 1;
// 	for (int i = 0; i < 3; i++) {
// 		road[i] = k;
// 		k++;
// 	}
// 	//printf("============\n");
// 	for (int j = 0; j < 2; j++){
// 		road_dist[j] = k;
// 		k++;
// 	}
// 	t_lst_res *res = mx_create_list_res(road, road_dist, 4, 3);
// 	mx_push_back_res(&res, road, road_dist, 4, 3);
// 	mx_push_back_res(&res, road, road_dist, 5, 3);
// 	//mx_pop_front_res(&res);
// 	//mx_sort_list_res(res);
// 	mx_pop_elem_of_lst(res);
// 	mx_print_res(res);


// }









