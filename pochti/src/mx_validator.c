#include "pathfinder.h"

int mx_char_count(char *str, char c) {
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

void valid_island(char **WordsA) {
	for(int i = 1; WordsA[i]; i++) {
			char **str = mx_strsplit(WordsA[i], '-');

		if (str[0] == NULL || mx_arrlen(str) < 2) {
			char *num = mx_itoa(i + 1);
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			mx_del_strarr(&str);
			exit (0);
		}
			char **str2 = mx_strsplit(str[1], ',');

		if (str2[0] == NULL || mx_arrlen(str2) < 2) {
			char *num = mx_itoa(i + 1);
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			mx_del_strarr(&str2);
			exit (0);
		}
		double_del_arr(str, str2);
	}
}
