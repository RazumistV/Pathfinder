#include "libmx.h"

 void *mx_memset(void *b, int c, size_t len) {
 	unsigned char *p = b;

 	if (p == 0)
 		return 0;
 	while (len > 0) {
 		*p = c;
 		p++;
 		len--;
 	}
 	return b;
 }
