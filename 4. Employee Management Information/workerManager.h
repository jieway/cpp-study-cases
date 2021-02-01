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

    // 查看职工信息
    void Show_Emp();

    // 判断职工是否存在
    int IsExist(int id);

    // 删除离职职工
    void Del_Emp();

    // 修改职工信息
    void Mod_Emp();

    // 查找职工
    void Find_Emp();

    // 排序
    void Sort_Emp();

    // 析构扫尾
    ~WorkerManager();
};
