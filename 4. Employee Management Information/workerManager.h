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
    
    // ��¼ְ������
    int m_EmpNum;

    // ְ������ָ��
    Worker ** m_EmpArray;

    // ��־�ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty;

    // ���ְ��
    void Add_Emp();

    // �����ļ�
    void save();

    // ��ȡ�ļ���ְ������
    int get_EmpNum();

    // ���ļ������ݴ��ı���ȡ���ڴ���
    void init_Emp();

    // �鿴
    void Show_Emp();
    
    ~WorkerManager();
};
