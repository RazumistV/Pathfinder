#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	int i = n - 1;
	char *ms = (char *)s;

	while (i >= 0) {
		if (ms[i] == c)
			return ms + i;
		i--;
	}
	return NULL;
}
