#include "libmx.h"

void *mx_memmove(void *dest, const void *src, size_t n) {
    unsigned char temp[n];
    
    mx_memcpy(temp,src,n);
    mx_memcpy(dest,temp,n);
    return dest;
}
