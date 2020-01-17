#include "libmx.h"

int mx_count_words(const char *str, char c) {
	int i = 0;
	int j = 0;

	if (str == NULL)
		return - 1;
	while (str[i] == c)
		i++;
	while (str[i + 1] != '\0') {
		if (str[i] == c && str[i + 1] != c)
			j++;
		i++;
	}
	if (j >= 0)
		return j + 1;
	return 0;
}
