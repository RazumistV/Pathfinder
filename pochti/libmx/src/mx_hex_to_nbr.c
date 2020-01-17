#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	int len = 0;
	unsigned long num = 1;
	unsigned long res = 0;

	while (hex[len])
 		len++;
	for (int i = len - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			res += (hex[i] - 48) * num;
			num *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			res += (hex[i] - 55) * num;
			num *= 16;
		} 
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			res += (hex[i] - 87) * num;
			num *= 16;
		}
	}
	return res;
}
