int nbrlen(int number) {
	int len = 1;

	while (number / 10) { 
		number /= 10;
		len++;
	}
	return len;
}
