#include "libmx.h"

int mx_list_size(t_list *list) {
	int c = 1;
	t_list *temp = list;

	if (!list) 
		return 0;

	while (temp->next) {
		c++;
		temp = temp->next;
	}
    return c;
}
