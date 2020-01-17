void swap_strings(char **str1, char **str2, unsigned int *c) {
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
	*c = *c + 1;
}
