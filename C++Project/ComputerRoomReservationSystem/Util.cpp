#include"Util.h"

void pauseAndClear()
{
	// mac 下实现暂停输出和清屏功能
	// cin.ignore();
	// cin.get();
	// system("clear");

	// windows 下的实现
	system("pause");
	system("cls");
}