#include<iostream>

using namespace std;

// ð������
//1.�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
//2.��ÿһ������Ԫ����ͬ���Ĺ�����ִ����Ϻ��ҵ���һ�����ֵ
//3.�ظ����ϵĲ��裬ÿ�αȽϴ��� - 1��ֱ������Ҫ�Ƚ�
int main_bubble_sort()
{
	int arr[9] = { 7, 3, 8, 2, 1, 6, 5, 9, 4 };
	cout << "����ǰ��" << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// ����
	for (int i = 0; i < size(arr) - 1; i++) // ��������� = ���鳤�� - 1��
	{
		for (int j = 0; j < size(arr) - 1 - i; j++) // ÿ�ֶԱȵĴ��� = ����ĳ��� - �������� - 1��
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "�����" << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}