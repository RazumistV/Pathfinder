#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	char *ms1 = (char *)s1;
	char *ms2 = (char *)s2;
	size_t i = 0;

	while (ms1[i] == ms2[i] && i < n && ms1[i] != '\0' && ms2[i] != '\0')
		i++;
	return ms1[i] - ms2[i];
}
