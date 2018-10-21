#include <stdio.h>

int echo() { //÷ÿ∏¥ ‰»Î
	char ch;
	while ((ch = getchar()) != '#')
		putchar(ch);
	return 0;
}