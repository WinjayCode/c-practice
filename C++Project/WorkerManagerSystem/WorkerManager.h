#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
#define FILENAME "WorkerManagerSystem\\empFile.txt"

class WorkerManager
{
public:
    WorkerManager();

    void Show_Menu();

    void Add_Emp();

    void saveFile();

    int get_EmpNum();

    void init_Emp();

    void Show_Emp();

    void Del_Emp();

    int IsExist(int id);

    void Mod_Emp();

    void Find_Emp();

    void Sort_Emp();

    void Clean_File();

    void exitSystem();

    void pauseAndClear();

    int m_EmpNum;

    Worker** m_EmpArray;

    bool m_FileIsEmpty;

    ~WorkerManager();
};
