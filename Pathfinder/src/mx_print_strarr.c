#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int i = 0;

	if (arr == NULL || str_is_null((char *)delim))
		return ;


	while (arr[i]) {
		mx_printstr(arr[i]);
		if (arr[i + 1] != NULL)
			mx_printstr(delim);
		i++;
	}
	mx_printchar('\n');
}
