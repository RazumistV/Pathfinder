#include "inc/libmx.h"
//#include <stdio.h>


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
	// if ()
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
	int i = 0;

	for (t_lst_res *tmp = lst; tmp ; tmp = tmp->next, i++) {
		for (t_lst_res *tmp2 = lst; tmp2; tmp2 = tmp2->next) {
			if (tmp->sum_dist > tmp2->sum_dist &&
				tmp->road[tmp->len - 1] == tmp2->road[tmp2->len - 1])
				return i;
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

void del_el_list(t_lst_res *tmp) {
	free(tmp->road);
	free(tmp->road_dist);
	free(tmp);
}

void mx_pop_elem_of_list(t_lst_res *lst) {
 if (lst) {
  t_lst_res *tmp = lst;
  t_lst_res *prv;

  while (find_itter(lst) != -1) {
   tmp = lst;
   if (find_itter(lst) == 0)
    mx_pop_front_res(&lst);
   else if (find_itter(lst) == list_size_res(lst) - 1)
    mx_pop_back_res(&lst);
   else {
    for (int i = 0; i < find_itter(lst); i++) {
     prv = tmp; 
            tmp = tmp->next; 
    }
    prv->next = tmp->next; 
    del_el_list(tmp);
   }
  }
 }
}

void mx_pop_elem_of_lst(t_lst_res *lst) {
	if (lst) {
	t_lst_res *tmp = lst;
	t_lst_res *current;
	t_lst_res *next;
	while (find_itter(lst) != -1) {
		tmp = lst;
		//printf("_____________________________________________________\n\n");
		if (find_itter(lst) == 0) {
		//	printf("###################################################################\n\n");
			mx_pop_front_res(&lst);
		}
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
		printf("LEN = %d\n", tmp->len);
		printf("\n");
		tmp = tmp->next;
	printf("*************************************\n");
	}
}

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
			mx_push_back_res(&l, road, road_dist, sum_dist, 2);
			
	}
	return l;
}


//*****************************************************************************************************



t_lst_res *mx_al(t_path *p, t_lst_res *l, int count, int z) {
	int *road;
	int *road_dist;
	int sum_dist;
	bool active[count];
	int i;
	t_lst_res *res = NULL;
	int n = 0;

	for (int j = 0; j < count; j++) {
		active[j] = true;
	}
	active[z] = false;

	while (l) {
		mx_sort_list_res(l);
		i = l->road[l->len - 1];
		for (int k = 0; k < p[i].count_distance; k++) {
			//printf("count_distance = %d\n", p[i].count_distance);
			if (active[p[i].d[k].index_point]) {
				//printf("len = %d\n", l->len);
				// printf("************** LST-ROAD *****************\n");
				// for (int i = 0; i < l->len; i++) {
				// 	printf("%d ,", l->road[i]);
				// }
				// printf("\n");
				// printf("\n");
				// printf("************** LST-ROAD_DIST *****************\n");
				// for (int i = 0; i < l->len - 1; i++) {
				// 	printf("%d ,", l->road_dist[i]);
				// }
				// printf("\n");
				// printf("\n");
				road = (int *)malloc(sizeof(int) * (l->len + 1));
				road = mx_memcpy(road, l->road, sizeof(int) * l->len);
				road[l->len] = p[i].d[k].index_point;
				road_dist = (int *)malloc(sizeof(int) * (l->len));
				road_dist = mx_memcpy(road_dist, l->road_dist, sizeof(int) * (l->len - 1));
				road_dist[l->len - 1] = p[i].d[k].dist;
				sum_dist = p[i].d[k].dist + l->sum_dist;
				// printf("==================== ROAD ===================\n");
				// for (int i = 0; i < l->len + 1; i++) {
				// 	printf("%d ,", road[i]);
				// }
				// printf("\n");
				// printf("\n");
				// printf("===================== ROAD_DIST =======================\n");
				// for (int i = 0; i < l->len; i++) {
				// 	printf("%d ,", road_dist[i]);
				// }
				// printf("\n");
				// printf("\n");
				mx_push_back_res(&l, road, road_dist, sum_dist, l->len + 1);
				free(road);
				free(road_dist);
			}
		}
		if (n == 0 && l->road[l->len - 1] > l->road[0]) {
			res = mx_create_list_res(l->road, l->road_dist, l->sum_dist, l->len);
			n++;
		}
		else if (l->road[l->len - 1] > l->road[0])
			mx_push_back_res(&res, l->road, l->road_dist, l->sum_dist, l->len);
		//mx_print_res(l);
		//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		mx_pop_elem_of_list(l);
		mx_pop_front_res(&l);
		//mx_print_res(l);
		//printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		active[i] = false;
		// printf("%s\n", "PREKL");
		//printf("===========================================================================================\n");

		//mx_print_res(res);
		//printf("===========================================================================================\n");
	}
	if (res == NULL) {
		mx_memset(res, 0, sizeof(t_lst_res));
	}
	return res;
}


t_lst_res *mx_sort_res1(t_lst_res *lst) {
	bool sort = false;
	t_lst_res *head = lst;

	if (!lst)
		return NULL;
	while (sort == false) {
		sort = true;
		while (lst->next) {
			if (lst->road[lst->len - 1] > lst->next->road[lst->next->len - 1]) {
				swap_intarr(&lst->road_dist, &lst->next->road_dist);
				swap_intarr(&lst->road, &lst->next->road);
				swap_int(&lst->sum_dist, &lst->next->sum_dist);
				swap_int(&lst->len, &lst->next->len);
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


t_lst_res *mx_sort_res3(t_lst_res *lst) {
	// bool sort = false;
	// t_lst_res *head = lst;

	// if (!lst)
	// 	return NULL;
	// while (sort == false) {
	// 	sort = true;
	int i = 0;
	int size = list_size_res(lst);
	t_lst_res *new = lst;

	if (i != size - 1)
		while (i < size) {
			if (lst->road[0] == lst->next->road[0] 
				&& lst->road[lst->len - 1] == lst->next->road[lst->next->len - 1]) {
				while (lst->road[i] == lst->next->road[i])
					i++;
				if (lst->road[i] > lst->next->road[i]) {
					swap_intarr(&lst->road_dist, &lst->next->road_dist);
					swap_intarr(&lst->road, &lst->next->road);
					swap_int(&lst->sum_dist, &lst->next->sum_dist);
					swap_int(&lst->len, &lst->next->len);
				}
			}
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}

	return lst;
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

void mx_vivod(t_lst_res *lst, t_path *p, int count) {
	while (lst) {
		mx_printstr(RAVNO);
		mx_printstr("Path: ");
		mx_printstr(p[lst->road[0]].name);
		mx_printstr(" -> ");
		mx_printstr(p[lst->road[lst->len - 1]].name);
		mx_printchar('\n');
		mx_printstr("Route: ");
		for (int i = 0; i < lst->len; i++) {
			mx_printstr(p[lst->road[i]].name);
			if (i != lst->len - 1)
				mx_printstr(" -> ");
		}
		mx_printchar('\n');
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
		tmp = mx_itoa(lst->sum_dist);
		mx_printstr(tmp);
		free(tmp);
		mx_printchar('\n');
		mx_printstr(RAVNO);
		lst = lst->next;
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
	t_lst_res **l = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
	t_lst_res **res = (t_lst_res **)malloc(sizeof(t_lst_res *) * count);
	for (int i = 0; i < count; i++) {
	
		l[i] = first_itter(p, i);
	// printf("*************** I = %d ********************\n", i);
		res[i] = mx_al(p, l[i], count, i);
		mx_sort_res2(res[i]);
		mx_sort_res1(res[i]);
		mx_sort_res3(res[i]);
		 //mx_print_res(res[i]);
		mx_vivod(res[i], p, count);
	}
	// print_island_struct(p, count);
	free(fl);
	mx_del_strarr(&WordsA);
	// for (int i = 0; i < count; i++) {
	// 	mx_vivod(res[i], p, count);
	// }
	// system("leaks -q a.out");
	return 0;
}
