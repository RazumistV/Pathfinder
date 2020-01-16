#include "pathfinder.h"

void mx_invalid_apex() {
	mx_printerr("error: invalid number of islands\n");
	exit(0);
}

void apex_count(char **WordsA) {
	if (!str_is_digit(WordsA[0])) {
		mx_printerr("error: line 1 is not valid\n");
		exit (0);
	}
}

void mx_print_inval(char *n) {
	mx_printerr(LINE_VALUE);
	mx_printerr(n);
	mx_printerr(LINE_VALUE2);
}

void mx_apex_repeat(char **str) {
	char **str1;
	char **str2;

	for (int i = 1; str[i]; i++) {
		str1 = mx_strsplit(str[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		if (mx_strcmp(str1[0], str2[0]) == 0 
			&& mx_strlen(str1[0]) == mx_strlen(str2[0])) {
			char *num = mx_itoa(i + 1);

			mx_print_inval(num);
			exit (0);
		}
		double_del_arr(str1, str2);
	}
}

bool mx_is_char(char *s) {
	for (int i = 0; s[i]; i++) {
		if (!((s[i] >= 65 && s[i] <= 90)
			|| (s[i] >= 97 && s[i] <= 122)))
			return false;
	}
	return true;
}

void mx_apex_ne_char(char **str) {
	char **str1;
	char **str2;

	for (int i = 1; str[i]; i++) {
		str1 = mx_strsplit(str[i], '-');
		str2 = mx_strsplit(str1[1], ',');
		if (!(mx_is_char(str1[0]))) {
			char *num = mx_itoa(i + 1);

			mx_print_inval(num);
			exit (0);
		}
		if (!(mx_is_char(str2[0]))) {
			char *num = mx_itoa(i + 1);

			mx_print_inval(num);
			exit (0);
		}
		double_del_arr(str1, str2);
	}
}

void mx_b_slash_n(char *fl) {
	int len = mx_strlen(fl);
	int count = 0;

	for (int i = 0; fl[i + 1]; i++) {
		if (fl[i] == '\n')
			count++;
		if (fl[i] == '\n' && fl[i + 1] == '\n' && i != len - 1) {
			count++;
			char *num = mx_itoa(count);

			mx_print_inval(num);
			exit(0);
		}
	}
}
