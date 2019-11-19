#include "libmx.h"

void mx_str_reverse(char *s) {

	int i = 0;
	while ( i < mx_strlen(s) / 2) {
		mx_swap_char(&s[i], &s[mx_strlen(s) - i - 1]);
		i++;
	}
}

