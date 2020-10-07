#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char c, p;
	unsigned int chars = 0, words = 0, lines = 0;

	while(read(fileno(stdin), &c, 1) > 0) {
		chars ++;
		if (c == '\n') {
			lines++;
			if (p != c) {
				words++;
			}
		} else if (c == ' ' && c != p && p != '\n') {
				words++;
		}
		p = c;
	}

	if (p != ' ' && p != '\n') {
		words++;
	}

	printf("%u\t%u\t%u\n", lines, words, chars);

	return 0;
}
