#include "libmx.h"

char *mx_strtrim(const char *str) {
	int i = 0;
	int j = 0;
	int len = mx_strlen(str) - 1;
	char *s;

	if (str == NULL)
		return NULL;
	while (is_whitespace(str[i]) && str[i]) 
		i++;
	while (len > 0 && is_whitespace(str[len]))
		len--;
	s = mx_strnew(len - i);

	while (i <= len) {
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';

	return s;
}
