#include <stdio.h>
#include <stdlib.h>
//第十二章 存储类别、链接和内存管理
void trystat(void);
int loc_stat(void) {
	int count;
	for (count = 1; count <= 3; count++) {
		printf("Here comes iteration %d:\n", count);
		trystat();
	}
	return 0;
}

void trystat(void) {
	int fade = 1;
	static int stay = 1;
	printf("fade = %d and stay = %d\n", fade++, stay++);

}

void report_count();
extern void accumulate(int k);
int count = 0;     // 文件作用域，外部链接
int partb(void) {
	int value;     // 自动变量
	register int i;  // 寄存器变量
	printf("Enter a positive integer (0 to quit): ");
	while (scanf("%d", &value) == 1 && value  > 0)
	{
		++count;    // 使用文件作用域变量
		for (i  = value; i  >= 0; i--)
			accumulate(i);
		printf("Enter a positive integer (0 to quit): ");
	}
	report_count();
	return 0;

}

void report_count()
{
	printf("Loop executed %d times\n", count);
}

static unsigned long int next = 1;/*种子*/

unsigned int rand0(void) {
	/*生成伪随机数的魔术公式*/
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

//充值随机书
void srand(unsigned int seed) {
	next = seed;
}

int dyn_arr(void) {
	double * ptd;
	int max;
	int number;
	int i = 0;
	puts("What is the maximum number of type double entries?");
	if (scanf("%d", &max) != 1) {
		puts("Number not correctly entered -- bye.");
		exit(EXIT_FAILURE);
	}
	ptd = (double *)malloc(max * sizeof(double));
	if (ptd == NULL) {
		puts("Memory allocation failed. Goodbye.");
		exit(EXIT_FAILURE);
	}

	puts("Enter the values (q to quit):");
	while (i < max && scanf("%Lf", &ptd[i]) == 1) {
		i++;
	}
	printf("Here are your %d entries:\n", number = i);
	for (i = 0; i < number; i++) {
		printf("%7.2f ", ptd[i]);
		if (i % 7 == 6) {
			putchar('\n');
		}
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Done");
	free(ptd);
	return 0;
}

/*使用标准I/O*/
int countFile(int argc, char *argv[]) {
	int ch; //读取文件时，储存每个字符的地方
	FILE *fp;//文件指针
	unsigned long count = 0;
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "w")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout); // 与putchar(ch)相同
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);
	return 0;
}