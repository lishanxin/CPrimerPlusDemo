#include <stdio.h>
#include <ctype.h>　
int cypher2(void)//替换输入的字母，非字母字符保持不变
{
	char ch;
	int cap = 'a' - 'A';
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch)) {// 如果是一个字符，
			if (ch >= 'a' && ch <= 'z')
				putchar(ch - cap); // 显示该字符的下一个字符
		}
		else // 否则，
			putchar(ch); // 原样显示
	}
	putchar(ch); // 显示换行符
	return 0;
}

int loccheck(void) {//查看变量被存储在何处
	int pooh = 2, bah = 5;
	printf("In loccheck(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In locckeck(), bah = %d and &bah = %p\n", bah, &bah);

	mikado(pooh);
	return 0;
}

int mikado(int bah) {
	int pooh = 10;
	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
	return 0;
}
