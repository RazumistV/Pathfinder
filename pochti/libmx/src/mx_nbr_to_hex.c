#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	char *str;
	int count = 0;
	unsigned long tmp = 0;
	char *hex = "0123456789abcdef";
	
	while (tmp > 0) {
		tmp /= 16;		
		count++;
	}
		str = (char *)malloc(sizeof(char) * (count + 1));
		str[count] = '\0';
		
		if (nbr == 0)
			*str = '0';
		else {
			while (nbr > 0) {
				str[--count] = hex[nbr % 16];
				nbr /= 16;
			}
	}
	return str;
}
