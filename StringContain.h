#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//�ַ����İ���

//����1��������ѯO(m*n)
int StringContain1(const char* arr, const char* a)
{
	assert(arr&&a);
	char* des = arr;
	char* src = a;
	while (*src != NULL)
	{
		des = arr;//��ѯһ�κ��轫des������Ϊԭ���ַ����Ŀ�ʼ�����²�ѯ
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
	
	printf("\"AACD\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr,a1));
	printf("\"BDEC\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr,a2));
	printf("\"ECDA\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr,a3));
	printf("\"EEBD\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr,a4));
	printf("\"BEF\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr, a5));
	printf("\"abcde\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain1(arr,a6));

	//printf("\"AACD\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n",StringContain2(arr,strlen(arr),a1,strlen(a1)));
	//printf("\"BDEC\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain2(arr, strlen(arr), a2, strlen(a1)));
	//printf("\"ECDA\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain2(arr, strlen(arr), a3, strlen(a1)));
	//printf("\"EEBD\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain2(arr, strlen(arr), a4, strlen(a1)));
	//printf("\"BEF\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain2(arr, strlen(arr), a5, strlen(a1)));
	//printf("\"abcde\"�Ƿ���\"ABCDE\"���Ӵ�?>%d\n", StringContain2(arr, strlen(arr), a6, strlen(a1)));
}