#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	size_t i = 0;
	char *mdst = (char *)dst;
	char *msrc = (char *)src;

	if (mx_strlen(msrc) == 1)
		return NULL;
	
	while (i < n && msrc[i] <= c) {
		mdst[i] = msrc[i];
		i++;
	}
	return dst;
}
