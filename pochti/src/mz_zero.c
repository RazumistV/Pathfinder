#include "pathfinder.h"

void mx_zero(char *s) {
	for (int i = 0; s[i] != '\0' ; i++) {
		if (s[i] == '0' && s[i + 1] == '\0')
			exit(0);
	}
}
