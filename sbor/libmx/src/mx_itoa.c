#include "libmx.h"

char *mx_itoa(int number) {
	char *str;
	int len = nbrlen(number);
	bool minus = false;
	long l = number;
	
	if (l < 0) {
		minus = true;
		l *= -1;
		len++;
	} 
	str = mx_strnew(len); 
	while (len--) {
		str[len] = l % 10 + 48;
		l /= 10;
	}
	if (minus)
		str[0] = '-';
	return str;
}
