#include "libmx.h"

void mx_printerr(char c) {
	write (2, &c, 1);
}
