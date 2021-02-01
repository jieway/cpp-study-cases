#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class WorkerManager {
public:
    WorkerManager();

    void Show_Menu();

    void ExitSystem();
    
    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker ** m_EmpArray;

    // 添加职工
    void Add_Emp();

    ~WorkerManager();
};
