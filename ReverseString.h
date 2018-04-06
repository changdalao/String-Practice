#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//字符串的旋转

//方法1:简单粗暴地一个一个字符移动，旋转m个字符,字符串长度为n,时间复杂度为O(m*n)
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
	while (input--)//多次旋转
		ReverseStringOne(arr, n);//单次旋转
}

//方法2：将旋转的字符看做一个整体
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
	//不能写char* arr="abcdef",这样写字符串保存在字符常量区，const类型，不可更改
	int input = 0;
	printf("原字符串>%s\n", arr);
	printf("请输入旋转个数>");
	scanf("%d", &input);
	//ReverseString(arr, (input % (strlen(arr))) , strlen(arr));
	ReverseStringR(arr, (input % (strlen(arr))) , strlen(arr));

	printf("旋转%d次后，字符串为>%s\n", input, arr);
}