#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>  //提供strlen()函数的原型
#define DENSITY 62.4 //人体密度 （单位：磅/立方英尺）
#define PRAISE "You are an extraordinary being."
int talkback() {
	float weight, volume;
	int size, letters;
	char name[40]; // name是一个可容纳40个字符的数组
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

//使用不同类型的字符串
int praise() {
	char name[40];
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);

	getchar();
	getchar();
	return 0;
}

//显示不同类型的数字所能显示的极值
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

//修饰符和标记的示例,查看“学习记录-打印转义字符”
int showDiffTypeMessage() {
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);//10表示宽度
	printf("*%-10d*\n", PAGES);//-表示靠左
	
	const double RENT = 3852.99; // const变量
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

//一些不匹配的整型转换
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

//不匹配的浮点型转换
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
	int age; // 变量
	float assets; // 变量
	char pet[30]; // 字符数组，用于储存字符串
	printf("Enter your age, assets, and favorite pet.\n");
	scanf("%d %f", &age, &assets); // 这里要使用&
	scanf("%s", pet); // 字符数组不使用&
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

//类型转换
int convertType() {
	char ch;
	int i;
	float fl;
	fl = i = ch = 'C';
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* 第10行 */
	ch = ch + 1; /* 第11行 */
	i = fl + 2 * ch; /* 第12行 */
	fl = 2.0 * ch + i; /* 第13行 */
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* 第14行 */
	ch = 1107; /* 第15行 */
	printf("Now ch = %c\n", ch); /* 第16行 */
	ch = 80.89; /* 第17行 */
	printf("Now ch = %c\n", ch); /* 第18行 */
	return 0;

}

int test10_7() {
	int zi[2][3] = { {1,2,3},{4,5,6} };
	printf("zi value: %p, &zi: %p", zi, &zi);
	printf("zi[0] value: %p, &zi[0]: %p", zi[0], &zi[0]);
	return 0;
}