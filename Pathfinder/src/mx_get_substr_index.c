#include "libmx.h"

int mx_strlen(const char *s);

int mx_get_substr_index(const char *str, const char *sub) {
	int i = 0;
	int j = 0;

	if (str == NULL || sub == NULL)
		return -2;
	while (str[i] != '\0') {
		j = 0;

		if (str[i] == sub[0]) {
			while (str[i + j] == sub[j])
				j++;
			if (j == mx_strlen(sub))
				return i;
		}

		i++;
	}

	return -1;
}
