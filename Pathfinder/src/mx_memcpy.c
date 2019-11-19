#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {

	size_t i = 0;
	char *msrc = (char *)src;
	char *mdst = (char *)dst;

	while(i < n) {
		mdst[i] = msrc[i];
		i++;
	}
	return mdst;
}
