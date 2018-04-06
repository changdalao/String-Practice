#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//�ַ�������ת

//����1:�򵥴ֱ���һ��һ���ַ��ƶ�����תm���ַ�,�ַ�������Ϊn,ʱ�临�Ӷ�ΪO(m*n)
void ReverseStringOne(char* arr,int n)
{
	assert(arr);
	char tmp = arr[0];
	int begin = 1;
	while (begin < n)
	{
		arr[begin - 1] = arr[begin];
		begin++;
	}
	arr[begin - 1] = tmp;
}
void ReverseString(char* arr,int input,int n)
{
	assert(arr);
	while (input--)//�����ת
		ReverseStringOne(arr, n);//������ת
}

//����2������ת���ַ�����һ������
void Reverse(char* arr, int begin, int end)
{
	assert(arr);
	while (begin < end)
	{
		char tmp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = tmp;
		end--, begin++;
	}
}
void ReverseStringR(char* arr, int input, int n)
{
	assert(arr);
	Reverse(arr, 0, input - 1);
	Reverse(arr, input, n - 1);
	Reverse(arr, 0, n - 1);
}
void Test1()
{
	char* arr = "abcdef";
	//����дchar* arr="abcdef",����д�ַ����������ַ���������const���ͣ����ɸ���
	int input = 0;
	printf("ԭ�ַ���>%s\n", arr);
	printf("��������ת����>");
	scanf("%d", &input);
	//ReverseString(arr, (input % (strlen(arr))) , strlen(arr));
	ReverseStringR(arr, (input % (strlen(arr))) , strlen(arr));

	printf("��ת%d�κ��ַ���Ϊ>%s\n", input, arr);
}