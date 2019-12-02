#include "libmx.h"

void freearray(char **arr) {
	int i = -1;

	if (arr == NULL)
		return ;
	while (arr[++i])
	{
		if (arr[i] != NULL)
			free(arr[i]);
	}
}
