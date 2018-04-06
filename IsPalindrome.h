#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"Stack.h"

//回文字符串的判断
//方法1：
//用栈判断，字符串入栈，出栈时和原字符串相比，如果栈为空，且字符串遍历结束期间都相等，则为回文字符串
int IsPalindrome1(char* arr,int len)
{
	assert(arr);
	Stack s;
	StackInit(&s);
	for (int i = 0; i < len; i++)//字符串挨个入栈
		StackPush(&s, arr[i]);
	while (StackEmpty(&s) && (*arr != '\0'))//出栈进行判断
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

//方法2：从两边向中间遍历判断
//时间复杂度O(n)
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
	//判断字符串是否回文字符串，不比修改字符串内容，所以定义为char*,字符串保存在字符常量区，即const类型，不可更改
	int len = strlen(arr);
	printf("是否回文字符串?>%d\n", IsPalindrome1(arr,len));
	printf("是否回文字符串?>%d\n", IsPalindrome2(arr, len));
}
