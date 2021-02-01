#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class WorkerManager {
public:
    WorkerManager();

    void Show_Menu();

    void ExitSystem();
    
    // ��¼ְ������
    int m_EmpNum;

    // ְ������ָ��
    Worker ** m_EmpArray;

    // ���ְ��
    void Add_Emp();

    ~WorkerManager();
};
