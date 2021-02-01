#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

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

    // 标志文件是否为空
    bool m_FileIsEmpty;

    // 添加职工
    void Add_Emp();

    // 保存文件
    void save();

    // 读取文件中职工人数
    int get_EmpNum();

    // 将文件的内容从文本读取到内存中
    void init_Emp();

    // 查看
    void Show_Emp();
    
    ~WorkerManager();
};
