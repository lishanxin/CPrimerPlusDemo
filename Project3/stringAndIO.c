#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>  //�ṩstrlen()������ԭ��
#define DENSITY 62.4 //�����ܶ� ����λ����/����Ӣ�ߣ�
#define PRAISE "You are an extraordinary being."
int talkback() {
	float weight, volume;
	int size, letters;
	char name[40]; // name��һ��������40���ַ�������
	printf("Hi! What's your first name?\n");
	scanf("%s", name);
	
	printf("%s, what's your weight in pounds?\n", name);
	scanf_s("%f", &weight);
	size = sizeof name;
	letters = strlen(name);

	volume = weight / DENSITY;
	printf("Well, %s, your volueme is %2.2f cubic feet.\n", name, volume);
	printf("Also, your fist name has %d letters, \n", letters);
	printf("and we have %d bytes to store it. \n", size);


	getchar();
	return 0;

}

//ʹ�ò�ͬ���͵��ַ���
int praise() {
	char name[40];
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);

	getchar();
	getchar();
	return 0;
}

//��ʾ��ͬ���͵�����������ʾ�ļ�ֵ
int definesNumbers() {
	printf("Some number limits for this system:\n");
	printf("Biggest int: %d\n", INT_MAX);
	printf("Smallest long long: %lld\n", LLONG_MIN);
	printf("One byte = %d bits on this system.\n", CHAR_BIT);
	printf("Largest double: %e\n", DBL_MAX);
	printf("Smallest normal float: %e\n", FLT_MIN);
	printf("float precision = %d digits\n", FLT_DIG);
	printf("float epsilon = %e\n", FLT_EPSILON);
	return 0;

}

#define PAGES 959
#define BLURB "Authentic imitation!"

//���η��ͱ�ǵ�ʾ��,�鿴��ѧϰ��¼-��ӡת���ַ���
int showDiffTypeMessage() {
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);//10��ʾ���
	printf("*%-10d*\n", PAGES);//-��ʾ����
	
	const double RENT = 3852.99; // const����
	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%10.1f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

	printf("%x %X %#x %#X\n", 31, 31, 31, 31);
	printf("**%d**% d**% d**\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);

	return 0;
	

}

//һЩ��ƥ�������ת��
#define PAGES2 336
#define WORDS 65618

int intconv() {
	short num = PAGES2;
	short mnum = -PAGES2;
	printf("num as short and unsigned short: %hd %hu\n", num, num);
	printf("mnum as short and unsigned short: %hd %hu\n", mnum, mnum);
	printf("num as int and char:%d %c\n", num, num);
	printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);
	return 0;
}

//��ƥ��ĸ�����ת��
int floatcnv() {
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
	return 0;
}

int getInputInStringAndIO() {
	int age; // ����
	float assets; // ����
	char pet[30]; // �ַ����飬���ڴ����ַ���
	printf("Enter your age, assets, and favorite pet.\n");
	scanf("%d %f", &age, &assets); // ����Ҫʹ��&
	scanf("%s", pet); // �ַ����鲻ʹ��&
	printf("%d $%.2f %s\n", age, assets, pet);
	getchar();
	return 0;
}

int test4_1() {
	char firstName[30];
	char secondName[30];
	printf("Enter your First Name:");
	scanf("%s", firstName);
	printf("Enter your Second Name:");
	scanf("%s", secondName);
	printf("Hello, %s %s", firstName, secondName);
	getchar();
	return 0;
}

int test4_2() {
	char name[30];
	int width;
	printf("Enter your Name:");
	scanf("%s", name);
	width = strlen(name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", width + 3, name);
	getchar();
	return 0;
}

int test4_3() {
	float num;
	printf("Enter a float:");
	scanf("%f", &num);
	printf("%.1f\n", num);
	printf("%3.1e\n", num);
	printf("%+2.3f\n", num);
	printf("%3.3e\n", num);
	getchar();
	return 0;
}

int test4_4() {
	float height;
	char name[30];
	printf("Enter your Name and Height(cm):");
	scanf("%s %f", name, &height);
	printf("%s, you are %10.3f miter tall", name, height/100);
	getchar();
	return 0;
}

int test4_5() {
	float speed;
	float fileSize;
	printf("Enter the speed(Mb/s) the Internet And the downloadFile Size(MB):");
	scanf("%f %f", &speed, &fileSize);

	printf("At %4.2f megabits per second, a file of %3.2f megabytes\n", speed, fileSize);
	printf("downloads in %3.2f seconds", fileSize * 8 / speed);

	getchar();
	return 0;
}

//����ת��
int convertType() {
	char ch;
	int i;
	float fl;
	fl = i = ch = 'C';
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* ��10�� */
	ch = ch + 1; /* ��11�� */
	i = fl + 2 * ch; /* ��12�� */
	fl = 2.0 * ch + i; /* ��13�� */
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* ��14�� */
	ch = 1107; /* ��15�� */
	printf("Now ch = %c\n", ch); /* ��16�� */
	ch = 80.89; /* ��17�� */
	printf("Now ch = %c\n", ch); /* ��18�� */
	return 0;

}

int test10_7() {
	int zi[2][3] = { {1,2,3},{4,5,6} };
	printf("zi value: %p, &zi: %p", zi, &zi);
	printf("zi[0] value: %p, &zi[0]: %p", zi[0], &zi[0]);
	return 0;
}