#include <iostream>
#include "workerManager.h"
#include "workerManager.cpp"

#include "worker.h"

#include "employee.h"
#include "employee.cpp"

#include "manager.h"
#include "manager.cpp"

#include "boss.h"
#include "boss.cpp"

using namespace std;

void TestM() {

    // 员工类，经理类和老板类测试。
    Worker *w = new Employee(1, "张三", 1);
    w->showInfo();

    Worker *m = new Manager(1, "张三", 2);
    m->showInfo();

    Worker *b = new Boss(1, "张三", 3);
    b->showInfo();
}

int main() {

    // TestM();
    // return 0;

    WorkerManager wm;

    int choice = 0;
    while(true) {
        wm.Show_Menu();
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch(choice) {
            case 0: // 0. 退出系统
                wm.ExitSystem();
                break;
            case 1: // 1. 增加职工信息
                wm.Add_Emp();
                break;
            case 2: // 2. 显示职工信息
                wm.Show_Emp();
                break;
            case 3: // 3. 删除励志职工
                break;
            case 4: // 4. 修改职工信息
                break;
            case 5: // 5. 查找职工信息
                break;
            case 6: // 6. 按照编号排序
                break;
            case 7: // 7. 清空所有文档
                break;
            default:
                system("cls");
                break;
            }
    }
    return 0;
}
