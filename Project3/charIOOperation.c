#include <stdio.h>
#include <stdlib.h> //为了使用exit()
int echo() { //重复输入
	char ch;
	while ((ch = getchar()) != '#')
		putchar(ch);
	return 0;
}

int echo_eof() { //不检测到文件结尾EOF，就重复输入
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
	fp = fopen("E:\\test.txt", "r"); //打开待读取文件
	if (fp == NULL) {
		printf("Failed to open file. Bye\n");
		exit(1);   // 退出程序
	}
	//getc(fp)从打开的文件中获取一个字符
	while ((ch = getc(fp)) != EOF) {
		putchar(ch);
	}
	fclose(fp);   //关闭文件
	return 0;
}