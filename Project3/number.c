#include <stdio.h>

//显示100在十进制/八进制/十六进制的值。加#会显示0与0x前缀。
int displayNum() {
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

	getchar();
	return 0;
}

//超出系统允许的最大int值
int toobigNum() {
	int i = 2147483647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);
	return 0;
}

//不同类型的数据打印时的格式,使用h会将数值转换为short类型显示。
int showNumInDiffType() {
	unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
	short end = 200;
	long big  = 16842753;
	long long verybig  = 12345678908642;
	printf("un　=　%u　and　not　%hd\n", un, un);
	printf("end　=　%hd　and　%d\n", end, end);
	printf("big　=　%ld　and　not　%hd\n", big, big);//hd只会显示big的后16位的值
	printf("verybig=　%lld　and　not　%ld\n", verybig, verybig);
	return 0;
}

int showChar() {
	char grade = 'FAT';//设置多位char时，char只取末位。
	printf("haha%c",grade);
	printf("Gramps sez, \"a \\ is a backslash.\"\n");
	printf("Hello!\a\n");//打印，并发出声音
	printf("Hello!7\n");
	return 0;
}

//用户输入字符
int inputChar() {
	char ch;
	printf("Please enter a character.\n");
	scanf_s("%c", &ch);
	printf("The code for %c is %d.\n", ch, ch);
	getchar();
	return 0;
}

//打印浮点型数据
int showFloat() {

	float aboat = 32000.0;
	double abet  = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f　can　be　written　%e\n", aboat, aboat);
	// 下一行要求编译器支持C99或其中的相关特性
	printf("And　it's　%a　in　hexadecimal,　powers　of　2　notation\n", aboat);
	printf("%f　can　be　written　%e\n", abet, abet);
	printf("%Lf　can　be　written　%Le\n", dip, dip);
	return 0;
	
}

//舍入错误
int showFloatWrong() {
	float a, b;
	b = 2.0e20 + 1.0;
	a  = b  - 2.0e20;
	printf("%f　\n", a);
	return 0;

}

//如何知道类型所占的大小
int showTypeSize(){
	/* C99为类型大小提供%zd转换说明 ,
	。一些不支持C99和C11的 编译器可用%u或%lu代替%zd。
	*/
	printf("Type　int　has　a　size　of　%zd　bytes.\n", sizeof(int));
	printf("Type　char　has　a　size　of　%zd　bytes.\n", sizeof(char));
	printf("Type　long　has　a　size　of　%zd　bytes.\n", sizeof(long));
	printf("Type　long　long　has　a　size　of　%zd　bytes.\n",
		sizeof(long long));
	printf("Type　double　has　a　size　of　%zd　bytes.\n",
		sizeof(double));
	printf("Type　long　double　has　a　size　of　%zd　bytes.\n",
		sizeof(long double));
	return 0;
}

//转义序列的兼容性测试
int escape()
{
	float salary;
	printf("\aEnter your desired monthly salary:"); /* 1 */
	printf(" $_______\b\b\b\b\b\b\b"); /* 2 */
	scanf_s("%f", &salary);
	printf("\n\t$%.2f　a　month　is　$%.2f　a　year.", salary,
		salary * 12.0); /* 3 */
	printf("\rGee!\n"); /* 4  \r使光标退回至起始处，\n使光标移至下一行。*/
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

//发出声音之后输出文字
int test3_3() {
	printf("\a\n");
	printf("Startled by the sudden sound, Sally shouted,\n");
	printf("\"By the Great Pumpkin\, what was that!\"");
	return 0;
}
