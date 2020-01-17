#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {

	while(*haystack) {
		if (*haystack == *needle) {
			if (mx_strlen(needle) == 0)
				mx_strncmp(haystack, needle, mx_strlen(needle));
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}
