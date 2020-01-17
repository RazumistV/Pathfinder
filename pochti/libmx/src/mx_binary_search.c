#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int low = 0;
	int hight = size - 1;
	int mid;
	*count = 0;

	while(low <= hight) {
		mid = low + (hight - low) / 2;
		*count += 1;
		if(mx_strcmp(arr[mid], s) > 0)
			hight = mid - 1;
		else if(mx_strcmp(arr[mid], s) < 0)
			low = mid + 1;
		else
			return mid;
	}
	*count = 0;
	return -1;
}
