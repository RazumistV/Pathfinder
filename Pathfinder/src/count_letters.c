#include "libmx.h"

int count_letters(const char *s, char c) {
	int i = 0;
	int count = 0;
	
	while (s[i] != c && s[i]) {
        count++;
		i++;
	}

	return count;
}
