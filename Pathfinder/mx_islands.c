#include "inc/libmx.h"
#include <stdio.h>


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

	for (int k = 0; k < p[0].count_distance; k++) {
		road[0] = p[0].index_name;
		road[1] = p[0].d[k].index_point;
		road_dist[0] = p[0].d[k].dist;
		sum_dist = p[0].d[k].dist;
		if (k == 0)
			l = mx_create_list_res(road, road_dist, sum_dist, 2);
		else
			mx_push_back_res(&l, road, road_dist, sum_dist, 2);
	}
	return l;
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

t_lst_res *mx_al(t_path *p, t_lst_res *l, int count) {
	int *road;
	int *road_dist;
	int sum_dist;
	int len;
	bool active[count];
	int i;
	int c = 0;
	t_lst_res *res;
	int n = 0;

	for (int j = 0; j < count; j++) {
		active[j] = true;
	}
	active[0] = false;

	while (l) {
		mx_sort_list_res(l);
		i = l->road[l->len - 1];
	
		for (int k = 0; k < p[i].count_distance; k++) {
			if (active[p[i].d[k].index_point]) {
				road = (int *)malloc(sizeof(int) * (l->len + 1));
				road = mx_memcpy(road, l->road, l->len);
				road[l->len] = p[i].d[k].index_point;
				road_dist = (int *)malloc(sizeof(int) * (l->len));
				road_dist = mx_memcpy(road, l->road, l->len - 1);
				road[l->len - 1] = p[i].d[k].index_point;
				sum_dist = p[i].d[k].dist;
				if (c == 0) {
					l = mx_create_list_res(road, road_dist, sum_dist, l->len + 1);
				}
				else {
					mx_push_back_res(&l, road, road_dist, sum_dist, l->len + 1);
					printf("33333333333333333333\n");
				}
				free(road);
				free(road_dist);
				c++;
			}
		}
		if (l->len == 2 && n == 0) {
			res = mx_create_list_res(l->road, l->road_dist, l->sum_dist, l->len);
			n++;
		}
		else
			mx_push_back_res(&l, l->road, l->road_dist, l->sum_dist, l->len);
		mx_pop_elem_of_lst(l);
		mx_pop_front_res(&l);
		active[i] = false;
	mx_print_res(res);
	}
	return res;
}



//*********************************************************

static int index_point(t_path *p, char *point, int count) {
	int index_point = -1;
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(p[i].name, point) == 0) {
			index_point = p[i].index_name;
		}
	}
	return index_point;
}

static bool new_island(char *str, t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		if (mx_strcmp(str, p[i].name) == 0)
			return false;
	}
	return true;
}

static void connect_count(t_path *p, char *fl, char **WordsA, int count) {
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

//***********************ПРОВЕРКА_КОЛ-ВО_ВЕРШИН*****************************************

// t_valid *mx_create_node1(void *data, int j) {
//     t_valid *node = malloc(sizeof(t_valid));

//     if (!node)
//         return NULL;
//     node->name = data;
//     node->index_name = j;
//     node->next = NULL;
//     return node;
// }

// void mx_push_back1(t_valid **list, void *data, int i) {
//     t_valid *pl = *list;
//  	t_valid *node = mx_create_node1(data, i);

//     if (pl == NULL) {
//     	*list = node;
//         return ;
//     }
//     while (pl->next != NULL) {
//         pl = pl->next;
//     }
//     pl->next = node;
// }


// static void mx_islands_check(char **WordsA, int count) {
// 	char **str1;
// 	char **str2;
// 	t_valid *p;
// 	int j = 0;
// 	char *name;

// 	for(int i = 1; WordsA[i]; i++) {
// 		str1 = mx_strsplit(WordsA[i], '-');
// 		str2 = mx_strsplit(str1[1], ',');
// 		if (new_island(str1[0], p, j)) {
// 			name = mx_strdup(str1[0]);
// 			j++;
// 			if (j == 0)
// 				p = mx_create_node1(name, j);
// 			else
// 				mx_push_back1(&p, name, j);
// 		}
// 		if (new_island(str2[0], p, j)) {
// 			name = mx_strdup(str1[0]);
// 			j++;
// 			mx_push_back1(&p, name, j);
// 		}
// 		free(name);
// 		p = p->next;
// 		double_del_arr(str1, str2);
// 	}
// 	if (j != count) {
// 		mx_printerr("error: invalid number of islands\n");
// 		system("leaks -q a.out");
// 		exit(0);
// 	}
// }

//***************************************************************************************

static void mx_islands(t_path *p, char *fl, char **WordsA, int count) {
	char **str1;
	char **str2;
	int j = 0;

	for(int i = 1; WordsA[i]; i++) {
		str1 = mx_strsplit(WordsA[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		if (new_island(str1[0], p, j)) {
			p[j].index_name = j;
			p[j++].name = mx_strdup(str1[0]);
		}
		if (new_island(str2[0], p, j)) {
			p[j].index_name = j;
			p[j++].name = mx_strdup(str2[0]);
		}
		double_del_arr(str1, str2);
	}
}

static void print_island_struct(t_path *p, int count) {
	for (int i = 0; i < count; i++) {
		printf("\n");
		printf("$******PRINT NEW ISLAND********$\n");
		printf("Name = %s ||| Index = %d ||| Count_distance = %d\n", 
			p[i].name, p[i].index_name, p[i].count_distance);
		for (int j = 0; j < p[i].count_distance; j++) {
			printf("point name = %s ||| index point = %d ||| distance = %d\n", 
				p[i].d[j].point, p[i].d[j].index_point, p[i].d[j].dist);
		}
		printf("$*********END ISLAND***********$\n\n");
	}
}


int main(int ac, char **av) {
	t_path *p;
	char *fl = mx_file_to_str(av[1]);
	char **WordsA = mx_strsplit(fl, '\n');
	int count = mx_atoi(fl);
	p = (t_path *)malloc(sizeof(t_path) * count);
	// mx_islands_check(WordsA, count);
	mx_islands(p, fl, WordsA, count);
	connect_count(p, fl, WordsA, count);
	t_lst_res *l = first_itter(p);
	t_lst_res *res = mx_al(p, l, count);
	//print_island_struct(p, count);
	// mx_print_res(l);
	free(fl);
	mx_del_strarr(&WordsA);
	
	system("leaks -q a.out");
	return 0;
}
