#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	int pivot;
	int l = left;
	int r = right;
	unsigned int c = 0;
        
	if (arr == NULL || *arr == NULL)
		return -1;
	pivot = mx_strlen(arr[(left + right) / 2]);
	while (l <= r)
	{
		while (mx_strlen(arr[l]) < pivot)
			l++;
		while (mx_strlen(arr[r]) > pivot)
			r--;
		if (l <= r) {
			if(mx_strlen(arr[l]) > mx_strlen(arr[r]))
				swap_strings(&arr[l], &arr[r], &c);
			r--;
			l++;
		}
	}
	if (left < r)
		c += mx_quicksort(arr, left, r);
	if (right > l)
		c += mx_quicksort(arr, l, right);
	return c;
}
