#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	int i = 0;
	int count = 0;

	if (str == NULL || sub == NULL)
		return -1;
	while (str[i] != '\0') {
		if (str[i] == *sub)
			count++;
		i++;
	}
	return count;
}
