#include <stdio.h>

int echo() { //�ظ�����
	char ch;
	while ((ch = getchar()) != '#')
		putchar(ch);
	return 0;
}