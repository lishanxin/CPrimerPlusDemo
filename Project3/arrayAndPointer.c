#include <stdio.h>

int day_mon2(void) {
	const int days[] = { 31,28,31,30,31,30,31,31,30,31 };
	int index;
	for (index = 0; index < sizeof days / sizeof days[0]; index++)
		printf("Month %2d has %d days.\n", index + 1, days[index]);
	return 0;
}

#define MONTHS 12
int designate(void) {
	int days[MONTHS] = { 31,28,[4] = 31,30,31,[1] = 29 };
	int i;
	for (i = 0; i < MONTHS; i++) {
		printf("%2d %d \n", i + 1, days[i]);
	}
	return 0;
}

#define SIZE 4
//指针地址的增加
int pnt_add(void) {
	short dates[SIZE];
	short *pti;
	short index;
	double bills[SIZE];
	double *ptf;
	pti = dates;//把数组地址赋值给指针
	ptf = bills;

	printf("%23s %15s \n", "short", "double");
	for (index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);

	return 0;
}

/*结果（在C中，指针加1指的是增加一个存储单元）
				  short          double
pointers + 0: 000000105DEFFB78 000000105DEFFBD8
pointers + 1: 000000105DEFFB7A 000000105DEFFBE0
pointers + 2: 000000105DEFFB7C 000000105DEFFBE8
pointers + 3: 000000105DEFFB7E 000000105DEFFBF0
*/

int zippo1(void) {
	int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
	printf("	zippo = %p, zippo + 1 = %p\n", zippo, zippo + 1);
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
	printf("  *zippo = %p, *zippo + 1 = %p\n", *zippo, *zippo + 1);
	printf("zippo[0][0] = %d\n", zippo[0][0]);
	printf(" *zippo[0] = %d\n", *zippo[0]);
	printf(" **zippo = %d\n", **zippo);
	printf("		zippo[2][1] = %d\n", zippo[2][1]);
	printf("*(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));
	return 0;
}

int arraysAndPointer(void) {
	int junk[3][4] = { {2,4,5,8}, {2,9,5,8} ,{0,4,6,8} };
	int i, j;
	int total = 0;
	for (i = 0; i < 3; i++)
		total += sum(junk[i], 4);
	printf("sum is %d", total);
}

int sum(int (*pt)[4], int num) {
	int sumNum = 0;
	int i;
	for (i = 0; i < num; i++)
		sumNum += (*pt)[i];
	return sumNum;
}

#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int[][COLS], int);    // 省略形参名，没问题
int sum2d(int(*ar)[COLS], int rows);  // 另一种语法

int array2d(void) {
	int junk[ROWS][COLS] = {
{ 2, 4, 6, 8 },
{ 3, 5, 7, 9 },
{ 12, 10, 8, 6 }
	};
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
	return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (r  = 0; r  < rows; r++)
	{
		tot  = 0;
		for (c  = 0; c  < COLS; c++)
			tot  += ar[r][c];
		printf("row %d: sum = %d\n", r, tot);
	}
}
void sum_cols(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (c  = 0; c  < COLS; c++)
	{
		tot  = 0;
		for (r  = 0; r  < rows; r++)
			tot  += ar[r][c];
		printf("col %d: sum = %d\n", c, tot);
	}
}

int sum2d(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot  = 0;
	for (r  = 0; r  < rows; r++)
		for (c  = 0; c  < COLS; c++)
		tot  += ar[r][c];
	return tot;
}

//int sum2(int ar[][], int rows); // 错误的声明
//int sum2(int ar[][4], int rows);  // 有效声明

#define MONTHS 12   // 一年的月份数
#define YEARS  5    // 年数

int rain(void) {
	// 用2010～2014年的降水量数据初始化数组
	const float rain[YEARS][MONTHS] =
	{
	{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5,  6.6 },
	{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4,  7.3 },
	{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1,  8.4 },
	{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3,  6.2 },
	{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6,  5.2 }
	};
	int year, month;
	float subtot, total;
	printf(" YEAR   RAINFALL  (inches)\n");
	for (year  = 0, total  = 0; year  < YEARS; year++)
	{             // 每一年，各月的降水量总和
		for (month  = 0, subtot  = 0; month  < MONTHS; month++)
			subtot  += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;  // 5年的总降水量
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total  / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
	printf(" Nov  Dec\n");
	for (month  = 0; month  < MONTHS; month++)
	{             // 每个月，5年的总降水量
		for (year  = 0, subtot  = 0; year  < YEARS; year++)
			subtot  += rain[year][month];
		printf("%4.1f ", subtot  / YEARS);
	}
	printf("\n");
	return 0;
}
int E10_1Rain(void) {
	// 用2010～2014年的降水量数据初始化数组
	const float rain[YEARS][MONTHS] =
	{
	{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5,  6.6 },
	{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4,  7.3 },
	{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1,  8.4 },
	{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3,  6.2 },
	{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6,  5.2 }
	};
	int year, month;
	float subtot, total;
	printf(" YEAR   RAINFALL  (inches)\n");
	const float (*pt)[MONTHS] = rain;
	for (year = 0, total = 0; year < YEARS; year++)
	{             // 每一年，各月的降水量总和
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(pt +year) + month);
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;  // 5年的总降水量
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
	printf(" Nov  Dec\n");
	for (month = 0; month < MONTHS; month++)
	{             // 每个月，5年的总降水量
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year)+ month);
		printf("%4.1f ", subtot / YEARS);
	}
	printf("\n");
	return 0;
}

