#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	size_t len;
	void *new;
	if (size <= 0 && ptr) {
		free(ptr);
		return NULL;
	}
	if (!ptr && size != 0)
		return malloc(size);
	len = malloc_size(ptr);

	if (len > size) {
		new = malloc(len);
		size = len;
	}
	
	else
		new = malloc(size);
	new = mx_memmove(new, ptr, size);
	free(ptr);
	return new;
}
