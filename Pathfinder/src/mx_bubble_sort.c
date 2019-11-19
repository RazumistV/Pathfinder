#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	char *tmp;
	char sort = 1;
	int count = 0;

	while(sort == 1) {
		sort = 0;

		for(int i = 0; i < size - 1; i++) {
			if (mx_strcmp(arr[i], arr[i + 1]) > 0) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sort = 1;
				count++;
			}
		} 
	}
	return count;
}
