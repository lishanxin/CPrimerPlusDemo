#include <stdio.h>
#include <stdlib.h>
//��ʮ���� �洢������Ӻ��ڴ����
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
int count = 0;     // �ļ��������ⲿ����
int partb(void) {
	int value;     // �Զ�����
	register int i;  // �Ĵ�������
	printf("Enter a positive integer (0 to quit): ");
	while (scanf("%d", &value) == 1 && value  > 0)
	{
		++count;    // ʹ���ļ����������
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

static unsigned long int next = 1;/*����*/

unsigned int rand0(void) {
	/*����α�������ħ����ʽ*/
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

//��ֵ�����
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

/*ʹ�ñ�׼I/O*/
int countFile(int argc, char *argv[]) {
	int ch; //��ȡ�ļ�ʱ������ÿ���ַ��ĵط�
	FILE *fp;//�ļ�ָ��
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
		putc(ch, stdout); // ��putchar(ch)��ͬ
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);
	return 0;
}