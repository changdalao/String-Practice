#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//字符串的包含

//方法1：遍历查询O(m*n)
int StringContain1(const char* arr, const char* a)
{
	assert(arr&&a);
	char* des = arr;
	char* src = a;
	while (*src != NULL)
	{
		des = arr;//查询一次后，需将des重新置为原来字符串的开始，重新查询
		while (*des)
		{
			if (*src == *des)
			{
				break;
			}
			des++;
		}
		if (*des != *src)
			return -1;
		src++;
	}
	return 1;
}
void Test3()
{
	char* arr = "ABCDE";
	char* a1 = "AACD";
	char* a2 = "BDEC";
	char* a3 = "ECDA";
	char* a4 = "EEBD";
	char* a5 = "BEF";
	char* a6 = "abcde";
	 
	printf("\"AACD\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr,a1));
	printf("\"BDEC\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr,a2));
	printf("\"ECDA\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr,a3));
	printf("\"EEBD\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr,a4));
	printf("\"BEF\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr, a5));
	printf("\"abcde\"是否是\"ABCDE\"的子串?>%d\n", StringContain1(arr,a6));

	//printf("\"AACD\"是否是\"ABCDE\"的子串?>%d\n",StringContain2(arr,strlen(arr),a1,strlen(a1)));
	//printf("\"BDEC\"是否是\"ABCDE\"的子串?>%d\n", StringContain2(arr, strlen(arr), a2, strlen(a1)));
	//printf("\"ECDA\"是否是\"ABCDE\"的子串?>%d\n", StringContain2(arr, strlen(arr), a3, strlen(a1)));
	//printf("\"EEBD\"是否是\"ABCDE\"的子串?>%d\n", StringContain2(arr, strlen(arr), a4, strlen(a1)));
	//printf("\"BEF\"是否是\"ABCDE\"的子串?>%d\n", StringContain2(arr, strlen(arr), a5, strlen(a1)));
	//printf("\"abcde\"是否是\"ABCDE\"的子串?>%d\n", StringContain2(arr, strlen(arr), a6, strlen(a1)));
}
