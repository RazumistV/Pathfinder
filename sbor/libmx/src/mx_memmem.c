#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	if (little_len <= big_len && big_len > 0 && little_len > 0) {
		unsigned char *b = (unsigned char *)big;
		unsigned char *l = (unsigned char *)little;

		while(*b) {
			if (mx_memcmp(b, l, little_len) == 0)
				return b;	
			b++;
		}
	}
	return NULL;
}
