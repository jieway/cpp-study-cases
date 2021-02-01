#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);    // 读文件

    if(!ifs.is_open()) {
        cout << "文件不存在！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;

    }

    char ch;
    ifs >> ch;
    if(ifs.eof()) {
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;
    
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    init_Emp();

    // for (int i = 0; i < this->m_EmpNum; i++){
    //     cout << "职工号：" << this->m_EmpArray[i]->m_Id
    //             << "职工姓名：" << this->m_EmpArray[i]->m_Name
    //             << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl; 
    // }

}

void WorkerManager::Show_Menu(){

    cout << "*******************************************************************" << endl;
    cout << "*********************欢迎使用职工管理系统！************************" << endl;
    cout << "********************* 0. 退出管理系统 *****************************" << endl;
    cout << "********************* 1. 增加职工信息 *****************************" << endl;
    cout << "********************* 2. 显示职工信息 *****************************" << endl;
    cout << "********************* 3. 删除离职职工 *****************************" << endl;
    cout << "********************* 4. 修改职工信息 *****************************" << endl;
    cout << "********************* 5. 查找职工信息 *****************************" << endl;
    cout << "********************* 6. 按照编号排序 *****************************" << endl;
    cout << "********************* 7. 清空所有文档 *****************************" << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp(){
    cout << "请输入添加职工的数量：" << endl;

    int addNum = 0;

    cin >> addNum;

    if (addNum > 0){
        int newSize = this->m_EmpNum + addNum;

        Worker **newSpace = new Worker *[newSize];

        if(this->m_EmpArray != NULL){
            for (int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 批量添加新数据
        for (int i = 0; i < addNum; i++){
            int id; // 职工编号
            string name; // 职工姓名
            int dSelect; // 部门选择

            cout << "请输入第" << i + 1 << "个新职工的编号。" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工的姓名。" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1. 普通职工" << endl;
            cout << "2. 经理" << endl;
            cout << "3. 老板" << endl;
            cin >> dSelect;
            
            Worker *worker = NULL;

            switch(dSelect){
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
            }

            // 将创建好的职工保存到数组中。
            newSpace[this->m_EmpNum + i] = worker;
        }

        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;

        cout << "成功添加" << addNum << "名新职工。" << endl; 

        this->save();

    }else {
        cout << "输入有误！" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::Show_Emp(){
    
    if(this->m_FileIsEmpty){
        cout << "文件不存在或记录为空！" << endl;
    }else {
        for (int i = 0; i < this->m_EmpNum; i++){
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::save(){

    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = NULL;
        if (dId == 1){
            worker = new Employee(id,name,dId);
        }else if (dId == 2){
            worker = new Manager(id,name,dId);
        }else if (dId == 3){
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index++] = worker;
    }
}

WorkerManager::~WorkerManager(){

    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }

}