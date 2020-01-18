#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define ERROR_USAGE "usage: ./pathfinder [filename]\n"
#define FILE_EXIST "error: file "
#define FILE_EXIST2 " does not exist\n"
#define EMPTY_FILE "error: file "
#define EMPTY_FILE2 " is empty\n"
#define LINE_ERROR "error: line " 
#define LINE_ERROR2 " is not valid\n"
#define LINE_VALUE "error: line "
#define LINE_VALUE2 " is not valid\n"
#define INVALID_ISLANDS "error: invalid number of islands\n"
#define RAVNO "========================================\n"


typedef struct s_dist {
	char *point;
	int index_point;
	int dist;
}				t_dist;

typedef struct 	s_path {
    char *name;
    int index_name;
    int count_distance;
	struct s_dist *d;
}				t_path;

typedef struct s_lst_res {
	int *road;
	int *road_dist;
	int sum_dist;
	int len;
	struct s_lst_res *next;
} t_lst_res;

t_lst_res	*mx_al(t_path *p, t_lst_res *l
			, int count, int itter);
t_lst_res 	*mx_sort_list_res(t_lst_res *lst);
t_lst_res	*mx_create_list_res(int *road, int *road_dist
			, int sum_dist, int len);
t_lst_res 	*mx_sort_res1(t_lst_res *lst);
t_lst_res 	*mx_sort_res2(t_lst_res *lst);
t_lst_res 	*first_itter(t_path *p , int count );
void		mx_create_active_list(t_lst_res *l, t_path p
			, bool *ative);
void		mx_connect_count(t_path *p, char *fl, char **WordsA
			, int count);
void		mx_push_back_res(t_lst_res **list, int *road, int count
			, int *road_dist, int dist);
void 		mx_pop_front_res(t_lst_res **lst);
void 		mx_invalid_apex();
void 		apex_count(char **WordsA);
void 		mx_print_inval(char *n);
void 		mx_apex_repeat(char **str);
void 		mx_apex_ne_char(char **str);
void 		mx_b_slash_n(char *fl);
void 		mx_islands(t_path *p, char **WordsA, int count);
void 		mx_pop_back_res(t_lst_res **lst);
void		del_el_list(t_lst_res *tmp);
void 		mx_pop_elem_of_lst(t_lst_res *lst);
void 		mx_sort_res3(t_lst_res *lst);
void 		mx_print_errors(char *av, char **WordsA);
void 		mx_vivod(t_lst_res *lst, t_path *p);
void 		mx_vivod_sort_lst(t_lst_res **res
			, t_path *p, int count);
void 		swap_int(int *lst1, int *lst2);
void 		swap_intarr(int **lst1, int **lst2);
void 		mx_swap_res(t_lst_res *lst);
void 		valid_island(char **WordsA);
void 		print_routes(t_lst_res *lst, t_path *p);
void 		mx_is_folder(char *file);
void 		print_routes_distance(t_lst_res *lst);
void 		mx_zero(char *s);
void 		mx_is_not_exist(char *file);
bool 		str_is_digit(char *str);
bool 		mx_print_errors2(int ac, char *av);
int 		list_size_res(t_lst_res *list);
int 		find_itter(t_lst_res *lst);
int 		mx_char_count(char *str, char c);


#endif
