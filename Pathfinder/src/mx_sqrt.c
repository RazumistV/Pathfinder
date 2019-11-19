#include "libmx.h"

int mx_sqrt(int x) {

	for (unsigned int i = 1; i * i <= (unsigned int)x; i++) {
		if (i * i == (unsigned int)x)
			return i;
	}
	return 0;
}
