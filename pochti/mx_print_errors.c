#include "inc/libmx.h"

static void validator_znakov(char **WordsA);
static void valid_apex(char **WordsA);
static void range_validator(char **WordsA);

bool str_is_digit(char *str) {
	for (int i = 0; str[i]; i++) {
		if (!mx_isdigit(str[i]))
			return false;
	}
	return true;
}

void mx_print_errors(char *av, char **WordsA) {
		apex_count(WordsA);
		mx_apex_ne_char(WordsA);
		mx_b_slash_n(av);
		mx_apex_repeat(WordsA);
		validator_znakov(av, WordsA);
		range_validator(av, WordsA);
		valid_island(WordsA);
}

static void validator_znakov(char **WordsA) {
	char minus = '-';
	char zap = ',';
	
	for (int i = 1; WordsA[i]; i++) {
		if (mx_char_count(WordsA[i], minus) != 1 
			|| mx_char_count(WordsA[i], zap) != 1) {
			char *num = mx_itoa(i + 1);
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			exit (0);
		}
	}
}

static void valid_apex(char **WordsA) {
	for(int i = 1; WordsA[i]; i++) {
		char **str = mx_strsplit(WordsA[i], '-');

		if (str[0] == NULL || mx_arrlen(str) < 2) {
			char *num = mx_itoa(i + 1);
			mx_print_inval(num);
			mx_del_strarr(&str);
			exit (0);
		}
		char **str2 = mx_strsplit(str[1], ',');

		if (str2[0] == NULL || mx_arrlen(str2) < 2) {
			char *num = mx_itoa(i + 1);
			mx_print_inval(num);
			mx_del_strarr(&str2);
			exit (0);
		}
		mx_double_del(str, str2);
	}
}

 static void range_validator(char **WordsA) {
	for (int i = 1; WordsA[i]; i++) {
		char **str = mx_strsplit(WordsA[i], ',');

		if (!str_is_digit(str[1])) {
			char *num = mx_itoa(i + 1);
			mx_print_inval(num);
			exit (0);
		}
		mx_del_strarr(&str);
	}
}
