#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	int i = 0;
	int j = 0;
	int sab = mx_count_substr(str, sub);
	char *new;
	int len = mx_strlen(str);
	
	if (str == NULL || sub == NULL || replace == NULL)
		return NULL;
	new = mx_strnew(len - sab * (mx_strlen(sub)) + sab * mx_strlen(replace));
	while (str[i]) {
		
		if (mx_strncmp(sub, &str[i], mx_strlen(sub)) == 0) {
			mx_strcat(new, replace);
			i += mx_strlen(sub);
			j += mx_strlen(replace);
		}
		else {
			new[j] = str[i];
			i++;
			j++;
		}
	}
	new[j] = '\0';
	return new;
}
