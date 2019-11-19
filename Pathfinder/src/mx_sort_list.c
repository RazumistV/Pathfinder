#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst)
        return NULL;
    void *tmp;

    for (t_list *i = lst; i->next; i = i->next)
        for (t_list *j = lst; j->next; j = j->next)
            if (cmp(j->data, j->next->data)) {
                tmp = j->next->data;
                j->next->data = j->data;
                j->data = tmp;
            }
    return lst;
}
