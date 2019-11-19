#include "libmx.h"

char *mx_strdup(const char *str) {
	char *dup;
	
	dup = mx_strnew(mx_strlen(str));
	if (str == NULL)
		return NULL;

	if (dup == NULL)
		return NULL;
	dup = mx_strcpy(dup, str);
	
	return dup;
}
