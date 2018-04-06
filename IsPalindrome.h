#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"Stack.h"

//�����ַ������ж�

//����1��
//��ջ�жϣ��ַ�����ջ����ջʱ��ԭ�ַ�����ȣ����ջΪ�գ����ַ������������ڼ䶼��ȣ���Ϊ�����ַ���
int IsPalindrome1(char* arr,int len)
{
	assert(arr);
	Stack s;
	StackInit(&s);
	for (int i = 0; i < len; i++)//�ַ���������ջ
		StackPush(&s, arr[i]);
	while (StackEmpty(&s) && (*arr != '\0'))//��ջ�����ж�
	{
		char tmp = StackTop(&s);
		if (*arr == tmp)
		{
			arr++;
			StackPop(&s);
		}
		else
			return -1;
	}
	return 1;

}

//����2�����������м�����ж�
//ʱ�临�Ӷ�O(n)
int IsPalindrome2(char* arr,int len)
{
	assert(arr);
	int begin = 0, end = len - 1;
	while (begin < end)
	{
		if (arr[begin] == arr[end])
		{
			begin++, end--;
		}
		else
			return -1;
	}
	return 1;
}
void Test2()
{
	char* arr = "aabccbaa";
	//�ж��ַ����Ƿ�����ַ����������޸��ַ������ݣ����Զ���Ϊchar*,�ַ����������ַ�����������const���ͣ����ɸ���
	int len = strlen(arr);
	printf("�Ƿ�����ַ���?>%d\n", IsPalindrome1(arr,len));
	printf("�Ƿ�����ַ���?>%d\n", IsPalindrome2(arr, len));
}