void copy_arr(double target[], double source[], int cols);
void copy_ptr(double *target, double *source, int cols);
void copy_ptrs(double *target, double *source, double *sourceEnd);
int E10_2_copy(void) {
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printf("target1 pointer is : %p, target1[0] is: %f", target1, target1[0]);
	printf("target2 pointer is : %p, target1[1] is: %f", target2, target1[1]);
	printf("target3 pointer is : %p, target1[2] is: %f", target3, target1[2]);
	return 0;
}

void copy_arr(double target[], double source[], int cols)
{
	int i;
	for (i = 0; i < cols; i++) {
		target[i] = source[i];
	}
}

void copy_ptr(double * target, double * source, int cols)
{
	int i;
	for (i = 0; i < cols; i++) {
		*(target + i) = *(source + i);
	}
}

void copy_ptrs(double *target, double *source, double *sourceEnd)
{
	while (source < sourceEnd) {
		*target++ = *source++;
	}
}

int max1d(int *nums, int cols);

int E10_3(void) {
	int maxNum;
	int nums[5] = { 1,8,6,4,9 };
	maxNum = max1d(nums, 5);
	printf("max Num is: %d", maxNum);
	return 0;
}

int max1d(int *nums, int cols) {
	int i;
	int max = nums[0];
	for (i = 1; i < cols; i++) {
		if (max < nums[i]) {
			max = nums[i];
		}
	}
	return max;
}

int max1f(double *dB, int cols);
int E10_4(void) {
	double db[6] = { 1.1,2.2,3.3 };
	int i = max1f(db, 6);
	printf("the max double is at: %d\n", i);
	printf("the max double is: %f", db[i]);
	return 0;
}

int max1f(double *dB, int cols) {
	int i = 0;
	int j;
	int max = dB[i];
	for (j = 1; j < cols; j++) {
		if (max < dB[j]) {
			i = j;
		}
	}
	return i;
}

double difference(double *num, int cols);
void sortOfMine(double *num, int cols);
int E10_5(void) {
	double nums[6] = {12.2,2.2,5.5,9.0,3.1,4.5};
	double D_value = difference(nums, 6);
	printf("the D_value is: %f", D_value);
	return 0;
}

double difference(double *num, int cols) {
	sortOfMine(num, cols);
	return num[cols - 1] - num[0];
}

void sortOfMine(double *num, int cols) {
	double temp;
	int i;
	int j;
	for (j = cols; j > 0; j--) {
		for (i = 1; i < j; i++) {
			if (num[i - 1] > num[i]) {
				temp = num[i - 1];
				num[i - 1] = num[i];
				num[i] = temp;
			}
		}
	}
}

int E10_6(void) {

}