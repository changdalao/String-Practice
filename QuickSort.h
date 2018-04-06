#include<stdio.h>
#include<assert.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Print(int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, size_t n)//ֱ�Ӳ�������
{
	assert(n);
	for (size_t i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//��������
		{
			if (a[end] > tmp)//���ұ�tmpС��λ��,���Һ�������
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
//�Ż�1������ȡ��
int MidInRange(int* a, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[right] < a[left])
			return left;
		else
			return right;
	}
	if (a[left] > a[mid])
	{
		if (a[right] < a[mid])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
}
//����1������ָ�뷨
int Partion1(int* a, int left, int right)
{
	int index = MidInRange(a, left, right);//����ȡ���Ż�
	Swap(&a[index], &a[right]);
	int key = a[right];
	int begin = left, end = right;
	while (begin < end)
	{
		while (a[begin] <= key && (begin<end))//�ҵ���߱�key���
			begin++;
		while (a[end] >= key && (begin<end))//�ҵ��ұ߱�keyС��
			end--;
		Swap(&a[begin], &a[end]);//��������ֵ
	}
	//�ҵ�key�ĺ���λ�ã���key����
	Swap(&a[end], &a[right]);
	return begin;
}
//����2���ڿӷ�
int Partion2(int* a, int left, int right)
{
	assert(a);
	int key = a[right];
	int begin = left, end = right;
	if (end - begin <= 25)//�Ż���������С����
		InsertSort(a, right - left + 1);
	else
	{
		while (begin < end)
		{
			while (a[begin] <= key && (begin < end))
				begin++;
			a[end] = a[begin];
			while (a[end] >= key && (begin < end))
				end--;
			a[begin] = a[end];
		}
		a[begin] = key;
		return begin;
	}
}
//����3;ǰ��ָ�뷨
int Partion3(int* a, int left, int right)
{
	assert(a);
	int prev = left - 1;
	int cur = left;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key)
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[++prev], &a[right]);
	return prev;
}

#include"Stack.h"

//�ݹ�
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left < right)
	{
		int div = Partion1(a, left, right);
		QuickSort(a, 0, div-1);//��
		QuickSort(a, div+1, right);//��
	}
}
//�ǵݹ�
void QuickSortR(int* a, int left, int right)
{
	assert(a);
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (StackEmpty(&s) != NULL)
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int div = Partion1(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, div - 1);
		}
		if (end > div + 1)
		{
			StackPush(&s, div + 1);
			StackPush(&s, end);
		}
	}
}
void TestQuickSort()
{
	int a[] = { 9,8,7,6,4,3,10,2,1,0,5 };
	int left = 0;
	int right = sizeof(a) / sizeof(a[0]) - 1;
	QuickSortR(a, left, right);
	Print(a, sizeof(a) / sizeof(a[0]));
}