#include <stdio.h>
#include <stdlib.h> //Ϊ��ʹ��exit()
int echo() { //�ظ�����
	char ch;
	while ((ch = getchar()) != '#')
		putchar(ch);
	return 0;
}

int echo_eof() { //����⵽�ļ���βEOF�����ظ�����
	int ch;
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}
	putchar('Q');
	return 0;
}

int file_eof() {
	int ch;
	FILE * fp;
	printf("Enter the name of the file:  ");
	fp = fopen("E:\\test.txt", "r"); //�򿪴���ȡ�ļ�
	if (fp == NULL) {
		printf("Failed to open file. Bye\n");
		exit(1);   // �˳�����
	}
	//getc(fp)�Ӵ򿪵��ļ��л�ȡһ���ַ�
	while ((ch = getc(fp)) != EOF) {
		putchar(ch);
	}
	fclose(fp);   //�ر��ļ�
	return 0;
}