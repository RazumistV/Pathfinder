#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *tmp = NULL;
	t_list *last = NULL;

	if ((*head)->next == NULL) {
 		free(*head);
 		(*head) = NULL;
 	}
	else { 
		tmp = (*head);
		last = (*head)->next;
		while (last->next != NULL) {
			tmp = last;
			last = last->next; 
		}
		free(last);
		tmp->next = NULL;
	}
}
