#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	char *s;

	if (s1 == NULL && s2 == NULL)
		return NULL;
	else if (s1 == NULL)
		return mx_strcpy(mx_strnew(mx_strlen(s2)), s2);
	else if (s2 == NULL)
		return mx_strcpy(mx_strnew(mx_strlen(s1)), s1);
	else {
		s = mx_strcpy(mx_strnew(mx_strlen(s1) + mx_strlen(s2)), s1);
		s = mx_strcat(s, s2);
	}
	return s;
}
