#include <stdio.h>
#include <ctype.h>��
int cypher2(void)//�滻�������ĸ������ĸ�ַ����ֲ���
{
	char ch;
	int cap = 'a' - 'A';
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch)) {// �����һ���ַ���
			if (ch >= 'a' && ch <= 'z')
				putchar(ch - cap); // ��ʾ���ַ�����һ���ַ�
		}
		else // ����
			putchar(ch); // ԭ����ʾ
	}
	putchar(ch); // ��ʾ���з�
	return 0;
}

int loccheck(void) {//�鿴�������洢�ںδ�
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
