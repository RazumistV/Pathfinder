#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	unsigned char *sm = (unsigned char*)s;
	
	while (n--) {
		if (*sm != (unsigned char)c)
			sm++;
		else
			return sm;
	}
	return 0;
}
