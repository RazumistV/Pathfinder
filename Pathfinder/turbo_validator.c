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
		mx_printerr(ERROR_USAGE);
	    exit (0);
    }
	else
		return file;
}

/***************************************************************************************************/

char *validator(char *file, char **WordsA) {
	char minus = '-';
	char zap = ',';
	
	for (int i = 1; WordsA[i]; i++) {
		if (mx_char_count(WordsA[i], minus) != 1) {
			char *num = mx_itoa(i + 1);
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			exit (0);
		}
		if (mx_char_count(WordsA[i], zap) != 1) {
			char *num = mx_itoa(i + 1);
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
			mx_printerr(LINE_VALUE);
			mx_printerr(num);
			mx_printerr(LINE_VALUE2);
			exit (0);
		}
		mx_del_strarr(&str);
	}
	//mx_del_strarr(&WordsA);
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
	    mx_printerr(FILE_EXIST);
	   	mx_printerr(file);
	    mx_printerr(FILE_EXIST2);
	    exit (0);
	}
	else
		return file;
}

/***************************************************************************************************/

char *print_error(int ac, char *av, char **WordsA, char *file) {
	//if (ac == 1)
		argument(ac, av);
		is_not_exist(av);
		is_folder(av);
		is_empty(av);
		validator(av, WordsA);
		range_validator(av, WordsA);
		mx_del_strarr(&WordsA);
		printf("%s\n", file);
	return file;
}

/***************************************************************************************************/

int main(int ac, char **av) {
	char *file = mx_file_to_str(av[1]);
	char **WordsA = mx_strsplit(file, '\n');
	//if (ac == 1)
		// argument(ac, av[1]);
		// is_not_exist(av[1]);
		// is_folder(av[1]);
		// is_empty(av[1]);
		// validator(file, WordsA);
		// range_validator(file, WordsA);
		// mx_del_strarr(&WordsA);
		print_error(ac, av[1], WordsA, file);
		//printf("%s\n", av[1]);
	system("leaks -q a.out");
}


