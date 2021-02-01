#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);    // ���ļ�

    if(!ifs.is_open()) {
        cout << "�ļ������ڣ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;

    }

    char ch;
    ifs >> ch;
    if(ifs.eof()) {
        cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;
    
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    init_Emp();

    // for (int i = 0; i < this->m_EmpNum; i++){
    //     cout << "ְ���ţ�" << this->m_EmpArray[i]->m_Id
    //             << "ְ��������" << this->m_EmpArray[i]->m_Name
    //             << "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl; 
    // }

}

void WorkerManager::Show_Menu(){

    cout << "*******************************************************************" << endl;
    cout << "*********************��ӭʹ��ְ������ϵͳ��************************" << endl;
    cout << "********************* 0. �˳�����ϵͳ *****************************" << endl;
    cout << "********************* 1. ����ְ����Ϣ *****************************" << endl;
    cout << "********************* 2. ��ʾְ����Ϣ *****************************" << endl;
    cout << "********************* 3. ɾ����ְְ�� *****************************" << endl;
    cout << "********************* 4. �޸�ְ����Ϣ *****************************" << endl;
    cout << "********************* 5. ����ְ����Ϣ *****************************" << endl;
    cout << "********************* 6. ���ձ������ *****************************" << endl;
    cout << "********************* 7. ��������ĵ� *****************************" << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp(){
    cout << "���������ְ����������" << endl;

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

        // �������������
        for (int i = 0; i < addNum; i++){
            int id; // ְ�����
            string name; // ְ������
            int dSelect; // ����ѡ��

            cout << "�������" << i + 1 << "����ְ���ı�š�" << endl;
            cin >> id;

            cout << "�������" << i + 1 << "����ְ����������" << endl;
            cin >> name;

            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1. ��ְͨ��" << endl;
            cout << "2. ����" << endl;
            cout << "3. �ϰ�" << endl;
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

            // �������õ�ְ�����浽�����С�
            newSpace[this->m_EmpNum + i] = worker;
        }

        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;

        cout << "�ɹ����" << addNum << "����ְ����" << endl; 

        this->save();

    }else {
        cout << "��������" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::Show_Emp(){
    
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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

int WorkerManager::IsExist(int id){
    int index = -1;

    for(int i = 0; i < this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            index = i;

            break;
        }
    }

    return index;
}

void WorkerManager::Del_Emp(){
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }else{

        int id;
        cout << "������Ҫɾ��Ա���� ID" << endl;
        cin >> id;
        if (IsExist(id) != -1){
            for (int i = id; i < this->m_EmpNum - 1; i++){
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "ְ���Ѿ�ɾ����" << endl;
        }else{
            cout << "ɾ��ʧ�ܣ�ְ�������ڣ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }else{
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;
        int index = this->IsExist(id);
        if(index != -1) {
            delete this->m_EmpArray[index];
            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newId;

            cout << "��������������" << endl;
            cin >> newName;

            cout << "�������λ��" << endl;
            cout << "1. ��ְͨ��" << endl;
            cout << "2. ����" << endl;
            cout << "3. �ϰ�" << endl;
            cin >> dSelect;

            Worker * newW = NULL;
            switch (dSelect){
                case 1:
                    newW = new Employee(newId, newName, dSelect);
                    break;
                case 2:
                    newW = new Manager(newId, newName, dSelect);
                    break;
                case 3:
                    newW = new Boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[index] = newW;

            cout << "�޸ĳɹ���" << endl;

            this->save();
        }else{
            cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp(){

    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }else{
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1. ��ְ����Ų���" << endl;
        cout << "2. ��ְ����������" << endl;

        int select = 0;
        cin >> select;

        if(select == 1){

            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;

            int index = IsExist(id);
            if(index != -1){
                cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
                this->m_EmpArray[index]->showInfo();
            }else {
                cout << "����ʧ�ܣ���Ա�������ڣ�" << endl;
            }
        }else if (select == 2){

            string name = "";
            cout << "������Ҫ��ѯԱ����������" << endl;
            cin >> name;

            bool flag = false;

            for(int i = 0; i < this->m_EmpNum; i++){
                if (this->m_EmpArray[i]->m_Name == name){
                    cout << "���ҳɹ���ְ�����Ϊ��" 
                         << this->m_EmpArray[i]->m_Id
                         << "��ְ����Ϣ���£�" << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }

            if(flag == false){
                cout << "����ʧ�ܣ����޴��ˣ�" << endl;
            }

        }else {
            cout << "����ѡ������" << endl;
        }

    system("pause");
    system("cls");
    }
}

WorkerManager::~WorkerManager(){

    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }

}