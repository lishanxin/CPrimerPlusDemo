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
