#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *res = NULL;
    size_t len = mx_strlen(s1);

    if (n < len) {
        len = n;
    }
    res = mx_strnew((int)len);
    return mx_strncpy(res, s1, len);
}
