#include<iostream>
using namespace std;

template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len;j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

static void test01()
{
	char charArr[] = "bacedf";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	printArray(charArr, len);
}

static void test02()
{
	int intArr[] = {4, 5, 7, 3, 9, 2, 1, 6, 8};
	int len = sizeof(intArr) / sizeof(int);
	mySort(intArr, len);
	printArray(intArr, len);
}

int main_method_template()
{
	//test01();
	
	test02();

	return 0;
}