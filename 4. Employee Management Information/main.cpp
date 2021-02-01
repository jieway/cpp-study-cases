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

    // Ա���࣬��������ϰ�����ԡ�
    Worker *w = new Employee(1, "����", 1);
    w->showInfo();

    Worker *m = new Manager(1, "����", 2);
    m->showInfo();

    Worker *b = new Boss(1, "����", 3);
    b->showInfo();
}

int main() {

    // TestM();
    // return 0;

    WorkerManager wm;

    int choice = 0;
    while(true) {
        wm.Show_Menu();
        cout << "���������ѡ��" << endl;
        cin >> choice;
        switch(choice) {
            case 0: // 0. �˳�ϵͳ
                wm.ExitSystem();
                break;
            case 1: // 1. ����ְ����Ϣ
                wm.Add_Emp();
                break;
            case 2: // 2. ��ʾְ����Ϣ
                wm.Show_Emp();
                break;
            case 3: // 3. ɾ����־ְ��
                break;
            case 4: // 4. �޸�ְ����Ϣ
                break;
            case 5: // 5. ����ְ����Ϣ
                break;
            case 6: // 6. ���ձ������
                break;
            case 7: // 7. ��������ĵ�
                break;
            default:
                system("cls");
                break;
            }
    }
    return 0;
}
