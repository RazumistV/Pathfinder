#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
	char *del;
	int i = 0;
	int j = 0;
	int space = 0;
	char *arr;

	if (str_is_null((char *)str))
		return NULL;
	del = mx_strtrim(str);
	while (del[i] != '\0') {
		if (!is_whitespace(del[i]))
			j++;
		if (!is_whitespace(del[i + 1]) && is_whitespace(del[i]))
			space++;
		i++;
	}
		arr = mx_strnew(j + space);
		i = 0;
		j = 0;

		while (del[j]) {
			if (is_whitespace(del[j]) && !is_whitespace(del[j + 1])) {
				arr[i] = ' ';
				i++;
			}
			else if (!is_whitespace(del[j])) {
				arr[i] = del[j];
				i++;
			}
			j++;
		}
		free(del);
		return arr;
}
