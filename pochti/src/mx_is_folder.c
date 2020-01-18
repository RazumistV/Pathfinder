#include "pathfinder.h"

void mx_is_folder(char *file) {
	int fd = open(file, O_RDONLY);

	if (read(fd, (void *)0, 0) < 0) {
 	    close(fd);
 		mx_printerr(ERROR_USAGE);
	    exit (0);
    }
}
