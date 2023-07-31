#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
#define FILENAME "SpeechManagerSystem\\speechRecord.csv"

class SpeechManager
{
public:
	SpeechManager();

	// 初始化容器和属性
	void initSpeech();

	// 创建12名选手
	void createSpeaker();

	// 开始比赛，比赛整个流程控制函数
	void startSpeech();

	// 抽签
	void speechDraw();

	// 比赛
	void speechContest();

	// 显示得分
	void showScore();

	// 保存记录
	void saveRecord();

	void show_Menu();

	void exitSystem();

	void pauseAndClear();

	~SpeechManager();

	// 保存第一轮比赛选手编号容器
	vector<int>v1;

	// 第一轮晋级选手编号容器
	vector<int>v2;

	// 胜出前三名选手编号容器
	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_Index;
};