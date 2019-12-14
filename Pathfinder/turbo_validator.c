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

char is_empty(char **av) {
    int fd = open(av[1], O_RDONLY);
    char buf;
    
	if (read(fd, &buf, 1) == 0) {
		close(fd);
		mx_printerr(EMPTY_FILE);
		mx_printerr(*av);
		mx_printerr(EMPTY_FILE2);
		exit (1);
	}
	else
		return 0;
}

/***************************************************************************************************/

char is_folder(char **av) {
	int fd = open(av[1], O_RDONLY);

	if (read(fd, (void *)0, 0) < 0) {
        close(fd);
        mx_printerr("usage: ./pathfinder [filename]");
        exit(1);
    }
	else
		return 0;
}

/***************************************************************************************************/

char validator(char *file, char **WordsA) {
	char **WordsA = mx_strsplit(file, '\n');
	char minus = '-';
	char zap = ',';
	
	for (int i = 1; WordsA[i]; i++) {
		if (mx_char_count(WordsA[i], minus) != 1) {
			mx_printerr(LINE_VALUE);
			mx_printerr(mx_itoa(i + 1));
			mx_printerr(LINE_VALUE2);
			exit (1);
		}
		if (mx_char_count(WordsA[i], zap) != 1) {
			mx_printerr(LINE_VALUE);
			mx_printerr(mx_itoa(i + 1));
			mx_printerr(LINE_VALUE2);
			exit (1);
		}
	}
	return *file;
}

/***************************************************************************************************/

char range_validator(char *file) {
	char **range = mx_strsplit(file, ',');
	char *str;
	for (int i = 0; range[i + 1]; ++i) {

	}

}

/***************************************************************************************************/

char is_not_exist(char **av) {
	int fd = open(av[1], O_RDONLY);

	if (fd == -1) {
	    close(fd);
	    mx_printerr(FILE_EXIST);
	   	mx_printerr(*av);
	    mx_printerr(FILE_EXIST2);
	    exit(1);
	}
	else
		return 0;
}

/***************************************************************************************************/

int main(int ac, char **av) {
	char *file = mx_file_to_str(av[1]);
	char **WordsA = mx_strsplit(file, '\n');
	//if (ac == 1)
		// is_folder(&av[1]);
		// is_not_exist(&av[1]);
		// is_empty(&av[1]);
		validator(file, WordsA);
		mx_del_strarr(&WordsA);
	system("leaks -q a.out");
}


