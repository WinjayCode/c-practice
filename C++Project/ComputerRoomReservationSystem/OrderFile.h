#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"GlobalFile.h"

class OrderFile
{
public:
	OrderFile();

	// 更新预约记录
	void updateOrder();

	// 记录的容器 key 记录的条数  value 具体记录的键值对信息
	map<int, map<string, string>> m_orderData;

	// 记录预约条数
	int m_Size;
};