#include <stdio.h>

//��ʾ100��ʮ����/�˽���/ʮ�����Ƶ�ֵ����#����ʾ0��0xǰ׺��
int displayNum() {
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

	getchar();
	return 0;
}

//����ϵͳ��������intֵ
int toobigNum() {
	int i = 2147483647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);
	return 0;
}

//��ͬ���͵����ݴ�ӡʱ�ĸ�ʽ,ʹ��h�Ὣ��ֵת��Ϊshort������ʾ��
int showNumInDiffType() {
	unsigned int un = 3000000000; /* intΪ32λ��shortΪ16λ��ϵͳ */
	short end = 200;
	long big  = 16842753;
	long long verybig  = 12345678908642;
	printf("un��=��%u��and��not��%hd\n", un, un);
	printf("end��=��%hd��and��%d\n", end, end);
	printf("big��=��%ld��and��not��%hd\n", big, big);//hdֻ����ʾbig�ĺ�16λ��ֵ
	printf("verybig=��%lld��and��not��%ld\n", verybig, verybig);
	return 0;
}

int showChar() {
	char grade = 'FAT';//���ö�λcharʱ��charֻȡĩλ��
	printf("haha%c",grade);
	printf("Gramps sez, \"a \\ is a backslash.\"\n");
	printf("Hello!\a\n");//��ӡ������������
	printf("Hello!7\n");
	return 0;
}

//�û������ַ�
int inputChar() {
	char ch;
	printf("Please enter a character.\n");
	scanf_s("%c", &ch);
	printf("The code for %c is %d.\n", ch, ch);
	getchar();
	return 0;
}

//��ӡ����������
int showFloat() {

	float aboat = 32000.0;
	double abet  = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f��can��be��written��%e\n", aboat, aboat);
	// ��һ��Ҫ�������֧��C99�����е��������
	printf("And��it's��%a��in��hexadecimal,��powers��of��2��notation\n", aboat);
	printf("%f��can��be��written��%e\n", abet, abet);
	printf("%Lf��can��be��written��%Le\n", dip, dip);
	return 0;
	
}

//�������
int showFloatWrong() {
	float a, b;
	b = 2.0e20 + 1.0;
	a  = b  - 2.0e20;
	printf("%f��\n", a);
	return 0;

}

//���֪��������ռ�Ĵ�С
int showTypeSize(){
	/* C99Ϊ���ʹ�С�ṩ%zdת��˵�� ,
	��һЩ��֧��C99��C11�� ����������%u��%lu����%zd��
	*/
	printf("Type��int��has��a��size��of��%zd��bytes.\n", sizeof(int));
	printf("Type��char��has��a��size��of��%zd��bytes.\n", sizeof(char));
	printf("Type��long��has��a��size��of��%zd��bytes.\n", sizeof(long));
	printf("Type��long��long��has��a��size��of��%zd��bytes.\n",
		sizeof(long long));
	printf("Type��double��has��a��size��of��%zd��bytes.\n",
		sizeof(double));
	printf("Type��long��double��has��a��size��of��%zd��bytes.\n",
		sizeof(long double));
	return 0;
}

//ת�����еļ����Բ���
int escape()
{
	float salary;
	printf("\aEnter your desired monthly salary:"); /* 1 */
	printf(" $_______\b\b\b\b\b\b\b"); /* 2 */
	scanf_s("%f", &salary);
	printf("\n\t$%.2f��a��month��is��$%.2f��a��year.", salary,
		salary * 12.0); /* 3 */
	printf("\rGee!\n"); /* 4  \rʹ����˻�����ʼ����\nʹ���������һ�С�*/
	getchar();
	return 0;
}

int testPrintChar() {
	int input;
	printf("Enter a Number to Show the Char of it:");
	scanf_s("%d", &input);
	printf("%d is the ASCII code for %c.\n", input, input);
	getchar();
	return 0;
}

//��������֮���������
int test3_3() {
	printf("\a\n");
	printf("Startled by the sudden sound, Sally shouted,\n");
	printf("\"By the Great Pumpkin\, what was that!\"");
	return 0;
}
