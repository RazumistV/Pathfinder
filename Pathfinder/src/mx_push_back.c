#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = *list;

    if (*list == NULL) {
        return;
    }
    while (node->next) {
        node = node->next;
    }
    node->next = mx_create_node(data);
}
