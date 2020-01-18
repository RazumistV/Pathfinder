#include "pathfinder.h"

static bool mx_map(char *s);

void mx_zero(char *s) {
	if (s[0] == '0' && !(mx_map(s)))
		exit(0);
}

static bool mx_map(char *s) {
	for (int i = 0; s[i]; i++) {
		if (s[i] != '0' && !(is_whitespace(s[i])))
			return true;
	}
	return false;
}
