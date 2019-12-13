#include "libmx.h"

void double_del_arr(char **str1, char **str2) {
	mx_del_strarr(&str1);
	mx_del_strarr(&str2);
}
