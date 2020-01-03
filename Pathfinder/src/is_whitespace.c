#include "libmx.h"

bool is_whitespace(char c) {
	if (c == '\n' || c == '\t' || c == '\v' || c == '\r' ||
		c == '\r' || c == '\f' || c == ' ')
		return true;
	else
		return false;

}
