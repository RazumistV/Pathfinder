#include "inc/libmx.h"
#include <stdio.h>
#include <string.h>

static void mx_points(t_path *p) {
	char *file = "A-B,11";
	char **apex = NULL;
	int i = 0;

	apex = mx_strsplit(file, '-');
	p->a = apex[i];
	apex = mx_strsplit(apex[1], ',');
	p->b = apex[i];
	free(apex);
}

void mx_islands(t_path *p) {
	char *file = "A-B,11";
	char **split = mx_strsplit(file, ',');
	int rast = 0;
	int i = 1;
	int j = 0;
	while (split[i][j]) {
		rast = mx_atoi(split[i]);
		p->distance = rast;
		j++;
	}
	free(split);
	mx_points(p);

}

int main() {
	t_path *p;
	int count = 10;


	p = (t_path *)malloc(sizeof(t_path)* count);
	// p[0].distance = 3;
	// p[1].distance = 2;
	mx_islands(p);
	printf("distance = %d\n Apex = %s\n Apex = %s\n",  p->distance, p->a, p->b);
}