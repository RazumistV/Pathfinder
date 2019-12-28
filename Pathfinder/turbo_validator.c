#include "inc/libmx.h"

int mx_char_count(char *str, char c) {
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

/***************************************************************************************************/

bool str_is_digit(char *str) {
	for (int i = 0; str[i]; i++) {
		if (!mx_isdigit(str[i]))
			return false;
	}
	return true;
}

/***************************************************************************************************/

char *is_empty(char *file) {
    int fd = open(file, O_RDONLY);
    char buf;
    
	if (read(fd, &buf, 1) == 0) {
		close(fd);
		// mx_printerr("File is empty");
		mx_printerr(EMPTY_FILE);
		mx_printerr(file);
		mx_printerr(EMPTY_FILE2);
		exit (0);
	}
	else
		return file;
}

/***************************************************************************************************/

char *is_folder(char *file) {
	int fd = open(file, O_RDONLY);

	if (read(fd, (void *)0, 0) < 0) {
 	    close(fd);
 	    // mx_printerr("Is folder");
		mx_printerr(ERROR_USAGE);
	    exit (0);
    }
	else
		return file;
}

/***************************************************************************************************/

char *validator_znakov(char *file, char **WordsA) {
	char minus = '-';
	char zap = ',';
	
	for (int i = 1; WordsA[i]; i++) {
		if (mx_char_count(WordsA[i], minus) != 1 
			|| mx_char_count(WordsA[i], zap) != 1) {
			char *num = mx_itoa(i + 1);
			// mx_printerr("Validator znakov");
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			exit (0);
		}
	}
	return file;
}

/***************************************************************************************************/

char *range_validator(char *file, char **WordsA) {
	for (int i = 1; WordsA[i]; i++) {
		char **str = mx_strsplit(WordsA[i], ',');
		if (!str_is_digit(str[1])) {
			char *num = mx_itoa(i + 1);
			// mx_printerr("range_validator");
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			exit (0);
		}
		mx_del_strarr(&str);
	}
	return file;
}

/***************************************************************************************************/

char *argument(int ac, char *file) {
	if (ac != 2) {
		mx_printerr(ERROR_USAGE);
		exit (0);
	}
	else
		return file;
}

/***************************************************************************************************/

char *is_not_exist(char *file) {
	int fd = open(file, O_RDONLY);

	if (fd < 0) {
	    close(fd);
	    //mx_printerr("File is not exists");
	    mx_printerr(FILE_EXIST);
	   	mx_printerr(file);
	    mx_printerr(FILE_EXIST2);
	    exit (0);
	}
	else
		return file;
}

/***************************************************************************************************/

// int mx_str_count(char *file) {
// 	char *str = mx_file_to_str(file);
// 	int j = 0;

// 	for (int i = 0; str[i]; i++) {
// 		if (str[i] == '\n')
// 			j++;
// 	}
// 	free(str);
// 	return j;
// }

/***************************************************************************************************/



/***************************************************************************************************/


char *valid_island(char *file, char **WordsA) {
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
	return file;
}

/***************************************************************************************************/

char *apex_count(char *file, char **WordsA) {
	if (!str_is_digit(WordsA[0])) {
		mx_printerr(INVALID_ISLANDS);
		exit (0);
	}
	return file;
}

/***************************************************************************************************/

char *print_error(int ac, char *av, char **WordsA, char *file) {
		argument(ac, av);
		is_not_exist(av);
		is_folder(av);
		is_empty(av);
		apex_count(av, WordsA);
		validator_znakov(av, WordsA);
		range_validator(av, WordsA);
		valid_island(file, WordsA);
		mx_del_strarr(&WordsA);
		printf("%s\n", file);
	return file;
}

/***************************************************************************************************/

int main(int ac, char **av) {
	char *file = mx_file_to_str(av[1]);
	char **WordsA = mx_strsplit(file, '\n');

	print_error(ac, av[1], WordsA, file);
	free(file);

	system("leaks -q a.out");
}


