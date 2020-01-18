#include "pathfinder.h"

void mx_is_not_exist(char *file) {
	int fd = open(file, O_RDONLY);

	if (fd < 0) {
		close(fd);
		mx_printerr(FILE_EXIST);
		mx_printerr(file);
		mx_printerr(FILE_EXIST2);
		exit (0);
	}
}
