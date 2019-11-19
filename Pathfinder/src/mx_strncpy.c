char *mx_strncpy(char *dst, const char *src, int len) {
	int i = 0;

	while (i < len) {
		if (src[i] == '\0')
			dst[i] = src[i];
		else
			dst[i] = src[i];
		i++;
	}
	return dst;
}
