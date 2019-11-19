#include "libmx.h"

void mx_printint(int n) {
	long l = n;

	if (l < 0) {
		l *= -1;
		mx_printchar('-');
	}
	if (n / 10 != 0) 
		mx_printint(l / 10);
	mx_printchar(l % 10 + 48);
}
