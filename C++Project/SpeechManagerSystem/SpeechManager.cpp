#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	initSpeech();
	createSpeaker();
	loadRecord();
}

void SpeechManager::initSpeech()
{
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Index = 1;
	m_Record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		v1.push_back(i + 10001);

		m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech()
{
	// 第一轮比赛
	// 1、抽签
	speechDraw();
	// 2、比赛
	speechContest();
	// 3、显示晋级结果
	showScore();

	// 第二轮比赛
	m_Index++;
	// 1、抽签
	speechDraw();
	// 2、比赛
	speechContest();
	// 3、显示最终结果
	showScore();
	// 4、保存分数
	saveRecord();

	// 重置比赛，获取记录
	initSpeech();
	createSpeaker();
	loadRecord();

	cout << "本届比赛结束！" << endl;
	pauseAndClear();
}

void SpeechManager::speechDraw()
{
	cout << "第 << " << m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "-------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << endl;
	system("pause");
}

void SpeechManager::speechContest()
{
	cout << "----------- 第" << m_Index << "轮正式比赛开始：-----------" << endl;
	
	multimap<double, int, greater<double>> groupScore; // 临时容器，保存 key分数 value选手编号

	int num = 0; // 记录人员数，6个为1组

	vector<int>v_Src; // 比赛的人员容器
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// 遍历所有参赛选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		// 评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 600 ~ 1000
			// cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>()); // 排序
		d.pop_front(); // 去掉最高分
		d.pop_back(); // 去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f); // 获取总分
		double avg = sum / (double)d.size(); // 获取平均分

		// cout << "编号：" << *it << " 选手：" << m_Speaker[*it].m_Name << " 获取平均分为：" << avg << endl; // 打印分数
		m_Speaker[*it].m_Score[m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << m_Speaker[it->second].m_Name
					<< " 成绩：" << m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}

			int count = 0;
			// 取前三名
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end() && count < 3; it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();

			cout << endl;
		}
	}

	cout << "----------- 第" << m_Index << "轮比赛完毕 -----------" << endl;
	cout << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "----------- 第" << m_Index << "轮晋级选手信息如下： -----------" << endl;
	vector<int>v;
	if (m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name
			<< " 成绩：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}

	cout << endl;
	pauseAndClear();
	show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "记录已经保存！" << endl;

	fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	fileIsEmpty = false;

	ifs.putback(ch); // 将上面读取的单个字符放回去

	string data;
	int index = 0; // 第几届
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v; // 存放6个string字符串

		int pos = -1; // 查找“,”位置的变量 
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); // 从0开始查找
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start); // 找到了，进行分割 参数1 起始位置，参数2 截取长度
			v.push_back(tmp);
			start = pos + 1;
		}

		m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" << endl;
			cout << "冠军编号：" << m_Record[i][0] << " 得分：" << m_Record[i][1] << " "
				"亚军编号：" << m_Record[i][2] << " 得分：" << m_Record[i][3] << " "
				"季军编号：" << m_Record[i][4] << " 得分：" << m_Record[i][5] << endl;
		}
	}
	
	pauseAndClear();
}

void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// 打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		initSpeech();
		createSpeaker();
		loadRecord();

		cout << "清空成功！" << endl;
	}

	pauseAndClear();
}

void SpeechManager::show_Menu()
{
	cout << "*************************************" << endl;
	cout << "********** 欢迎参加演讲比赛 *********" << endl;
	cout << "********** 1、开始演讲比赛 **********" << endl;
	cout << "********** 2、查看往届记录 **********" << endl;
	cout << "********** 3、清空比赛记录 **********" << endl;
	cout << "********** 0、退出比赛程序 **********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void SpeechManager::pauseAndClear()
{
	// mac 下实现暂停输出和清屏功能
	// cin.ignore();
	// cin.get();
	// system("clear");

	// windows 下的实现
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}