#include <stdio.h>
#include <string.h>

//��ʮһ��

#define MSG " I am a symbolic string constant."
#define MAXLENGTH 81
int strings1(void) {
	char words[MAXLENGTH] = "I am a string in an array.";
	const char *pt1 = "Something is pointing at me.";
	puts("Here are some strings:");
	puts(MSG);//ֻ��ʾ�ַ�������
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);
	return 0;
}


int strptr(void) {
	printf("%s , %p, %c\n", "We", "are", *"space farers");
	return 0;
}


int p_and_s(void) {
	const char *mesg = "Don't be a fool!";
	const char *copy;
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
	return 0;
	/*
	Don't be a fool!
	Don't be a fool!   x;  z;
	Don't be a fool!   y;  z;
	*/
}

#define STLEN 5
int getsputs(void) {
	char words[STLEN];
	puts("Enter a string, please.");
	gets(words);//�����÷�
	printf("your string twice:\n");
	printf("%s\n", words);
	puts(words);
	puts("DONE.");
	return 0;
}

#define STLEN 14
int fgets1(void) {
	char  words[STLEN];
	puts("Enter  strings  (empty  line  to  quit):");
	while  (fgets(words, STLEN, stdin) != NULL   && words[0] != '\n')
		fputs(words, stdout);
	puts("Done.");
	return  0;


}

int scan_str(void) {
	char name1[11], name2[11];
	int count;
	printf("Please enter 2 names.\n");
	count = scanf("%5s  %10s", name1, name2);
	printf("I read the %d names %s and %s. \n", count, name1, name2);
	return 0;
}

#define SIZE 30
#define BUGSIZE 13

char * s_gets(char *st, int n);
int join_chk(void) {
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;
	puts("What is your favorite flower?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat(flower, addon);
	puts(flower);
	puts("What is your favorite bug?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);
	return 0;
}

char * s_gets(char *st, int n) {
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
	while (st[i] != '\n' && st[i] != '\0')
		i++;
	if (st[i] == '\n')
		st[i] = '\0';
	else
	while (getchar() != '\n')
	continue;
	}
    return ret_val;
}


extern int count;      // ����ʽ�������ⲿ����
static int total = 0;    // ��̬���壬�ڲ�����
void accumulate(int k);   // ����ԭ��
void accumulate(int k)// k ���п�������������
{
	static int subtotal = 0;  // ��̬��������
	if (k  <= 0)
	{
		printf("loop cycle: %d\n", count);
		printf("subtotal: %d; total: %d\n", subtotal, total);
		subtotal  = 0;
	}
	else
	{
	subtotal  += k;
	total  += k;
	}
}
