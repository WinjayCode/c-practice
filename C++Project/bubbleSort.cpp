#include<iostream>

using namespace std;

// 冒泡排序
//1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//2.对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值
//3.重复以上的步骤，每次比较次数 - 1，直到不需要比较
int main_bubble_sort()
{
	int arr[9] = { 7, 3, 8, 2, 1, 6, 5, 9, 4 };
	cout << "排序前：" << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// 排序
	for (int i = 0; i < size(arr) - 1; i++) // 排序的轮数 = 数组长度 - 1；
	{
		for (int j = 0; j < size(arr) - 1 - i; j++) // 每轮对比的次数 = 数组的长度 - 排序轮数 - 1；
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "排序后：" << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}